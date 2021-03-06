//////////////////////////////////////////////////////////////////////////////////
//
//  Python wrappers
//
// -------------------------------------------------------------------------------
//
//  AUTHOR: Miguel Ramos Pernas
//  e-mail: miguel.ramos.pernas@cern.ch
//
//  Last update: 19/10/2017
//
// -------------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////


#include "Exceptions.hpp"
#include "GlobalWrappers.hpp"
#include "Messenger.hpp"

#include <boost/python/numpy.hpp>
#include <boost/python.hpp>
#include <boost/python/dict.hpp>
#include <boost/python/list.hpp>
#include <boost/python/object.hpp>

#include <iostream>

namespace py = boost::python;
namespace np = boost::python::numpy;


//_______________________________________________________________________________

namespace iboost {

  //_______________________________________________________________________________
  // The dtype to character type parser is initialized calling the empty
  // constructor
  DTypeParser NUMPY_TYPE_CONVERTER;
  
  //_______________________________________________________________________________
  //
  py::ssize_t boostDictListSize( py::dict dict ) {

    py::list keys  = dict.keys();
    py::ssize_t nk = py::len( keys );

    py::ssize_t length = py::len( dict[ keys[ 0 ] ] );
    for ( ssize_t i = 1; i < nk; ++i ) {
    
      py::object list  = dict[ keys[ i ] ];
    
      if ( py::len( list ) != length )
	throw isis::BaseException("Lists in dictionary do not have the same length");
    }
  
    return length;
  }

  //_______________________________________________________________________________
  //
  void checkArgs( py::tuple &args,
		  const unsigned int &nargs ) {
  
    py::ssize_t n = py::len( args );
    if ( n != nargs )
      throw isis::BaseException("Incorrect number of arguments " +
				std::to_string(n) +
				" (" + std::to_string(nargs) + ")");
  }

  //_______________________________________________________________________________
  //
  void checkKwargs( py::dict &kwargs,
		    const std::vector<const char*> &lst ) {
  
    py::object keys = kwargs.keys();
    for ( int i = 0; i < py::len( keys ); ++i ) {

      py::object arg = extractFromIndex<py::object>(keys, i);
    
      const char *name = py::extract<const char*>( arg );
    
      if ( std::find(lst.begin(), lst.end(), name) != lst.end() )
	IWarning << "Unknown input keyword argument < " << name << " >" << IEndMsg;
    }
  }

}
