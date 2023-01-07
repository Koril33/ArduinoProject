void showInterface(String title, unsigned char bitmap[]) {
  display.clearDisplay();

  // 设置文本颜色
  display.setTextColor(SSD1306_WHITE);
  
  // 标题
  // textAtCenter(0, title, 2);
  
  display.drawBitmap(0, 16, bitmap, 128, 48, WHITE);
  display.display();
}

void timerInterface() {
  display.clearDisplay();

  // 设置 2 倍的字体大小
  display.setTextSize(2);
  // 设置文本颜色
  display.setTextColor(SSD1306_WHITE);
  
  // 标题
  display.setCursor(0, 0);
  textAtCenter(0, "Timer", 2); 
  
  display.drawBitmap(0, 16, timer_bmp, 128, 48, WHITE);
  display.display();
}


void clockInterface() {
  display.clearDisplay();

  // 设置 2 倍的字体大小
  display.setTextSize(2);
  // 设置文本颜色
  display.setTextColor(SSD1306_WHITE);
  
  // 标题
  display.setCursor(0, 0);
  // display.println("   Clock");
  textAtCenter(0, "Clock", 2);
  
  display.drawBitmap(0, 16, clock_bmp, 128, 48, WHITE);
  display.display();
}


void weatherInterface() {
  display.clearDisplay();

  // 设置 2 倍的字体大小
  display.setTextSize(2);
  // 设置文本颜色
  display.setTextColor(SSD1306_WHITE);
  
  // 标题
  display.setCursor(0, 0);
  textAtCenter(0, "Weather", 2);
  
  display.drawBitmap(0, 16, weather_bmp, 128, 48, WHITE);
  display.display();
}


void gameInterface() {
  display.clearDisplay();

  // 设置 2 倍的字体大小
  display.setTextSize(2);
  // 设置文本颜色
  display.setTextColor(SSD1306_WHITE);
  
  // 标题
  display.setCursor(0, 0);
  textAtCenter(0, "Game", 2);
  
  display.drawBitmap(0, 16, game_bmp, 128, 48, WHITE);
  display.display();
}


void settingInterface() {
  display.clearDisplay();

  // 设置 2 倍的字体大小
  display.setTextSize(2);
  // 设置文本颜色
  display.setTextColor(SSD1306_WHITE);
  
  // 标题
  display.setCursor(0, 0);
  textAtCenter(0, "Setting", 2);
  
  display.drawBitmap(0, 16, setting_bmp, 128, 48, WHITE);
  display.display();
}
