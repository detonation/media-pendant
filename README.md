# media-pendant
An exercise in overkill from onhand parts.

Square D NOM-117 Start/Stop pendant based media controller.

Uses the great Onebutton (https://github.com/mathertel/OneButton) and HID (https://github.com/NicoHood/HID) libraries.

Hardware is just a half-dead Arduino Micro controller, usb cable, and the pendant.

Single click behavior is: START - Play/Pause, and STOP is.. stop (shocking, I know).
Double click behavior is: START - Next Track, STOP - Previous Track
Long press behavior is: START - Volume Up, STOP is Volume Down.

The timings have been adjusted because the buttons are long travel and VERY heavy spring pressure.

Overall, I'm very pleased with how it came out. 
The only addition / modification is I'm waiting for a PG7 1/2" NPT gland for strain relief on the cable.
Otherwise there will probably be no updates, as this is a bare simple project with almost no coding or programming whatsoever. 
