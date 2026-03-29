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
The seats where people’s views are obstructed

Example Execution

- ./see Seats.txt

Example Output (conceptual):
- In column 1 there are 2 that can see. Their heights are: 92.5, 121.2.
