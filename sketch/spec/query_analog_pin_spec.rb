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
  
    it 'reports a value of 0' do
      @response.should include('value=0')
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
  
    it 'reports a value of 0' do
      @response.should include('value=1023')
    end
    
  end
    
end

