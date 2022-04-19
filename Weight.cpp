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


//initial constructor sets weight to UNKNOWN
Weight::Weight() noexcept{
    weight = UNKNOWN_WEIGHT;
}

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
