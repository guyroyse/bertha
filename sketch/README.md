Build the Sketch
================

Setup
-----

An Arduino must be plugged into the development machine in order to run the tests as the
tests run against the hardware.

The Arduino IDE must be installed.  Go to http://arduino.cc to download and install it.

Ino (http://inotool.org/) must be installed.  Follow the instructions on the site.  If
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
