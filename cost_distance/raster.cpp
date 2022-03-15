
// Ulises Olivares
// uolivares@unam.mx
// June 13, 2020.

#include "raster.h"

float** Raster::importRaster(string file) {
        int scale, m, n;
        cout << "Reading tiff ..." << endl;
        GDALDataset *dataset;
        char **MD;
        char *info;
        GDALAllRegister();
        string ds = file;
        dataset = (GDALDataset *) GDALOpen(ds.c_str(), GA_ReadOnly);
        GDALRasterBand  *poBand;

        poBand = dataset->GetRasterBand(1);
        dataset->GetGeoTransform( adfGeoTransform );

        int nXSize = poBand->GetXSize();
        int nYSize = poBand->GetYSize();
        scale = adfGeoTransform[1];

        m = nYSize;
        n = nXSize;

        dataset->GetGeoTransform( adfGeoTransform );
        scale = adfGeoTransform[1];
        noDataValue = poBand->GetNoDataValue();  //read null value of cell

        ROWS = nYSize; COLS = nXSize;
        input = new float*[ROWS];
        for(int i = 0; i< ROWS; ++i) {
            input[i] = new float[COLS];
        }

        //GDALDataType dataType = poBand->GetRasterDataType();
        float *pBuf = new float[nYSize * nXSize];

        poBand->RasterIO(GF_Read, 0, 0, nXSize, nYSize, pBuf, nXSize, nYSize, GDT_Float32, 0, 0);

        int location;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++)
            {
                location = (nXSize * (i)) + j;
                input[i][j] = *(pBuf+location);
            }
        }

        return input;
}

void exportTiff(string path, float** output_raster, int rows, int cols) {
    cout << "Writing tiff ..." << endl;
    GDALDataset *poDstDS;
    //char **papszOptions = NULL;
    GDALDriver *poDriver;
    OGRSpatialReference oSRS;
    string fileName = "cost_distance_output_" + ".tiff";
    string proyeccion = "EPSG:" + epsg;
    poDriver = GetGDALDriverManager()->GetDriverByName("Gtiff");
    poDstDS = poDriver->Create( fileName.c_str(), cols, rows, 1, GDT_Float32, NULL);
    poDstDS->SetGeoTransform(adfGeoTransform);
    oSRS.SetWellKnownGeogCS(proyeccion.c_str());
    GDALRasterBand *poBand;
    float *pBuf = new float[rows * cols];
    poBand = poDstDS->GetRasterBand(1);
    poDstDS->GetRasterBand(1)->SetNoDataValue(-9999);
    poBand->RasterIO( GF_Write, 0, 0, cols, rows,
                      pBuf, cols, rows, GDT_Float32, 0, 0 );
    GDALClose( (GDALDatasetH) poDstDS );

}


// Get methods
int Raster::getCols(){
    return COLS;
}

int Raster::getRows(){
    return ROWS;
}
