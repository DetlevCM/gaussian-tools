/*
 * ValenceAngle.cpp
 *
 *  Created on: 19.12.2015
 *      Author: DetlevCM
 */


#include<Headers.h>

double ValenceAngle(vector< AtomDefinition > Molecule, int atom1, int atom2, int atom3)
{
	// http://mathworld.wolfram.com/SSSTheorem.html
	double ValenceAngle;

	// Needs Pythagoras 3D...
	// In triangle ABC, with sides abc, cos (beta) = (a^2 + c^2 -b^2)/(2ac)
	// atom1 = A, atom2 = B, atom3 = C

	double a = Pythagoras3D(Molecule, atom2, atom3);
	double b = Pythagoras3D(Molecule, atom3, atom1);
	double c = Pythagoras3D(Molecule, atom1, atom2);

	double temp = (a*a + c*c - b*b)/(2*a*c);

	double Pi = 3.1415926535897; // no constant apparently, quick google...
	ValenceAngle = acos(temp)*180/Pi;

	//cout << ValenceAngle;

	return ValenceAngle;
}
