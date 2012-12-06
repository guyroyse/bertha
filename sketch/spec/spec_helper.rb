def read_write request
  serial.puts request
  serial.gets.chomp
end


