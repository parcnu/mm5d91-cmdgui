#ifndef MESSAGECRCBODY_H
#define MESSAGECRCBODY_H
#include <iostream>
class MessageCrcBody
{
    public:
        struct MessageCrcBody_t
        {
            uint crc_hi;
            uint crc_lo;
        };
};

#endif // MESSAGECRCBODY_H
