# 超声波测距仪 - ESP32-C3

《从代码到实物：造你所想》期末 Hackathon 项目

## 项目简介

基于 ESP32-C3 的超声波测距仪，能够实时测量距离并通过 OLED 显示屏显示结果，同时支持声光报警提示。

## 团队成员

| 姓名 | 负责内容 |
|------|----------|
| 吴天鹏 | 项目负责人，硬件搭建，嵌入式编程 |
| 符永儒 | 电路设计，焊接调试 |
| 司淼清 | 外壳设计，3D建模 |
| 吴辉 | 文档编写，测试验证 |

## 功能特性

- 超声波测距（2cm - 400cm）
- OLED 实时距离显示
- 蜂鸣器分级报警（危险/警告）
- LED 状态指示

## 硬件清单

| 组件 | 型号 | 数量 |
|------|------|------|
| 主控板 | ESP32-C3 | 1 |
| 超声波传感器 | HC-SR04 | 1 |
| OLED显示屏 | SSD1306 0.96寸 | 1 |
| 蜂鸣器 | 有源蜂鸣器 | 1 |
| LED灯 | 红色LED | 1 |
| 电阻 | 220Ω | 1 |
| 导线 | 杜邦线若干 | - |

## 接线图

```
ESP32-C3 Pin    ->    组件
GPIO 2          ->    HC-SR04 TRIG
GPIO 3          ->    HC-SR04 ECHO
GPIO 4          ->    蜂鸣器正极
GPIO 5          ->    LED正极（串联220Ω电阻）
3.3V            ->    VCC（OLED、HC-SR04）
GND             ->    GND（所有组件）
SDA (GPIO 6)    ->    OLED SDA
SCL (GPIO 7)    ->    OLED SCL
```

## 报警逻辑

| 距离范围 | 状态 | 蜂鸣器 | LED |
|----------|------|--------|-----|
| > 30cm | 安全 | 静音 | 灭 |
| 10-30cm | 警告 | 间歇响 | 亮 |
| < 10cm | 危险 | 急促响 | 亮 |

## 开发环境

- Arduino IDE 2.x
- ESP32-C3 开发板支持包
- Adafruit SSD1306 库
- Adafruit GFX Library

## 快速开始

1. 安装 Arduino IDE
2. 添加 ESP32 开发板 URL：`https://dl.espressif.com/dl/package_esp32_index.json`
3. 安装 ESP32-C3 开发板支持
4. 安装依赖库：Adafruit SSD1306、Adafruit GFX Library
5. 打开 `src/ultrasonic_distance.ino`
6. 选择开发板：ESP32C3 Dev Module
7. 编译上传

## 许可证

MIT License
