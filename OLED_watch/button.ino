#include "button.h"

/**
 * 按键消抖
 * param btn_pin: 按键引脚
 * return bool: 按键电平高低
 */
bool debounce(int btn_pin) {
  bool state;
  bool previous_state;
  
  // 记录当前的状态
  previous_state = digitalRead(btn_pin);

  // 如果给定的 debounce_delay 时间中，状态都没有发生改变，说明按键稳定
  for(int cnt = 0; cnt < debounce_delay; cnt++) {
    delay(1);
    state = digitalRead(btn_pin);
    // 状态不一致，cnt 重置为 0
    if(state != previous_state) {
      cnt = 0; 
      // 记录当前状态
      previous_state = state;
    }
  }
  // 保持稳定，超过 debounce_delay 的时间，则返回按键状态
  return state;
}

/**
 * 判断按键是否按下
 * param btn_pin: 按键引脚
 * return bool: 按下为 true，否则为 false
 */
bool isBtnPressDown(int btn_pin) {
  bool btn_state = debounce(btn_pin);
  return !btn_state;
}