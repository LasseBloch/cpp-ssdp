//
// Created by Lasse Lauritsen on 28/03/16.
//

#include <iostream>
#include "client.h"

client::client() {
    listen_addr_ = boost::asio::ip::address::from_string("0.0.0.0");
    multicast_addr_ = boost::asio::ip::address::from_string("239.255.255.250");
    if (udp_listner_ != nullptr) {
        std::cout << "This should never happen what did you do?" << std::endl;
    } else {
        udp_listner_ = std::unique_ptr<udp_listener>(new udp_listener(io_service_,listen_addr_,multicast_addr_));
    }
    io_service_.run();
}