Common Port Issues

* Incorrect COM port selected in Arduino IDE.
* USB cable connected loosely or faulty.
* Required USB drivers not installed.
* Another application using the same serial port.

 Baud Rate Issues

* Baud rate in Serial Monitor must match the value in `Serial.begin()`.
* Incorrect baud rate results in unreadable or garbled characters.
* For this project, the baud rate is set to **9600 bps**.

 Brownout Symptoms

* Arduino resets unexpectedly.
* Serial Monitor repeatedly shows startup messages.
* LED flickers or turns off randomly.
* USB connection disconnects and reconnects.
* Usually caused by insufficient power supply or excessive current draw.

 Troubleshooting Steps

1. Verify the correct COM port is selected.
2. Check USB cable and connections.
3. Ensure Serial Monitor baud rate is 9600.
4. Confirm adequate power supply.
5. Re-upload the sketch if communication fails.
