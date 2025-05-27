// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA3: Do You See What I See?

#include <iostream> // input and output functions
#include <string> // includes std::string
#include "MonoStack.h" // includes contents from header class

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

// CONSTRUCTORS AND DESTRUCTORS

MonoStack::MonoStack(){
    // default constructor
    size = 10; // default size 10
    stackDir = 'd'; // default decreasing
    stack = new double[size]; // declares stack with size size
    count = 0; // defaults to 0 when empty
    top = -1; // starts at -1 and increments when each double is added
    // top is an index of the stack
}

MonoStack::MonoStack(int sz, char stkDir) {
// overloaded constructor
// sz is an input for the stack;s size and stkDir is the orientation (increasing or decreasing)
    size = sz; // assigns size to the parameter
    stackDir = stkDir; // character for the direction of the stack
    stack = new double[size]; // declares stack of size sz
    count = 0; // defaults to 0 when empty
    top = -1; // starts at -1 and increments when each double is added
    // top is an index of the stack
}

MonoStack::~MonoStack(){
// default destructor
    delete[] stack; // clears array
}

// PUBLIC METHODS

bool MonoStack::isFull(){
// public bool method for checking if a stack is full
    return (count == size); // if the count of elements reaches the size, then the array is full
}

bool MonoStack::isEmpty(){
// public bool method for checking if a stack is empty
    return (count == 0);
    // if the count is still 0, the stack is empty
}

double MonoStack::pop(){
// public double method for removing and returning a double from the top of the stack
    // remove from the top
    // check the stack is not currently empty
    if (isEmpty()) {
        // if the stack is empty, print an error
        // do not pop
        cout << "ERROR: STACK IS CURRENTLY EMPTY!!!!" << endl;
        return 1.0; // return 1 as default
    }
    else { // if the stack is not empty
        --count; // remove one from count
        return stack[top--];
    }
}

double MonoStack::peek(){
// public double method for getting the top number of the stack
    // if stack is empty, this is a seg fault
    if (isEmpty()) {
        // if the stack is empty, print an error
        // do not peek
        cout << "ERROR: STACK IS CURRENTLY EMPTY!!!!" << endl;
        return 1.0; // return 1 as default
    }
    else { // if the stack is not empty
        return stack[top]; // return the current top
    }
}

int MonoStack::getSize(){
// a public int method for returning a stack's size
    return count; // count records how many elements are inside the stack
}

void MonoStack::push(double d){
// a public void method for pushing a number into a stack
// double d is the number to be added
    if (isFull()) {
        // if the stack is full, resize by doubling
        double* temp = new double[2*size];
        for(int i = 0; i < size; ++i){
            temp[i] = stack[i];
        }
        size *= 2;
        delete[] stack;
        stack = temp;
        stack[++top] = d; // push element d into the next index of the stack
        ++count; // increment the count
    }
    else if (isEmpty()) {
        // if the stack is empty
        stack[++top] = d; // push element d into the next index of the stack
        ++count; // increment the count
    }
    else { // if the stack is not full
        if (stackDir == 'i') {
            // if the orientation of the stack is ascending
            if (d > peek()) {
                // if the next input is larger than the previous
                stack[++top] = d; // push element d into the next index of the stack
                ++count; // increment the count
            }
            else { // if the stack's next value is not larger than the previous
                while (!isEmpty() && d <= peek()) {
                    // while the array is not empty and there are values that are less than or equal to the previous
                    pop(); // pop these values in the stack before pushing
                }
                stack[++top] = d; // push element d into the next index of the stack
                ++count; // increment the count
            }
        }
        else if (stackDir == 'd') {
            // if the orientation of the stack is descending
            if (d < peek()) {
                // if the next input is less than the previous
                stack[++top] = d; // push element d into the next index of the stack
                ++count; // increment the count
            }
            else { // if the stack's next value is not smaller than the previous
                while (!isEmpty() && d >= peek()) {
                    // while the array is not empty and there are values that are greater than or equal to the previous
                    pop(); // pop these values in the stack before pushing
                }
                stack[++top] = d; // push element d into the next index of the stack
                ++count; // increment the count
            }
        }
    }
}

double MonoStack::getCell(int idx) {
// a public double method that returns an element from a specific position in the stack
// int idx is the element's index
    return stack[idx]; 
}