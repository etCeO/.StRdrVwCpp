// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA3: Do You See What I See?

#include <iostream> // include input and output functions
#include <string> // include std::string
#include <fstream> // includes ifstream and ofstream
#include <sstream> // includes std::stringstream
#include "SpeakerView.h" // includes contents from header file
#include "MonoStack.h" // includes MonoStack class

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

SpeakerView::SpeakerView(){}; // default constructor

SpeakerView::~SpeakerView(){}; // default destructor

// PUBLIC METHOD

void SpeakerView::analyzeSeats(std::string inFileName) {
// a public void method for analyzing how many people can see the stage in each column in a txt file
// inFileName is the name of the txt to be read and processed

    std::ifstream inFile(inFileName); // declares a reader for inFileName
    std::string line; // a string for each line read

    if (inFile.is_open()) {
        // if the file is opened properly, continue the program

        int rowNum = -1; // number of total rows in the txt (count)
        // -1 for proper incrementing
        int colNum = 0; // a variable for keeping track of each column (count)

        while (std::getline(inFile, line)) {
        // for all lines in the file
            if (line == "BEGIN") {
                // if the line says BEGIN, reading has begun
                continue; // skip this line
            }
            else if (line == "END") {
                // if the line says END, reading has ended
                break; // break from the while loop
            }
            else {
            // if numbers are currently being read

                ++rowNum; // increment to indicate a new row exists

                if (colNum == 0) { // only reads columns once
                    std::stringstream ss(line); // create a stringstream for the numbers
                    double doubleNum; // doubleNum keeps track of all doubles that are read
                    while (ss >> doubleNum) {
                    // while there are seats to be read in the seat row
                        ++colNum; // increment to indicate a new column exists
                    }
                }
            }
        }
        inFile.clear(); // clears EOF flag
        inFile.seekg(0); // resets file cursor to the beginning
        double** seats = new double*[rowNum]; // a dynamic 2d array of doubles of size NxP is declared
        for (int n = 0; n < rowNum; n++) {
            seats[n] = new double[colNum];
        }
        int rowIndex = -1; // index for rows starts at 0
        // -1 for proper indexing when incremented
        while (std::getline(inFile, line)) {
        // for all lines in the file
            if (line == "BEGIN") {
                // if the line says BEGIN, reading has begun
                continue; // skip this line
            }
            else if (line == "END") {
                // if the line says END, reading has ended
                break; // break from the while loop
            }
            else {
            // if numbers are currently being read

                std::stringstream sstr(line); // create a stringstream for the numbers
                double lineDouble; // lineDouble is the double that is stored in the array
                int colIndex = 0; // starting index for columns

                while (sstr >> lineDouble) {
                // while there are column doubles to be read in the seat row
                    seats[rowIndex][colIndex] = lineDouble; // assigns each double to each array index in the 2d array
                    ++colIndex; // increment index to keep assigning
                }
                ++rowIndex; // increment rows to move to next row / line
            }
        }

        MonoStack ms_stacks[colNum];
        // declare an array of MonoStacks for each column
        // this array automatically calls the MonoStack default constructor (size 10 and decreasing)

        for (int x = rowNum - 1; x >= 0; x--) {
            // for each row in the stack array
            for (int y = colNum - 1; y >= 0; y--) {
                // for each column in the stack array
                ms_stacks[y].push(seats[x][y]);
                // push the double into the assigned stack
                // since there are stacks made for each column, index y should access each
            }
        }

        for (int j = 0; j < colNum; j++) {
            // for all columns existing
            cout << "In column " << j << " there are " << ms_stacks[j].getSize() << " that can see. Their heights are: ";
            // output the column # and its size, which presents how many people can see
            for (int i = ms_stacks[j].getSize() - 1; i >= 0; i--) {
                // for all elements in the stack
                if (i == 0) {
                    // if the element is the first element added
                    cout << ms_stacks[j].getCell(i) << " ";
                    // print the value with a space
                }
                else { // if the element is not first
                    cout << ms_stacks[j].getCell(i) << ", ";
                    // print the value with a comma to continue
                }
            }
            cout << "inches." << endl;
            // end the sentence and continue the program
            // output the results of each into the terminal
            // each stack is called by index j
            // j is also the current column number
        }
        for (int k = 0; k < rowNum; k++) {
            delete[] seats[k];
        }
        delete[] seats;
        // clear memory of dynamically allocated 2d array

        inFile.close(); // close reading 
    }
    else { // if there are problems opening the file, print so
        cout << "Error: Something went wrong when reading the file!" << endl;
    }

}