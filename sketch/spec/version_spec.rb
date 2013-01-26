describe 'version' do

  before :each do
    @response = read_write("version")
  end

  it 'reports an OK status' do
    @response.should include('OK')
  end

  it 'returns version information' do
    @response.should include('version=1.0.0')
  end

end