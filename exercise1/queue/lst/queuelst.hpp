
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : virtual public Queue<Data>, virtual public List<Data>{
                  // Must extend Queue<Data>,
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
  // QueueLst() specifier;
  inline QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  // QueueLst(argument) specifiers; // A queue obtained from a MappableContainer
  QueueLst(const MappableContainer<Data> & con) : List<Data>(con) {};

  // QueueLst(argument) specifiers; // A queue obtained from a MutableMappableContainer
  QueueLst(MutableMappableContainer<Data> && con) : List<Data>(std::move(con)) {};

  /* ************************************************************************ */

  // Copy constructor
  // QueueLst(argument);
  inline QueueLst(const QueueLst & queue) : List<Data>(queue) {};

  // Move constructor
  // QueueLst(argument);
  inline QueueLst(QueueLst && queue) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~QueueLst() specifier;
  virtual ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  inline QueueLst & operator = (const QueueLst &);

  // Move assignment
  // type operator=(argument);
  inline QueueLst & operator = (QueueLst &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator == (const QueueLst &) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator != (const QueueLst &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  inline const Data & Head() const override;

  // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)
  inline Data & Head() override;

  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  inline void Dequeue() override;

  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  inline Data HeadNDequeue() override;

  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  inline void Enqueue(const Data &) override;

  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)
  inline void Enqueue(Data &&) override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // using List<Data>::Clear;
  using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
