#Task 6: PWM Motor and Interrupt E-Stop

Objective

The objective of this project is to control a DC motor using PWM (Pulse Width Modulation) through an L298N motor driver and implement an interrupt-driven Emergency Stop (E-Stop) system. A relay-controlled valve is also integrated to demonstrate safe shutdown during emergency conditions.

Components Used

- Arduino Uno
- L298N Motor Driver Module
- DC Motor
- Relay Module
- Push Button (Emergency Stop)
- LED
- Breadboard
- Jumper Wires
- External Power Supply

Features

- PWM-based motor speed control
- L298N motor driver interface
- Interrupt-driven emergency stop
- Relay-controlled valve operation
- LED status indication
- Serial command interface
- Safe system reset mechanism

Pin Configuration

Arduino Pin| Function
D9| PWM Output (ENA)
D10| Motor Direction IN1
D11| Motor Direction IN2
D6| Relay Control
D13| Status LED
D2| Emergency Stop Interrupt

Serial Commands

Command| Action
1 - 9| Set Motor Speed
0| Stop Motor
o| Open Valve
f| Close Valve
r| Reset Emergency Stop

Working

The Arduino generates PWM signals on pin D9 to control motor speed through the L298N motor driver. Motor direction is controlled using pins D10 and D11.

The relay module connected to pin D6 controls the valve. The user can open or close the valve using serial commands.

An emergency stop push button is connected to interrupt pin D2. When pressed, the interrupt immediately stops the motor, turns off the relay, closes the valve, and places the system in a safe state until reset.

Emergency Stop Operation

1. Button press triggers interrupt.
2. ISR sets emergency flag.
3. Motor PWM becomes zero.
4. Relay turns OFF.
5. Valve closes immediately.
6. LED turns OFF.
7. User must send 'r' command to reset.

ISR and IRAM_ATTR Note

This project uses an interrupt service routine (ISR) for the Emergency Stop button.

void emergencyISR()
 {
    emergencyStop = true;
}

For Arduino Uno (AVR), the ISR does not require the IRAM_ATTR attribute.

IRAM_ATTR is mainly used on ESP32 platforms to place interrupt functions in instruction RAM for faster execution.

Since this project is implemented on Arduino Uno, a standard ISR function is sufficient.

Outcome

Successfully implemented PWM-based DC motor speed control with interrupt-driven emergency stop and relay-controlled valve operation using Arduino Uno and the L298N motor driver module.
