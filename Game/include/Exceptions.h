#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
	
/*!
*  \brief this is an exception for an empty cell
*/
class empty_cell : public std::exception {
   const char * what () const throw () {
      return "empty cell";
   }
};

/*!
*  \brief this is an exception for when all freecells are full cell
*/
class full_cells : public std::exception {
   const char * what () const throw () {
      return "all free cells are full";
   }
};

/*!
*  \brief this is an exception for an invalid move in the game
*/
class invalid_move : public std::exception {
   const char * what () const throw () {
      return "invalid move";
   }
};

/*!
*  \brief this is an exception for when a deck is a wrong size
*/
class wrong_size_deck: public std::exception {
   const char * what () const throw () {
      return "deck is wrong size";
   }
};

/*!
*  \brief this is an exception for an invalid argument in a parameter
*/
class invalid_argument: public std::exception {
   const char * what () const throw () {
      return "invalid argument";
   }
};


#endif