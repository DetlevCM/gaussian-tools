/*
 * Normalize_Vector.cpp
 *
 *  Created on: 19.12.2015
 *      Author: DetlevCM
 */


#include<Headers.h>

vector< double > Normalize_Vector(vector< double > input)
		{
	double max = 0;
	int i;

	for(i=0;i<(int)input.size();i++)
	{
		if(fabs(input[i]) > fabs(max))
		{
			max = input[i];
		}
	}

	if(max == 0) // just in case, don't want division by zero
	{
		max = 1;
	}

	vector< double > output((int)input.size()); // using size defined vectors is faster

	for(i=0;i<(int)input.size();i++)
	{
		output[i] = input[i]/max;
	}


	return output;
}
