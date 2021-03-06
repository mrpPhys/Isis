///////////////////////////////////////////////////////////////////////
//
//  General package
//
// --------------------------------------------------------------------
//
//  AUTHOR: Miguel Ramos Pernas
//  e-mail: miguel.ramos.pernas@cern.ch
//
//  Last update: 19/10/2017
//
// --------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////


#include "ConfigParser.hpp"
#include "Definitions.hpp"
#include "Exceptions.hpp"
#include "Utils.hpp"

#include <algorithm>


//_______________________________________________________________________________

namespace isis {

  //_______________________________________________________________________________
  //
  ConfigParser::ConfigParser() : fParsed( false ) { }

  //_______________________________________________________________________________
  //
  ConfigParser::~ConfigParser() { }

  //_______________________________________________________________________________
  //
  void ConfigParser::bookConfigOpt( const std::string &name,
				    const char &type,
				    const Strings &poss ) {
    
    switch ( type ) {
    case 'D':
      break;
    case 'I':
      break;
    case 'S':
      break;
    default:
      throw BaseException("Unknown type for variable \"" + name + "\" (" +
			  std::string(1, type) + ')');
    }

    fArgs[ name ] = std::make_pair( std::string(), poss );
    fVariables.push_back( { name, type } );
  }

  //_______________________________________________________________________________
  //
  void ConfigParser::parseArgs( const int &nargs, const char *argv[] ) {

    // Allows the class to extract values
    fParsed = true;

    // The first argument is the name of the script
    const size_t truenargs = nargs - 1;

    // An error is displayed if the number of parameters in the main function is not
    // equal to that in the class
    const size_t &gsize = fArgs.size();
    if ( gsize != truenargs )
      throw BaseException("Incorrect number of input parameters (" +
			  std::to_string(truenargs) +
			  '/' + std::to_string(gsize) + ')');

    bool status = true;
    for ( auto it = fVariables.begin(); status && it != fVariables.end(); ++it ) {

      const std::string &name = it->first;
      const char &type = it->second;
      const size_t pos = it - fVariables.begin() + 1;
      const std::string &arg = argv[ pos ];
    
      switch ( type ) {
      case 'D':
	status *= checkStringType<float>( arg );
	break;
      case 'I':
	status *= checkStringType<int>( arg );
	break;
      case 'S':
	break;
      }
    
      auto def = fArgs[ name ].second;
      if ( def.size() && std::find( def.begin(), def.end(), arg ) == def.end() )
	throw BaseException("Input for \"" + name +
			    "\" does not match any of the possibilities: " +
			    contToString(def));
      else
	fArgs[ name ].first = arg;

      // An error is displayed when an argument can not be parsed
      if ( !status )
	throw BaseException("Unable to parse argument " + std::to_string(pos) +
			    ": \"" + name + "\" (" + std::string(1, type) + ')');
    }
  }

}
