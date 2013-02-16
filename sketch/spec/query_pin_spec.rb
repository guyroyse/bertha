describe 'queryPin' do

  before :each do
    write 'reset'
  end
  
  context 'when unconfigured' do

    before :each do
      @response = read_write("queryPin pin=13")
    end
    
    it 'reports an OK status' do
      @response.should include('OK')
    end
  
    it 'reports the pin number' do
      @response.should include('pin=13')
    end
  
    it 'reports a default mode of INPUT' do
      @response.should include('mode=INPUT')
    end
    
  end
  
  context 'when setting mode to OUTPUT' do
    
    before :each do
      write "setPin pin=13 mode=OUTPUT"
      @response = read_write("queryPin pin=13")
    end
  
    it 'reports an OK status' do
      @response.should include('OK')
    end
  
    it 'reports the pin number' do
      @response.should include('pin=13')
    end
  
    it 'reports a mode of OUTPUT' do
      @response.should include('mode=OUTPUT')
    end
    
    it 'reports a value of 0' do
      @response.should include('value=0')
    end
    
    context 'when setting value to HIGH' do
      
      before :each do
        write "setPin pin=13 value=HIGH"
        @response = read_write("queryPin pin=13")
      end
    
      it 'reports an OK status' do
        @response.should include('OK')
      end
    
      it 'reports the pin number' do
        @response.should include('pin=13')
      end
    
      it 'reports a mode of OUTPUT' do
        @response.should include('mode=OUTPUT')
      end
      
      it 'reports a value of HIGH' do
        @response.should include('value=1')
      end
      
    end
    
    context 'when setting value to LOW' do
      
      before :each do
        write "setPin pin=13 value=LOW"
        @response = read_write("queryPin pin=13")
      end
    
      it 'reports an OK status' do
        @response.should include('OK')
      end
    
      it 'reports the pin number' do
        @response.should include('pin=13')
      end
    
      it 'reports a mode of OUTPUT' do
        @response.should include('mode=OUTPUT')
      end
      
      it 'reports a value of LOW' do
        @response.should include('value=0')
      end
      
    end
    
  end
  
  context 'when setting mode to OUTPUT and value to HIGH' do
    
    before :each do
      write "setPin pin=13 mode=OUTPUT value=HIGH"
      @response = read_write("queryPin pin=13")
    end
  
    it 'reports an OK status' do
      @response.should include('OK')
    end
  
    it 'reports the pin number' do
      @response.should include('pin=13')
    end
  
    it 'reports a mode of OUTPUT' do
      @response.should include('mode=OUTPUT')
    end
    
    it 'reports a value of HIGH' do
      @response.should include('value=1')
    end
    
  end

  context 'when setting mode to OUTPUT and value to LOW' do
    
    before :each do
      write "setPin pin=13 mode=OUTPUT value=LOW"
      @response = read_write("queryPin pin=13")
    end
  
    it 'reports an OK status' do
      @response.should include('OK')
    end
  
    it 'reports the pin number' do
      @response.should include('pin=13')
    end
  
    it 'reports a mode of OUTPUT' do
      @response.should include('mode=OUTPUT')
    end
    
    it 'reports a value of LOW' do
      @response.should include('value=0')
    end
    
  end
    
  context 'when setting mode to INPUT' do
    
    before :each do
      write "setPin pin=13 mode=INPUT"
      @response = read_write("queryPin pin=13")
    end
    
    it 'reports an OK status' do
      @response.should include('OK')
    end
  
    it 'reports the pin number' do
      @response.should include('pin=13')
    end
  
    it 'reports a mode of INPUT' do
      @response.should include('mode=INPUT')
    end
    
    context 'when accepting a HIGH input' do
      
      before :each do
        write "setPin pin=12 mode=OUTPUT value=1"
        @response = read_write("queryPin pin=13")
      end
      
      it 'reports an OK status' do
        @response.should include('OK')
      end
    
      it 'reports the pin number' do
        @response.should include('pin=13')
      end
    
      it 'reports a mode of INPUT' do
        @response.should include('mode=INPUT')
      end
      
      it 'reports a value of HIGH' do
        @response.should include('value=1')
      end
      
    end
    
    context 'when accepting a LOW input' do
      
      before :each do
        write "setPin pin=12 mode=OUTPUT value=0"
        @response = read_write("queryPin pin=13")
      end
      
      it 'reports an OK status' do
        @response.should include('OK')
      end
    
      it 'reports the pin number' do
        @response.should include('pin=13')
      end
    
      it 'reports a mode of INPUT' do
        @response.should include('mode=INPUT')
      end
      
      it 'reports a value of LOW' do
        @response.should include('value=0')
      end
      
    end
  
  end

  # complains when pin is missing
  # complains when pin is out of range
  # complains when pin is not a number
  
end

