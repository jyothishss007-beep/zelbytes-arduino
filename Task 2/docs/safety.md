1. Solenoid valve is controlled through a relay, never directly from Arduino.
2. Relay input is connected to Arduino pin D8.
3. Valve defaults to OFF during startup using `setValve(false)`.
4. Relay is configured as active-low.
5. Emergency stop command: `e` turns valve OFF immediately.
6. Test command: `v` opens valve briefly (~200 ms) then closes.
7. Manual shutoff valve must be installed upstream.
8. Keep a drip tray under the plumbing setup.
9. Never leave the valve energized unattended.
10. Verify relay operation before connecting the solenoid valve.
