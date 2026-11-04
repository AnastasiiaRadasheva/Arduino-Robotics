# Smart Greenhouse

A mini automated greenhouse. A servo motor opens the window when it gets too warm and closes it when it is cold.
A photoresistor turns on the light when it gets dark.

**Components:** Arduino Uno, TMP36 temperature sensor, photoresistor, SG90 servo, LED, resistors.
**Logic:** ≤ 20 °C → window closed, ≥ 30 °C → window open (smooth servo movement); dark → LED on.
**Concepts:** `Servo.h`, analog sensors, smooth servo control.

## Demo

[![Video](https://img.youtube.com/vi/n6NPtWs6Cvc/hqdefault.jpg)](https://www.youtube.com/watch?v=n6NPtWs6Cvc)

[Watch on YouTube](https://www.youtube.com/watch?v=n6NPtWs6Cvc) · [Open circuit in Tinkercad](https://www.tinkercad.com/things/3JhxidDXPrc-parnik)

## Circuit

![Circuit](https://anastasiiaradashevatar.wordpress.com/wp-content/uploads/2025/05/pilt-2.png)
