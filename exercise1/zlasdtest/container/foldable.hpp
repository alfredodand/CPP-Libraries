
#ifndef FOLDABLETEST_HPP
#define FOLDABLETEST_HPP

#include "../../container/foldable.hpp"

/* ************************************************************************** */

// FoldableContainer member functions!

template <typename Data, typename Value>
void Fold(unsigned int& testnum, unsigned int& testerr, const lasd::FoldableContainer<Data>& con, bool chk, typename lasd::FoldableContainer<Data>::FoldFunctor fun, const Value& inival, const Value& finval) {
  bool tst;
  testnum++;
  Value val = inival;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing fold - ";
    con.Fold(fun, &val);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void FoldAdd(const Data& dat, void* acc) {
  *((Data*) acc) += dat;
}

template <typename Data>
void FoldMultiply(const Data& dat, void* acc) {
  *((Data*) acc) *= dat;
}

void FoldParity(const int&, void*);

void FoldStringConcatenate(const std::string&, void*);

/* ************************************************************************** */

// PreOrderFoldableContainer member functions!

template <typename Data, typename Value>
void FoldPreOrder(unsigned int& testnum, unsigned int& testerr, const lasd::PreOrderFoldableContainer<Data>& con, bool chk, typename lasd::FoldableContainer<Data>::FoldFunctor fun, const Value& inival, const Value& finval) {
  bool tst;
  testnum++;
  Value val = inival;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing fold in pre order - ";
    con.PreOrderFold(fun, &val);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

/* ************************************************************************** */

// PostOrderFoldableContainer member functions!

template <typename Data, typename Value>
void FoldPostOrder(unsigned int& testnum, unsigned int& testerr, const lasd::PostOrderFoldableContainer<Data>& con, bool chk, typename lasd::FoldableContainer<Data>::FoldFunctor fun, const Value& inival, const Value& finval) {
  bool tst;
  testnum++;
  Value val = inival;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing fold in post order - ";
    con.PostOrderFold(fun, &val);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

/* ************************************************************************** */

// InOrderFoldableContainer member functions!

template <typename Data, typename Value>
void FoldInOrder(unsigned int& testnum, unsigned int& testerr, const lasd::InOrderFoldableContainer<Data>& con, bool chk, typename lasd::FoldableContainer<Data>::FoldFunctor fun, const Value& inival, const Value& finval) {
  bool tst;
  testnum++;
  Value val = inival;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing fold in order - ";
    con.InOrderFold(fun, &val);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

/* ************************************************************************** */

// BreadthFoldableContainer member functions!

template <typename Data, typename Value>
void FoldBreadth(unsigned int& testnum, unsigned int& testerr, const lasd::BreadthFoldableContainer<Data>& con, bool chk, typename lasd::FoldableContainer<Data>::FoldFunctor fun, const Value& inival, const Value& finval) {
  bool tst;
  testnum++;
  Value val = inival;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing fold in breadth - ";
    con.BreadthFold(fun, &val);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

/* ************************************************************************** */

#endif
