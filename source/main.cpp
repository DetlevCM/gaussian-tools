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
	int type = 1;	// output type 0 = csv , 1 = txt (default)

	bool InputIsFilename = true;

	while(true) // loop until user quits
	{
		cout << "Please enter the filename - the ending may be included or omitted.\n";
		cout << "The filetype output can be changed by inputting 'csv' or 'txt' (default). \n";

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

				ProcessFile(GaussianData, DataInputFile);
				DataInputFile.close();

				vector< OutPair > Atom_Pairs;

				/* Now we need to process the read in data to print
				 * the output the user desires:
				 */

				cout << "Enter the atom bonds that are desired in pairs.\n";
				cout << "e.g. 1 2 'enter'\n";
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

					OutPair AtomPair;
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
					if( (int) temp.size() == 2)
					{
						if(temp[0] != 0 && temp[1] != 0)
						{
							AtomPair.Atom1 = temp[0];
							AtomPair.Atom2 = temp[1];
							Atom_Pairs.push_back(AtomPair);
						}
					}
				}


				// Now we can print the data, from 'GaussianData' and 'Atom_Pairs'
				PrintOutput_Scan(GaussianData, Atom_Pairs, output_filename, type);


				// Housekeeping, clear the vectors for rerun
				Atom_Pairs.clear();
				GaussianData.clear();


			}
			else cout << "Unable to open input file\n";
		}
	}

	return 0;
}






