////////////////////////////////////////////////////////////
//
//  General package
//
// ---------------------------------------------------------
//
//  AUTHOR: Miguel Ramos Pernas
//  e-mail: miguel.ramos.pernas@cern.ch
//
//  Last update: 18/10/2017
//
// ---------------------------------------------------------
////////////////////////////////////////////////////////////


#include "Definitions.hpp"
#include "Messenger.hpp"
#include "MessengerConfig.hpp"

#include <iostream>


//_______________________________________________________________________________

namespace isis {

  //_______________________________________________________________________________
  //
  extern const bool ANSIFormat::ColoredStdErr = isatty( STDERR_FILENO );
  extern const bool ANSIFormat::ColoredStdOut = isatty( STDOUT_FILENO );
  
  //_______________________________________________________________________________
  //
  int ANSIFormat::ErrorColor   = aRed;
  int ANSIFormat::InfoColor    = aGreen;
  int ANSIFormat::WarningColor = aYellow;
  
  std::string ANSIFormat::ErrorPrefix   = "ERROR: ";
  std::string ANSIFormat::InfoPrefix    = "INFO: ";
  std::string ANSIFormat::MsgPrefix     = "--- ";
  std::string ANSIFormat::WarningPrefix = "WARNING: ";

  //_______________________________________________________________________________
  //
  bool applyColor( const std::ostream &os ) {

    if ( &os == &std::cerr )
      return ANSIFormat::ColoredStdErr;
    else
      return ANSIFormat::ColoredStdOut;
  }

  //_______________________________________________________________________________
  //
  std::ostream& endMsgLine( std::ostream &os ) {

    if ( applyColor(os) )
      os << "\033[0m";
    
    os << std::endl;
  
    return os;
  }

}
