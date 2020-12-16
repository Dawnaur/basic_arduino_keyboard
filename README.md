# Basic arduino keyboard

This is a very simple sketch about the rudiments of keyboard firmware.

## Specifications

As it is a really basic system, it doesn't implement USB connection nor driver handling.
This firmware is using 9600 bauds UART link.
Though it is configurable, it only send keypress over serial.
This features are not working yet, but could be added with quite reduced workload:
- Basic lightning effects (needs a LED matrix driver).
- Basic macros

## Requierements

- Arduino card, such as an Arduino Uno
- Arduino IDE
- Home made keyboard with mecanical switches. Diodes are not required as long as you don't need N-key rollover

## License

Project under MIT License.
https://opensource.org/licenses/MIT

