#define POSITIVE_NUM 9
#define NEGATIVE_NUM 3

#define first_layer   0
#define second_layer  1
#define third_layer   2

// 9 个公共正极引脚
uint8_t cp[POSITIVE_NUM] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

// 3 层公共负极引脚
uint8_t cn[NEGATIVE_NUM] = {A0, A1, A2};

/**
 * 每个 LED 的坐标由两部分组成
 * 1. num:    编号（0 - 8），正极引脚
 * 2. layer:  层数（0 - 2），负极引脚
 */
struct coordinate {
  int num;
  int layer;
};


void setup() {
  // put your setup code here, to run once:
  setPinMode(cp, POSITIVE_NUM, OUTPUT);
  setPinMode(cn, NEGATIVE_NUM, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  unsigned long delayTime = 200;
  lightenInOrder(delayTime);
  display1(delayTime);
  display2(delayTime);
}


/**
 * 设置 pinMode
 * param a[]: 给定的 IO 端口数组
 * param len: 数组长度
 * param mode: pinMode，INPUT or OUTPUT
 */
void setPinMode(uint8_t a[], int len, uint8_t mode) {
  for (int i = 0; i < len; i++) {
    pinMode(a[i], mode);
  }
}


/**
 * 根据坐标，点亮单个 LED 灯
 * param c: 给定的坐标
 * return void
 */
void lighten(struct coordinate c) {
  for (int i = 0; i < NEGATIVE_NUM; i++) {
    if (i == c.layer) {
      analogWrite(cn[i], 0);
    }
    else {
      analogWrite(cn[i], 255);
    }
  }

  for (int j = 0; j < POSITIVE_NUM; j++) {
    if (j == c.num) {
      analogWrite(cp[j], 255);
    }
    else {
      analogWrite(cp[j], 0);
    }
  }
}


/**
 * 依次点亮每一个 LED
 * param ms: 点亮的间隔时间，单位：毫秒
 * return void
 */
void lightenInOrder(unsigned long ms) {
  struct coordinate c;

  // 外循环遍历每一层
  for (int i = 0; i < NEGATIVE_NUM; i++) {
    // 内循环遍历每一层的每一个 LED
    for (int j = 0; j < POSITIVE_NUM; j++) {
      c.num = j;
      c.layer = i;
      lighten(c);
      delay(ms);
    }
  }
}


void display1(unsigned long ms) {

  //1
  analogWrite(cp[0], 255);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 255);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 255);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //2
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 255);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 255);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 255);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //3
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 255);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 255);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 255);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //4
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 255);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 255);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 255);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //5
  analogWrite(cp[0], 255);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 255);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 255);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //6
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 255);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 255);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 255);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //7
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 255);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 255);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 255);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //8
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 255);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 255);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 255);
  analogWrite(cn[third_layer], 255);
  delay(ms);


  //9
  analogWrite(cp[0], 255);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 255);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //10
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 255);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 255);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //11
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 255);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 255);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //12
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 255);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 255);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //13
  analogWrite(cp[0], 255);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 255);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //14
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 255);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 255);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //15
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 255);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 255);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //16
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 255);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 255);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //17
  analogWrite(cp[0], 255);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 255);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //18
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 255);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 255);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //19
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 255);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 255);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //20
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 255);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 255);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //21
  analogWrite(cp[0], 255);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 255);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //22
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 255);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 255);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //23
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 255);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 255);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //24
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 255);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 255);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);
}


void display2(unsigned long ms) {

  //1
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 0);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);


  //2
  analogWrite(cp[0], 255);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 255);
  analogWrite(cp[4], 0);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 255);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //3
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 255);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 255);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);



  //4
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 255);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 0);
  analogWrite(cp[5], 255);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 255);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //5
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 255);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 255);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //6
  analogWrite(cp[0], 255);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 255);
  analogWrite(cp[4], 0);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 255);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);


  //7
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 0);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //8
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 0);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 255);
  analogWrite(cp[7], 255);
  analogWrite(cp[8], 255);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //9
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 255);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 255);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //10
  analogWrite(cp[0], 255);
  analogWrite(cp[1], 255);
  analogWrite(cp[2], 255);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 0);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);



  //11
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 255);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 255);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //12
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 0);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 255);
  analogWrite(cp[7], 255);
  analogWrite(cp[8], 255);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //13
  analogWrite(cp[0], 0);
  analogWrite(cp[1], 0);
  analogWrite(cp[2], 0);
  analogWrite(cp[3], 0);
  analogWrite(cp[4], 0);
  analogWrite(cp[5], 0);
  analogWrite(cp[6], 0);
  analogWrite(cp[7], 0);
  analogWrite(cp[8], 0);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //14
  analogWrite(cp[0], 255);
  analogWrite(cp[1], 255);
  analogWrite(cp[2], 255);
  analogWrite(cp[3], 255);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 255);
  analogWrite(cp[6], 255);
  analogWrite(cp[7], 255);
  analogWrite(cp[8], 255);

  analogWrite(cn[first_layer], 255);
  analogWrite(cn[second_layer], 255);
  analogWrite(cn[third_layer], 0);
  delay(ms);

  //15
  analogWrite(cp[0], 255);
  analogWrite(cp[1], 255);
  analogWrite(cp[2], 255);
  analogWrite(cp[3], 255);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 255);
  analogWrite(cp[6], 255);
  analogWrite(cp[7], 255);
  analogWrite(cp[8], 255);

  analogWrite(cn[first_layer], 255);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //16
  analogWrite(cp[0], 255);
  analogWrite(cp[1], 255);
  analogWrite(cp[2], 255);
  analogWrite(cp[3], 255);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 255);
  analogWrite(cp[6], 255);
  analogWrite(cp[7], 255);
  analogWrite(cp[8], 255);

  analogWrite(cn[first_layer], 0);
  analogWrite(cn[second_layer], 255);
  analogWrite(cn[third_layer], 255);
  delay(ms);


  //17
  analogWrite(cp[0], 255);
  analogWrite(cp[1], 255);
  analogWrite(cp[2], 255);
  analogWrite(cp[3], 255);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 255);
  analogWrite(cp[6], 255);
  analogWrite(cp[7], 255);
  analogWrite(cp[8], 255);

  analogWrite(cn[first_layer], 255);
  analogWrite(cn[second_layer], 0);
  analogWrite(cn[third_layer], 255);
  delay(ms);

  //18
  analogWrite(cp[0], 255);
  analogWrite(cp[1], 255);
  analogWrite(cp[2], 255);
  analogWrite(cp[3], 255);
  analogWrite(cp[4], 255);
  analogWrite(cp[5], 255);
  analogWrite(cp[6], 255);
  analogWrite(cp[7], 255);
  analogWrite(cp[8], 255);

  analogWrite(cn[first_layer], 255);
  analogWrite(cn[second_layer], 255);
  analogWrite(cn[third_layer], 0);
  delay(ms);
}
