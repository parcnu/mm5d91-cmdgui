#ifndef MESSAGE_H
#define MESSAGE_H

#include <string_view>
#include <string>
#include <vector>
#include <map>
#include "messageBody.h"

class Message
{

private:
    void create_type_strings();
    void init_message(const std::string_view ms);

protected: 
    bool debug_status{false};
    const char delim{','};


    MessageBody::MessageAdditionalInfo_t message_info;
    std::vector<std::string_view> sub_strings;
    std::vector<std::string_view>::iterator sub_str_it;

    std::map<int, std::string_view> msg_type_to_string;
    std::vector<std::string_view> split_string_view(const std::string_view str, const char c);
    std::string_view get_msg_name(int key);
    unsigned int convert_hex_string_view_to_uint(const std::string_view sv);
    std::string convert_int_to_hex(const uint8_t *v, const size_t s);
    uint64_t convert_hex_string_to_uint64(const std::string_view str);
    float convert_hex_string_to_float(const std::string_view str);



    virtual void split_message();
    std::string_view get_rawdata();   
    void set_rawdata(const std::string_view rawms);
    bool is_raw_data_empty();
    
public:

    Message();
    Message(std::string_view ms);
    //Message(std::string_view ms, bool db);
    virtual ~Message();
    void show_data();
    void set_debug(const bool db);
    bool get_debug(void);
    bool is_debug(void);

};

#endif //MESSAGE_H


