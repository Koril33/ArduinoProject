#include <SPI.h>
#include <Adafruit_SSD1306.h>
#include <dht11.h>
#include "OLED_watch.h"
#include "game_flappy_bird.h"
#include "watch_interface.h"
#include "button.h"


bool last_btn_state = HIGH;
String origin_time_str = "19:01:46";
int start_time = 0;

int interface_index = 1;
const int interface_total_num   = 5;

// OLED 显示
Adafruit_SSD1306 display(
  SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, 
  OLED_RESET, OLED_CS
);


// DHT11
dht11 DHT;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);

  pinMode(MENU_BTN, INPUT_PULLUP);
  pinMode(CHECK_BTN, INPUT_PULLUP);

  display.clearDisplay();

  start_time = millis();

}


void loop() {

  watch_app();

}


void watch_app() {
  // 绘制页面
  switchInterface(interface_index);

  // 菜单按钮按下，跳到下一个功能页面
  if (isBtnPressDown(MENU_BTN)) {
    delay(100);
    interface_index++;
    if (interface_index > interface_total_num) {
      interface_index = 1;
    }
  }

  // 确认按钮按下，进入当前功能页面
  if (isBtnPressDown(CHECK_BTN)) {
    delay(100);
    while (1) {
      enterInterface(interface_index);

      if (isBtnPressDown(MENU_BTN)) {
        delay(100);
        break;
      }
    }
  }
}


/**
 * 菜单，选择功能页面
 * param n: 指定的页面编号
 */
void switchInterface(int n) {

  switch (n) {
    
    case 1: clockInterface();   break;
    case 2: timerInterface();   break;
    case 3: weatherInterface(); break;
    case 4: gameInterface();    break;
    case 5: settingInterface(); break;

    default: clockInterface();
  }
}


/**
 * 进入指定的功能页面
 */
void enterInterface(int n) {

  switch (n) {
    
    case 1: clock();   break;
    case 2: timer();   break;
    case 3: weather(); break;
    case 4: game();    break;
    case 5: setting(); break;

  }
}


/**
 * 定时器
 */
void timer() {
  
  unsigned long elapsedTime = 0L;

  while(1) {
    timerStartInterface(millisToString(elapsedTime));
    delay(100);
    
    if (isBtnPressDown(CHECK_BTN)) {
      delay(100);
      elapsedTime = timerStart();
      delay(100);
      break;
    }
    
    if (isBtnPressDown(MENU_BTN)) {
      delay(100);
      return;
    }
  }

  while (1) {
    timerStartInterface(millisToString(elapsedTime));
    delay(100);
    if (isBtnPressDown(CHECK_BTN)) {
      delay(100);
      break;
    }
    
    if (isBtnPressDown(MENU_BTN)) {
      delay(100);
      return;
    }
  }

  if (isBtnPressDown(CHECK_BTN)) {
    delay(100);
    return;
  }
  
}


/**
 * 时钟
 */
void clock() {
  display.clearDisplay();

  // 设置 2 倍的字体大小
  display.setTextSize(2);
  // 设置文本颜色
  display.setTextColor(SSD1306_WHITE);
  
  // 标题
  display.setCursor(0, 0);
  display.println("   Clock");

  display.setTextSize(2);
  display.setCursor(20, 30);

  unsigned long interval = getInterval();
  unsigned long originTime = getOriginTime();

  String s = millisToString(interval + originTime);

  display.print(s.substring(0, s.indexOf(".")));
  display.display();
}


/**
 * 天气
 */
void weather() {
  display.clearDisplay();
  // 设置 2 倍的字体大小
  display.setTextSize(2);
  // 设置文本颜色
  display.setTextColor(SSD1306_WHITE);
  
  // 标题
  display.setCursor(0, 0);
  display.println("  Weather");
  

  int chk = DHT.read(DHT11_PIN);

  // 湿度数据
  display.setTextSize(1);
  display.setCursor(0, 30);
  display.print("Humidity:    ");
  display.print(DHT.humidity);
  display.print(" %");

  // 温度数据
  display.setCursor(0, 40);
  display.print("Temperature: ");
  display.print(DHT.temperature);
  display.print(" C");
  display.display();
}


/**
 * 游戏
 */
void game() {
  gameFlappyBird();
}


/**
 * 设置
 */
void setting() {
  display.clearDisplay();

  // 设置 2 倍的字体大小
  display.setTextSize(2);
  // 设置文本颜色
  display.setTextColor(SSD1306_WHITE);
  
  // 标题
  display.setCursor(0, 0);
  display.println("  Setting");
  
  display.setTextSize(1);
  display.setCursor(0, 30);
  display.print("Setting");
  display.display();
}


/**
 * 开始计时的页面
 * param time_str: 时间字符串，格式：HH:mm:ss.SSS
 */
void timerStartInterface(String time_str) {
  display.clearDisplay();

  // 设置 2 倍的字体大小
  display.setTextSize(2);
  // 设置文本颜色
  display.setTextColor(SSD1306_WHITE);

  // 标题
  display.setCursor(0, 0);
  display.println(" StopWatch"); 

  

  int splitIndex = time_str.indexOf(".");
  // 分成上下两行展示
  // 第一行：HH:mm:ss
  // 第二行：SSS
  String s1 = time_str.substring(0, splitIndex);
  String s2 = time_str.substring(splitIndex + 1, time_str.length());
  
  display.setCursor(15, 20);
  display.print(s1);

  display.setCursor(45, 40);
  display.print(s2);

  display.display();
}


unsigned long timerStart() {
  unsigned long start = millis();
  unsigned long elapsedTime;
  delay(100);
  while (!isBtnPressDown(CHECK_BTN)) {
    elapsedTime = millis() - start;
    timerStartInterface(millisToString(elapsedTime));
  }
  return elapsedTime;
}


String millisToString(unsigned long ms) {
  unsigned long seconds = 0;
  unsigned long minutes = 0;
  unsigned long hours   = 0;
  seconds = ms / 1000;
  if (seconds > 59) {
    minutes = seconds / 60;
    seconds = seconds % 60;
  }
  if (minutes > 59) {
    hours = minutes / 60;
    minutes = minutes % 60;
  }
  ms = ms % 1000;

  String hourStr = String(hours);
  String minuteStr = String(minutes);
  String secondStr = String(seconds);
  String msStr = String(ms);

  if (hourStr.length() == 1) {
    hourStr = "0" + hourStr;
  }

  if (minuteStr.length() == 1) {
    minuteStr = "0" + minuteStr;
  }

  if (secondStr.length() == 1) {
    secondStr = "0" + secondStr;
  }

  while (msStr.length() < 3) {
    msStr = "0" + msStr;
  }

  return hourStr + ":" + minuteStr + ":" + secondStr + "." + msStr;
}


unsigned long stringToMillis(String s) {
  String hourStr = s.substring(0, 2);
  unsigned long hour = (unsigned long) hourStr.toInt();
  String minuteStr = s.substring(3, 5);
  unsigned long minute = (unsigned long) minuteStr.toInt();
  String secondStr = s.substring(6, 8);
  unsigned long second = (unsigned long) secondStr.toInt();
  unsigned long res = hour * 3600 * 1000 + minute * 60 * 1000 + second * 1000;
  return res;
}


unsigned long getInterval() {
  return millis() - start_time;
}


unsigned long getOriginTime() {
  return stringToMillis(origin_time_str);
}