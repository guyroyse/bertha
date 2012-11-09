require 'serialport'

class Bertha

  def initialize port, speed = 9600
    @serial = SerialPort.new port, speed, 8, 1
    @serial.read_timeout = 200
    @serial.read
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
    @serial.puts 'version'
    @serial.gets.chomp
  end

  def pin number
    Bertha::Pin.new @serial, number
  end

  class Pin

    def initialize serial, pin
      @serial = serial
      @pin = pin
    end

    def mode= mode
      @serial.puts "pinMode #{@pin} #{mode.to_s.upcase}"
      @serial.gets
    end

  end

end

