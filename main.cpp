#include <iostream>
#include "Weight.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    //test that the weight is initialized to 1.
    Weight myWeight = Weight();
    cout<< myWeight.getWeight() <<endl;
    //cout<< myWeight.unit <<endl;

    //test conversion functions
    cout<<Weight::convertWeight(5, Weight::POUND, Weight::KILO)<<endl;
    cout<<Weight::convertWeight(5, Weight::POUND, Weight::SLUG)<<endl;
    cout<<Weight::convertWeight(5, Weight::POUND, Weight::POUND)<<endl;
    cout<<Weight::convertWeight(5, Weight::SLUG, Weight::SLUG)<<endl;
    cout<<Weight::convertWeight(5, Weight::SLUG, Weight::KILO)<<endl;
    cout<<Weight::convertWeight(5, Weight::SLUG, Weight::POUND)<<endl;
    cout<<Weight::convertWeight(5, Weight::KILO, Weight::KILO)<<endl;
    cout<<Weight::convertWeight(5, Weight::KILO, Weight::SLUG)<<endl;
    cout<<Weight::convertWeight(5, Weight::KILO, Weight::POUND)<<endl;

    //test each constructor
    myWeight=Weight(5);
    cout<<myWeight.getWeight()<<endl;









    return 0;



}
