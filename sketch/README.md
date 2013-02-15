Build the Sketch
================

Setup
-----

An Arduino must be plugged into the development machine in order to run the tests as the
tests run against the hardware.  Also, the following pins should be connected via short wires:

- pins 12 & 13 should be connected to each other
- pin A0 should be grounded
- pin A1 should be set to 5V
- pin A2 should be set to 3.3V

The Arduino IDE must be installed.  Go to main [Arduino](http://arduino.cc) page to download and install it.

[Ino](http://inotool.org/) must be installed.  Follow the instructions on the site.  If
you have problems with the install, use the setup.py script to install instead.

      python setup.py install

Of course, you will need ruby to run the tests.  Bundler should take care of the dependencies
for you.  The tests were developed and run on ruby 1.9.2.

Once these tools are in place, you should be good to go.

Useful Commands
---------------

Build the sketch:

      ino build

Clean the build folder:

      ino clean

Push to compiled sketch to the Arduino:

      ino upload

Run the tests:

      bundle exec rake spec 
