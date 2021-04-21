#include <iostream>
// #include <string>
#include "./include/arr.h"
#include "./include/timer.h"

using namespace std;

int main(int argc, char *argv[]){
    Timer ct;
    ct.start();
    // unsigned char **data;
    // int len;
    // read_bin(".", data, &len);
    ct.finish();
    cout << ct.ret_time() << endl;
    return 0;
}