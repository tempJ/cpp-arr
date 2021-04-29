#include <iostream>
#include <thread>
#include <iomanip>
// #include <string>
#include "./include/bin.h"
#include "./include/timer.h"
#include "./include/data.h"

using namespace std;

void print_vector(vector<float> _vector){
    for(auto item: _vector){
        cout << item << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]){
    Timer ct;
    

    vector<float> test(40'000'001, 1);
    for(unsigned long long int i=0; i<test.size(); ++i){
        test[i] = test[i]*static_cast<float>(i);
    }
    // vector<float> test(11, -1);
    // cout << test.size() << endl;
    Data v(test, 1.1);

    cout << "- scale: " << endl;
    ct.start();
    v.for_scale();
    ct.finish();
    cout << "for: " << v.get_scale().size() << ": " << ct.ret_time() << endl;

    v.clean();

    ct.start();
    v.while_scale();
    ct.finish();
    cout << "while: " << v.get_scale().size() << ": " << ct.ret_time() << endl;

    v.clean();

    ct.start();
    v.for_iterator_scale();
    ct.finish();
    cout << "for_iterator: " << v.get_scale().size() << ": " << ct.ret_time() << endl;

    v.clean();

    ct.start();
    v.foreach_scale();
    ct.finish();
    cout << "foreach: " << v.get_scale().size() << ": " << ct.ret_time() << endl;

    v.clean();

    cout << "- divide: " << endl;
    ct.start();
    v.for_divide();
    ct.finish();
    cout << "for: " << v.get_even().size() << ": " << ct.ret_time() << endl;

    v.clean();

    ct.start();
    v.for_2_divide();
    ct.finish();
    // cout << setprecision(8) << v.get_odd()[v.get_odd().size()-1] << endl;
    // cout << setprecision(8) << v.get_even()[v.get_even().size()-3] << endl;
    // cout << setprecision(8) << v.get_even()[v.get_even().size()-2] << endl;
    // cout << setprecision(8) << v.get_even()[v.get_even().size()-1] << endl;
    cout << "for_2: " << v.get_even().size() << ": " << ct.ret_time() << endl;

    v.clean();

    ct.start();
    v.for_async_divide();
    ct.finish();
    // cout << v.get_odd()[v.get_scale().size()-1] << ", " <<;
    // print_vector(v.get_even());
    cout << "for_async: " << v.get_even().size() << ": " << ct.ret_time() << endl;

    v.clean();

    ct.start();
    v.for_thread_divide();
    ct.finish();
    // cout << v.get_odd()[v.get_scale().size()-1] << ", " <<;
    // print_vector(v.get_even());
    cout << "for_thread: " << v.get_even().size() << ": " << ct.ret_time() << endl;

    return 0;
}