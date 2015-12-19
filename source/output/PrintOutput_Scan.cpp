/*
 * Print_Output_Scan_v2.cpp
 *
 *  Created on: 23.07.2015
 *      Author: DetlevCM
 */

#include<Headers.h>


void PrintOutput_Scan(
		vector< OptPoints >& GaussianData ,
		vector< vector< int > >& Selected_Atoms,
		string output_filename,
		int type
)
{
	ofstream DataOutputFile(output_filename.c_str(),ios::out);

	if (DataOutputFile.is_open())
	{
		// How many atom pairs are to be investigated
		int GaussianDataSize = GaussianData.size();
		int NumberOfPairs = Selected_Atoms.size();
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
		//DataOutputFile << "Nr." << Separator;
		DataOutputFile << "Nr." << Separator << "Energy" << Separator;
		for(i=0;i<NumberOfPairs;i++)
		{
			if((int) Selected_Atoms[i].size() == 2) // distance
			{
				//DataOutputFile << "Distance " << Selected_Atoms[i][0] << "-" << Selected_Atoms[i][1] << Separator;
				DataOutputFile << "Dis-" << Selected_Atoms[i][0] << "-" << Selected_Atoms[i][1] << "" << Separator;
			}
			if((int) Selected_Atoms[i].size() == 3) // valence angle
			{
				//DataOutputFile << "Angle " << Selected_Atoms[i][0] << "-" << Selected_Atoms[i][1] << "-" << Selected_Atoms[i][2]  << Separator;
				DataOutputFile << "Val-" << Selected_Atoms[i][0] << "-" << Selected_Atoms[i][1] << "-" << Selected_Atoms[i][2]  << "" << Separator;
			}
			if((int) Selected_Atoms[i].size() == 4) // dihedral angle (to do)
			{
				//DataOutputFile << "Dihedral " << Selected_Atoms[i][0] << "-" << Selected_Atoms[i][1]  << "-" << Selected_Atoms[i][2]  << "-" << Selected_Atoms[i][3] << Separator;
				DataOutputFile << "Dih-" << Selected_Atoms[i][0] << "-" << Selected_Atoms[i][1]  << "-" << Selected_Atoms[i][2]  << "-" << Selected_Atoms[i][3] << "" << Separator;
			}
		}
		DataOutputFile << "\n";


		// Now lets look at writing the data
		for(j=0;j< GaussianDataSize - 1;j++)
		{
			// need to identify the final steps to be printed from the dataset, then they can be printed
			if(GaussianData[j+1].ScanStep == 1) // next step in optimisation is 1, so previous must be optimised
			{
				//DataOutputFile << k << Separator;
				DataOutputFile << k << Separator << std::setprecision(15) << GaussianData[j].Energy << std::setprecision(6) << Separator;

				for(i=0;i<NumberOfPairs;i++)
				{
					if((int) Selected_Atoms[i].size() == 2) // distance
					{
						int atom1 = Selected_Atoms[i][0] - 1;
						int atom2 = Selected_Atoms[i][1] - 1;

						// 3D Pythagoras
						if(	(int) GaussianData[j].Molecule.size() + 1 >= atom1 &&
								(int) GaussianData[j].Molecule.size() + 1 >= atom2)
						{
							DataOutputFile << Pythagoras3D(GaussianData[j].Molecule, atom1, atom2) << Separator;
						}
					}
					if((int) Selected_Atoms[i].size() == 3) // valence angle
					{
						int atom1 = Selected_Atoms[i][0] - 1;
						int atom2 = Selected_Atoms[i][1] - 1;
						int atom3 = Selected_Atoms[i][2] - 1;

						if(	(int) GaussianData[j].Molecule.size() + 1 >= atom1 &&
								(int) GaussianData[j].Molecule.size() + 1 >= atom2 &&
								(int) GaussianData[j].Molecule.size() + 1 >= atom3)
						{
							DataOutputFile << ValenceAngle(GaussianData[j].Molecule, atom1, atom2, atom3) << Separator;
						}
					}
					if((int) Selected_Atoms[i].size() == 4) // dihedral angle (to do)
					{
						int atom1 = Selected_Atoms[i][0] - 1;
						int atom2 = Selected_Atoms[i][1] - 1;
						int atom3 = Selected_Atoms[i][2] - 1;
						int atom4 = Selected_Atoms[i][3] - 1;


						if(	(int) GaussianData[j].Molecule.size() + 1 >= atom1 &&
								(int) GaussianData[j].Molecule.size() + 1 >= atom2 &&
								(int) GaussianData[j].Molecule.size() + 1 >= atom3 &&
								(int) GaussianData[j].Molecule.size() + 1 >= atom4)
						{
							//DataOutputFile << DihedralAngle_v1(GaussianData[j].Molecule, atom1, atom2, atom3, atom4) << Separator;
							DataOutputFile << DihedralAngle_v2(GaussianData[j].Molecule, atom1, atom2, atom3, atom4) << Separator;
						}
					}
				}
				DataOutputFile << "\n";
				k = k + 1;
			}
		}



		// the final & last entry, no matter whether the run succeeded or not:
		//DataOutputFile << k << Separator;
		DataOutputFile << k << Separator << std::setprecision(15) << GaussianData[j].Energy << std::setprecision(6) << Separator;
		for(i=0;i<NumberOfPairs;i++)
		{
			if((int) Selected_Atoms[i].size() == 2) // distance
			{
				int atom1 = Selected_Atoms[i][0] - 1;
				int atom2 = Selected_Atoms[i][1] - 1;

				// 3D Pythagoras
				if(	(int) GaussianData[j].Molecule.size() + 1 >= atom1 &&
						(int) GaussianData[j].Molecule.size() + 1 >= atom2)
				{
					DataOutputFile << Pythagoras3D(GaussianData[j].Molecule, atom1, atom2) << Separator;
				}
			}
			if((int) Selected_Atoms[i].size() == 3) // valence angle
			{
				int atom1 = Selected_Atoms[i][0] - 1;
				int atom2 = Selected_Atoms[i][1] - 1;
				int atom3 = Selected_Atoms[i][2] - 1;

				if(	(int) GaussianData[j].Molecule.size() + 1 >= atom1 &&
						(int) GaussianData[j].Molecule.size() + 1 >= atom2 &&
						(int) GaussianData[j].Molecule.size() + 1 >= atom3)
				{
					DataOutputFile << ValenceAngle(GaussianData[j].Molecule, atom1, atom2, atom3) << Separator;
				}
			}
			if((int) Selected_Atoms[i].size() == 4) // dihedral angle (to do)
			{
				int atom1 = Selected_Atoms[i][0] - 1;
				int atom2 = Selected_Atoms[i][1] - 1;
				int atom3 = Selected_Atoms[i][2] - 1;
				int atom4 = Selected_Atoms[i][3] - 1;


				if(	(int) GaussianData[j].Molecule.size() + 1 >= atom1 &&
						(int) GaussianData[j].Molecule.size() + 1 >= atom2 &&
						(int) GaussianData[j].Molecule.size() + 1 >= atom3 &&
						(int) GaussianData[j].Molecule.size() + 1 >= atom4)
				{
					//DataOutputFile << DihedralAngle_v1(GaussianData[j].Molecule, atom1, atom2, atom3, atom4) << Separator;
					DataOutputFile << DihedralAngle_v2(GaussianData[j].Molecule, atom1, atom2, atom3, atom4) << Separator;
				}
			}
		}
		DataOutputFile << "\n";

		// close at the end which also flushes the buffer
		DataOutputFile.close();
	}
	else cout << "Unable to open output file";


}




