
#ifndef MESSAGE07_H
#define MESSAGE07_H

#include <string_view>
#include <string>
#include <span>
#include <memory>
#include "message.h"
#include "message07Body.h"

class Message07:public Message
{
private: 
    void init_message(const std::string_view ms);
    std::shared_ptr<Message> debug_instance;
protected:
    Message07Body::Message07Body_t msg_07_body;
    void extract_data();

public:
    //Message07();
    Message07(std::shared_ptr<Message> db);
    //Message07(const std::string_view ms);
    Message07(const std::string_view ms, std::shared_ptr<Message> db);
    virtual ~Message07();
    virtual void show_data();
    void set_debug(const bool db);
    bool get_debug(void);
    bool is_debug(void);
    void set_message_data(std::string_view ms);
    
};
#endif //MESSAGE07_H
