#ifndef MOTOR_H_
#define MOTOR_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include "stm32f4xx_tim.h"
#include "stm32f4xx_gpio.h"
#include "misc.h"

#include "Drivers/Timer.h"
#include "Drivers/Pin.h"
#include "Drivers/PWM.h"
#include "Misc/Formatter.h"
#include "Utilities/LCD.h"

#define MAX_DUTY 0.10
#define MIN_DUTY 0.05
#define MOTOR_STARTUP_DUTY 0.0526 // 测试出来的最小电机启动占空比

class Motor {
 private:
  PWM pwm_;
  float duty_;
  float limit_duty(float duty);
 public:
  Motor();
  Motor(uint32_t freq, float duty, uint8_t TIM_No, uint8_t CH_No,PinTypedef pin);
  void set_duty(float duty);
  float duty(void);
}; // class Motor

#ifdef __cplusplus
}
#endif

#endif