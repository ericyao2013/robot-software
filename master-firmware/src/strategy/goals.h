#ifndef STRATEGY_GOALS_H
#define STRATEGY_GOALS_H

#include <goap/goap.hpp>
#include "state.h"

struct InitGoal : goap::Goal<RobotState> {
    bool is_reached(RobotState state)
    {
        return state.arms_are_deployed == false;
    }
};

struct TowerGoal : goap::Goal<RobotState> {
    bool is_reached(RobotState state)
    {
        return state.arms_are_deployed == false
            && state.tower_built == true;
    }
};

struct SwitchGoal : goap::Goal<RobotState> {
    bool is_reached(RobotState state)
    {
        return state.switch_on == true;
    }
};

struct GameGoal : goap::Goal<RobotState> {
    bool is_reached(RobotState state)
    {
        return state.arms_are_deployed == false
            && state.tower_built == true
            && state.switch_on == true;
    }
};

#endif /* STRATEGY_GOALS_H */
