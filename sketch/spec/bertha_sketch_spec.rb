require 'serialport'

describe 'Bertha Sketch' do

  let(:port) { '/dev/cu.usbmodemfa131' }
  let(:serial) { SerialPort.new port, 9600, 8, 1 }

  before :each do
    serial.read_timeout = 200
    serial.read
  end 

  after :each do
    serial.close
  end

  it 'returns ERROR for an unknown command' do
    read_write("bad_command").should == 'ERR: unknown command'
  end

  it 'returns correct version number' do
    read_write("version").should == 'v1.0.0'
  end

  context 'setting pin mode' do

    it 'sets pin mode to OUTPUT' do
      read_write("pinMode 13 OUTPUT").should == 'OK: pin 13 set to OUTPUT'
    end

    it 'sets pin mode to INPUT' do
      read_write("pinMode 13 INPUT").should == 'OK: pin 13 set to INPUT'
    end

    it 'sets pin mode to PULLUP' do
      read_write("pinMode 13 PULLUP").should == 'OK: pin 13 set to PULLUP'
    end

  end

  context 'writing to a pin' do

    before :each do
      read_write("pinMode 13 OUTPUT").should == 'OK: pin 13 set to OUTPUT'
    end

    it 'turns a PIN on' do
      read_write("digitalWrite 13 1").should == 'OK: pin 13 set to 1'
    end

    it 'turns a PIN off' do
      read_write("digitalWrite 13 0").should == 'OK: pin 13 set to 0'
    end

  end

end
