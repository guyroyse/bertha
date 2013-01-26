describe 'setPin' do

  before :each do
    write 'reset'
  end
  
  context 'when setting mode to OUTPUT' do
    
    before :each do
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
        @response.should include('value=HIGH')
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
        @response.should include('value=LOW')
      end
      
    end
    
  end
      
  context 'when setting value to HIGH and mode to OUTPUT' do
    
    before :each do
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
      @response.should include('value=HIGH')
    end
    
  end
  
  context 'when seeting value to LOW and mode to OUTPUT' do
    
    before :each do
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
      @response.should include('value=LOW')
    end
    
  end
  
  context 'when setting mode to INPUT' do
    
    before :each do
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
  
end