
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...
#include "../../vector/vector.hpp"
#include "../../bst/bst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr : virtual public HashTable<Data> {
                        // Must extend HashTable<Data>

private:

  // ...

protected:

  // using HashTable<Data>::???;
  using HashTable<Data>::size;
  using HashTable<Data>::tableSize;
  using HashTable<Data>::HashKey;
  // insert insertall

  // ...
  Vector<BST<Data>> table;

public:

  // Default constructor
  // HashTableClsAdr() specifiers;
  HashTableClsAdr() = default;

  /* ************************************************************************ */

  // Specific constructors
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size
  HashTableClsAdr(unsigned long); 
  
  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a MappableContainer
  HashTableClsAdr(const MappableContainer<Data> &); 
  
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer
  HashTableClsAdr(unsigned long, const MappableContainer<Data> &); 
  
  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a MutableMappableContainer
  HashTableClsAdr(MutableMappableContainer<Data> &&);
  
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a MutableMappableContainer
  HashTableClsAdr(unsigned long, MutableMappableContainer<Data> &&);
  

  /* ************************************************************************ */

  // Copy constructor
  // HashTableClsAdr(argument) specifiers;
  HashTableClsAdr(const HashTableClsAdr<Data> &);

  // Move constructor
  // HashTableClsAdr(argument) specifiers;  
  HashTableClsAdr(HashTableClsAdr<Data> &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~HashTableClsAdr() specifiers;
  virtual ~HashTableClsAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  HashTableClsAdr & operator = (const HashTableClsAdr &);

  // Move assignment
  // type operator=(argument) specifiers;
  HashTableClsAdr & operator = (HashTableClsAdr &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const HashTableClsAdr &) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator != (const HashTableClsAdr &) const noexcept;

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
  virtual void Clear() noexcept override;

  // // // // // // // // // using typename MappableContainer<Data>::MapFunctor;
  // // // // // // // // // using typename FoldableContainer<Data>::FoldFunctor;

  // // // // // // // // // void Map(MapFunctor, void*) override; 
  // // // // // // // // // void Fold(FoldFunctor, const void*, void*) const override;

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
