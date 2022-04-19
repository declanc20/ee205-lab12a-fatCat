#include <iostream>
#include "Weight.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    //test that the weight is initialized to 1.
    Weight myWeight = Weight();
    cout<< myWeight.weight <<endl;
    cout<< myWeight.unit <<endl;

    return 0;



}
