#ifndef MESSAGEBODY_H
#define MESSAGEBODY_H

#include <iostream>
#include "messageBody.h"

class MessageBody
{

public:
    enum {
        AckMsg = 2,
        InMsg = 6,
        OutMsg = 7
    };

    struct MessageAdditionalInfo_t{
        std::string_view msg_name;
        std::string_view msg_rawdata;
    };
};

#endif //MESSAGEBODY