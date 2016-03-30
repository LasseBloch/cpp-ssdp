//
// Created by Lasse Lauritsen on 28/03/16.
//

#include "udp_listener.h"
#include <boost/bind.hpp>
#include <iostream>

udp_listener::udp_listener(boost::asio::io_service &io, const boost::asio::ip::address listen_addr,
                           const boost::asio::ip::address multicast_addr,
                           std::shared_ptr<parser> parser) : socket_(io) {

    parser_ = parser;
    boost::asio::ip::udp::endpoint endpoint(listen_addr, port_);
    socket_.open(endpoint.protocol());
    socket_.set_option(boost::asio::ip::udp::socket::reuse_address(true));
    socket_.bind(endpoint);

    // Join multicast group
    socket_.set_option(boost::asio::ip::multicast::join_group(multicast_addr));

    socket_.async_receive_from(boost::asio::buffer(data_, MAX_DATA_LEN), sender_endpoint_,
                            boost::bind(
                                    &udp_listener::handle_receive,
                                    this,
                                    boost::asio::placeholders::error,
                                    boost::asio::placeholders::bytes_transferred
                            ));
}

void udp_listener::handle_receive(const boost::system::error_code &error, const size_t bytes_recived) {
    if (!error) {
        std::cout.write(data_, bytes_recived);
        std::cout << std::endl;

        socket_.async_receive_from(boost::asio::buffer(data_, MAX_DATA_LEN), sender_endpoint_,
                              boost::bind(&udp_listener::handle_receive,
                                          this,
                                          boost::asio::placeholders::error,
                                          boost::asio::placeholders::bytes_transferred
                              ));
    }
}
