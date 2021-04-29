#pragma once

#include <vector>
// template<class T>
class Data{
    private:
        std::vector<float> data;
        // float* data;
        // boost::array<float> data;

        std::vector<float> data_scale;
        std::vector<float> data_even;
        std::vector<float> data_odd;
        // boost::array<float> data_arr_scale;
        // boost::array<float> data_arr_even;
        // boost::array<float> data_arr_odd;

        // float *data;
        unsigned long long int size;
        float scale;

    public:
        Data();
        Data(std::vector<float> _data, float _scale);
        ~Data();

        std::vector<float> get_data();
        std::vector<float> get_scale();
        std::vector<float> get_even();
        std::vector<float> get_odd();

        void for_scale();
        void while_scale();
        void for_iterator_scale();
        void foreach_scale();
        // void for_scale_arr();
        // void for_iterator_scale_arr();
        // void foreach_scale_arr();

        void for_divide();
        void for_2_divide();
        void for_async_divide();
        void for_thread_divide();
        // void foreach_scale();
        // void foreach_scale();

        void clean();
};