require_relative 'em-websocket-client'
require "serialport"




EM.run do
    conn = EventMachine::WebSocketClient.connect("ws://0.0.0.0:3001/")

    conn.callback do
        conn.send_msg "connected!"
    end

    conn.errback do |e|
        puts "Got error: #{e}"
    end

    conn.stream do |msg|
        port_file = "/dev/ttyACM0"
        baud_rate = 9600
       data_bits = 8
        stop_bits = 1
        parity = SerialPort::NONE
        ser = SerialPort.new(port_file , baud_rate , data_bits , stop_bits , parity)
        
        ser.write("#{msg}")


        
    end

    conn.disconnect do
        puts "disconnected!"
        EM::stop_event_loop
    end
end
