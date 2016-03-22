#///////////////////////////////////////////////////////////////////////////////
#//                                                                           //
#//  Python modules                                                           //
#//                                                                           //
#// ------------------------------------------------------------------------- //
#//                                                                           //
#//  AUTHOR: Miguel Ramos Pernas                                              //
#//  e-mail: miguel.ramos.pernas@cern.ch                                      //
#//                                                                           //
#//  Last update: 22/03/2016                                                  //
#//                                                                           //
#// --------------------------------------------------------------------------//
#//                                                                           //
#//  Description:                                                             //
#//                                                                           //
#//  In this file there are defined some useful decorators for the different  //
#//  functions and methods of the project.                                    //
#//                                                                           //
#// ------------------------------------------------------------------------- //
#///////////////////////////////////////////////////////////////////////////////


import time
from Isis.Utils import FormatTime, TerminalSize


#_______________________________________________________________________________
# This decorator displays the time information about a particular job, together
# with some separators
def TrackTime( function ):

    def wrapper( *args, **kwargs ):
        '''
        This is the wrapper function to be returned
        '''

        ''' Gets the time information '''
        stime, lctime, gmtime = time.time(), time.localtime(), time.gmtime()        
        lctstr = time.strftime( "%a, %d %b %Y %H:%M:%S", lctime )
        if time.strftime( "%d", lctime ) != time.strftime( "%d", gmtime ):
            gmtstr = time.strftime( "%a, %d %b %Y %H:%M:%S", gmtime )
        else:
            gmtstr = time.strftime( "%H:%M:%S", gmtime )

        ''' Gets the terminal size and creates the separator '''
        (height, width) = TerminalSize()
        separator = width*"*"

        ''' Displays the initial information '''
        msg = lctstr + " (LOCAL) " + gmtstr + " (UTC)"
        print separator
        print "START OF NEW TRACKED JOB".center( width )
        print separator
        print msg.center( width )
        print separator

        ''' Calls the function '''
        function( *args, **kwargs )

        ''' Gets the time after the function calling '''
        etime, lctime, gmtime = time.time(), time.localtime(), time.gmtime()
        lctstr = time.strftime( "%a, %d %b %Y %H:%M:%S", lctime )
        if time.strftime( "%d", lctime ) != time.strftime( "%d", gmtime ):
            gmtstr = time.strftime( "%a, %d %b %Y %H:%M:%S", gmtime )
        else:
            gmtstr = time.strftime( "%H:%M:%S", gmtime )

        ''' Displays the ending information '''
        msg = lctstr + " (LOCAL) " + gmtstr + " (UTC)"
        print separator
        print ("TRACKED JOB FINISHED (Time elapsed: %s)"
               % FormatTime( etime - stime ) ).center( width )
        print separator
        print msg.center( width )
        print separator
    
    return wrapper
