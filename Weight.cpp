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
/*Weight::Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight){

}
Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight);*/




//define weight constant conversions
const float Weight::UNKNOWN_WEIGHT = -1; //set the weight to an impossible value
const float Weight::KILOS_IN_A_POUND = 0.453592 ;
const float Weight::SLUGS_IN_A_POUND = 0.031081 ;
static const std::string POUND_LABEL = "POUND";
static const std::string KILO_LABEL = "KILO" ;
static const std::string SLUG_LABEL = "SLUG";






//weight conversion functions
static float fromKilogramToPound(float kilogram) noexcept;
static float fromPoundToKilogram(float kilogram) noexcept;
static float fromSlugToPound(float slug) noexcept;
static float fromPoundToSlug(float pound) noexcept;
static float convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept;
