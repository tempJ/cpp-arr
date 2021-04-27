#include <iostream>
#include <algorithm>
#include "data.h"

Data::Data(){

}
Data::Data(std::vector<float> _data){
    std::for_each(_data.begin(), _data.end(), push);
    this->size = this->data.size();
}
Data::~Data(){

}

void Data::push(float _item){
    this->data.push_back(_item);
}