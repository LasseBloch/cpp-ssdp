//
// Created by Lasse Lauritsen on 10/06/16.
//

#ifndef CPP_SSDP_DISOVERY_MESSAGE_H
#define CPP_SSDP_DISOVERY_MESSAGE_H

#include <string>

class disovery_message {
public:
    static std::string gen_discovery_messages(int MX = 1, const std::string& ST = "sddp:all") ;
};


#endif //CPP_SSDP_DISOVERY_MESSAGE_H
