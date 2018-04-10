#include <EthernetInterface.h>
#include <string>

#ifndef RECIEVER_H
#define RECIEVER_H

/**
 * @brief Recieves messages over ethernet.
 *
 * Version: 1.0
 * Date: 08/04/2018
 * Originally Created: 08/04/2018
 */
class Reciever
{
    private:

        //[buffer] A buffer made of 1l bytes, where the
        //recieved messages are stored.
        char buffer[1024]; 

        //[ethernet] Handles the ethernet connection.
        EthernetInterface ethernet;

        //[udp] The UDP socket used to recieve messages.
        UDPSocket udp;

        //[source] Stores the socket address of the messages source.
        SocketAddress source;

    public:

        /**
         * @brief Constructor for the Reciever class.
         */
        Reciever();

        /**
         * @return If a message has been sent, it returns the message
         *         in string format.
         */
        string getMessage();
};

#endif // RECIEVER_H
