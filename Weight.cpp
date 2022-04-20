///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  untitled - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Declan Campbell <declanc@hawaii.edu>
/// @date   18_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "Weight.h"

using namespace std;

//set the weight to an impossible value
const float Weight::KILOS_IN_A_POUND = 0.453592 ;
const float Weight::SLUGS_IN_A_POUND = 0.031081 ;
static const string POUND_LABEL = "POUND";
static const string KILO_LABEL = "KILO" ;
static const string SLUG_LABEL = "SLUG";
//define weight constant conversions
const float Weight::UNKNOWN_WEIGHT = -1;


 ostream& operator<<( ostream& lhs_stream
        ,const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << POUND_LABEL ;
        case Weight::KILO: return lhs_stream << KILO_LABEL ;
        case Weight::SLUG: return lhs_stream << SLUG_LABEL ;
        default:
            throw out_of_range( "The unit can’t be mapped to a string" );
    }
}

// consturctors
//initial constructor sets weight to UNKNOWN and unit of weight ot pounds
Weight::Weight() noexcept{
    bIsKnown= false;
    bHasMax = false;
    weight = UNKNOWN_WEIGHT;
    unit = POUND;
    maxWeight = UNKNOWN_WEIGHT;

}

Weight::Weight(float newWeight){
    bHasMax = false;
    bIsKnown = true;
    isWeightValid(newWeight); // make sure weight is valid
    setWeight(newWeight);
    unit = POUND;
    setMaxWeight(UNKNOWN_WEIGHT);
    assert(validate());
}

Weight::Weight(UnitOfWeight newUnitOfWeight) noexcept{
    bIsKnown = false;
    bHasMax = false;
    weight = UNKNOWN_WEIGHT;
    unit = newUnitOfWeight;
    setMaxWeight(UNKNOWN_WEIGHT);
    assert(validate());
}

Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight){
    bHasMax = false;
    isWeightValid(newWeight);
    setWeight(newWeight,newUnitOfWeight);
    setMaxWeight(UNKNOWN_WEIGHT);
    assert(validate());
}

Weight::Weight(float newWeight, float newMaxWeight){
    bHasMax = true;
    setMaxWeight(newMaxWeight);
    isWeightValid(newWeight);
    setWeight(newWeight);
    unit = POUND;
}
Weight::Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight){
    bHasMax = true;
    bIsKnown= false;
    weight=UNKNOWN_WEIGHT;
    setMaxWeight(newMaxWeight);
    unit = newUnitOfWeight;
}

Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight){
    bHasMax = true;
    bIsKnown= false;
    setWeight(newWeight,newUnitOfWeight);
    setMaxWeight(newMaxWeight);
}



bool Weight::operator<(const Weight &rhs_Weight) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight < rhs_weight;
}

bool Weight::operator==( const Weight& rhs_Weight ) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight == rhs_weight;
}

 Weight& Weight::operator+=( float rhs_addToWeight ) {
     this -> weight += rhs_addToWeight;
    return *this;

}


//getters and setters
void Weight::setMaxWeight(float newMaxWeight) {
    Weight::maxWeight = newMaxWeight;
}

float Weight::getWeight() const {
    return weight;
}

float Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept{
     return convertWeight(Weight::weight, Weight::unit, weightUnits );
 }

void Weight::setWeight(float newWeight) {
   isWeightValid(newWeight);
   Weight::weight = newWeight;
}

float Weight::getMaxWeight() const noexcept{
     return maxWeight;
 }

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept{
     return unit;
 }

void Weight::setWeight(float newWeight, UnitOfWeight weightUnits){
     //first nconvert (if necessary), the units to the same as the units that are currently set
    newWeight = convertWeight(newWeight, weightUnits, Weight::unit);
    isWeightValid(newWeight);
     Weight::weight = newWeight;

 }

bool Weight::hasMaxWeight() const noexcept {

     return Weight::bHasMax;
}

bool Weight::isWeightKnown() const noexcept {
    return Weight::bIsKnown;
}


//weight conversion functions
float Weight::fromKilogramToPound(float kilogram) noexcept{
    return kilogram/KILOS_IN_A_POUND;
}
float Weight::fromPoundToKilogram(float pound) noexcept{
    return pound*KILOS_IN_A_POUND;
}
float Weight::fromSlugToPound(float slug) noexcept {
    return slug / SLUGS_IN_A_POUND;
}
float Weight::fromPoundToSlug(float pound) noexcept{
    return pound * SLUGS_IN_A_POUND;
}
float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept{

    //always convert to pounds (a common unit)
    float weightInPounds;
    switch(fromUnit){
        case (POUND): weightInPounds = fromWeight; break;
        case (KILO): weightInPounds = fromKilogramToPound(fromWeight); break;
        case(SLUG): weightInPounds = fromSlugToPound(fromWeight); break;
    }

    //now convert to whatever unit is needed from pounds
    switch(toUnit){
        case (POUND): return weightInPounds;
        case (KILO): return fromPoundToKilogram(weightInPounds);
        case(SLUG): return fromPoundToSlug(weightInPounds);
    }
    return 0;
}

bool Weight::isWeightValid(float checkWeight) const noexcept {
    if (checkWeight > 0 && bHasMax == false){
        return true;
    }
    else if (bHasMax == true && checkWeight >0 && checkWeight<=maxWeight){
        return true;
    }
    throw ("weight is not valid");
}
bool Weight::validate() const noexcept {
    if( Weight::weight == UNKNOWN_WEIGHT){
        return true;
    }
    else if (bHasMax == false && weight > 0) {
        return true;
    } else if (bHasMax && Weight::weight > 0 && Weight::weight <= maxWeight) {
        return true;
    }

    throw ("weight is not valid");
}

    /// Format a line for printing the members of a class
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)
    void Weight::dump() const noexcept{
        cout << setw(80) << setfill( '=' ) << "" << endl ;
        cout << setfill( ' ' ) ;
        cout << left ;
        cout << boolalpha ;
        FORMAT_LINE( "Weight", "this" ) << &weight << endl ;
        FORMAT_LINE( "Weight", "isKnown" ) << isWeightKnown() << endl ;
        FORMAT_LINE( "Weight", "weight" ) <<  getWeight() << endl ;
        FORMAT_LINE( "Weight", "unitOfWeight" ) << getWeightUnit() << endl ;
        FORMAT_LINE( "Weight", "hasMax" ) << hasMaxWeight()<< endl ;
        FORMAT_LINE( "Weight", "maxWeight" ) << getMaxWeight() << endl ;
}


