
#ifndef FOLDABLE_HPP
#define FOLDABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class FoldableContainer : virtual public TestableContainer<Data>{
                          // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~FoldableContainer() specifiers
  virtual ~FoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  FoldableContainer & operator = (const FoldableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  FoldableContainer & operator = (FoldableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const FoldableContainer &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const FoldableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using FoldFunctor = std::function<void(const Data &, void *)>;
  using FoldFunctor = std::function<void(const Data &, void *)>;

  // type Fold(arguments) specifiers;
  virtual void Fold(FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  inline virtual bool Exists(const Data &) const noexcept override;
  

};

/* ************************************************************************** */

template <typename Data>
class PreOrderFoldableContainer : virtual public FoldableContainer<Data> {
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PreOrderFoldableContainer() specifiers
  virtual ~PreOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  PreOrderFoldableContainer & operator = (const PreOrderFoldableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  PreOrderFoldableContainer & operator = (PreOrderFoldableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const PreOrderFoldableContainer &) const noexcept= delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const PreOrderFoldableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type PreOrderFold(arguments) specifiers;
  virtual void PreOrderFold(FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  virtual void Fold(FoldFunctor, void *) const override;
  

};

/* ************************************************************************** */

template <typename Data>
class PostOrderFoldableContainer : virtual public FoldableContainer<Data> {
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PostOrderFoldableContainer() specifiers
  virtual ~PostOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  PostOrderFoldableContainer & operator = (const PostOrderFoldableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  PostOrderFoldableContainer & operator = (PostOrderFoldableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const PostOrderFoldableContainer &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const PostOrderFoldableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type PostOrderFold(arguments) specifiers;
  virtual void PostOrderFold(FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  virtual void Fold(FoldFunctor, void *) const override;

};

/* ************************************************************************** */

template <typename Data>
class InOrderFoldableContainer : virtual public FoldableContainer<Data>{
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~InOrderFoldableContainer() specifiers
  virtual ~InOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  InOrderFoldableContainer & operator = (const InOrderFoldableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  InOrderFoldableContainer & operator = (InOrderFoldableContainer &&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const InOrderFoldableContainer &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const InOrderFoldableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type InOrderFold(arguments) specifiers;
  virtual void InOrderFold(FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  virtual void Fold(FoldFunctor, void *) const override;

};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer : virtual public FoldableContainer<Data> {
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthFoldableContainer() specifiers
  virtual ~BreadthFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  BreadthFoldableContainer operator = (const BreadthFoldableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  BreadthFoldableContainer operator = (BreadthFoldableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const BreadthFoldableContainer &) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const BreadthFoldableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type BreadthFold(arguments) specifiers;
  virtual void BreadthFold(FoldFunctor, void *) const = 0;;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  virtual void Fold(FoldFunctor, void *) const override;

};

/* ************************************************************************** */

}

#include "foldable.cpp"

#endif
