/*
 * Structs.h
 *
 *  Created on: 19.12.2015
 *      Author: DetlevCM
 */

#ifndef HEADERS_STRUCTS_H_
#define HEADERS_STRUCTS_H_

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
	double Energy;
	vector< AtomDefinition > Molecule;
};

struct OutPair {
	int Atom1;
	int Atom2;
};




#endif /* HEADERS_STRUCTS_H_ */
