// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA3: Do You See What I See?

#ifndef MONOSTACK_H // instantiates class once
#define MONOSTACK_H // defines MonoStack class

#include <iostream> // includes input and output functions
#include <string> // includes std::string

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

class MonoStack{ // class body

    private: // private variables and methods
        int size; // size of the stack
        char stackDir; // direction of stack's order
        double* stack; // array of doubles (a stack)
        int count; // number of items currently in the stack
        int top; // index of the current top of the stack

    public: // public constructors, destructors, and methods
        MonoStack(); // default constructor
        MonoStack(int sz, char stkDir); // overloaded constructor
        // monostack takes in the size of a seated column and a direction from the front to the back
        ~MonoStack(); // default destructor
        void push(double d); // add to the top
        int getSize(); // how many elements in the stack
        double getCell(int idx); // returns a double in a requested position in the stack
        double pop(); // remove from the top
        double peek(); // return the top without removing
        bool isFull(); // checks if the stack is full
        bool isEmpty(); // checks if the stack is empty
        
};

#endif // finishes defining the class