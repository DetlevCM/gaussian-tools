/*
 * Calc.h
 *
 *  Created on: 19.12.2015
 *      Author: DetlevCM
 */

#ifndef HEADERS_CALC_H_
#define HEADERS_CALC_H_


vector< double > Normalize_Vector(
		vector< double >
);

double Pythagoras3D (
		vector< AtomDefinition > ,
		int , int
);

double ValenceAngle(
		vector< AtomDefinition > ,
		int , int , int
);

double DihedralAngle_v1(
		vector< AtomDefinition > ,
		int , int , int , int
);

double DihedralAngle_v2(
		vector< AtomDefinition > ,
		int , int , int , int
);




#endif /* HEADERS_CALC_H_ */
