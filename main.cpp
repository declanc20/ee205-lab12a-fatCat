#include <iostream>
#include<cassert>
#include "Weight.h"

#define Debug

using namespace std;


int main() {
    cout << "Hello, World!" << endl;


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

    //test all 7 constructors
    Weight myWeight = Weight();
    Weight myWeight2 = Weight(17);
    Weight myWeight3 = Weight(Weight::SLUG);
    Weight myWeight4 = Weight(14, Weight::KILO);
    Weight myWeight5 = Weight(20, 33);
    Weight myWeight6 = Weight(Weight::SLUG, 33);
    Weight myWeight7 = Weight(23, Weight::POUND, 33 );

    myWeight.dump();
    myWeight2.dump();
    myWeight3.dump();
    myWeight4.dump();
    myWeight5.dump();
    myWeight6.dump();
    myWeight7.dump();


#ifdef Debug //All of these tests fail
    //myWeight2.setWeight(Weight::UNKNOWN_WEIGHT); //fails because weight can't be "un-kown"
    //myWeight5.setWeight(100); //fails because 100 pounds is more than max weight of 33
    //myWeight5.setWeight(100, Weight::KILO); //fails because 100 kilos is more than max wieght of 33 pounds
#endif

    cout<<endl;
    cout<<endl;

    //test overriden operators
    bool overrideTester = Weight(19)<Weight(17);
    cout<< overrideTester << endl;
    overrideTester = Weight(17)<Weight(19);
    cout<< overrideTester << endl;

    overrideTester = Weight(19)==Weight(17);
    cout<< overrideTester << endl;
    overrideTester = Weight(17)==Weight(17);
    cout<< overrideTester << endl;

    Weight testWeight = Weight(3);
    testWeight += 2;
    cout<<testWeight.getWeight() <<endl;


    return 0;



}
