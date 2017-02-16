////////////////////////////////////////////////////////////
//
//  General package
//
// ---------------------------------------------------------
//
//  AUTHOR: Miguel Ramos Pernas
//  e-mail: miguel.ramos.pernas@cern.ch
//
//  Last update: 16/02/2016
//
// ---------------------------------------------------------
////////////////////////////////////////////////////////////


#include "Messenger.h"
#include "MessengerConfig.h"


//_______________________________________________________________________________
//
General::Messenger::Messenger( const std::string &start,
			       std::ostream &os,
			       const int &fgcol,
			       const int &bgcol,
			       const int &sty ) :
  fOStream( &os ) {

  // Check if color must be applied
  switch ( ApplyColor(os) ) {
    
  case true:
    
    *fOStream << "\033[";

    // Configure foreground color
    switch ( fgcol ) {
      
    case ANSIFormat::aNoColor:
      NOOP;
      
    default:
      *fOStream << ";3" << std::to_string( fgcol );
    }

    // Configure background color
    switch ( bgcol ) {
    case ANSIFormat::aNoColor:
      NOOP;
    default:
      *fOStream << ";4" << std::to_string( bgcol );
    }

    // Configure style
    switch ( sty ) {
    case ANSIFormat::aNoStyle:
      NOOP;
    default:
      *fOStream << ";" << std::to_string( sty );
    }
      
    *fOStream << "m";
    
  default:
    NOOP;
  }

  *fOStream << start;
}

//_______________________________________________________________________________
//
General::Messenger::~Messenger() { }
