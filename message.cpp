#include <string_view>
#include <iostream>
#include <memory>
#include <vector>
#include <charconv>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "message.h"
#include "messageBody.h"
/**
 * @brief Constructor of Message Class
*/
Message::Message(void)
{
    if (is_debug()) std::cout << "Message constructor called" << std::endl;
    Message::create_type_strings();
}

/**
 * @brief Constructor of Message Class with message string
 * @param ms 
*/
Message::Message(const std::string_view ms)
{
    bool dbs = get_debug();
    set_debug(dbs);
    Message::init_message(ms);
    Message::create_type_strings();
    if (is_debug()) std::cout << "Message constructor with ms called" << std::endl;
}

/**
 * @brief Destructor of Message Class
*/
Message::~Message()
{
    if (is_debug()) std::cout << "Message destructor called" << std::endl;
}

/**
 * @brief set_rawdata saves given string to message_info
*/
void Message::set_rawdata(const std::string_view rawms)
{
   message_info.msg_rawdata = rawms;
}

/**
 * @brief get_rawdata return saved raw data string.
 * @return std::string_view string
*/
std::string_view Message::get_rawdata()
{
    return message_info.msg_rawdata;
}

/**
 * @brief split_string_view splits given string_view to substrings based omn comma.
 * @param string const std::string_view carrying the raw message data
 * @param delim delimiter accoring which string is split to substrings
 * @return vector collection containing substrings 
*/
std::vector<std::string_view> Message::split_string_view (const std::string_view string, const char c)
{
    std::vector<std::string_view> substrings;
    
    auto start_pos = string.find_first_not_of(c);
    auto end_pos = start_pos;
    auto max_length = string.length();

    while (start_pos < max_length)
    {
        end_pos = std::min(max_length, string.find_first_of(c, start_pos));

        if (end_pos != start_pos)
        {
            substrings.emplace_back(&string[start_pos], end_pos - start_pos);
            start_pos = string.find_first_not_of(c, end_pos);
        }
    }

    return substrings;

}

/**
 * @brief split_message splits saved raw_data to substrings
 * Saves results to Message::sub_strings 
 * 
*/
void Message::split_message()
{
    if (!is_raw_data_empty())
    {
        sub_strings = Message::split_string_view(Message::get_rawdata(),delim);   
    }
}

/**
 * @brief create_type_strings creates naming conventions based on integers
*/
void Message::create_type_strings()
{
      Message::msg_type_to_string = {
        {MessageBody::AckMsg, "Acknowlege"},
        {MessageBody::InMsg, "Detection ON"},
        {MessageBody::OutMsg, "Detection OFF"}
    };
}

/**
 * @brief get_msg_name gets message name based on integer received in message
 * @param key value extracted from mesasge
 * @return std::string_view
*/
std::string_view Message::get_msg_name(const int key)
{
    std::map<int, std::string_view>::iterator it;
    if((it = Message::msg_type_to_string.find(key)) != Message::msg_type_to_string.end())
        return it->second;
    else
        return NULL;
}

/**
 * @brief convert_hex_string_view_to_uint converts given string to unsigned integer
 * @param sv std::string_view, string carrying hex string 
 * @return converted integer
*/
 unsigned int Message::convert_hex_string_view_to_uint(const std::string_view sv)
 {
    unsigned int out;
    auto [ptr, ec] = std::from_chars(sv.data(), sv.data() + sv.size(), out);
    
    if (ec == std::errc()) {

    } else {
        if (is_debug()) std::cout << "Conversion error!" << std::endl;
        out = 0;
    }
    return out;
}

/**
 * @brief convert_string_view_to_iunt64 converts given string to unsigned integer64
 * @param str std::string_view, string carrying hex string 
 * @return converted integer
*/
uint64_t Message::convert_hex_string_to_uint64(const std::string_view str)
{
    char *end;
    const char *l_str;
    uint64_t result{};
    errno = 0;
    l_str = str.data();
    result = strtoull(l_str, &end, 16);
    return result;
}

/**
 * @brief convert_hex_string_view_to_float converts given string to float
 * @param sv std::string_view, string carrying hex string 
 * @return converted float
*/
float Message::convert_hex_string_to_float(const std::string_view str)
{
    uint32_t num;
    float f;
    if (!str.empty())
    {
        sscanf(str.data(), "%x", &num); 
        f = *((float*)&num);
    } else
        f = 0.0;
    return f;
}

/**
 * @brief convert_string_int_to_hex converts given decimal value to hex
 * @param v cont uint8_t *v int to be converted
 * @param s const size_t number of bytes to be converted.
 * @return converted float
*/
std::string Message::convert_int_to_hex(const uint8_t *v, const size_t s)
{
    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (int i = 0; i < s; i++) {
        ss << std::hex << std::setw(2) << static_cast<int>(v[i]);
    }
    return ss.str();
}

/**
 * @brief set_debug sets debug value on oro off. 
 * @param db const bool to be set 
*/
void Message::set_debug(const bool db)
{
    debug_status = db;
}

/**
 * @brief get_debug returns debug value
 * @return returns debug value
*/
bool Message::get_debug()
{
    return debug_status;
}

/**
 * @brief is_debug returns debug value
 * @return returns debug value
*/
bool Message::is_debug(void)
{
    return debug_status;
}

/**
 * @brief init_message makes initial activities for received message
 * @param ms std::string_view message string to be initialized
*/
void Message::init_message(const std::string_view ms)
{
    if (is_debug()) std::cout << "Message constructor called" << std::endl;
    Message::set_rawdata(ms);
    Message::sub_strings = Message::split_string_view(ms, Message::delim);
}

void Message::show_data()
{

}

/**
 * @brief is_raw_data_empty checks that raw_date has been set
 * @return returns true if raw_data is emåty, false if raw_data has been initialized - i.e. is bigger than 0;
*/
bool Message::is_raw_data_empty()
{
    std::string_view str;
    str = Message::get_rawdata();
    if (str.size() == 0)
        return true;
    else 
        return false;
}




