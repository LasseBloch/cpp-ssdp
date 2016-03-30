//
// Created by Lasse Lauritsen on 30/03/16.
//

#include <iostream>
#include "parser.h"


void parser::parse(std::unique_ptr<std::string> raw_msg) {
    std::cout << raw_msg.get() << std::endl;
}

