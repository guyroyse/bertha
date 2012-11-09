require 'bertha'

describe Bertha do

  let(:port) { '/dev/foo' }
  let(:speed) { 9600 }
  let(:serial_port) { mock SerialPort }

  before :each  do
    SerialPort.stub!(:new).and_return(serial_port)
    serial_port.stub! :read_timeout=
    serial_port.stub! :read
    serial_port.stub! :close
  end

  context 'when instantiating' do

    it 'connects to the Arduino' do
      SerialPort.should_receive :new
      Bertha.new port, speed
    end

    it 'connects with the requested port and speed' do
      SerialPort.should_receive(:new).with(port, speed, 8, 1)
      Bertha.new port, speed
    end

    it 'connects with the default speed when not specified' do
      SerialPort.should_receive(:new).with(port, speed, 8, 1)
      Bertha.new port
    end

  end

  context 'when opening with a block' do

    it 'opens and closes a connection to the Arduino' do

      SerialPort.should_receive :new
      serial_port.should_receive :close

      Bertha.open port, speed do end

    end

    it 'calls the block' do
      block_called = false
      Bertha.open(port, speed) do
        block_called = true
      end
      block_called.should be_true
    end

    it 'passes an instance of Bertha to the block' do
      Bertha.open(port, speed) do |bertha|
        bertha.should_not be_nil
      end
    end

  end

  context 'when closing' do

    it 'closes connection' do
      serial_port.should_receive :close
      bertha = Bertha.new port, speed
      bertha.close
    end

  end

  context 'when connected' do

    subject { Bertha.new port }

    after :each do
      subject.close
    end

    it 'returns the Bertha version' do
      serial_port.should_receive(:puts).with('version')
      serial_port.should_receive(:gets).and_return("v1.0.0\r\n")
      subject.version.should == 'v1.0.0'
    end

    it 'returns a pin for a number' do
      subject.pin(1).should be_an_instance_of(Bertha::Pin)
    end

  end

end
