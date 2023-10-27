
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : virtual public Stack<Data>, virtual public List<Data>{
                  // Must extend Stack<Data>,
                  //             List<Data>

private:

  // ...

protected:

  // using List<Data>::???;
  using List<Data>::size;
  using List<Data>::head;
  using List<Data>::tail;
  using typename List<Data>::Node;

  // ...

public:

  // Default constructor
  // StackLst() specifier;
  inline StackLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  // StackLst(argument) specifiers; // A stack obtained from a MappableContainer
  StackLst(const MappableContainer<Data> & con) : List<Data>(con) {};

  // StackLst(argument) specifiers; // A stack obtained from a MutableMappableContainer
  StackLst(MutableMappableContainer<Data> && con) : List<Data>(std::move(con)) {};

  /* ************************************************************************ */

  // Copy constructor
  // StackLst(argument);
  inline StackLst(const StackLst & stack);

  // Move constructor
  // StackLst(argument);
  inline StackLst(StackLst && stack) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~StackLst() specifier;
  virtual ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  inline StackLst & operator = (const StackLst &);

  // Move assignment
  // type operator=(argument);
  inline StackLst & operator = (StackLst &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator == (const StackLst &) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator != (const StackLst &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  inline Data Top() const override;
  
  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  inline Data & Top() override;
  
  // type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
  inline void Pop() override;
  
  // type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)
  inline Data TopNPop() override;
  
  // type Push(argument) specifiers; // Override Stack member (copy of the value)
  inline void Push(const Data &) override;
  
  // type Push(argument) specifiers; // Override Stack member (move of the value)
  inline void Push(Data &&) noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // using List<Data>::Clear;
  using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
