require 'serialport'

describe 'Bertha Sketch' do

  def read_write request
    @serial.puts request
    @serial.gets.chomp
  end

  def write request
    read_write request
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

  it 'returns an unknown command error when given an unknown command' do
    read_write("bad_command").should == "ERR msg='unknown command'"
  end

  it 'returns version information' do
    read_write("version").should == 'OK version=1.0.0'
  end

  describe 'queryPin' do

    before :each do
      @query_response = read_write("queryPin pin=13")
    end

    it 'reports an OK status' do
      @query_response.should include('OK')
    end

    it 'reports the pin number' do
      @query_response.should include('pin=13')
    end

#   it 'reports a default mode of INPUT' do
#     @query_response.should include('mode=INPUT')
#   end

#   it 'reports a default value of LOW' do
#     @query_response.should include('value=LOW')
#   end

# complains when pin is missing
# complains when pin is out of range
# ignores other arguments
# complains when pin is not a number

  end

  it 'sets pin mode' do
    read_write("setPinMode 13 OUTPUT").should == 'OK: pin 13 set to OUTPUT'
  end

  context 'when pin mode has been set to OUTPUT' do

    before :each do
      write "setPinMode 13 OUTPUT"
      write "setPinMode 12 INPUT"
    end

    it 'queries pin mode of OUTPUT' do
      read_write("queryPinMode 13").should == 'OK: pin 13 set to OUTPUT'
    end

    it 'writes to a pin' do
      read_write("digitalWrite 13 1").should == 'OK: pin 13 set to 1'
    end

    context 'when an ON is written to the pin' do

      before :each do        
        write "digitalWrite 13 1"
      end

      it 'writes an ON' do
        read_write('digitalRead 12').should == 'OK: pin 12 is 1'
      end

      it 'queries value written to pin as ON' do
        read_write("queryDigitalWrite 13").should == 'OK: pin 13 set to 1'
      end

    end

    context 'when an OFF is written to the pin' do

      before :each do
        write "digitalWrite 13 0"
      end

      it 'writes an OFF' do
        read_write('digitalRead 12').should == 'OK: pin 12 is 0'
      end

      it 'queries value written to pin as OFF' do
        read_write("queryDigitalWrite 13").should == 'OK: pin 13 set to 0'
      end

    end

  end

  context 'when pin mode has been set to INPUT' do

    before :each do
      write "setPinMode 12 INPUT"
    end

    it 'queries pin mode of INPUT' do
      read_write("queryPinMode 12").should == 'OK: pin 12 set to INPUT'
    end

    it 'reads an ON value from the pin' do
      write "setPinMode 13 OUTPUT"
      write "digitalWrite 13 1"
      read_write("digitalRead 12").should == 'OK: pin 12 is 1'
    end

    it 'reads an OFF value from the pin' do
      write "setPinMode 13 OUTPUT"
      write "digitalWrite 13 0"
      read_write("digitalRead 12").should == 'OK: pin 12 is 0'
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
