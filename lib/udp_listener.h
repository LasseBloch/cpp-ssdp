//
// Created by Lasse Lauritsen on 28/03/16.
//

#ifndef CPP_SSDP_UDP_LISTENER_H
#define CPP_SSDP_UDP_LISTENER_H

#include <boost/asio.hpp>

class udp_listener {
public:
    udp_listener(boost::asio::io_service& io, const boost::asio::ip::address listen_addr,
                 const boost::asio::ip::address multicast_addr) ;
    void handle_receive(const boost::system::error_code& error, const size_t bytes_recived);
private:
    const int port_ = 1900;
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint sender_endpoint_;
    const static int MAX_DATA_LEN = 1024;
    char data_[MAX_DATA_LEN];
};


#endif //CPP_SSDP_UDP_LISTENER_H
