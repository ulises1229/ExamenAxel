//
// Ulises Olivares
// uolivares@unam.mx
// June 13, 2020.
//

#ifndef SRC_RASTER_H
#define SRC_RASTER_H

#endif //SRC_RASTER_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include "gdal/gdal.h"
#include "gdal/gdal_priv.h"
#include "gdal/ogr_spatialref.h"

using namespace std;
//using namespace cv;
//using namespace cv::ml;




class Raster{
public:

   
    float** importRaster(string file);
    double adfGeoTransform[6];
    void exportTiff(string path, float** output_raster, int rows, int cols);

    // Get methods
    int getCols();
    int getRows();
    



private:
    int ROWS, COLS, noDataValue;
    float **input;


};
