#ifndef MESSAGE06BODY_H
#define MESSAGE06BODY_H

#include <iostream>
#include "messageBody.h"

class Message06Body
{


public:
    struct Message06AdditionalInfo_t
    {
        float distance{};
        float accuracy{};
        uint64_t time{};
    };

    enum MESSAGE_O6_FIELDS{
        header = 0,
        id,
        len_lo,
        len_hi,
        time8,
        time7,
        time6,
        time5,
        time4,
        time3,
        time2,
        time1,
        dist4,
        dist3,
        dist2,
        dist1,
        acc_4,
        acc_3,
        acc_2,
        acc_1,
        crc_hi,
        crc_lo
    };

    struct Message06Body_t{
        uint8_t header;
        uint8_t id;
        uint8_t len_lo;
        uint8_t len_hi;
        uint8_t time4;
        uint8_t time3;
        uint8_t time2;
        uint8_t time1;
        uint8_t dist4;
        uint8_t dist3;
        uint8_t dist2;
        uint8_t dist1;
        uint8_t acc_4;
        uint8_t acc_3;
        uint8_t acc_2;
        uint8_t acc_1;
        uint8_t crc_hi;
        uint8_t crc_lo;
    };
};

#endif //MESSAGE06BODY