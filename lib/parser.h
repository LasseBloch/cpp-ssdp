//
// Created by Lasse Lauritsen on 30/03/16.
//

#ifndef CPP_SSDP_PARSER_H
#define CPP_SSDP_PARSER_H


#include <memory>

class parser {
public:
    void parse(std::unique_ptr<std::string> raw_msg);
};


#endif //CPP_SSDP_PARSER_H
