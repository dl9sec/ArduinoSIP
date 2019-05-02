# ArduinoSIP (BETA)
Arduino SIP library with UDP communications. Original class and methods authored by Juergen Liegner (SIP protocoll not fully implemented. Discussed at https://www.mikrocontroller.net/topic/444994).
Can be used do do a notifying SIP call through e.g. a FRITZ!Box.

Tested with NodeMCU 1.0 (AI-Thinker ESP8266MOD ESP-12E).
Because of this, _"architectures"_ in _"library.properties"_ is currently set to _"esp8266"-only_. If you want to use the library on another Arduino architecture, replace the _"esp8266"_ with a _"*"_ and let me know, if it works.

# Prequisites for the examples

ToDo

# Examples

<dl>
  <dt>DualDoorbell</dt>
  <dd>A dual doorbell example adapted from Florian Wernze (see https://wernze-home.net/wordpress/hobbys/arduino-esp8266-tuerklingel/).</dd>
  <dt>ToDo: LaundryNotifier</dt>
  <dd>A laundry notifier example based on the dual doorbell example using the TR-064 SOAP library to aquire the power information from two home automation smart plugs and notify via SIP call, that the washing machine and/or dryer is ready.</dd>
  
