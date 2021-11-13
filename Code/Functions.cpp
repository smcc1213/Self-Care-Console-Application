/*
CREATED BY: Sean McConville
TITLE: Self-Care Meditation and Journal Application
DESCRIPTION: For my Final Project in my Advanced Computer Programming class, I created a Self-Care Meditation and Journal Console Application. I have provided all the code
for this application. I may update this in the future to include a GUI. Along with my main.cpp file, I have provided an
additional .cpp file (Functions.cpp) and .h file (Header.h).
*/

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>
#include <cstdlib>
#include "Header.h"

using namespace std;

//menu functions

void menuIntro() {


    cout << "Welcome to the Self-Care Meditation and Journal Application!" << endl
         << "To get started, please view the options and input your selection below...\n\n";

    cout << "1: Meditation Timer" << endl
        << "2: Positive and Negative Thoughts Journal" << endl
        << "3: Daily Journal" << endl
        << "4: How to Use This Application" << endl
        << "5: Exit Application\n\n";

    menuSelect();

}

void menuSelect() {
    
    int selection;

    cout << "Which option would you like to do today (1, 2, 3, 4, or 5)?: ";
    cin >> selection;
    system("cls");

    if (selection == 1) {

        Timer newTimer;
        newTimer.userTimer();
    }
    
    if (selection == 2) {

       
        NegEntry negEntry;
        PosEntry posEntry;
        negEntry.makeNegEntry();
        posEntry.makePosEntry();
    }
    
    if (selection == 3) {

        
        JEntry newEntry;
        newEntry.makeJoEntry();

    }

    if (selection == 4) {

        cout << "\n";
        Instructions newView;
        newView.InstructFunction();

    }

    if (selection == 5) {

        exit(0);
    }

    while (selection != 1 && selection != 2 && selection != 3 && selection != 4 && selection != 5) {

        cout << "\n";
        cout << "Not a valid selection. Please input '1', '2', '3', '4', or '5'" << endl;
        menuSelect();

    }

    

}

void whatNext() {

    int choice;

    cout << "\n\n";


    cout << "1: Main Menu" << endl
        << "2: Meditation Timer" << endl
        << "3: Positive and Negative Thoughts Journal" << endl
        << "4: Daily Journal" << endl
        << "5: Exit Application\n\n";


    cout << "Which else would you like to do today (1, 2, 3, 4, or 5)?: ";
    cin >> choice;
    system("cls"); //clears screen

    if (choice == 1) {

        
        menuIntro();

    }

    if (choice == 2) {

        Timer newTimer;
        newTimer.userTimer();


    }

    if (choice == 3) {

        
        PNThoughts newEntry;
        newEntry.PNThoughts_entry();

    }

    if (choice == 4) {

        
        JEntry newEntry;
        newEntry.makeJoEntry();

    }

    if (choice == 5) {

        exit(0);

    }

    while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice !=5) {

        cout << "\n";
        cout << "Not a valid selection. Please input '1', '2', '3', '4', or '5'" << endl;
        whatNext();


    }



}


//functions for Positive and Negative Thoughts Journal


void PNThoughts::PNThoughts_entry() {

    NegEntry negEntry;
    PosEntry posEntry;

    negEntry.makeNegEntry();
    posEntry.makePosEntry();

    

}

void PosEntry::set_pEntry(string p) {

    pEntry = p;

    PNFile << pEntry; //writes to file
    PNFile << "\n\n";

}

string PosEntry::get_pEntry() {

    return pEntry;

}

void PosEntry::makePosEntry() {

    string x;

    PNFile.open("Positive and Negative Thoughts.txt", ios::app);
    if (PNFile.is_open()) {

        cout << "\n";
        cout << "Please discuss your positive thoughts below" << endl << endl;

        cout << "Positive Thoughts: ";
        getline(cin >> ws, x);

        PNFile << "*****************************************\n"
               << "            POSITIVE THOUGHTS\n"
               << "*****************************************\n\n";

        set_pEntry(x);

        PNFile.close();

    }

    else {

        cout << "ERROR! UNABLE TO OPEN FILE\n";
    }

   whatNext();

}



void NegEntry::set_nEntry(string n) { //setter

    nEntry = n;

    PNFile << nEntry; //writes to file
    PNFile << "\n\n";
}

string NegEntry::get_nEntry() { //getter

    return nEntry;

}

void NegEntry::makeNegEntry() {

    string y;

    PNFile.open("Positive and Negative Thoughts.txt", ios::app);
    if (PNFile.is_open()) {

        
        cout << "Please discuss your negative thoughts below" << endl << endl;

        cout << "Negative Thoughts: ";
        getline(cin >> ws, y);

        PNFile << "*****************************************\n"
               << "            NEGATIVE THOUGHTS\n"
               << "*****************************************\n\n";

        set_nEntry(y);

    }

    else {

        cout << "ERROR! UNABLE TO OPEN FILE\n";
    }


}

//functions for Daily Journal

void JEntry::set_jEntry(string j) {

    jEntry = j;

    JFile << jEntry; //writes to file
    JFile << "\n\n";

}

string JEntry::get_jEntry() {

    return jEntry;

}

void JEntry::makeJoEntry() {

    string z;

    JFile.open("My Journal.txt", ios::app);
    if (JFile.is_open()) {

        
        cout << "Please make your journal entry below." << endl << endl;

        cout << "Today's Journal Entry: ";
        getline(cin >> ws, z);

        JFile << "*****************************************\n"
              << "           NEW JOURNAL ENTRY\n"
              << "*****************************************\n\n";

        set_jEntry(z);

        JFile.close();
    }

    else {

        cout << "ERROR! UNABLE TO OPEN FILE\n";
    }

    whatNext();

}

//functions for Timer


void Timer::timerSetUp(int hr, int min, int sec) {



    for (;;) {

        if (hr == 0 && min == 0 && sec == 0) {

            cout << '\a'; //alarm
            cout << endl << endl;
            cout << "TIME IS UP! GREAT WORK!" << endl << endl;
            whatNext();

        }
        
        if (min == 0 && sec == 0)
        {
            min = 60;
            hr--;

        }

        if (sec == 0)
        {
            sec = 60;
            min--;
        }
        system("cls");

        cout << hr << ":" << min << ":" << sec--;
        Sleep(1000); //makes timer count in seconds 

    }


}

void Timer::userTimer() {

    int h = 0,
        m,
        s = 0;

    
    cout << "\n";
    cout << "How many minutes would you like to meditate today (up to 60)?: ";
    cin >> m;
    cout << endl;

    timerSetUp(h, m, s);

    

}

//functions for Instructions

void Instructions::SetInstructions() {

    fstream InstructFile;

    InstructFile.open("Instructions.txt", ios::out);

    if (InstructFile.is_open()) {

        InstructFile << instructions; //writes instructions to file

        InstructFile.close();
    }

    else {

        cout << "ERROR! UNABLE TO OPEN FILE\n";
    }


}

void Instructions::ReadInstructions() {

    fstream InstructFile;

    InstructFile.open("Instructions.txt", ios::in); //reads from file

    if (InstructFile.is_open()) {

        string textLine;
        while (getline(InstructFile, textLine)) {

            cout << textLine << endl; //prints file contents to console

        }

        InstructFile.close();

    }

    else {

        cout << "ERROR! UNABLE TO OPEN FILE\n";
    }

}

void Instructions::InstructFunction() {

    string yesNo;

    SetInstructions();
    ReadInstructions();

    cout << "Would you like to go to the main menu? "
        << "Input 'yes' to go to the main menu. "
        << "Input 'no' to exit the application.: ";

    cin >> yesNo;
    system("cls");

    if (yesNo == "yes" || yesNo == "Yes") {

        menuIntro();

    }

    if (yesNo == "no" || yesNo == "No") {

        exit(0);

    }

}
