#include <iostream>
#include <fstream>
#include <cstring>
#include <linux/input.h>

using namespace std;

//structure to hold event info
struct input_event event;

int main(int argc, char *argv[])
{
    cout << "Receiving Keyboard Presses!" << endl;

    //open the file for reading
    ifstream file("/dev/input/event0");

    //temp storage for event
    char data[sizeof(event)];

    //check if file opened!
    if (file.is_open())
    {

        //lets loop until esc key
        bool session = true;
        while (session)
        {

            //lets get to work
            file.read(data, sizeof(event));

            //now copy the data to the struct
            memcpy(&event, data, sizeof(event));

            cout << "Key Press " << event.code << endl;
            //now lets read the event
            //event type
            // if (event.type == EV_KEY)
            // {

            //its a keyboard event
            //was it the esc key?
            // switch (event.code)
            // {
            // case KEY_ESC:
            //     cout << "The Escape Key Was Pushed!" << endl;
            //     session = false;
            //     break;

            // default:
            //     cout << "Key Press " << event.code << endl;
            //     break;
            // }
            // }
        }

        //dont forget to close the file
        file.close();
    }
    else
    {

        cout << "Unable to open file!" << endl;
        return 1;
    }

    return 0;
}