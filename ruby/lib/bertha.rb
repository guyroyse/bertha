require 'serialport'

class Bertha

  def initialize port, speed = 9600
    @serial = SerialPort.new port, speed, 8, 1
  end

  def close
    @serial.close
  end

  def Bertha.open port, speed
    bertha = Bertha.new port, speed
    yield bertha
    bertha.close
  end

  def version
    @serial.puts 'VERSION'
    @serial.gets
  end

end
