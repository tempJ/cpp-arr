#pragma once

#include <vector>
// template<class T>
class Data
{
    private:
        std::vector<float> data;
        // float *data;
        unsigned int size;

    public:
        Data();
        Data(unsigned int _size);
        Data(std::vector<float> _data);
        ~Data();

        void push(float _item);
        void use_for();
        void ues_foreach();
};