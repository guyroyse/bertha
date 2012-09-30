#Bertha

Bertha of Burgundy was the wife of Arduin of Ivrea who was an Italian king over a millennium ago. The Arduino
was named after Arduin.  So, what better name for a framework that exposes the inside of the Arduino to high-order
programming languages.  Sure, C is great and we can program the Arduino with it.  But Ruby is more powerful, Java
more ubiquitous, and C# more... uh... Microsofty.  But most importantly, the hardware that these languages run on
has more ready and sophisticated access to things like networking, video, and sound.  Things that the Arduino can
do if you buy more hardware but something like say... a Raspberry Pi can do just as easily.

##How It Works

A standard sketch is loaded on the Arduino that responds to commands sent over the serial port from a computer to
the Arduino.  These command will do things like set a pin to output, read the value of a pin, read an analog value,
set the value of pin, etc.  Each command will respond with an appropriate status for the command.

For example, using a simple terminal an exchange might look something like this:

    VERSION
    *1.0.0*
    PIN 1 OUTPUT
    *OK*
    PIN 1 ON
    *OK*
    PIN 2 INPUT
    *OK*
    PIN 2
    *ON"

With this protocol in place the second piece of Bertha shines.  This protocol is then wrapped in an API for several
of the common and popular languages.  Ruby is planned first and the API will look something like this.

    Bertha.open <port> do |bertha|
      bertha.version     # returns 1.0.0
      bertha.pin_out 1
      bertha.pin_on 1
      bertha.pin_in 2
      bertha.pin 2       # returns true
    end

Right now only VERSION is implemented.

##How To Use It

There's not much that's been developed yet to actually use.  The sketch needs to be compiled and loaded on the
Arduino.  The various APIs that talk over the serial port to the Arduino will have specialize install instructions.

Right now, I am working on the Ruby library.  It will be a gem, of course.  I also have plans to add Java ad a JAR,
JavaScript/CoffeeScript for Node.js as npm packages after that.  Then, whatever strikes my fancy!  Hopefully, some
intrepid helper (that's you!) will come along and support other platforms that I know less about like Python or Perl.

Come back later when there's more too see or, better yet, get involved and send me some pull requests.
