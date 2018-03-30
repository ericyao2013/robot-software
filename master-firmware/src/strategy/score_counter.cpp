#include <ch.h>
#include <hal.h>
#include <error/error.h>

#include "main.h"
#include "priorities.h"

#include "strategy/score.h"
#include "strategy/score_counter.h"
#include "strategy/state.h"

#define SCORE_COUNTER_STACKSIZE 1024

static THD_FUNCTION(score_counter_thd, arg)
{
    (void)arg;
    chRegSetThreadName(__FUNCTION__);

    static messagebus_topic_t score_topic;
    static MUTEX_DECL(score_topic_lock);
    static CONDVAR_DECL(score_topic_condvar);
    static int _score;
    messagebus_topic_init(&score_topic, &score_topic_lock, &score_topic_condvar, &_score, sizeof(_score));
    messagebus_advertise_topic(&bus, &score_topic, "/score");

    RobotState state;
    messagebus_topic_t* strategy_state_topic = messagebus_find_topic_blocking(&bus, "/state");

    NOTICE("Score initialized");
    while (true) {
        messagebus_topic_wait(strategy_state_topic, &state, sizeof(state));
        NOTICE("Received strategy state");

        int score = 5 + 5 + score_count_bee(state) + score_count_switch(state);
        messagebus_topic_publish(&score_topic, &score, sizeof(score));

        chThdSleepMilliseconds(1000 / SCORE_COUNTER_FREQUENCY);
    }
}

void score_counter_start()
{
    static THD_WORKING_AREA(score_counter_thd_wa, SCORE_COUNTER_STACKSIZE);
    chThdCreateStatic(score_counter_thd_wa, sizeof(score_counter_thd_wa),
                      SCORE_COUNTER_PRIO, score_counter_thd, NULL);
}
