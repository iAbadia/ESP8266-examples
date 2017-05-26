# WebServer + mDNS + DNS-SD

Simple WebServer example, including mDNS Responder and DNS-SD Advertiser.

## About

ESP8266WebServer library can be found on [esp8266/Arduino](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WebServer) GitHub.

Learn more about [mDNS](https://en.wikipedia.org/wiki/Multicast_DNS) and [DNS-SD](http://www.dns-sd.org/).

### Note

DNS-SD can be very useful for local network auto configuration. If you're using it with Android, go check [Network Service Discovery](https://developer.android.com/training/connect-devices-wirelessly/nsd.html). Also, there's a working example on this other [GitHub repo](https://github.com/iAbadia/Laboratorio-Empotrados-2016-17/blob/master/Android/RFIDCloner/app/src/main/java/edu/labemp/inaki/rfidcloner/Controller/NsdHelper.java).