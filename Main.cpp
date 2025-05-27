// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA3: Do You See What I See?

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include "SpeakerView.h" // includes SpeakerView class
#include "MonoStack.h" // includes MonoStack class

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

int main(int argc, char* argv[]) { // main method
// takes in a txt file and processes its contents

    SpeakerView sv; // SpeakerView file processor object sv for reading

    cout << endl; // newline for neatness

    try { // try the following program
        sv.analyzeSeats(argv[1]);
        // outputs to the terminal how many people can see in their seat assignments and their corresponding heights
        // analyze seats is a public void method from SpeakerView default constructor
    }
    catch (const std::exception& e) { // if something goes wrong
        std::cerr << "Error loading file... " << e.what() << endl;
        // print an error occurred and communicate what happened
        return 1; // end the program
    }

    cout << endl; // newline for neatness

    return 0; // ends the program when success

}