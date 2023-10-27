
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */
#include <random>

#include "../hashtable.hpp"
// #include ...
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data>{
                        // Must extend HashTable<Data>

private:

  // ...

protected:

  // using HashTable<Data>::???;
  using HashTable<Data>::size;
  using HashTable<Data>::a;
  using HashTable<Data>::b;
  using HashTable<Data>::prime;
  using HashTable<Data>::tableSize;

  Vector<Data> table;
  Vector<char> status;

  // ...

public:

  // Default constructor
  // HashTableOpnAdr() specifiers;
  HashTableOpnAdr();

  /* ************************************************************************ */

  // Specific constructors
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size
  HashTableOpnAdr(unsigned long); 
  
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a MappableContainer
  HashTableOpnAdr(const MappableContainer<Data> &); 
  
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer
  HashTableOpnAdr(unsigned long, const MappableContainer<Data> &); 
  
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a MutableMappableContainer
  HashTableOpnAdr(MutableMappableContainer<Data> &&);
  
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a MutableMappableContainer
  HashTableOpnAdr(unsigned long, MutableMappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  // HashTableOpnAdr(argument) specifiers;
  HashTableOpnAdr(const HashTableOpnAdr<Data> &);

  // Move constructor
  // HashTableOpnAdr(argument) specifiers;
  HashTableOpnAdr(HashTableOpnAdr<Data> &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~HashTableOpnAdr() specifiers;  
  virtual ~HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  HashTableOpnAdr & operator = (const HashTableOpnAdr &);

  // Move assignment
  // type operator=(argument) specifiers;
  HashTableOpnAdr & operator = (HashTableOpnAdr &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const HashTableOpnAdr<Data> &) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator != (const HashTableOpnAdr<Data> &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  virtual bool Insert(const Data &) override;

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  virtual bool Insert(Data &&) noexcept override;

  // type Remove(argument) specifiers; // Override DictionaryContainer member
  virtual bool Remove(const Data &) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  inline virtual bool Exists(const Data &) const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Resize the hashtable to a given size
  virtual void Resize(unsigned long) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  // type Clear() specifiers; // Override Container member
  virtual void Clear() override;

protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  unsigned long HashKey(const Data &, const unsigned long) const;

  // type Remove(argument) specifiers;
  bool RemoveFromIndex(const unsigned long, const Data &); //rimuovi da un certo indice in poi
  
  void ResetStatus();

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
