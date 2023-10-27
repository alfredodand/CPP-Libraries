
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data>, virtual public Vector<Data>{
                  // Must extend Queue<Data>,
                  //             Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;
  using Vector<Data>::size;
  using Vector<Data>::Elements;

  // ...
  int head = 0;
  int tail = 0;
  unsigned long realsize = 0;

public:

  // Default constructor
  // QueueVec() specifier;
  inline QueueVec() = default;

  /* ************************************************************************ */

  // Specific constructor
  // QueueVec(argument) specifiers; // A queue obtained from a MappableContainer
  QueueVec(const MappableContainer<Data> &);
  // QueueVec(argument) specifiers; // A queue obtained from a MutableMappableContainer
  QueueVec(MutableMappableContainer<Data> && con) : Vector<Data>(std::move(con)) {};

  /* ************************************************************************ */

  // Copy constructor
  // QueueVec(argument);
  inline QueueVec(const QueueVec & queue);

  // Move constructor
  // QueueVec(argument);
  inline QueueVec(QueueVec && queue) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~QueueVec() specifier;
  virtual ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  inline QueueVec & operator = (const QueueVec &);

  // Move assignment
  // type operator=(argument);
  inline QueueVec & operator = (QueueVec &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const QueueVec &) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator != (const QueueVec &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  const Data & Head() const override;

  // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)
  Data & Head() override;
  
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  void Dequeue() override;
  
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override;
  
  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  void Enqueue(const Data &) override;
  
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)
  void Enqueue(Data &&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member
  inline bool Empty() const noexcept override;

  // type Size() specifiers; // Override Container member
  inline unsigned long  Size() const noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;

protected:

  // Auxiliary member functions

  // type Expand() specifiers;
  void Expand();

  // type Reduce() specifiers;
  void Reduce();

  // type SwapVectors(arguments) specifiers;
  //void Resize(unsigned long, unsigned long);

  void SwapVectors(Data *, unsigned long);


};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
