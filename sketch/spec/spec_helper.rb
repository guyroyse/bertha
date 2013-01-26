require 'serialport'

$port = '/dev/cu.usbmodemfa131'

$serial = SerialPort.new $port, 9600, 8, 1
$serial.read_timeout = 5000
$serial.read

def read_write request
  $serial.puts request
  $serial.gets.chomp
end

def write request
  read_write request
end

at_exit do
  $serial.close
end