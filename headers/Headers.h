/*
 * Header.h
 *
 *  Created on: 22.07.2015
 *      Author: DetlevCM
 */

#ifndef HEADERS_HEADERS_H_
#define HEADERS_HEADERS_H_




// Fiel Streams and IO
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <fstream>


// For strtod -> string to double
#include <stdlib.h>

// Math Operations
#include <cmath>

// To get the CPU time
#include <time.h>

// For Vectors
#include <vector>

// For strings, C strings right now...
//#include <cstring>
#include<string.h>

//using namespace std;

using std::cout;
using std::cin;

using std::vector;
using std::string;

using std::ofstream;
//using std::iostream;
//using std::fstream;
using std::ifstream;
using std::ios;



// quick short progarm to parse the xml output from the PetroOxy into
// a more handy output format


struct AtomDefinition {
	int CenterID;
	int AtomNumber;
	int AtomType;
	double X;
	double Y;
	double Z;
};


struct OptPoints {
	int ScanStep;
	int OptStep;
	int OptStepMax;
	vector< AtomDefinition > Molecule;
};

struct OutPair {
	int Atom1;
	int Atom2;
};


void ProcessFile(vector< OptPoints >&, ifstream&);

void PrintOutput_Scan(
		vector< OptPoints >&,
		vector< OutPair>&,
		//ofstream&,
		string,
		int
);

double Pythagoras3D (vector< AtomDefinition > , int , int );

#endif /* HEADERS_HEADERS_H_ */


