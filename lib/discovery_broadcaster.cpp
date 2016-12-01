//
// Created by Lasse Lauritsen on 10/06/16.
//

#include "discovery_broadcaster.h"
#include <iostream>
#include <boost/bind.hpp>

discovery_broadcaster::discovery_broadcaster(boost::asio::io_service &io_service,
                                             const boost::asio::ip::address multicast_addr) : socket_(io_service),
                                                                                              endpoint_(multicast_addr, 1900)  {
    socket_.open(endpoint_.protocol());
}

void discovery_broadcaster::send_discovery(const std::string &msg) {
    if (socket_.is_open()) {
        socket_.async_send_to(boost::asio::buffer(msg),
                           endpoint_,
                           boost::bind(
                                   &discovery_broadcaster::handle_send,
                                   this,
                                   boost::asio::placeholders::error,
                                   boost::asio::placeholders::bytes_transferred
                           )
        );
    }
}


void discovery_broadcaster::handle_send(const boost::system::error_code &error, size_t bytes_send) {
    std::cout << "Error code: " << error << " size of transmitted data: " << bytes_send << std::endl;
    std::cout << error.value() << '\n';
    std::cout << error.category().name() << '\n';
    std::cout << error.message() << '\n';
}





