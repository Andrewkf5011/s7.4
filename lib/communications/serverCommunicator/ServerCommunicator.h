#include <EthernetInterface.h>
#include <string>

#ifndef SERVERCOMMUNICATOR_H
#define SERVERCOMMUNICATOR_H

/**
 * @brief Requests and recieves massages from a server.
 *
 * Version: 1.0
 * Date: 10/04/2018
 * Originally Created: 10/04/2018
 */
class ServerCommunicator
{
    private:
        //[buffer] A buffer made of 1l bytes, where the
        //recieved messages are stored.
        char buffer[256];

        //[ethernet] Handles the ethernet connection.
        EthernetInterface ethernet;

        //[udp] The UDP socket used to recieve messages.
        UDPSocket udp;

        //[source] Stores the socket address of the messages source.
        SocketAddress source;

        //[server] This is the server being communicated with.
        SocketAddress server;

        /**
         * @brief Requests a message from the server.
         */
        void requestMessage();

    public:

        /**
         * @brief Constructor for the Server Communicator class.
         * @param server This is the server to communicate with.
         */
        ServerCommunicator(SocketAddress server);

        /**
         * @return Retrieves a message that has been sent from a server.
         */
        string getMessage();

        /**
         * @brief Sends a message to the server.
         * @param message This is the message to be sent.
         */
        void sendMessage(string message);
};

#endif // SERVERCOMMUNICATOR_H
