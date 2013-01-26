describe 'queryPin' do

  before :each do
    write 'reset'
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
  
# when pin is set to OUTPUT
# when pin is set to INPUT
    
# complains when pin is missing
# complains when pin is out of range
# ignores other arguments
# complains when pin is not a number

end

