#Bertha

The [Arduino](http://arduino.cc) microcontroller was named after Arduin of Ivrea.  Arduin was an Italian king who
lived over a millennium ago.  His wife was Bertha of Burgundy and this library is named in her honor.

_And what is this library?_ you might ask.  Well, this library exposes the inner-workings of the Arduino to high-order
programming languages.  Sure, C is great and we can program the Arduino with it.  But Ruby is more powerful, Java
more ubiquitous, and C# more... uh... Microsofty.  But most importantly, the hardware that these languages run on
has more ready and sophisticated access to things like networking, video, and sound.  Things that the Arduino can
do if you buy more hardware but something like say... a Raspberry Pi can do just as easily.

##How It Works

A standard sketch is loaded on the Arduino that responds to commands sent over the serial port from a computer to
the Arduino.  These command will do things like set a pin to output, read the value of a pin, read an analog value,
set the value of pin, etc.  Each command will respond with an appropriate status for the command.

For example, using a simple terminal an exchange might look something like this:

    version
    v1.0.0
    setPinMode 1 OUTPUT
    OK: pin 1 set to OUTPUT
    digitalWrite 1 1
    OK: pin 1 set to 1
    setPinMode 2 INPUT
    OK: pin 2 set to INPUT
    digitalRead 2
    OK: pin 2 is 1

With this protocol in place the second piece of Bertha shines.  Out protocol is wrapped in an API for several
of the more common and popular languages.  Ruby is planned first and the API will look something like this.

    Bertha.open <port> do |bertha|
      bertha.version     # returns 1.0.0
      bertha.pin_out 1
      bertha.pin_on 1
      bertha.pin_in 2
      bertha.pin 2       # returns true
    end

Current the standard sketch is being developed and the protocol is totally subject to change.  Once completed,
however, gems, jars, and packages galore shall be build.  Maybe you'll build some of them yourself?
