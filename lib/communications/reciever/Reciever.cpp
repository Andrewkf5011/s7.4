#include <EthernetInterface.h>
#include <string>
#include "Reciever.h"

Reciever::Reciever()
{
    //Development only.
    printf("conecting on DHCP\n");

    ethernet.connect();
    const char *ip = ethernet.get_ip_address();

    //Development only (must manually enter the IP into the Java program).
    printf("IP address is: %s\n", ip ? ip : "No IP");

    udp.open( &ethernet);

    //Listen for UDP on port 65000.
    udp.bind(65000);

    //Development only.
    printf("listening on 65000\n");
}

string Reciever::getMessage()
{
    //[messageLength] How many characters the message consists of.
    int messageLength = udp.recvfrom( &source, buffer, sizeof(buffer));
    //Add a terminating character to the end of the message.
    buffer[messageLength]='\0';

    //Development only.
    printf("message from %s/%d \n", source.get_ip_address(), source.get_port());

    return buffer;
}
