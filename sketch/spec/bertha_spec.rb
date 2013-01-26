describe 'berta' do
  
  it 'ignores superfluos arguments' do
    read_write("version alpha=bravo foo=bar").should_not include("ERR")
  end
  
end