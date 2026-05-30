// ESP32-C3 超声波测距 + 单 LED 提示
// 团队：吴天鹏、符永儒、司淼清、吴辉

#define TRIG_PIN  4
#define ECHO_PIN  5
#define LED_PIN   6

#define THRESHOLD 30  // 距离阈值（cm）

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("=== 智能超声波防撞提示器 ===");
  Serial.println("Ready");
}

// 单次测距
float singleMeasure() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration <= 0) return 400;  // 超时返回最大值
  return duration * 0.034 / 2;
}

// 中位数滤波：连续读5次取中间值
float getStableDistance() {
  float readings[5];
  for (int i = 0; i < 5; i++) {
    readings[i] = singleMeasure();
    delay(30);
  }

  // 冒泡排序
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4 - i; j++) {
      if (readings[j] > readings[j + 1]) {
        float temp = readings[j];
        readings[j] = readings[j + 1];
        readings[j + 1] = temp;
      }
    }
  }

  return readings[2];  // 返回中位数
}

void loop() {
  float distance = getStableDistance();

  // 过滤异常值
  if (distance <= 0 || distance > 400) {
    Serial.println("Out of range");
    digitalWrite(LED_PIN, LOW);
    delay(200);
    return;
  }

  // 串口打印距离
  Serial.print("Distance: ");
  Serial.print(distance, 1);
  Serial.print(" cm  ");

  // 简易柱状图
  int bars = (int)distance / 2;
  for (int i = 0; i < bars && i < 40; i++) {
    Serial.print("█");
  }
  Serial.println();

  // LED 控制
  if (distance < THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(200);
}
