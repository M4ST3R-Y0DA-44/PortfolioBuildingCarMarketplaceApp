/*
 * \file   ExceptionContract.cpp
 * \author M4ST3R-Y0DA-44
 * \brief This file contains the ExceptionContract class definition
 *
 * \date Created on 11 décembre 2021
 */

#include "ExceptionContract.h"
#include <sstream>

using namespace std;


/*Constructor of class ExceptionCont*/
ExceptionContract::ExceptionContract (std::string p_fichP, unsigned int p_prmLigne,
                                      std::string p_exprP, std::string p_msgP) :
logic_error (p_msgP), m_expression (p_exprP), m_file (p_fichP), m_line (p_prmLigne) { }


/*Method to return error string*/
const std::string
ExceptionContract::reqTexteException () const
{
  // ---  Prépare le message
  ostringstream os;
  os << "Message : " << what () << endl;
  os << "Fichier : " << m_file << endl;
  os << "Ligne   : " << m_line << endl;
  os << "Test    : " << m_expression << endl;

  return os.str ();
}


/*Constructor of AssertionException class*/
AssertionException::AssertionException (std::string p_fichP, unsigned int p_prmLigne,
                                        std::string p_exprP)
: ExceptionContract (p_fichP, p_prmLigne, p_exprP, "ERREUR D'ASSERTION") { }


/*Constructor of PreconditionException class*/
PreconditionException::PreconditionException (std::string p_fichP, unsigned int p_prmLigne,
                                              std::string p_exprP)
: ExceptionContract (p_fichP, p_prmLigne, p_exprP, "ERREUR DE PRECONDITION") { }


/*Constructor of the PostconditionException class*/
PostconditionException::PostconditionException (std::string p_fichP, unsigned int p_prmLigne,
                                                std::string p_exprP)
: ExceptionContract (p_fichP, p_prmLigne, p_exprP, "ERREUR DE POSTCONDITION") { }


/*Constructor of the InvariantException class*/
InvariantException::InvariantException (std::string p_fichP, unsigned int p_prmLigne,
                                        std::string p_exprP)
: ExceptionContract (p_fichP, p_prmLigne, p_exprP, "ERREUR D'INVARIANT") { }