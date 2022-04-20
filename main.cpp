#include <iostream>
#include "Weight.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    //test all 7 constructors
    Weight myWeight = Weight();
    Weight myWeight2 = Weight(17);
    Weight myWeight3 = Weight(Weight::SLUG);
    Weight myWeight4 = Weight(14, Weight::KILO);
    Weight myWeight5 = Weight(20, 33);
    Weight myWeight6 = Weight(Weight::SLUG, 33);
    Weight myWeight7 = Weight(23, Weight::POUND, 33 );


    //test conversion functions
    /*cout<<Weight::convertWeight(5, Weight::POUND, Weight::KILO)<<endl;
    cout<<Weight::convertWeight(5, Weight::POUND, Weight::SLUG)<<endl;
    cout<<Weight::convertWeight(5, Weight::POUND, Weight::POUND)<<endl;
    cout<<Weight::convertWeight(5, Weight::SLUG, Weight::SLUG)<<endl;
    cout<<Weight::convertWeight(5, Weight::SLUG, Weight::KILO)<<endl;
    cout<<Weight::convertWeight(5, Weight::SLUG, Weight::POUND)<<endl;
    cout<<Weight::convertWeight(5, Weight::KILO, Weight::KILO)<<endl;
    cout<<Weight::convertWeight(5, Weight::KILO, Weight::SLUG)<<endl;
    cout<<Weight::convertWeight(5, Weight::KILO, Weight::POUND)<<endl;*/










    return 0;



}
