#include "io_general.h"

std::vector<std::vector<int>> loadGraph(std::string fname){
    int dim;
    std::ifstream ifs(fname.c_str(), std::ifstream::in);
    ifs >> dim;
    std::vector<std::vector<int>> matrix(dim, std::vector<int>(dim));
    for (int i = 0; i < dim; i ++) {
        for (int j = 0; j < dim; j ++){
            int x;
            ifs >> x;
            matrix[i][j] = x;
        }
    }
    return matrix;
}