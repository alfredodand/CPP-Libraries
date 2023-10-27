
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : virtual public ResizableContainer, virtual public SortableLinearContainer<Data> {
                // Must extend ResizableContainer,
                //             SortableLinearContainer<Data>

private:

  // ...

protected:

  // using Container::???;
  using Container::size;

  // ...
  Data * Elements = nullptr;
  unsigned long i = 0;

public:

  // Default constructor
  // Vector() specifiers;
  Vector() = default;


  /* ************************************************************************ */

  // Specific constructors
  // Vector(argument) specifiers; // A vector with a given initial dimension
  Vector(const unsigned long);

  // Vector(argument) specifiers; // A vector obtained from a MappableContainer
  Vector(const MappableContainer<Data> &);

  // Vector(argument) specifiers; // A vector obtained from a MutableMappableContainer
  Vector(MutableMappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  // Vector(argument) specifiers;
  Vector(const Vector &);

  // Move constructor
  // Vector(argument) specifiers;
  Vector(Vector &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~Vector() specifiers;
  virtual ~Vector();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  Vector & operator = (const Vector &);

  // Move assignment
  // type operator=(argument) specifiers;
  Vector & operator = (Vector &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const Vector &) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator != (const Vector &) const noexcept;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Override ResizableContainer member
  void Resize(const unsigned long) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  const Data & operator[](const unsigned long) const override;

  // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)
  Data & operator[](const unsigned long) override;

  // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  const Data & Front() const override;

  // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
  Data & Front() override;

  // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  const Data & Back() const override;

  // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
  Data & Back() override;

  /* ************************************************************************ */

  // Specific member function (inherited from SortableLinearContainer)

  // type Sort() specifiers; // Override SortableLinearContainer member
  void Sort() noexcept override;

protected:

  // Auxiliary functions, if necessary!
  void QuickSort(unsigned long x, unsigned long y) noexcept;
  unsigned long Partition(unsigned long x, unsigned long y) noexcept;

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
