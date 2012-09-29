require 'bertha'
require 'serialport'

describe Bertha do

  before(:each) do
    @serial_port = mock(SerialPort)
    SerialPort.stub!(:new).and_return(@serial_port)
    @serial_port.stub!(:close)
  end

  it 'connects to the Arduino' do
    SerialPort.should_receive(:new).with('/dev/foo', 9600, 8, 1)
    bertha = Bertha.new('/dev/foo', 9600)
  end

  it 'closes a connection to the Arduino' do
    @serial_port.should_receive(:close)
    bertha = Bertha.new('/dev/foo', 9600)
    bertha.close
  end

  it 'opens and closes a connection to the Arduion in a block' do

    SerialPort.should_receive(:new).with('/dev/foo', 9600, 8, 1).and_return(@serial_port)
    @serial_port.should_receive(:close)

    Bertha.open('/dev/foo', 9600) do
    end

  end

  it 'passes the instance to the block' do
    Bertha.open('/dev/foo', 9600) do |bertha|
      bertha.should_not be_nil
    end
  end

end
