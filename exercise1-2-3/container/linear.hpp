
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual public MutablePreOrderMappableContainer<Data>, virtual public MutablePostOrderMappableContainer<Data> {
                        // Must extend MutablePreOrderMappableContainer<Data>,
                        //             MutablePostOrderMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~LinearContainer() specifiers
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  Data & operator = (const Data &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  Data & operator = (Data &&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  bool operator == (const Data &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types is possible.
  bool operator != (const Data &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type operator[](argument) specifiers; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
  virtual const Data & operator[](const unsigned long) const;

  // type operator[](argument) specifiers; // (mutable version; concrete function must throw std::out_of_range when out of range)
  virtual Data & operator[](const unsigned long);

  // type Front() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  const inline virtual Data & Front() const;

  // type Front() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  inline virtual Data & Front();

  // type Back() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  const inline virtual Data & Back() const;

  // type Back() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  inline virtual Data & Back();

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  inline virtual void Fold(FoldFunctor, void *) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderFoldableContainer)

  // type PreOrderFold(arguments) specifiers; // Override PreOrderFoldableContainer member
  inline virtual void PreOrderFold(FoldFunctor, void *) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderFoldableContainer)

  // type PostOrderFold(arguments) specifiers; // Override PostOrderFoldableContainer member
  inline virtual void PostOrderFold(FoldFunctor, void *) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFunctor;
  using typename MappableContainer<Data>::MapFunctor;

  // type Map(argument) specifiers; // Override MappableContainer member
  inline virtual void Map(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member
  inline virtual void PreOrderMap(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member
  inline virtual void PostOrderMap(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;
  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type Map(argument) specifiers; // Override MutableMappableContainer member
  inline virtual void Map(MutableMapFunctor) override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override MutablePreOrderMappableContainer member
  inline virtual void PreOrderMap(MutableMapFunctor) override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override MutablePostOrderMappableContainer member
  inline virtual void PostOrderMap(MutableMapFunctor) override;

};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer : virtual public LinearContainer<Data> {
                                // Must extend LinearContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~SortableLinearContainer() specifiers
  virtual ~SortableLinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  Data & operator = (const Data &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  Data & operator = (Data &&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  bool operator == (const Data &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types is possible.
  bool operator != (const Data &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // type Sort() specifiers;
  virtual void Sort() noexcept = 0;

};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
