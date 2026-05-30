# 智能超声波防撞提示器

《从代码到实物：造你所想》期末 Hackathon 项目

## 项目简介

基于 ESP32-C3 的超声波测距仪，当障碍物距离小于 30cm 时 LED 自动点亮，提醒用户注意避撞。

**应用场景：** 桌面防撞、盲人辅助导航、倒车提示、智能垃圾桶感应开盖

## 团队成员

| 姓名 | 负责内容 |
|------|----------|
| 吴天鹏 | 软件/代码、系统集成、文档编写 |
| 符永儒 | 硬件接线、电路调试、焊接 |
| 司淼清 | 3D建模、外壳设计、打印 |
| 吴辉 | 测试验证、演示准备、物料协调 |

## 功能特性

- 超声波测距（2cm - 400cm）
- 中位数滤波，数据稳定
- LED 自动报警（< 30cm 亮，≥ 30cm 灭）
- 串口实时输出距离数据
- 3D 打印外壳，美观便携

## 硬件清单

| 组件 | 型号 | 数量 | 来源 |
|------|------|------|------|
| 主控板 | ESP32-C3 | 1 | 教学物资 |
| 超声波传感器 | HC-SR04 | 1 | 教学物资 |
| LED灯 | 5mm 红色 | 1 | 教学物资 |
| 电阻 | 220Ω | 1 | 教学物资 |
| 导线 | 母对公杜邦线 | 6 | 教学物资 |
| 数据线 | USB-C / Micro-USB | 1 | 教学物资 |

## 接线图

```
ESP32-C3          组件
─────────────────────────
GPIO 4    ───►    HC-SR04 Trig
GPIO 5    ◄───    HC-SR04 Echo
GPIO 6    ───►    220Ω电阻 ───► LED正极
5V / VIN  ───►    HC-SR04 VCC
GND       ───►    HC-SR04 GND + LED负极
```

## 开发环境

- Arduino IDE 2.x
- ESP32-C3 开发板支持包
- 开发板选择：ESP32C3 Dev Module

## 快速开始

1. 安装 Arduino IDE 2.x
2. 文件 → 首选项 → 附加开发板管理器网址：
   ```
   https://dl.espressif.com/dl/package_esp32_index.json
   ```
3. 工具 → 开发板 → 开发板管理器 → 搜索 "esp32" → 安装
4. 工具 → 开发板 → ESP32 Arduino → ESP32C3 Dev Module
5. 打开 `src/ultrasonic_distance.ino`
6. 按住 BOOT 键 → 点击上传 → 松开 BOOT 键
7. 打开串口监视器，波特率设为 115200

## 上传代码注意事项

ESP32-C3 进入下载模式的方法：
1. 按住 BOOT 键
2. 点击 Arduino IDE 的上传按钮
3. 等待出现 "Connecting..." 或进度条开始
4. 松开 BOOT 键

## GitHub 仓库

https://github.com/T1per07/UltrasonicDistanceMeter

## 许可证

MIT License
