// add_gussian_noise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FileManager.h"

int main(int argc, char* argv[])
{
	FileManager * file_manager = new FileManager;
	PointSet *ps = new PointSet;
	std::cout << "********************************************************************" << endl;
	std::cout << "Read points file..." << endl;

	char input_filename[256];
	strcpy_s(input_filename, "Data\\");   //file location, 
	strcat_s(input_filename, "hand_original.pwn");  //file name, note that the inputfile should be a pwn(point with normal) file
    
	FILE* file;

	file = fopen(input_filename, "r");
	file_manager->setFile(file, input_filename, "pwn");
	file_manager->open(ps);
	fclose(file);
	
	std::cout << "file input finished!" << endl;
	std::cout << ps->point_N << " points input" << endl;

	ps->add_Noise_Pointset(0.1);  // add noise level;

	std::cout << "output point cloud " << endl;

	char output_filename[256];
	strcpy(output_filename, "Data\\");
	strcat(output_filename, "hand_original.xyz");
	file = fopen(output_filename, "w");

	for (int i = 0; i < ps->point_N; i++)
	{
		float *point = ps->point[i];
		fprintf(file, "%f %f %f\n", point[0], point[1], point[2]);
	}
	fclose(file);

	std::cout << "output point cloud finished" << endl;
    return 0;
}

