Gem::Specification.new do |s|

  s.name        = 'bertha'
  s.version     = '1.0.0'
  s.summary     = "Bertha Ruby API"
  s.description = "Bertha talks to the Arduino so you don't have to."
  s.authors     = ["Guy Royse"]
  s.email       = 'guy@guyroyse.com'
  s.homepage    = 'http://rubygems.org/gems/bertha'

  s.files       = ["lib/bertha.rb"]
  s.test_files  = ["spec/bertha_spec.rb"]

  s.add_runtime_dependency "serialport", ">=1.1.0"
  s.add_development_dependency "rspec"

end
