#include <SPI.h>
#include <Adafruit_SSD1306.h>
#include <dht11.h>

// OLED display width, in pixels
#define SCREEN_WIDTH 128
// OLED display height, in pixels
#define SCREEN_HEIGHT 64 

// Declaration for SSD1306 display connected using software SPI (default case):
// Clock
#define OLED_CLK    2
// Master Output Slave Input
#define OLED_MOSI   3
// Reset
#define OLED_RESET  4
// Data/Command
#define OLED_DC     5
// Chip Select
#define OLED_CS     6

#define DHT_DATA 7

// OLED 显示
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

// DHT11
dht11 DHT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 读取 DHT11 的数据
  int chk = DHT.read(DHT_DATA);
  // 显示在 OLED 上
  showDHT11Date(DHT.temperature, DHT.humidity);
  display.display();

  delay(100);
}

/**
 * DHT11 测试代码
 */ 
void DHT11Test() {
  int chk = DHT.read(DHT_DATA);

  Serial.print("Humidity (%): ");
  Serial.println(DHT.humidity);

  Serial.print("Temperature (C): ");
  Serial.println(DHT.temperature);
  delay(1000); 
}


/**
 * OLED 展示 DHT11 的数据
 * param t: 温度
 * param h: 湿度
 */
void showDHT11Date(int t, int h) {
  display.clearDisplay();
  // 设置 2 倍的字体大小
  display.setTextSize(2);
  // 设置文本颜色
  display.setTextColor(SSD1306_WHITE);
  
  // 标题
  display.setCursor(0, 0);
  display.println("DHT11 DATA");
  
  // 湿度数据
  display.setTextSize(1);
  display.setCursor(0, 30);
  display.print("Humidity:    ");
  display.print(h);
  display.print(" %");

  // 温度数据
  display.setCursor(0, 40);
  display.print("Temperature: ");
  display.print(t);
  display.print(" C");
}