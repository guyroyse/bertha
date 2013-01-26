describe 'reset' do

  before :each do
    write "setPin pin=13 mode=OUTPUT value=HIGH"
    @response = read_write("reset");
  end

  it 'reports an OK status' do
    @response.should == 'OK'
  end

  it 'resets mode' do
    read_write("queryPin pin=13").should include("mode=INPUT")
  end

end
