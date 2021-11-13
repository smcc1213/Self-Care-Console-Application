/*
CREATED BY: Sean McConville
TITLE: Self-Care Meditation and Journal Application
DESCRIPTION: For my Final Project in my Advanced Computer Programming class, I created a Self-Care Meditation and Journal Console Application. I have provided all the code for this application. I may update this in the future to include a GUI. Along with my main.cpp file, I have provided an
additional .cpp file (Functions.cpp) and .h file (Header.h).
*/

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <stdlib.h>


using namespace std;


//menu functions
void menuIntro();

void menuSelect();

//function to be displayed after user completes an application activity
void whatNext();


//Positive entrys for Positive & Negative Thoughts Journal
class PNThoughts {

public:
    fstream PNFile;
   void PNThoughts_entry();
};

class PosEntry : public PNThoughts {

private:
    string pEntry;

public:


    void set_pEntry(string p);

    string get_pEntry();

    void makePosEntry();
};

//Negative entrys for Positive & Negative Thoughts Journal
class NegEntry : public PNThoughts {

private:
    string nEntry;

public:


    void set_nEntry(string n);

    string get_nEntry();

    void makeNegEntry();

};

class Journal {

public:

    fstream JFile;


};

//Entry for Daily Journal
class JEntry : public Journal {

private:
    string jEntry;

public:

    void set_jEntry(string j);

    string get_jEntry();

    void makeJoEntry();
};

//Timer 

class Timer {

private:

    void timerSetUp(int hr, int min, int sec);

public:

    void userTimer();

};

//Applcation Instructions/ How-to use
class Instructions
{
private:

    string instructions = string("Welcome to your shiney new Self-Care Meditation and Journal application!\n")
        + string("This application was designed to help you get an idea of what self-care looks like.\n")
        + string("Self-care looks different for everybody, this application is just the starting point.\n")
        + string("Once you get a handle on things, feel free to add whatever you would like as part of your own \nself-care. ")
        + string("To get started, the application will display 5 options for you to chose from. Simply type in \na number corresponding to the activity you would like to do when prompted.")
        + string("\n\n")
        + string("Input option '1' from the main menu in order to use the timer function. \n")
        + string("Once selected, input the amount of time in minutes (up to 60) that you would like to meditate for. The \n")
        + string("timer will then begin to count down. Once you are finished with the timer, you will be shown\n")
        + string("a list of options similar to those in the main menu. When prompted please make a selection \n")
        + string("from the list by inputting '1', '2', '3', '4', or '5'.\n")
        + string("\n")
        + string("Input option '2' from the main menu to write an entry into your Positive and Negative Thoughts Journal.\n")
        + string("Once prompted, you will first be asked to write down any negative thoughts you had while \n")
        + string("meditating or throughout the day. Once finished you will be asked to write the positive \n")
        + string("thoughts you had while meditating or throughout the day. Your postive and negative thoughts \n")
        + string("will be saved in the 'Positive and Negative Thoughts.txt' file for you to view whenever \n")
        + string("you would like. Once you are finished with the positive thoughts entry, you will be shown \n")
        + string("a list of options similar to those in the main menu. When prompted, please make a selection \n")
        + string("from the list by inputting '1', '2', '3', '4', or '5'.\n")
        + string("\n")
        + string("Input option '3' from the main menu to to write an entry into your Journal.\n")
        + string("Once prompted, you can begin to write about whatever you would like into your journal. \n")
        + string("What you want to write about is completely up to you. your entries will be saved in the\n")
        + string("'My Journal.txt' file for you to view whenever you would like. Once you are done with your entry,\n")
        + string("a list of options similar will be displayed to those in the main menu. When prompted, please\n")
        + string("make a selection from the list by inputting '1', '2', '3', '4', or '5'.\n")
        + string("\n")
        + string("Input option '4' in order to view the instructions on how to use this application.\n")
        + string("An 'Instructions.txt' file will be created after you view the instructions for you to\n")
        + string("review whenever you would like. After you are finished viewing the instructions, you will\n")
        + string(" be asked if you would like to go to the main menu. Input 'yes' to go the main menu.\n") 
        + string("Input 'no' to close the application.\n")
        + string("\n")
        + string("Input option '5' in order to exit the application\n\n");

    void SetInstructions();

public:

    fstream InstructFile;

    void ReadInstructions();

    void InstructFunction();
};

#endif // HEADER_H