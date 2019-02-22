#ifndef UTILITY_H
#define UTILITY_H

// Standard template library include files.
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>

//using namespace std;

//My Includes
#include "Declarations.h"

using namespace std;

////////////////////
// Print Functions
////////////////////

void printEvent(Event* e);
string PrintOutput(string Output, string Color);

////////////////////
// Read Functions
////////////////////

void ReadEvent(Event *e);
unsigned char readUChar(std::ifstream& fin);
unsigned short readUShort(std::ifstream& fin);
unsigned int readUInt(std::ifstream& fin);
int readInt(std::ifstream& fin);
double readDouble(std::ifstream& fin);

////////////////////
// Other Functions
////////////////////

void ResetInStructs();
std::vector<std::vector<std::vector<float>>> CalculateAngles();
//vector<vector<vector<float>>> CalculateAngles();
void PrintHyperSort(string Color);


#endif
