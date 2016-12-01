//
// Created by Lasse Lauritsen on 28/03/16.
//

#include <iostream>
#include "client.h"
#include "disovery_message.h"

client::client() {
    listen_addr_ = boost::asio::ip::address::from_string("0.0.0.0");
    multicast_addr_ = boost::asio::ip::address::from_string("239.255.255.250");
    parser_ = std::make_shared<parser>();
    std::cout << "parser use count: " << parser_.use_count() << std::endl;
    udp_listner_ = std::make_unique<udp_listener>(io_service_,listen_addr_, multicast_addr_, parser_);
    std::cout << "parser use count: " << parser_.use_count() << std::endl;
    discovery_bcaster_ = std::make_unique<discovery_broadcaster>(io_service_, multicast_addr_);
}

void client::broadcast_disover_all() {
    discovery_bcaster_->send_discovery(disovery_message::gen_discovery_messages());
    io_service_.run();
}
