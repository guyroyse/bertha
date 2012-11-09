describe Bertha::Pin do

  let(:serial_port) { mock SerialPort }

  subject { Bertha::Pin.new serial_port, 1 }

  it 'set a pin for output' do
    serial_port.should_receive(:puts).with('pinMode 1 OUTPUT')
    serial_port.should_receive(:gets).and_return("OK: pin 1 set to output\r\n")
    subject.mode = :output
  end

  it 'set a pin for input' do
    serial_port.should_receive(:puts).with('pinMode 1 INPUT')
    serial_port.should_receive(:gets).and_return("OK: pin 1 set to input\r\n")
    subject.mode = :input
  end

  it 'set a pin for input pullup' do
    serial_port.should_receive(:puts).with('pinMode 1 PULLUP')
    serial_port.should_receive(:gets).and_return("OK: pin 1 set to pullup\r\n")
    subject.mode = :pullup
  end

end
