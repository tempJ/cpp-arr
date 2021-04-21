#pragma once

#include <chrono>
// using namespace std::chrono;

// namespace std::chrono{

// }
class Timer
{
    private:
        std::chrono::system_clock::time_point now;
        std::chrono::system_clock::time_point end;
        std::chrono::duration<float, std::micro> time;

    public:
        Timer();
        // Timer(std::chrono::system_clock::time_point _now);
        // Timer(std::chrono::system_clock::time_point _now, std::chrono::system_clock::time_point _end);
        ~Timer();

        void start();
        void finish();
        float ret_time();
};