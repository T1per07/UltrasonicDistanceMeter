# 接线说明

## ESP32-C3 与超声波传感器 HC-SR04 连接

```
ESP32-C3          HC-SR04
─────────────────────────
GPIO 2    ───►    TRIG
GPIO 3    ◄───    ECHO
3.3V      ───►    VCC
GND       ───►    GND
```

## ESP32-C3 与 OLED 显示屏 SSD1306 连接

```
ESP32-C3          SSD1306
─────────────────────────
GPIO 6 (SDA) ───► SDA
GPIO 7 (SCL) ───► SCL
3.3V         ───► VCC
GND          ───► GND
```

## ESP32-C3 与蜂鸣器、LED 连接

```
ESP32-C3          组件
─────────────────────────
GPIO 4    ───►    蜂鸣器正极
GND       ───►    蜂鸣器负极

GPIO 5    ───►    220Ω电阻 ───► LED正极
GND       ───►    LED负极
```

## 注意事项

1. HC-SR04 工作电压为 5V，但 ESP32-C3 的 GPIO 为 3.3V 逻辑。实际测试中 HC-SR04 的 ECHO 输出在 3.3V 下仍可被 ESP32-C3 正确读取。
2. 如需更稳定，可在 ECHO 引脚加分压电路（1kΩ + 2kΩ）。
3. OLED 显示屏使用 I2C 通信，默认地址为 0x3C。
