describe 'setPin' do

  before :each do
    write 'reset'
  end
  
  context 'when mode and value are not set' do
    
    before :each do
      write "setPin pin=12 mode=INPUT"
      write "setPin pin=13 mode=OUTPUT value=HIGH"
      @response = read_write("setPin pin=13")
    end
    
    it 'reports an OK status' do
      @response.should include('OK')
    end
    
    it 'reports the pin number' do
      @response.should include('pin=13')        
    end
    
    it 'reports the previous mode' do
      @response.should include('mode=OUTPUT')
    end
    
    it 'reports the previous value' do
      @response.should include('value=1')      
    end
    
    it 'emmits the previous value' do
      read_write("queryPin pin=12").should include("value=1")      
    end
    
    
  end
  
  context 'when setting mode to OUTPUT' do
    
    before :each do
      write "setPin pin=12 mode=INPUT"
      @response = read_write("setPin pin=13 mode=OUTPUT")
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
    
    it 'emmits a value of LOW' do
      read_write("queryPin pin=12").should include("value=0")      
    end
    
    context 'when setting value to HIGH' do
      
      before :each do
        @response = read_write("setPin pin=13 value=HIGH")
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
      
      it 'emmits a value of HIGH' do
        read_write("queryPin pin=12").should include("value=1")
      end
      
    end
    
    context 'when setting value to LOW' do
      
      before :each do
        @response = read_write("setPin pin=13 value=LOW")
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
      
      it 'emmits a value of LOW' do
        read_write("queryPin pin=12").should include("value=0")
      end
      
    end
    
  end
      
  context 'when setting value to HIGH and mode to OUTPUT' do
    
    before :each do
      write "setPin pin=12 mode=INPUT"
      @response = read_write("setPin pin=13 mode=OUTPUT value=HIGH")
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
    
    it 'emmits a value of HIGH' do
      read_write("queryPin pin=12").should include("value=1")
    end
    
  end
  
  context 'when setting value to LOW and mode to OUTPUT' do
    
    before :each do
      write "setPin pin=12 mode=INPUT"
      @response = read_write("setPin pin=13 mode=OUTPUT value=LOW")
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
    
    it 'emmits a value of LOW' do
      read_write("queryPin pin=12").should include("value=0")
    end
    
  end
  
  context 'when setting mode to INPUT' do
    
    before :each do
      write "setPin pin=12 mode=OUTPUT"
      @response = read_write("setPin pin=13 mode=INPUT")
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
    
  end
  
  context 'when setting mode to PWM' do
    
    before :each do
      @response = read_write("setPin pin=11 mode=PWM")
    end
    
    it 'reports an OK status' do
      @response.should include('OK')
    end
    
    it 'reports the pin number' do
      @response.should include('pin=11')        
    end
            
    it 'reports a mode of PWM' do
      @response.should include('mode=PWM')
    end
    
    it 'reports a PWM value of 0' do
      @response.should include('value=0')
    end
    
    context 'when setting value' do
      
      before :each do
        @response = read_write("setPin pin=11 value=128")
      end
      
      it 'reports an OK status' do
        @response.should include('OK')
      end
      
      it 'reports the pin number' do
        @response.should include('pin=11')        
      end
              
      it 'reports a mode of PWM' do
        @response.should include('mode=PWM')
      end
      
      it 'reports the PWN value' do
        @response.should include('value=128')
      end
      
    end
    
    
  end
  
  # complains when pin is missing
  # complains when pin is out of range
  # complains when pin is not a number
  
end