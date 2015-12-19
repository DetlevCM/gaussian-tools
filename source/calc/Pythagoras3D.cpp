/*
 * Pythagoras3D.cpp
 *
 *  Created on: 19.12.2015
 *      Author: DetlevCM
 */

#include<Headers.h>

double Pythagoras3D (vector< AtomDefinition > Molecule, int atom1, int atom2)
{
	double Distance;

	double DistanceSquared =
			(Molecule[atom1].X - Molecule[atom2].X)*(Molecule[atom1].X - Molecule[atom2].X)
			+
			(Molecule[atom1].Y - Molecule[atom2].Y)*(Molecule[atom1].Y - Molecule[atom2].Y)
			+
			(Molecule[atom1].Z - Molecule[atom2].Z)*(Molecule[atom1].Z - Molecule[atom2].Z)
			;

	Distance = sqrt(DistanceSquared);

	return Distance;
}
