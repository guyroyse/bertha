describe 'bad command' do
  
  before :each do
    @response = read_write("bad_command")
  end

  it 'reports an ERR status' do
    @response.should include('ERR')      
  end
  
  it 'reports an unknown command message' do
    read_write("bad_command").should include("msg='unknown command'")
  end
      
end