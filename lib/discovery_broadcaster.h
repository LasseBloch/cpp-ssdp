//
// Created by Lasse Lauritsen on 10/06/16.
//

#ifndef CPP_SSDP_DISCOVERY_BROADCASTER_H
#define CPP_SSDP_DISCOVERY_BROADCASTER_H

#include <boost/asio.hpp>
#include <string>

class discovery_broadcaster {
public:
    discovery_broadcaster(boost::asio::io_service& io_service, const boost::asio::ip::address multicast_addr);
    void send_discovery(const std::string& msg);
private:

    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint endpoint_;
    void handle_send(const boost::system::error_code &error, size_t bytes_send);
};


#endif //CPP_SSDP_DISCOVERY_BROADCASTER_H
