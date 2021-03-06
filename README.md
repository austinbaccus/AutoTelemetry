# AutoTelemetry
AutoTelemetry allows you to record and remotely view your car's telemetry while you drive. You can save your telemetry data to a CSV file, view your telemetry data in the car on your laptop, or view your telemetry data online in real time on the [AutoTelemetry website](https://autotelemetry.azurewebsites.net/).

## Hardware
1. [DB9-R2S32 cable](https://www.amazon.com/dp/B01ETRINYO/ref=cm_sw_em_r_mt_dp_jWzoFb6F0DSE8)
2. [Arduino Uno + serial cable](https://www.amazon.com/dp/B01EWOE0UU/ref=cm_sw_em_r_mt_dp_sZzoFbJMW9MM0)
3. [Arduino CAN-BUS shield](https://www.amazon.com/dp/B00NQVH666/ref=cm_sw_em_r_mt_dp_zYzoFb48E4WSF)
4. Laptop (unless you want to hookup your desktop PC inside the car)

## Setup
1. Download the code. Upload the [/arduino/speed](https://github.com/austinbaccus/autotelemetry/blob/master/arduino/Speed.ino) program to your Arduino Uno. This is most easily done using the [Arduino IDE](https://www.arduino.cc/en/Main/Software).
2. Connect the Arduino Uno and the Arduino CAN-BUS shield together.
3. Plug in the DB9-RS32 cable into your car's OBD-II port. 
4. Plug in the other end of the DB9-RS232 cable into your Arduino CAN-BUS shield.
5. Connect the Arduino to your Laptop with the serial cable.
6. Use the Arduino IDE to see which port the serial cable is connected to ("COM7" is the default).
7. Turn the car on.
8. Start the laptop program.
9. Login to the [AutoTelemetry website](https://autotelemetry.azurewebsites.net/) if you want to watch the data remotely.
10. Start testing!
