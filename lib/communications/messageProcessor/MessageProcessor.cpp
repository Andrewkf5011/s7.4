#include <mbed.h>
#include <string>
#include "MessageProcessor.h"

MessageProcessor::MessageProcessor()
{

}

void MessageProcessor::decodeMessage(string message)
{
    //Print out the message, and the length of the message (development only).
    printf("\nMessage: %s", message.c_str());
    printf("MessageLength: %d\n", message.length());

    //[seperatorLocation] Stores the location of the seperator
    //within the message.
    int seperatorLocation = message.find(':');

    //Print out the location of the seperator (development only).
    printf("seperator location: %d\n", seperatorLocation);

    key = message.substr(0, seperatorLocation);

    //Print out the key (development only).
    printf("Key: %s\n", key.c_str());


    //[valueLength] stores the number of characters between the seperator
    //and the end of the message. (Note: 2 is subtracted to account for
    //the "end of line" characters: '\n').
    int valueLength = message.length() - seperatorLocation - 2;

    value = message.substr((seperatorLocation + 1), valueLength);

    //Print out the value (development only).
    printf("Value: %s\n", value.c_str());
}

string MessageProcessor::constructMessage(string key, string value)
{
    //Set the key and value components.
    MessageProcessor::key = key;
    MessageProcessor::value = value;

    string message = (
        MessageProcessor::getKey() +
        ":" +
        MessageProcessor::getValue() +
        "\n\0"
    );

    return message;
}

string MessageProcessor::getKey()
{
    return key;
}

string MessageProcessor::getValue()
{
    return value;
}
