///////////////////////////////////////////////////////////////////////
//
//  Analysis package
//
// --------------------------------------------------------------------
//
//  AUTHOR: Miguel Ramos Pernas
//  e-mail: miguel.ramos.pernas@cern.ch
//
//  Last update: 12/01/2016
//
// --------------------------------------------------------------------
//
//  Description:
//
//  Implements the abstract class to defines adaptive bins. Each
//  been has defined the limits, the number of entries and the sum
//  of weights.
//
// --------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////


#include "Bin.h"


//______________________________________________________________________________


// -- CONSTRUCTOR AND DESTRUCTOR

//______________________________________________________________________________
// Constructor
Analysis::Bin::Bin() : fEntries( 0 ), fSumOfWeights( 0 ) { }

//______________________________________________________________________________
// Destructor
Analysis::Bin::~Bin() { }
