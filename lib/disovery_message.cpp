//
// Created by Lasse Lauritsen on 10/06/16.
//

#include "disovery_message.h"

std::string disovery_message::gen_discovery_messages(int MX, const std::string& ST) {
    std::string msg;
    msg += "M-SEARCH * HTTP/1.1\r\n";
    msg += "HOST: 239.255.255.250:1900\r\n";
    msg += "MAN: \"ssdp:discover\"\r\n";
    msg += "MX: ";  msg += std::to_string(MX);  msg += "\r\n";
    msg += "ST: "; msg += ST; msg += "\r\n";
    msg += "\r\n";

    return msg;
}

