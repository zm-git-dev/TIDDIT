/*
 * RunModules.h
 *
 *  Created on: Jul 1, 2015
 *      Author: vezzi, Eisfeldt
 */
//This header files contains the main functions of each program/run module of the find translocations software

#ifndef PROGRAMMODULES_H_
#define PROGRAMMODULES_H_

#include "common.h"
#include <list>

//The extraction module
class Extract{
public:
	//Constructor
	Extract();
	//Main function
	void extract(string BamFileName,string outputFileHeader,string inputFileName,map<string,unsigned int> contig2position, string indexFile,int BedOrVCF, int exclusion);
};

//The module used to find structural variants
class StructuralVariations{
public:
	//constructor
	StructuralVariations();
	//main function
	void findTranslocationsOnTheFly(string bamFileName, bool outtie, float meanCoverage,string outputFileHeader, map<string,int> SV_options);
};

//This class contains functions used to recognize and read vcf and bed files
class VcfBedInput{
public:
	//constructor
	VcfBedInput();
	//main function accepts a bed or vcf file, stores the regions and return them as a vector of queue of int
	queue<string> findRegions(string inputFileName,int selection);
	//reads vcf generated by FindTranslocations files and returns the regions
	queue<string> readVCF(string inputFileName);
	//reads bed files and returns the regions o the file
	queue<string> readBed(string inputFileName);

};

#endif /* PROGRAMMODULES_H_ */
