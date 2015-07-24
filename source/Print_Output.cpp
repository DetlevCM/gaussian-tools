/*
 * Print_Output.cpp
 *
 *  Created on: 23.07.2015
 *      Author: DetlevCM
 */

#include<Headers.h>


void PrintOutput_Scan(
		vector< OptPoints >& GaussianData ,
		vector< OutPair>& Atom_Pairs,
		//ofstream& DataOutputFile,
		string output_filename,
		int type
		)
{
	ofstream DataOutputFile(output_filename.c_str(),ios::out);

	if (DataOutputFile.is_open())
	{
		// How many atom pairs are to be investigated
		int GaussianDataSize = GaussianData.size();
		int NumberOfPairs = Atom_Pairs.size();
		int i, j, k=1;
		string Separator = "";

		if(type == 0)
		{
			Separator = ","; // comma
		}
		if(type == 1)
		{
			Separator = "	"; // tab
		}


		// Write Header
		DataOutputFile << "Nr." << Separator;
		for(i=0;i<NumberOfPairs;i++)
		{
			DataOutputFile << "Atom " << Atom_Pairs[i].Atom1 << " to " << Atom_Pairs[i].Atom2 << Separator;
		}
		DataOutputFile << "\n";


		// Now lets look at writing the data
		for(j=0;j< GaussianDataSize - 1;j++)
		{
			// need to identify the final steps to be printed from the dataset, then they can be printed
			if(GaussianData[j+1].ScanStep == 1) // next step in optimisation is 1, so previous must be optimised
			{
				DataOutputFile << k << Separator;

				for(i=0;i<NumberOfPairs;i++)
				{
					int atom1 = Atom_Pairs[i].Atom1 - 1;
					int atom2 = Atom_Pairs[i].Atom2 - 1;

					// 3D Pythagoras
					if(	(int) GaussianData[j].Molecule.size() + 1 >= atom1 &&	(int) GaussianData[j].Molecule.size() + 1 >= atom2)
					{
						DataOutputFile << Pythagoras3D(GaussianData[j].Molecule, atom1, atom2) << Separator;
					}
				}
				DataOutputFile << "\n";
				k = k + 1;
			}
		}


		// the final & last entry, no matter whether the run succeeded or not:
		DataOutputFile << k << Separator;
		for(i=0;i<NumberOfPairs;i++)
		{
			int atom1 = Atom_Pairs[i].Atom1 - 1;
			int atom2 = Atom_Pairs[i].Atom2 - 1;

			// 3D Pythagoras
			if(	(int) GaussianData[GaussianDataSize-1].Molecule.size() + 1 >= atom1 &&	(int) GaussianData[GaussianDataSize-1].Molecule.size() + 1 >= atom2)
			{
				DataOutputFile << Pythagoras3D(GaussianData[GaussianDataSize-1].Molecule, atom1, atom2) << Separator;
			}
		}
		DataOutputFile << "\n";

		// close at the end which also flushes the buffer
		DataOutputFile.close();
	}
	else cout << "Unable to open output file";


}



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

