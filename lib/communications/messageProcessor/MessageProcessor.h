#include<mbed.h>
#include<string>

#ifndef MESSAGEPROCESSOR_H
#define MESSAGEPROCESSOR_H

/**
 * @brief Constructs and decodes messages in the following format:
 *        "key:value\n"
 *        These messages can be broken down into
 *        'key' and 'value' components.
 */
class MessageProcessor
{
    private:
        //[key] Stores the key component of the message.
        string key;
        //[value] Stores the value component of the message.
        string value;

    public:
        /**
         * @brief Constructor for the Message Processor class.
         */
        MessageProcessor();

        /**
         * Decodes a message into it's 'key' and 'value' components.
         * Message format should be: "key:value\n".
         */
        void decodeMessage(string message);

        /**
         * @brief Sets the key and value components, and uses them
         *        to construct a message in the format: "key:value\n".
         * @param key This is the 'key' component of the message.
         * @param value This is the 'value' component of the message.
         */
        string constructMessage(string key, string value);

        /**
         * @return Returns the 'key' component of the message
         *         currently being processed.
         */
        string getKey();

        /**
         * @return Returns the 'value' component of the message
         *         currently being processed.
         */
        string getValue();
};

#endif // MESSAGEPROCESSOR_H
