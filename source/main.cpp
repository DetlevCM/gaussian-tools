/*
 * main.cpp
 *
 *  Created on: 22 July 2015
 *      Author: DetlevCM
 */

#include<Headers.h>


// Not sure if I should consider the locale...
// http://stackoverflow.com/questions/15220861/how-can-i-set-the-comma-to-be-a-decimal-point

int main(int argc, char* argv[])
{
	string filename;
	string input;
	int type = 0;	// output type 0 = csv , 1 = txt (default)

	bool InputIsFilename = true;

	while(true) // loop until user quits
	{
		cout << "Please enter the filename - the ending may be included or omitted.\n";
		cout << "The filetype output can be changed by inputting 'csv' (default) or 'txt'. \n";

		vector< OptPoints > GaussianData;
		//GaussianData.clear();
		//cin >> input;
		getline(cin, input);

		if(strcmp(input.c_str(),"quit")==0) // user wants to quit
		{
			//EndProgram = true;
			return 0;
		}
		InputIsFilename = true;

		if(strcmp(input.c_str(),"csv")==0) // user wants csv, default
		{
			type = 0;
			InputIsFilename = false;
		}
		if(strcmp(input.c_str(),"txt")==0) // user wants csv, default
		{
			type = 1;
			InputIsFilename = false;
		}

		if(InputIsFilename)
		{
			string input_filename;
			filename = input;

			// check if file ending is included
			if (filename.find(".log")!=string::npos)
			{
				input_filename = filename;
			}
			else
			{
				input_filename = filename+".log";
			}

			//string input_filename = filename+".log";

			string output_filename;

			if(type==0)
			{
				output_filename = filename+".csv";
			}
			if(type==1)
			{
				output_filename = filename+".txt";
			}

			ifstream DataInputFile;
			DataInputFile.open(input_filename.c_str());


			if (DataInputFile.is_open()) {


				// check if scan or opt
				bool IsScan;
				IsScan = false;

				while(DataInputFile.good())
				{

					string line;
					getline(DataInputFile,line);

					size_t found = line.find("Scan");
					if(found!=string::npos)
					{
						IsScan = true;
					}

				}
				DataInputFile.close();

				if(IsScan == true)
				{
					Process_Scan_Data(GaussianData, input_filename.c_str());
				}
				else
				{
					Process_Opt_Data(GaussianData, input_filename.c_str());
				}



				// Now we can print the data, from 'GaussianData' and 'Atom_Pairs'
				//PrintOutput_Scan(GaussianData, Atom_Pairs, output_filename, type);
				if(GaussianData.size() > 0) // seems to fail if GaussianData is empty
				{


					// needs a "jagged array"
					// 2 atoms = distance, 3 atoms = valence angle, 4 atoms = dihedral
					vector< vector < int > > SelectedAtoms;

					/* Now we need to process the read in data to print
					 * the output the user desires:
					 */

					cout << "Enter the atom IDs to be investigated.\n";
					cout << "e.g. 1 2 'enter' for the distance\n";
					cout << "e.g. 1 2 3 'enter' for the valence angle on 2\n";
					cout << "e.g. 1 2 3 4 'enter' for the dihedral angle\n";
					cout << "Finish the input by submitting 'print'.\n";

					while(true)
					{
						/* struct OutPair {
						 * 	int Atom1;
						 * 	int Atom2;
						 * 	};
						 */

						getline(cin,input);

						if(strcmp(input.c_str(),"print")==0	|| strcmp(input.c_str(),"p")==0 ) // user wants to print output
						{
							break;
						}
						if(strcmp(input.c_str(),"quit")==0) // user wants to quit
						{
							cout << "Really close program?\n";
							getline(cin,input);
							if(strcmp(input.c_str(),"yes")==0) // user wants to quit
							{
								return 0;
							}
						}

						//OutPair AtomPair;
						char * cstr, *p;
						string str = input;
						vector< double > temp;

						cstr = new char [str.size()+1];
						strcpy (cstr, str.c_str());

						p=strtok (cstr," 	,;.:");
						while (p!=NULL)
						{
							temp.push_back(strtod(p,NULL));
							p=strtok(NULL," 	,;.:");
						}
						delete[] cstr;
						delete[] p;

						// strtod is 0 where no valid conversion is possible
						// Atom number is at least 1
						if( (int)temp.size() >= 2)// && (int)temp.size <= 3) // switch to 4 to enable dihedral
						{
							bool NoZeroEntry=true;
							int i;
							for(i=0;i<(int)temp.size();i++)
							{
								if(temp[i] == 0) // check all converted correctly, Gaussian starts atom counts at 1
								{
									NoZeroEntry = false;
								}
							}

							if(NoZeroEntry)
							{
								vector< int > AtomPicks;
								for(i=0;i<(int)temp.size();i++)
								{
									AtomPicks.push_back(temp[i]);
								}
								SelectedAtoms.push_back(AtomPicks);
								AtomPicks.clear();
							}
						}
					}


					if(IsScan)
					{
						PrintOutput_Scan(GaussianData, SelectedAtoms, output_filename, type);
					}
					else
					{
						PrintOutput_Opt(GaussianData, SelectedAtoms, output_filename, type);
					}
					GaussianData.clear();
				}
				else
				{
					cout << "Error reading in logfile - molecule definitions are empty.\n";
				}

			}
			else cout << "Unable to open input file\n";
		}
	}

	return 0;
}






