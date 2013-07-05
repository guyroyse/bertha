describe 'queryAnalogPin' do

  context 'when grounded' do

    before :each do
      @response = read_write("queryAnalogPin pin=0")
    end
    
    it 'reports an OK status' do
      @response.should include('OK')
    end
  
    it 'reports the pin number' do
      @response.should include('pin=0')
    end
  
    it 'reports a value of around 0' do
      @response.should match /value=[0-2]/
    end
    
  end
    
  context 'when set to 5 volts' do

    before :each do
      @response = read_write("queryAnalogPin pin=1")
    end
    
    it 'reports an OK status' do
      @response.should include('OK')
    end
  
    it 'reports the pin number' do
      @response.should include('pin=1')
    end
  
    it 'reports a value of around 1023' do
      @response.should match /value=102[1-3]/
    end
    
  end
    
  context 'when set to 3.3 volts' do

    before :each do
      @response = read_write("queryAnalogPin pin=2")
    end
    
    it 'reports an OK status' do
      @response.should include('OK')
    end
  
    it 'reports the pin number' do
      @response.should include('pin=2')
    end
  
    it 'reports a value of around 682' do
      @response.should match /value=68[0-9]/
    end
    
  end
    
end