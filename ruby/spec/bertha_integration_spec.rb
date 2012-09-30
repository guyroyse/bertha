require 'bertha'

describe "Bertha Integration" do

  it "call's Bertha to retrieve version number" do
    Bertha.open '/dev/cu.usbmodemfa131', 9600 do |bertha|
      bertha.version.should == '1.0.0'
    end
  end

end
