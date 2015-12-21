/*
 * Handle_Filenames.cpp
 *
 *  Created on: 21.12.2015
 *      Author: DetlevCM
 */


#include<Headers.h>

void Handle_Filenames(string& input_filename, int output_type, string& output_filename)
{
	// check if file ending is included, add it if not included
	if (input_filename.find(".log")==string::npos)
	{
		input_filename = input_filename + ".log";
	}

	// We have ensured that logfile ending is present, so we can remove it to add the output ending
	string filename = input_filename;
	filename = input_filename.substr(0,input_filename.length()-4);

	if(output_type==0)
	{
		output_filename = filename + ".csv";
	}
	if(output_type==1)
	{
		output_filename = filename + ".txt";
	}
}
