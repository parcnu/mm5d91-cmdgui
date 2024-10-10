
#ifndef MESSAGE06_H
#define MESSAGE06_H

#include <string_view>
#include <string>
#include <span>
#include <memory>
#include "message.h"
#include "message06Body.h"

class Message06:public Message
{
private: 
    void init_message(const std::string_view ms);
    std::shared_ptr<Message> debug_instance;

protected:
    Message06Body::Message06Body_t msg_06_body;
    Message06Body::Message06AdditionalInfo_t msg_06_info;
    void extract_data();

public:
    Message06(std::shared_ptr<Message> db);
    Message06(const std::string_view ms, std::shared_ptr<Message> db);
    Message06(const std::string_view ms);
    virtual ~Message06();
    virtual void show_data();
    void set_debug(const bool db);
    bool get_debug(void);
    bool is_debug(void);
    void set_message_data(std::string_view ms);
};
#endif //MESSAGE06_H
