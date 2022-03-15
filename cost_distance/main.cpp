/*
 * main.cpp
 * Author: Ulises Olivares
 * uolivares@unam.mx
 * June 12, 2020
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "raster.h"

using namespace std;

// Object definition import GIS raster
Raster objRaster;

int main(int argc, const char** argv){

	// Import friction and localities
    cout << "-------------------------------------------------------"<< endl;
    cout << "Importing data ...  " << endl;

    // Modify this path to convinence
   string frictionMap = "input/fricc_small.tif";
   string locsMap = "input/locs_small.tif"
	

	clock_t begin = clock();// start timer

	// Import input maps
	float **friction = objRaster.importRaster(frictionMap, true);

	float **locs = objRaster.imp;

    // TODO: store each locality in a structure, each locality is denoted by an ID in the matrix.
    
    // Code the CD function
    // Calculate 



	clock_t end = clock();

    int rows = objRaster.getRows();
	int cols = objRaster.getCols();

	cout << "Map importation sucessful!, Raster with " << rows <<" rows and " << cols << " cols " << endl;  
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Total importation time: " << elapsed_secs << " secs." << endl;
    cout << "-------------------------------------------------------"<< endl;
}
