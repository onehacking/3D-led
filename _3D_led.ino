/*
  2018年12月7日
  auther: onehacking
  Lience: MIT
  About: LED顺序，从左至右，第一层顺序为1-2-3，第二层为2-3-4
*/

#include "ESP8266WiFi.h"
const int GND[] = {16, 05, 04}; // Z轴楼层 共阴极 1-2-3
const int L1[] = {0, 2, 14};    // Z1共阳极 1-2-3
const int L2[] = {12, 13, 15};  // Z2共阳极 1-2-3
const int L3[] = {3, 1, 10};    // Z3共阳极 1-2-3

void OPG(int id) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(GND[i], HIGH);
  }
  if (id >= 0)
    digitalWrite(GND[id], LOW);
}

// 点亮所有LED
void openAll()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(GND[i], LOW);
    digitalWrite(L1[i], HIGH);
    digitalWrite(L2[i], HIGH);
    digitalWrite(L3[i], HIGH);
  }
}

// 关闭所有LED
void closeAll()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(GND[i], LOW);
    digitalWrite(L1[i], LOW);
    digitalWrite(L2[i], LOW);
    digitalWrite(L3[i], LOW);
  }
}

// 初始化GPIO
void RST()
{
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  Serial.begin(115200);
  // 循环GPIO全部置为输出模式
  for (int i = 0; i <= 3; i++)
  {
    pinMode(GND[i], OUTPUT);
    pinMode(L1[i], OUTPUT);
    pinMode(L2[i], OUTPUT);
    pinMode(L3[i], OUTPUT);
  }
  closeAll();
}

void OBO(int del)
{
  delay(del);
  digitalWrite(L1[0], HIGH);
  delay(del);
  digitalWrite(L1[1], HIGH);
  delay(del);
  digitalWrite(L1[2], HIGH);
  delay(del);
  digitalWrite(L2[0], HIGH);
  delay(del);
  digitalWrite(L2[1], HIGH);
  delay(del);
  digitalWrite(L2[2], HIGH);
  delay(del);
  digitalWrite(L3[0], HIGH);
  delay(del);
  digitalWrite(L3[1], HIGH);
  delay(del);
  digitalWrite(L3[2], HIGH);
  delay(del);
}

void RING(int del)
{
  delay(del);
  digitalWrite(L1[0], HIGH);
  delay(del);
  digitalWrite(L1[1], HIGH);
  delay(del);
  digitalWrite(L1[2], HIGH);
  delay(del);
  digitalWrite(L2[2], HIGH);
  delay(del);
  digitalWrite(L3[2], HIGH);
  delay(del);
  digitalWrite(L3[1], HIGH);
  delay(del);
  digitalWrite(L3[0], HIGH);
  delay(del);
  digitalWrite(L2[0], HIGH);
  delay(del);
}

int delayTimes = 300;
void setup()
{
  RST();
  delay(100);
  while (1) {
    RING(delayTimes);
    closeAll();
    OBO(delayTimes);
    closeAll();

    // 逐渐变快
    delayTimes -= 10;
    if (delayTimes <= 220)
      delayTimes = 300;

  }
}

void loop()
{

}

