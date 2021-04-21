#include "timer.h"
// using namespace std;

Timer::Timer(){
    this->now = std::chrono::system_clock::now();
    this->end = std::chrono::system_clock::now();
    this->time = this->end - this->now;
}
// Timer::Timer(std::chrono::system_clock::time_point _now){
//     this->now = _now;
//     this->end = _now;
//     this->time = this->end - this->now;
// }
// Timer::Timer(std::chrono::system_clock::time_point _now, std::chrono::system_clock::time_point _end){
//     this->now = _now;
//     this->end = _end;
//     this->time = this->end - this->now;
// }

Timer::~Timer(){
}

void Timer::start(){
    this->now = std::chrono::system_clock::now();
}

void Timer::finish(){
    this->end = std::chrono::system_clock::now();
}

float Timer::ret_time(){
    this->time = this->end - this->now;
    return this->time.count();
}