#include <mbed.h>
#include <EthernetInterface.h>
#include <rtos.h>
#include <mbed_events.h>
#include <string>
#include "communications.h"


//Interrupts for the buttons.
InterruptIn sw2(SW2);
InterruptIn sw3(SW3);

//Thread handlers.
Thread eventhandler;
EventQueue eventqueue;

//[server] This is the server to be communicated with.
//The address must be hardwired.
SocketAddress server("192.168.70.15",65500);

//[serverCommunication] Handles communication with the server.
ServerCommunicator serverCommunicator(server);

//[messageProcessor] Processes the messages being
//sent/recieved to/from the server.
MessageProcessor messageProcessor;

/**
 * @brief Sends the state of a button to the server.
 * @param button This is the button thats state has changed.
 * @param state This is the state of the button.
 */
void sendstate(const char *button, const char *state)
{
    string message = messageProcessor.constructMessage(button, state);

    serverCommunicator.sendMessage(message);
}

void press(const char *b)
{
    sendstate(b,"pressed");
}

void release(const char *b)
{
    sendstate(b,"released");
}

/* function  to poll the 5 way joystich switch */
enum { Btn1, Btn2, sw_up, sw_down, sw_left, sw_right, sw_center};

const char *swname[] = {"SW2","SW3","Up","Down","Left","Right","Center"};

struct pushbutton
{
    DigitalIn sw;
    bool invert;
}

buttons[] = {
  {DigitalIn(SW2),true},
  {DigitalIn(SW3),true},
  {DigitalIn(A2),false},
  {DigitalIn(A3),false},
  {DigitalIn(A4),false},
  {DigitalIn(A5),false},
  {DigitalIn(D4),false},
};

bool ispressed(int b)
{
  return (buttons[b].sw.read())^buttons[b].invert;
}

void jspoll(void)
{
    int b;
    
    for(b=sw_up ; b<=sw_center ; b++)
    {
        if(ispressed(b))
        {
            sendstate(swname[b],"pressed");
        }
        else
        {
            sendstate(swname[b],"released");
        }
    }
}

int main()
{
    sw2.fall(eventqueue.event(press,"SW2"));
    sw3.fall(eventqueue.event(press,"SW3"));

    sw2.rise(eventqueue.event(release,"SW2"));
    sw3.rise(eventqueue.event(release,"SW3"));

    //eventqueue.call_every(500,jspoll);

    eventhandler.start(callback(&eventqueue, &EventQueue::dispatch_forever));

    while(1){}
}
