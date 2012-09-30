require 'serialport'

describe 'Bertha Sketch' do

  let(:port) { '/dev/cu.usbmodemfa131' }

  let :serial do
    SerialPort.new port, 9600, 8, 1
  end

  before :each do
    serial.read_timeout = 200
    serial.read
  end 

  after :each do
    serial.close
  end

  def send request
    serial.puts request
    serial.gets.chomp
  end

  it 'returns ERROR for an unknown command' do
    send("BAD_COMMAND").should == 'ERROR'
  end

  it 'returns correct version number' do
    send("VERSION").should == '1.0.0'
  end

end
