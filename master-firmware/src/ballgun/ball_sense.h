#ifndef BALL_SENSE_H
#define BALL_SENSE_H

#ifdef __cplusplus
extern "C" {
#endif

void ball_sense_start(void);
unsigned ball_sense_count(void);
void ball_sense_reset_count(void);

#ifdef __cplusplus
}
#endif

#endif /* BALL_SENSE_H */
