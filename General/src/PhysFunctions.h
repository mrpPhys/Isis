///////////////////////////////////////////////////////////////////////////////////
//
//  General package
//
// --------------------------------------------------------------------------------
//
//  AUTHOR : Miguel Ramos Pernas
//  e-mail: miguel.ramos.pernas@cern.ch
//
//  Last Update: 23/03/2017
//
// --------------------------------------------------------------------------------
//
//  Description:
//
//  Implements different functions to perform calculations of physical and
//  algebraic variables.
//
// --------------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////


#ifndef PHYS_FUNCTIONS
#define PHYS_FUNCTIONS

#include "LorentzVector.h"


//_______________________________________________________________________________

namespace Isis {

  // Return the proper lifetime multiplied by the speed of light
  double ctau( LorentzVector TLV, Vector OwnPV, Vector EndV );

  // Calculates the determinant of three 3D vectors
  double det( Vector vec1, Vector vec2, Vector vec3 );

  // Calculates the determinant of three LorentzVector 
  double det( LorentzVector vec1, LorentzVector vec2, LorentzVector vec3 );

  // Calculates the impact parametere given the momentum and the primary and
  // secondary vertex
  double ip( Vector vec, Vector pv, Vector sv );

  // Return the distance of closest approach given two vectors and two points
  double doca( LorentzVector vec1, Vector EndV1, LorentzVector vec2, Vector EndV2 );

}

#endif
