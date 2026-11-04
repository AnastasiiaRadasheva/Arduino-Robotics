<div align="center">

# 🤖 Arduino Robotics

**8 hardware projects: from a traffic light to a smart parking lot**

<img src="https://img.shields.io/badge/Arduino-0d1b2a?style=for-the-badge&logo=arduino&logoColor=7aa2f7" /> <img src="https://img.shields.io/badge/C%2B%2B-0d1b2a?style=for-the-badge&logo=cplusplus&logoColor=7aa2f7" /> <img src="https://img.shields.io/badge/Tinkercad-0d1b2a?style=for-the-badge&logo=autodesk&logoColor=7aa2f7" /> <img src="https://img.shields.io/badge/YouTube_demos-0d1b2a?style=for-the-badge&logo=youtube&logoColor=7aa2f7" />

</div>

---

Arduino projects from my robotics course at Tallinna Tööstushariduskeskus.
Each project was first built and tested in Tinkercad and then assembled on a real Arduino Uno.
Every folder has the sketch (`.ino`), a short description, the circuit and a demo video.

| # | Project | What it does | Video |
|---|---|---|---|
| 1 | [Traffic Light](01_TrafficLight) | Car and pedestrian lights working together | [▶️](https://www.youtube.com/watch?v=2yGatcYg2lg) |
| 2 | [LED Light Chain](02_LightChain) | 10 LEDs, 5 modes selected with a potentiometer | [▶️](https://www.youtube.com/watch?v=N4ACMPCPnNw) |
| 3 | [Night Lamp](03_NightLamp) | RGB lamp that reacts to room light | [▶️](https://www.youtube.com/watch?v=kXCbUpjKoV8) |
| 4 | [Smart Greenhouse](04_Greenhouse) | Servo opens the window based on temperature | [▶️](https://www.youtube.com/watch?v=n6NPtWs6Cvc) |
| 5 | [Weather Station](05_WeatherStation) | LCD with temperature, weather messages and icons | [▶️](https://www.youtube.com/watch?v=C32qWZ_rbdQ) |
| 6 | [Alarm System](06_AlarmSystem) | Temperature and light monitoring with a buzzer alarm | [▶️](https://www.youtube.com/watch?v=VYIe20I3tPg) |
| 7 | [Smart Trash Bin](07_SmartTrashBin) | Touchless lid opened by an ultrasonic sensor | [▶️](https://www.youtube.com/watch?v=4bFT4Nq2XqU) |
| 8 | [Parking System](08_ParkingSystem) | Barrier and free-spot counter with 2 ultrasonic sensors | [▶️](https://www.youtube.com/watch?v=YxrtW7DX4O4) |

## Skills

- C++ for Arduino: digital and analog I/O, PWM, timing with `millis()`
- Sensors: temperature (TMP36), light (LDR), ultrasonic distance (HC-SR04)
- Actuators and output: servo motors, LEDs and RGB LEDs, buzzer, 16×2 LCD with custom characters
- Libraries: `Servo.h`, `LiquidCrystal.h`
- Circuit design and simulation in Tinkercad

## How to run

1. Open a project's `.ino` file in the [Arduino IDE](https://www.arduino.cc/en/software).
2. Build the circuit from the project's README (or open the Tinkercad link).
3. Select **Arduino Uno** and upload.

Full reports (in Estonian): [portfolio](https://anastasiiaradasheva24.thkit.ee/wp/eng/robotika/)
