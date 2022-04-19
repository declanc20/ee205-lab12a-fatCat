///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  untitled - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Declan Campbell <declanc@hawaii.edu>
/// @date   18_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <string>
#include <ostream>


class Weight {


public: //Enumerators
    enum UnitOfWeight {POUND, KILO, SLUG };

private: //Weight and its unit variable declarations
    float weight;
    enum UnitOfWeight unit;
    float maxWeight;
    bool bIsKnown;
    bool bHasMax;


private: //private getters and setters
    void setMaxWeight(float newMaxWeight);
    void setWeight(float newWeight);
public://public getters and setters
    void setWeight(float newWeight, UnitOfWeight weightUnits);
    float getWeight() const;
    float getWeight(Weight::UnitOfWeight weightUnits) const noexcept;
    float getMaxWeight() const noexcept;
    UnitOfWeight getWeightUnit() const noexcept;
    bool isWeightKnown() const noexcept;
    bool hasMaxWeight() const noexcept;

public://constructors
    Weight() noexcept;
    Weight(float newWeight);
    Weight(UnitOfWeight newUnitOfWeight) noexcept;
    Weight(float newWeight, UnitOfWeight newUnitOfWeight);
    Weight(float newWeight, float newMaxWeight);
    Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight);
    Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight);




public: //conversion constants and labels
    static const float UNKNOWN_WEIGHT;
    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND ;
    static const std::string POUND_LABEL ;
    static const std::string KILO_LABEL ;
    static const std::string SLUG_LABEL ;

public: //weight conversions

    static float fromKilogramToPound(float kilogram) noexcept;
    static float fromPoundToKilogram(float poun) noexcept;
    static float fromSlugToPound(float slug) noexcept;
    static float fromPoundToSlug(float pound) noexcept;
    static float convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept;

public://validation functions
    bool isWeightValid(float checkWeight) const noexcept;
    bool validate() const noexcept;


};










