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


//initial constructor sets weight to UNKNOWN and unit of weight ot pounds
Weight::Weight() noexcept{
    bIsKnown= false;
    bHasMax = false;
    weight = UNKNOWN_WEIGHT;
    unit = POUND;

}

//initial constructor that actually initialzies the weight from the user (main)
Weight::Weight(const float newWeight) {
    weight = newWeight;
}

Weight::Weight(UnitOfWeight newUnitOfWeight) noexcept {

    unit = newUnitOfWeight;
}


Weight::Weight(const float newWeight, UnitOfWeight newUnitOfWeight){
    weight = newWeight;
    unit = newUnitOfWeight;
}
Weight::Weight(float newWeight, float newMaxWeight){
    maxWeight = newWeight;
}

/*Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight){

}
Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight){
 }*/




//define weight constant conversions
const float Weight::UNKNOWN_WEIGHT = -1; //set the weight to an impossible value
const float Weight::KILOS_IN_A_POUND = 0.453592 ;
const float Weight::SLUGS_IN_A_POUND = 0.031081 ;
static const std::string POUND_LABEL = "POUND";
static const std::string KILO_LABEL = "KILO" ;
static const std::string SLUG_LABEL = "SLUG";






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
    Weight::weight = weight;
}

float Weight::getMaxWeight() const noexcept{
     return maxWeight;
 }

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept{
     return unit;
 }

void Weight::setWeight(float newWeight, UnitOfWeight weightUnits){
     Weight::weight = newWeight;
     Weight::unit = weightUnits;
 }

bool Weight::hasMaxWeight() const noexcept {

     return Weight::bHasMax;
}

bool Weight::isWeightKnown() const noexcept {
    return Weight::bIsKnown;
}