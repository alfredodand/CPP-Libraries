
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  // type operator()(argument) specifiers; // (concrete function should not throw exceptions)
  unsigned long operator()(const Data &) const noexcept = 0;

};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer, virtual public DictionaryContainer<Data> {
                  // Must extend ResizableContainer,
                  //             DictionaryContainer<Data>

private:

  // ...

protected:

  // using DictionaryContainer<Data>::???;
  using DictionaryContainer<Data>::size;

  unsigned long a = 1;
  unsigned long b = 0;
  const unsigned long prime = 4294967311; //primo numero primo dopo 2^32
  unsigned long tableSize = 128;
  const unsigned long myTableSize = 128;
  Hashable<Data> hash;

  std::default_random_engine generateRandom = std::default_random_engine(std::random_device{}());
  std::uniform_int_distribution<unsigned long> distributorA = std::uniform_int_distribution<unsigned long>(1, prime -  1);
  std::uniform_int_distribution<unsigned long> distributorB = std::uniform_int_distribution<unsigned long>(0, prime -  1);

  // ...

  // Constructor
  HashTable();

  // Copy Constructor
  HashTable(const HashTable &);

  // Move Constructor
  HashTable(HashTable &&) noexcept;

  // // Copy assignment
  // HashTable & operator = (const HashTable &);

  // // Move assignment
  // HashTable & operator = (HashTable &&) noexcept;

public:

  

  // Destructor
  // ~HashTable() specifiers
  virtual ~HashTable() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  HashTable & operator = (const HashTable &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  HashTable & operator = (HashTable &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract hashtable is possible but not required.
  bool operator == (const HashTable &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract hashtable is possible but not required.
  bool operator != (const HashTable &) const noexcept = delete;

protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  unsigned long HashKey(const Data &) const noexcept; 
  unsigned long HashKey(unsigned long) const noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
