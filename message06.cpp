#include <iostream>
#include <string_view>
#include <sstream>
#include <vector>
#include <span>
#include "message06.h"
#include "message06Body.h"

/**
 * @brief Message06 constructor. Initializes shared pointer to debug_instance
 * @param db shared pointer to Message debug_instance
*/
Message06::Message06(std::shared_ptr<Message> db)
: debug_instance(db)
{
   if (debug_instance->is_debug()) std::cout << "Message06 constructor with db called" << std::endl;
}

/**
 * @brief Message06 constructor. Initializes shared pointer to debug_instance
 * @param ms std::string_view message raw content
 * @param db shared pointer to Message debug_instance
*/
Message06::Message06(const std::string_view ms, std::shared_ptr<Message> db) 
: debug_instance(db)
{
    Message06::init_message(ms);
    if (debug_instance->is_debug()) std::cout << "Message06 constructor with ms and db called" << std::endl;
}

/**
 * @brief Message06 destructor
*/
Message06::~Message06()
{
    if (debug_instance->is_debug()) std::cout << "Message06 destructor called" << std::endl;
}

/**
 * @brief Message06 extract_data extracts message values in Message class.
*/
void Message06::extract_data()
{
    if (!Message::sub_strings.empty())
    {
        std::string temp1, temp2, temp3, temp4, temp5, temp6, temp7 , temp8, temp; 
        std::string NOL{"00"};
        int out;
        int i = 0;
        for (auto& item: Message::sub_strings)
        {
            switch (i)
            {
                case Message06Body::header:
                    msg_06_body.header = Message::convert_hex_string_view_to_uint(item);
                    break;
                case Message06Body::id:
                    msg_06_body.id = Message::convert_hex_string_view_to_uint(item); 
                    break;
                case Message06Body::len_lo:
                    msg_06_body.len_lo = Message::convert_hex_string_view_to_uint(item);
                    break;
                case Message06Body::len_hi:
                    msg_06_body.len_hi = Message::convert_hex_string_view_to_uint(item);
                    break;
                case Message06Body::time8:
                    msg_06_body.time4 = Message::convert_hex_string_view_to_uint(item);
                    temp8 = Message::convert_int_to_hex(&msg_06_body.time4,sizeof(uint8_t));
                    break;
                case Message06Body::time7:
                    msg_06_body.time4 = Message::convert_hex_string_view_to_uint(item);
                    temp7 = Message::convert_int_to_hex(&msg_06_body.time4,sizeof(uint8_t));
                    break;
                case Message06Body::time6:
                    msg_06_body.time4 = Message::convert_hex_string_view_to_uint(item);
                    temp6 = Message::convert_int_to_hex(&msg_06_body.time4,sizeof(uint8_t));
                    break;
                case Message06Body::time5:
                    msg_06_body.time4 = Message::convert_hex_string_view_to_uint(item);
                    temp5 = Message::convert_int_to_hex(&msg_06_body.time4,sizeof(uint8_t));
                    break;
                case Message06Body::time4:
                    msg_06_body.time4 = Message::convert_hex_string_view_to_uint(item);
                    temp4 = Message::convert_int_to_hex(&msg_06_body.time4,sizeof(uint8_t));
                    break;
                case Message06Body::time3:
                    msg_06_body.time3 = Message::convert_hex_string_view_to_uint(item);
                    temp3= Message::convert_int_to_hex(&msg_06_body.time3,sizeof(uint8_t));
                    break;
                case Message06Body::time2:
                    msg_06_body.time2 = Message::convert_hex_string_view_to_uint(item);
                    temp2= Message::convert_int_to_hex(&msg_06_body.time2,sizeof(uint8_t));
                    break;
                case Message06Body::time1:
                    msg_06_body.time1 = Message::convert_hex_string_view_to_uint(item);
                    temp1 = Message::convert_int_to_hex(&msg_06_body.time1,sizeof(uint8_t));
                    temp = temp1 + temp2 + temp3 + temp4 + temp5 + temp6 + temp7 +temp8;
                    msg_06_info.time = convert_hex_string_to_uint64(temp);
                    break;
                case Message06Body::dist4:
                    msg_06_body.dist4 = Message::convert_hex_string_view_to_uint(item);
                    temp4 = Message::convert_int_to_hex(&msg_06_body.dist4,sizeof(uint8_t));
                    break;
                case Message06Body::dist3:
                    msg_06_body.dist3 = Message::convert_hex_string_view_to_uint(item);
                    temp3 = Message::convert_int_to_hex(&msg_06_body.dist3,sizeof(uint8_t));
                    break;
                case Message06Body::dist2:
                    msg_06_body.dist2 = Message::convert_hex_string_view_to_uint(item);
                    temp2 = Message::convert_int_to_hex(&msg_06_body.dist2,sizeof(uint8_t));
                    break;
                case Message06Body::dist1:
                    msg_06_body.dist1 = Message::convert_hex_string_view_to_uint(item);
                    temp1 = Message::convert_int_to_hex(&msg_06_body.dist1,sizeof(uint8_t));
                    temp = temp1 + temp2 + temp3 + temp4;
                    msg_06_info.distance  = Message::convert_hex_string_to_float(temp);
                    break;
                case Message06Body::acc_4:
                    msg_06_body.acc_4 = Message::convert_hex_string_view_to_uint(item);
                    temp4= Message::convert_int_to_hex(&msg_06_body.acc_4,sizeof(uint8_t));
                    break;
                case Message06Body::acc_3:
                    msg_06_body.acc_3 = Message::convert_hex_string_view_to_uint(item);
                    temp3 = Message::convert_int_to_hex(&msg_06_body.acc_3,sizeof(uint8_t));
                    break;
                case Message06Body::acc_2:
                    msg_06_body.acc_2 = Message::convert_hex_string_view_to_uint(item);
                    temp2 = Message::convert_int_to_hex(&msg_06_body.acc_2,sizeof(uint8_t));
                    break;
                case Message06Body::acc_1:
                    msg_06_body.acc_1 = Message::convert_hex_string_view_to_uint(item);
                    temp1 = Message::convert_int_to_hex(&msg_06_body.acc_1,sizeof(uint8_t));
                    temp = temp1 + temp2 + temp3 + temp4;
                    msg_06_info.accuracy = Message::convert_hex_string_to_float(temp);
                    break;
                case Message06Body::crc_lo:
                    msg_06_body.crc_lo = Message::convert_hex_string_view_to_uint(item);
                    break;
                case Message06Body::crc_hi:
                    msg_06_body.crc_hi = Message::convert_hex_string_view_to_uint(item);
                    break;
                default:
                    break;
            }
            i++;
        }
        message_info.msg_name = get_msg_name(msg_06_body.id);
    }
}

/**
 * @brief Message06 show_data prints calulated values of In message
*/
void Message06::show_data()
{
    std::cout << "msg name: " << message_info.msg_name << std::endl;
    std::cout << "msg time: " << msg_06_info.time << std::endl;
    std::cout << "msg distance: " << msg_06_info.distance << std::endl;
    std::cout << "msg accuracy: " <<  msg_06_info.accuracy << std::endl;
}

/**
 * @brief Message06 set_debug sets shared pointer value to Message class
 * @param db const bool value to be set in shared pointer and to be saved in Message class.
*/
void Message06::set_debug(const bool db)
{
   debug_instance->set_debug(db);
}

/**
 * @brief Message06 get_debug returns global shared pointer of the Message class
*/
bool Message06::get_debug()
{
    return debug_instance->get_debug();
}

/**
 * @brief Message06 is_debug returns debug value
*/
bool Message06::is_debug()
{
    return debug_instance->get_debug();
}

/**
 * @brief Message06 init_message initializes in message
 * @param ms std::string_view to carry raw message data
*/
void Message06::init_message(const std::string_view ms)
{
    if (debug_instance->is_debug()) std::cout << "Message06 init message called" << std::endl;
    Message::set_rawdata(ms);
    Message::split_message();
    Message06::extract_data();
}

/**
 * @brief Message06 set_message_data saves received message data to Message class.
 * @param ms std::string_view to carry raw message data
*/
void Message06::set_message_data(std::string_view ms)
{
    Message06::init_message(ms);
}




