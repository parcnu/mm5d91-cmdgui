#include <iostream>
#include <string_view>
#include <sstream>
#include <vector>
#include <span>
#include "message07.h"
#include "message07Body.h"

/**
 * @brief Message07 constructor. Initializes shared pointer to debug_instance
 * @param db shared pointer to Message debug_instance
*/
Message07::Message07(std::shared_ptr<Message> db)
: debug_instance(db)
{
   if (debug_instance->is_debug()) std::cout << "Message07 constructor with db called" << std::endl;
}

/**
 * @brief Message07 constructor. Initializes shared pointer to debug_instance
 * @param ms std::string_view message raw content
 * @param db shared pointer to Message debug_instance
*/
Message07::Message07(const std::string_view ms, std::shared_ptr<Message> db)
: debug_instance(db)
{
    Message07::init_message(ms);
    if (debug_instance->is_debug()) std::cout << "Message07 contructor with ms and db called" << std::endl;
}

/**
 * @brief Message07 destructor
*/
Message07::~Message07()
{
    if (debug_instance->is_debug()) std::cout << "Message07 destructor called" << std::endl;
}

/**
 * @brief Message07 extract_data extracts message values in Message class.
*/
void Message07::extract_data()
{
    if (!Message::is_raw_data_empty())
    {
        std::string temp1, temp2, temp3, temp4, temp5, temp6, temp7 , temp8, temp; 
        std::string NOL{"00"};
        int out;
        int i = 0;
        for (auto& item: Message::sub_strings)
        {
            switch (i)
            {
                case Message07Body::header:
                    msg_07_body.header = Message::convert_hex_string_view_to_uint(item);
                    break;
                case Message07Body::id:
                    msg_07_body.id = Message::convert_hex_string_view_to_uint(item); 
                    break;
                case Message07Body::len_lo:
                    msg_07_body.len_lo = Message::convert_hex_string_view_to_uint(item);
                    break;
                case Message07Body::len_hi:
                    msg_07_body.len_hi = Message::convert_hex_string_view_to_uint(item);
                    break;
                case Message07Body::crc_lo:
                    msg_07_body.crc_lo = Message::convert_hex_string_view_to_uint(item);
                    break;
                case Message07Body::crc_hi:
                    msg_07_body.crc_hi = Message::convert_hex_string_view_to_uint(item);
                    break;
                default:
                    break;
            }
            i++;
        }
        message_info.msg_name = get_msg_name(msg_07_body.id);
    }
}

/**
 * @brief Message07 show_data prints calulated values of In message
*/
void Message07::show_data()
{
    std::cout << "msg name: " << message_info.msg_name << std::endl;
    
}

/**
 * @brief Message07 set_debug sets shared pointer value to Message class
 * @param db const bool value to be set in shared pointer and to be saved in Message class.
*/
void Message07::set_debug(const bool db)
{
    debug_instance->set_debug(db);
}

/**
 * @brief Message07 get_debug returns global shared pointer of the Message class
*/
bool Message07::get_debug()
{
    return debug_instance->get_debug();
}

/**
 * @brief Message07 is_debug returns debug value
*/
bool Message07::is_debug()
{
    return debug_instance->get_debug();
}

/**
 * @brief Message07 init_message initializes in message
 * @param ms std::string_view to carry raw message data
*/
void Message07::init_message(const std::string_view ms)
{
    if (debug_instance->is_debug()) std::cout << "Message07 init message called" << std::endl;
    Message::set_rawdata(ms);
    Message::split_message();
    Message07::extract_data();
}

/**
 * @brief Message07 set_message_data saves received message data to Message class.
 * @param ms std::string_view to carry raw message data
*/
void Message07::set_message_data(std::string_view ms)
{
    Message07::init_message(ms);
}




