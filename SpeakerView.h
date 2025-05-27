// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA3: Do You See What I See?

#ifndef SPEAKERVIEW_H // instantiates class once
#define SPEAKERVIEW_H // defines SpeakerView class

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <fstream> // includes ifstream and ofstream
#include <sstream> // includes std::stringstream
#include "MonoStack.h" // includes contents from MonoStack class

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

class SpeakerView { // class body

    public: 
        SpeakerView(); // default constructor
        ~SpeakerView(); // default destructor
        void analyzeSeats(std::string inFileName); 
        // public void method that takes in a txt file of seats and tells how many people can see in each column and what their heights are

};

#endif // end of class definition