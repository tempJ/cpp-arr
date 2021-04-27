#include <iostream>
#include <fstream>
#include "bin.h"
// using namespace std;

bool read_bin(std::string path, unsigned char **data, int *len){
    std::ifstream _is;

    _is.open(path, std::ios::binary | std::ios::in);
    if(!_is.is_open()){
        std::cout << "read_bin: fail open file" << std::endl;
        return false; 
    }

    int _len = static_cast<int>(_is.tellg());
    _is.seekg(0, _is.beg);
    unsigned char *_buff = (unsigned char*)malloc(_len);

    _is.read((char*)_buff, _len);
    _is.close();
    *data = _buff;
    *len = _len;

    return true;
}

// bool convert_data(unsigned char **data, float **cvt_data, int *len){

//     return true;
// }