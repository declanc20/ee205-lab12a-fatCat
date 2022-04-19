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


    //set the weight

public: //Enumerators
    enum UnitOfWeight {POUND, KILO, SLUG };

public: //conversion constants and labels
    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND ;
    static const std::string POUND_LABEL ;
    static const std::string KILO_LABEL ;
    static const std::string SLUG_LABEL ;






};


