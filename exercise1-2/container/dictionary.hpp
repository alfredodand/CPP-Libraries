
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "testable.hpp"
#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer : virtual public TestableContainer<Data>{
                            // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~DictionaryContainer() specifiers
  virtual ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  DictionaryContainer & operator = (const DictionaryContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  DictionaryContainer & operator = (DictionaryContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator = (const Container &) const noexcept = delete;
  
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const Container &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Insert(argument) specifiers; // Copy of the value
  virtual bool Insert(const Data &) = 0;
  // type Insert(argument) specifiers; // Move of the value
  virtual bool Insert(Data &&) noexcept = 0;
  // type Remove(argument) specifiers;
  virtual bool Remove(const Data &) = 0;

  // type InsertAll(argument) specifiers; // Copy of the value; From MappableContainer; True if all are inserted
  inline bool InsertAll(const MappableContainer<Data> &);
  // type InsertAll(argument) specifiers; // Move of the value; From MutableMappableContainer; True if all are inserted
  inline bool InsertAll(MappableContainer<Data> &&);
  // type RemoveAll(argument) specifiers; // From MappableContainer; True if all are removed
  inline bool RemoveAll(const MappableContainer<Data> &);

  // type InsertSome(argument) specifiers; // Copy of the value; From MappableContainer; True if some is inserted
  inline bool InsertSome(const MappableContainer<Data> &);
  // type InsertSome(argument) specifiers; // Move of the value; From MutableMappableContainer; True if some is inserted
  inline bool InsertSome(MappableContainer<Data> &&);
  // type RemoveSome(argument) specifiers; // From MappableContainer; True if some is removed
  inline bool RemoveSome(const MappableContainer<Data> &);

};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
