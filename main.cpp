#include <iostream>
#include <sstream>
#include "message.h"
#include "message06.h"
#include "message07.h"

/**
 * @brief Main function
 * @param argc amount of arguments
 * @param argv array of given argiments
 */
int main(int argc, char **argv){
    bool deb{false};
    // Cast argv[1] to bool
    if (argc > 1)
    {
        std::stringstream ss(argv[1]);
        if(!(ss >> std::boolalpha >> deb)) {
            printf("Incorrect argiment. Use either true or false");
            return 0;
        }   
    }
    printf("deb %d\n", deb);
    std::shared_ptr<Message> debug = std::make_shared<Message>();
    debug->set_debug(deb);
    Message06 m6(debug);
    Message07 m7(debug);
    m6.set_message_data("217,6,16,0,241,119,66,5,0,0,0,0,148,250,98,64,77,215,38,62,31,160");
    m7.set_message_data("217,7,16,0,31,160");
    m6.show_data();
    m7.show_data();

    return 0;
}