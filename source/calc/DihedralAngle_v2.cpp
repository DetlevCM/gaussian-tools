/*
 * DihedralAngle_v2.cpp
 *
 *  Created on: 19.12.2015
 *      Author: DetlevCM
 */



#include<Headers.h>


double DihedralAngle_v2(vector< AtomDefinition > Molecule, int atom1, int atom2, int atom3, int atom4)
{
	// http://mathworld.wolfram.com/DihedralAngle.html
	// http://math.stackexchange.com/questions/137538/calculate-the-vector-normal-to-the-plane-by-given-points
	double DihedralAngle;


	vector< double > v1(3);
	v1[0] = Molecule[atom1].X - Molecule[atom2].X;
	v1[1] = Molecule[atom1].Y - Molecule[atom2].Y;
	v1[2] = Molecule[atom1].Z - Molecule[atom2].Z;


	vector< double > v_rot(3);
	v_rot[0] = Molecule[atom2].X - Molecule[atom3].X;
	v_rot[1] = Molecule[atom2].Y - Molecule[atom3].Y;
	v_rot[2] = Molecule[atom2].Z - Molecule[atom3].Z;


	vector< double > v2(3);
	v2[0] = Molecule[atom3].X - Molecule[atom4].X;
	v2[1] = Molecule[atom3].Y - Molecule[atom4].Y;
	v2[2] = Molecule[atom3].Z - Molecule[atom4].Z;


	vector < double > nor_p1(3);
	nor_p1[0] =  v1[1]*v_rot[2] - v1[2]*v_rot[1];
	nor_p1[1] = -v1[0]*v_rot[2] + v1[2]*v_rot[0];
	nor_p1[2] =  v1[0]*v_rot[1] - v1[1]*v_rot[0];


	vector < double > nor_p2(3);
	nor_p2[0] =  v_rot[1]*v2[2] - v_rot[2]*v2[1];
	nor_p2[1] = -v_rot[0]*v2[2] + v_rot[2]*v2[0];
	nor_p2[2] =  v_rot[0]*v2[1] - v_rot[1]*v2[0];

	// http://math.stackexchange.com/questions/47059/how-do-i-calculate-a-dihedral-angle-given-cartesian-coordinates
	// cross product v_rot nor_p1


	double dot_n1_n2;
	dot_n1_n2 = nor_p1[0]*nor_p2[0] + nor_p1[1]*nor_p2[1] + nor_p1[2]*nor_p2[2];


	double mag_n1, mag_n2;
	mag_n1 =  sqrt(nor_p1[0]*nor_p1[0] + nor_p1[1]*nor_p1[1] + nor_p1[2]*nor_p1[2]);
	mag_n2 =  sqrt(nor_p2[0]*nor_p2[0] + nor_p2[1]*nor_p2[1] + nor_p2[2]*nor_p2[2]);


	double v1_dot_n2;
	v1_dot_n2 = v1[0]*nor_p2[0] + v1[1]*nor_p2[1] + v1[2]*nor_p2[2];

	//double v1_dot_n2_x_mag_v_rot; <- |n1||n2|sin phi
	double mag_v_rot;
	mag_v_rot = sqrt(v_rot[0]*v_rot[0] + v_rot[1]*v_rot[1] + v_rot[2]*v_rot[2]);


	double Pi = 3.1415926535897; // no constant apparently, quick google...
	double cos_phi;
	double sin_phi;

	cos_phi = dot_n1_n2 / (mag_n1 * mag_n2);
	sin_phi = (mag_v_rot * v1_dot_n2) / (mag_n1 * mag_n2);


	DihedralAngle =  -atan2(sin_phi,cos_phi)*180/Pi;

	return DihedralAngle;
}
