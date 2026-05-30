#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define TRIG_PIN 2
#define ECHO_PIN 3
#define BUZZER_PIN 4
#define LED_PIN 5

#define MAX_DISTANCE 400
#define WARNING_DISTANCE 30
#define DANGER_DISTANCE 10

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 10);
  display.println(F("Ultrasonic"));
  display.setCursor(30, 35);
  display.println(F("Meter"));
  display.display();
  delay(2000);
}

float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return -1;

  float distance = duration * 0.034 / 2;
  return (distance > MAX_DISTANCE) ? -1 : distance;
}

void updateDisplay(float distance) {
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("Distance Meter"));

  display.drawLine(0, 10, 128, 10, SSD1306_WHITE);

  if (distance < 0) {
    display.setTextSize(2);
    display.setCursor(15, 25);
    display.println(F("Out of"));
    display.setCursor(15, 45);
    display.println(F("Range!"));
  } else {
    display.setTextSize(3);
    display.setCursor(10, 20);
    display.print(distance, 1);

    display.setTextSize(2);
    display.setCursor(95, 30);
    display.println(F("cm"));
  }

  display.display();
}

void alertFeedback(float distance) {
  if (distance < 0) {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    return;
  }

  if (distance <= DANGER_DISTANCE) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000, 100);
    delay(150);
    tone(BUZZER_PIN, 1500, 100);
    delay(150);
  } else if (distance <= WARNING_DISTANCE) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 800, 200);
    delay(300);
    digitalWrite(LED_PIN, LOW);
    delay(200);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
  }
}

void loop() {
  float distance = measureDistance();

  Serial.print(F("Distance: "));
  if (distance < 0) {
    Serial.println(F("Out of range"));
  } else {
    Serial.print(distance);
    Serial.println(F(" cm"));
  }

  updateDisplay(distance);
  alertFeedback(distance);

  delay(200);
}
