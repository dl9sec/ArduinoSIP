# ArduinoSIP
Arduino SIP library with UDP communications. Original class and methods authored by Juergen Liegner (SIP protocoll not fully implemented. Discussed at https://www.mikrocontroller.net/topic/444994).
Can be used do do a notifying SIP call through e.g. a FRITZ!Box.

Tested with NodeMCU 1.0 (AI-Thinker ESP8266MOD ESP-12E).
Because of this, _"architectures"_ in _"library.properties"_ is currently set to _"esp8266"-only_. If you want to use the library on another Arduino architecture, replace the _"esp8266"_ with a _"*"_ and let me know, if it works.

# Prequisites for the examples

* **General**
  * You need a FRITZ!Box or equivalent which supports SIP and TR-064.
  * Grant access for applications to the FRITZ!Box:<br>
   `Heimnetz -> Netzwerk -> Netzwerkeinstellungen -> Heimnetzfreigaben: Zufriff für Anwendungen zulassen / Statusinformationen über UPnP übertragen`
  
* **For SIP call functionality ("DualDoorbell" and "LaundryNotifier" example)**
  * The ESP8266 acts as a VOIP telephone for the FRITZ!Box, so a new phone has to be set up:<br>
 `Telefonie -> Telefoniegeräte -> Neues Gerät einrichten: Telefon (mit und ohne Anrufbeantworter) -> LAN/WLAN (IP-Telefon) -> Benutzername / Kennwort ...`
  * Follow the setup assistant. Benutzername (Username) will be used for "SipUSER" and Kennwort (Password) will be used for "SipPW" in the code. 

* **For TR-064 SOAP communications ("LaundryNotifier" example)**
  * Install Aypac's "Arduino-TR-064-SOAP-Library" from https://github.com/Aypac/Arduino-TR-064-SOAP-Library to your Arduino library path.
  * Set up a net FRITZ!Box user for interaction with the TR-064 SOAP interface:<br>
 `System -> FRITZ!Box-Benutzer -> Benutzer: Benutzer hinzufügen -> Benutzername / Kennwort, Berechtigungen: Fritz!Box Einstellungen / Sprachnachrichten, Faxnachrichten, FRITZ!App Fon und Anrufliste / Smart Home`
  * Follow the setup assistant. Benutzername (Username) will be used for "FbApiUSER" and Kennwort (Password) will be used for "FbApiPW" in the code. Check the mentioned boxes for that user.

*Maybe someone can give me the correct translations from an english localized FRITZ!Box browser interface.*

# Examples

<dl>
  <dt>DualDoorbell</dt>
  <dd>A dual doorbell example adapted from Florian Wernze (see https://wernze-home.net/wordpress/hobbys/arduino-esp8266-tuerklingel/).</dd>
  <dt>ToDo: LaundryNotifier</dt>
  <dd>A laundry notifier example using the TR-064 SOAP library (https://github.com/Aypac/Arduino-TR-064-SOAP-Library) to aquire the power information from two home automation smart plugs and notify via SIP call, that the washing machine and/or dryer is ready.</dd>
  
