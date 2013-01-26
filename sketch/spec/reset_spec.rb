describe 'reset' do

  before :each do
    @response = read_write("reset");
  end

  it 'reports an OK status' do
    @response.should == 'OK'
  end

#   it 'resets mode' do
#   end

#   it 'resets value' do
#   end

end
