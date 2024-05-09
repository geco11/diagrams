#pragma warning (disable:4996)
#include"DownloadFromFile.h"
#include"vector"
std::vector<double> vectorFromFile(const char* path){
    FILE* myPath;
    std::vector<double> data;
    myPath=fopen(path,"r");
    double d;
    while (fscanf(myPath,"%lf",&d) > 0) {
        data.push_back(d);
    }
    fclose(myPath);
    return data;
}