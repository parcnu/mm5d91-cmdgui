#ifndef MESSAGE07BODY_H
#define MESSAGE07BODY_H

#include <iostream>
#include "messageBody.h"

class Message07Body
{


public:

    enum MESSAGE_O7_FIELDS{
        header = 0,
        id,
        len_lo,
        len_hi,
        crc_hi,
        crc_lo
    };

    struct Message07Body_t{
        uint8_t header;
        uint8_t id;
        uint8_t len_lo;
        uint8_t len_hi;
        uint8_t crc_hi;
        uint8_t crc_lo;
    };
};

#endif //MESSAGE07BODY