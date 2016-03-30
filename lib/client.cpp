//
// Created by Lasse Lauritsen on 28/03/16.
//

#include <iostream>
#include "client.h"

client::client() {
    listen_addr_ = boost::asio::ip::address::from_string("0.0.0.0");
    multicast_addr_ = boost::asio::ip::address::from_string("239.255.255.250");
    parser_ = std::make_shared<parser>();
    std::cout << "parser use count: " << parser_.use_count() << std::endl;
    udp_listner_ = std::make_unique<udp_listener>(io_service_,listen_addr_, multicast_addr_, parser_);
    std::cout << "parser use count: " << parser_.use_count() << std::endl;
    io_service_.run();
}