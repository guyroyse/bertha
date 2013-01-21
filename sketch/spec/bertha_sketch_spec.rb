require 'serialport'

describe 'Bertha Sketch' do

  def read_write request
    @serial.puts request
    @serial.gets.chomp
  end

  let(:port) { '/dev/cu.usbmodemfa131' }

  before :all do
    @serial = SerialPort.new port, 9600, 8, 1
    @serial.read_timeout = 2000
    @serial.read
  end

  after :all do
    @serial.close
  end

  it 'returns ERROR for an unknown command' do
    read_write("bad_command").should == 'ERR: unknown command'
  end

  it 'returns version information' do
    read_write("version").should == 'v1.0.0'
  end

  it 'sets pin mode' do
    read_write("setPinMode 13 OUTPUT").should == 'OK: pin 13 set to OUTPUT'
  end

  context 'when pin mode has been set to OUTPUT' do

    before :each do
      read_write("setPinMode 13 OUTPUT").should == 'OK: pin 13 set to OUTPUT'
    end

    it 'queries pin mode of OUTPUT' do
      read_write("queryPinMode 13").should == 'OK: pin 13 set to OUTPUT'
    end

    it 'writes to a pin' do
      read_write("digitalWrite 13 1").should == 'OK: pin 13 set to 1'
    end

    context 'when a pin is ON' do

      before :each do
        read_write("digitalWrite 13 1").should == 'OK: pin 13 set to 1'
      end

      it 'queries value written to pin' do
        read_write("queryDigitalWrite 13").should == 'OK: pin 13 set to 1'
      end

    end

    context 'when a pin is OFF' do

      before :each do
        read_write("digitalWrite 13 0").should == 'OK: pin 13 set to 0'
      end

      it 'queries value written to pin' do
        read_write("queryDigitalWrite 13").should == 'OK: pin 13 set to 0'
      end

    end

  end

  context 'when pin mode has been set to INPUT' do

    before :each do
      read_write("setPinMode 13 INPUT").should == 'OK: pin 13 set to INPUT'
    end

    it 'queries pin mode of INPUT' do
      read_write("queryPinMode 13").should == 'OK: pin 13 set to INPUT'
    end

  end

  context 'when pin mode has been set to PULLUP' do

    before :each do
      read_write("setPinMode 13 PULLUP").should == 'OK: pin 13 set to PULLUP'
    end

    it 'queries pin mode of PULLUP' do
      read_write("queryPinMode 13").should == 'OK: pin 13 set to PULLUP'
    end

  end

end
