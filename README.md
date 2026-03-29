# Seat Reader View
### Do You See What I See?

- A program that processes a text-based seating chart to evaluate sightline accessibility, analyzing attendee placement and individual heights (in inches) to determine whether any participants have obstructed views of the front stage.

## Author Info

- Full Name: Ethan E. Lopez
- Chapman Email: etlopez@chapman.edu

## Source Files

- Main.cpp
- SpeakerView.cpp
- SpeakerView.h
- MonoStack.cpp
- MonoStack.h
- Seats.txt

## Errors
- N/A

## Instructions For Running
- To compile: g++ *.cpp -o see.exe
- To run: ./see Seats.txt
- Note: "Seats.txt" may be replaced with any .txt file that contains doubles for row and column inputs

## Usage

This program checks if people in a seating configuration have a view of the stage based on the heights of the people in front of them.

### What The Program Does
---

1. Reads in a seating configuration from an input file
2. Treats this configuration as a grid representing heights
3. For every column (i.e., every direction to look at the stage):
  - Checks if someone’s view is obstructed because someone in front of them is taller

### Output
---
The seats where people's views are not obstructed

Example Execution

- ./see Seats.txt

Example Output (conceptual):
- In column 1 there are 2 that can see. Their heights are: 92.5, 121.2.

## Input Format

The input file is a seating chart represented as a grid of heights.

#### Expected Structure

- BEGIN
- 81.4 121.4 50.2 75.3 75.1
- 90.0 90.5 80.2 60.3 50.2
- 80.8 80.3 90.7 89.9 94.7
- 82.2 72.1 92.6 54.4 95.1
- END

#### Rules

1. Each number represents the height of a person in a seat.
2. The seats are ordered from front to back. So, row 0 is the closest to the stage.
3. A seat is blocked if there is a taller or equal height person sitting directly in front.

## Implementation Details

### Core Concept: Monotonic Stack
---

The code employs a monotonic stack data structure to facilitate fast computation of visibility in every column.
- A monotonic stack is a data structure where elements are stored in a particular order (in this case, heights in descending order).

As we progress through every column:

1. It compares heights with those in front
2. Removes those in front that do not block those behind
3. Detects when a person in front blocks the current seat

### Algorithm Overview
---

For every column:
1. Create an empty monotonic stack data structure
2. Process every row from front to back

For every seat:

While stack is not empty and current height is greater than top:
  - Pop stack (people in front do not block those behind)
  - If stack is not empty after popping:
    - The current seat is blocked
  - Push current height onto stack

### Data Structures Used
---

- 2D Array: Used to represent seating chart
- Monotonic Stack (MonoStack):

Provides methods to:
1. Push onto stack
2. Pop off stack
3. Peek top element on stack
4. Check if stack is empty
