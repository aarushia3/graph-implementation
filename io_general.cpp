#include "io_general.h"

std::vector<std::vector<int>> loadGraph(std::string fname){
    int dim;
    std::ifstream ifs(fname.c_str(), std::ifstream::in);
    ifs >> dim;
}