/*
 * \file   ExceptionContract.h
 * \author M4ST3R-Y0DA-44
 * \brief This file contains the ExceptionContract class declarations
 *
 * \date Created on 11 décembre 2021
 */

#ifndef EXCEPTIONCONTRACT_H
#define EXCEPTIONCONTRACT_H

#include <string>
#include <stdexcept>

/**
 * \class ExceptionContract
 * \brief Class that verifies the conditions of validation and throws errors when invalid data
 *
 * Attributes: std::string m_expression Error message expression
 * std::string m_file name of file in wich the error is found
 * unsigned int m_line the number of line on wich the error was found
 *
 */
class ExceptionContract : public std::logic_error
{
public:
  /**
   * \fn ExceptionContract (std::string, unsigned int, std::string, std::string)
   * \brief Constructor of base class ExceptionContract
   * \param p_fichP (string) name of source file where error was located
   * \param p_prmLigne (int) number of line where error occured
   * \param p_msgP (string) Message describing the error
   * \param p_exprP (string) failed logic test name
   */
  ExceptionContract (std::string, unsigned int, std::string, std::string);

  /**
   * \fn ~ExceptionContract
   * \brief destructor of ExceptionContract class
   */
  ~ExceptionContract () throw () { };

  /** \fn std::string reqTexteException ()
   * \brief method that return the error message
   * \returns (string) error string
   */
  const std::string reqTexteException ()const;

private:
  std::string m_expression; /**\brief (string) error message expression*/
  std::string m_file; /**\brief (string) file name where the error occured*/
  unsigned int m_line; /**\brief (int( line number where error occured*/


};

/**
 * \class AssertionException
 * \brief Class to manage AssertionExceptions
 */
class AssertionException : public ExceptionContract
{
public:
  /**
   * \fn AssertionException (std::string, unsigned int, std::string)
   * \brief Constructor of AssertionException class \n
   * \param p_fichP (string) name of source file where error was located
   * \param p_prmLigne (int) number of line where error occured
   * \param p_exprP (string) failed logic test name
   */
  AssertionException (std::string, unsigned int, std::string);
};

/**
 * \class PreconditionException
 * \brief Class to manage PreconditionExceptions
 */
class PreconditionException : public ExceptionContract
{
public:
  /**
   * \fn PreconditionException (std::string, unsigned int, std::string)
   * \brief Constructor of the PreconditionException class
   * \param p_fichP (string) name of source file where error was located
   * \param p_prmLigne (int) number of line where error occured
   * \param p_exprP (string) failed logic test name
   */
  PreconditionException (std::string, unsigned int, std::string);
};

/**
 * \class PostconditionException
 * \brief Class to manage Postcondition exceptions
 */
class PostconditionException : public ExceptionContract
{
public:
  /**
   * \fn PostconditionException (std::string, unsigned int, std::string)
   * \brief Constructor of the PostconditionException class
   * \param p_fichP (string) name of source file where error was located
   * \param p_prmLigne (int) number of line where error occured
   * \param p_exprP (string) failed logic test name
   */
  PostconditionException (std::string, unsigned int, std::string);
};

/**
 * \class InvariantException
 * \brief class to manage Invariant type exceptions
 */
class InvariantException : public ExceptionContract
{
public:
  /**
   * \fn InvariantException (std::string, unsigned int, std::string)
   * \brief Constructor of the InvariantException class
   * \param p_fichP (string) name of source file where error was located
   * \param p_prmLigne (int) number of line where error occured
   * \param p_exprP (string) failed logic test name
   */
  InvariantException (std::string, unsigned int, std::string);
};

// --- Definition for the Macro controls for the contract

#if !defined(NDEBUG)
// --- Mode debug

#define INVARIANTS() \
      verifieInvariant()

#define ASSERTION(f)     \
      if (!(f)) throw AssertionException(__FILE__,__LINE__, #f);
#define PRECONDITION(f)  \
      if (!(f)) throw PreconditionException(__FILE__, __LINE__, #f);
#define POSTCONDITION(f) \
      if (!(f)) throw PostconditionException(__FILE__, __LINE__, #f);
#define INVARIANT(f)   \
      if (!(f)) throw InvariantException(__FILE__,__LINE__, #f);

// --- LE MODE RELEASE
#else

#define PRECONDITION(f);
#define POSTCONDITION(f);
#define INVARIANTS();
#define INVARIANT(f);
#define ASSERTION(f);



#endif /* EXCEPTIONCONTRACT_H */

