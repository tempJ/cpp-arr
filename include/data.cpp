#include <iostream>
#include <algorithm>
#include <thread>
#include <future>
// #include <chrono>
#include "data.h"

Data::Data(){
    // fill(0, 10, this->data);
    this->data.assign(10, 10);
    this->size = 10;
    this->scale = 1.1;
}
Data::Data(std::vector<float> _data, float _scale){
    std::for_each(_data.begin(), _data.end(), [=](float _item) { this->data.push_back(_item); });
    this->size = this->data.size();
    this->scale = _scale;

    // data_scale.resize(this->size);
    data_even.resize(this->size/2+this->size%2);
    data_odd.resize(this->size/2);
}
Data::~Data(){

}

std::vector<float> Data::get_data(){
    return this->data;
}

std::vector<float> Data::get_scale(){
    return this->data_scale;
}

std::vector<float> Data::get_even(){
    return this->data_even;
}
std::vector<float> Data::get_odd(){
    return this->data_odd;
}

void Data::clean(){
    std::vector<float> _tmp;

    this->data_scale = _tmp;
    this->data_even = _tmp;
    this->data_odd = _tmp;
    
    data_even.resize(this->size/2+this->size%2);
    data_odd.resize(this->size/2);
}

void Data::for_scale(){
    for(unsigned long long int idx=0; idx<this->size; idx++){
        this->data_scale.push_back(this->data[idx]*this->scale);
    }
}
void Data::while_scale(){
    unsigned long long int idx = 0;
    while(idx < this->size){
        this->data_scale.push_back(this->data[idx]*this->scale);
        idx++;
    }
}
void Data::for_iterator_scale(){
    for(auto iter: this->data){
        this->data_scale.push_back(iter*this->scale);
    }
}
void Data::foreach_scale(){
    std::for_each(this->data.begin(), this->data.end(), [=](float _item) {
        this->data_scale.push_back(_item*this->scale);
    });
}

void Data::for_divide(){
    for(unsigned long long int idx=0; idx<this->size; idx++){
        if(idx%2){
            this->data_odd[idx/2] = this->data[idx]*this->scale;
        }
        else {
            this->data_even[idx/2] = this->data[idx]*this->scale;
        }
    }
}
void Data::for_2_divide(){
    unsigned long long int _size = this->size - this->size%2;
    // std::cout << "inData: " << _size << std::endl;
    for(unsigned long long int idx=0; idx<_size; idx+=2){
        this->data_even[idx/2] = this->data[idx]*this->scale;
        this->data_odd[idx/2] = this->data[idx+1]*this->scale;
    }
    // std::cout << "inData: " << this->data_even[this->data_even.size()] << std::endl;
    if(this->size%2) { this->data_even[this->data_even.size()-1] = this->data[this->size-1]*this->scale; }
}
void Data::for_async_divide(){
    // std::vector<std::future<void>> future(2);
    // auto future[2];

    // for(unsigned int idx=0; idx<this->size; idx++){
    //     if(idx%2){
    //         auto future_1 = std::async(std::launch::async, [=] { this->data_odd[idx/2] = this->data[idx]; });
    //         // future_1.get();
    //     }
    //     else {
    //         auto future_2 = std::async(std::launch::async, [=] { this->data_even[idx/2] = this->data[idx]; });
    //         // future_2.get();
    //     }
    // }

    auto future_1 = std::async(std::launch::async, [=]{
        for(unsigned long long int idx=0; idx<this->size; idx+=2){
            this->data_even[idx/2] = this->data[idx]*this->scale;
        }
    });
    auto future_2 = std::async(std::launch::async, [=]{
        for(unsigned long long int idx=1; idx<this->size; idx+=2){
            this->data_odd[idx/2] = this->data[idx]*this->scale;
        }
    });
}
void Data::for_thread_divide(){
    std::thread thread_1([=]{
        for(unsigned long long int idx=0; idx<this->size; idx+=2){
            this->data_even[idx/2] = this->data[idx]*this->scale;
        }
    });
    std::thread thread_2([=]{
        for(unsigned long long int idx=1; idx<this->size; idx+=2){
            this->data_odd[idx/2] = this->data[idx]*this->scale;
        }
    });

    thread_1.join();
    thread_2.join();
}