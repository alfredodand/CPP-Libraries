
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "foldable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer : virtual public FoldableContainer<Data>{
                          // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MappableContainer() specifiers
  virtual ~MappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  MappableContainer & operator = (const MappableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  MappableContainer & operator = (MappableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const MappableContainer &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const MappableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using MapFunctor = std::function<void(const Data &)>;
  using MapFunctor = std::function<void(const Data &)>;

  // type Map(argument) specifiers;
  virtual void Map(MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  inline void Fold(FoldFunctor, void *) const override;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer : virtual public MappableContainer<Data>, virtual public PreOrderFoldableContainer<Data>{
                                  // Must extend MappableContainer<Data>,
                                  //             PreOrderFoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PreOrderMappableContainer() specifiers
  virtual ~PreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  PreOrderMappableContainer & operator = (const PreOrderMappableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  PreOrderMappableContainer & operator = (PreOrderMappableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const PreOrderMappableContainer &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const PreOrderMappableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFunctor;
  using typename MappableContainer<Data>::MapFunctor;

  // type PreOrderMap(argument) specifiers;
  virtual void PreOrderMap(MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  virtual void Map(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  virtual void Fold(FoldFunctor, void *) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderFoldableContainer)

  // type PreOrderFold(arguments) specifiers; // Override PreOrderFoldableContainer memberF
  virtual void PreOrderFold(FoldFunctor, void *) const override;

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer : virtual public MappableContainer<Data>, virtual public PostOrderFoldableContainer<Data>{
                                  // Must extend MappableContainer<Data>,
                                  //             PostOrderFoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PostOrderMappableContainer() specifiers
  virtual ~PostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  PostOrderMappableContainer & operator = (const PostOrderMappableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  PostOrderMappableContainer & operator = (PostOrderMappableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const PostOrderMappableContainer &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const PostOrderMappableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFunctor;
  using typename MappableContainer<Data>::MapFunctor;

  // type PostOrderMap(argument) specifiers;
  virtual void PostOrderMap(MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  virtual void Map(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  virtual void Fold(FoldFunctor, void *) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderFoldableContainer)

  // type PostOrderFold(arguments) specifiers; // Override PostOrderFoldableContainer member
  virtual void PostOrderFold(FoldFunctor, void *) const override;

};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer : virtual public MappableContainer<Data>, virtual public InOrderFoldableContainer<Data>{
                                  // Must extend MappableContainer<Data>,
                                  //             InOrderFoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~InOrderMappableContainer() specifiers
  virtual ~InOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  InOrderMappableContainer & operator = (const InOrderMappableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  InOrderMappableContainer & operator = (InOrderMappableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const InOrderMappableContainer &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const InOrderMappableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFunctor;
  using typename MappableContainer<Data>::MapFunctor;

  // type InOrderMap(argument) specifiers;
  virtual void InOrderMap(MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  virtual void Map(MapFunctor)const override;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  virtual void Fold(FoldFunctor, void *)const override;

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderFoldableContainer)

  // type InOrderFold(arguments) specifiers; // Override InOrderFoldableContainer member
  virtual void InOrderFold(FoldFunctor, void *) const override;

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer : virtual public MappableContainer<Data>, virtual public BreadthFoldableContainer<Data>{
                                  // Must extend MappableContainer<Data>,
                                  //             BreadthFoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthMappableContainer() specifiers
  virtual ~BreadthMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  BreadthMappableContainer & operator = (const BreadthMappableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  BreadthMappableContainer & operator = (BreadthMappableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const BreadthMappableContainer &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const BreadthMappableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFunctor;
  using typename MappableContainer<Data>::MapFunctor;

  // type BreadthMap(argument) specifiers;
  virtual void BreadthMap(MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  virtual void Map(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  virtual void Fold(FoldFunctor, void *)const override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthFoldableContainer)

  // type BreadthFold(arguments) specifiers; // Override BreadthFoldableContainer member
  virtual void BreadthFold(FoldFunctor, void *) const override;

};

/* ************************************************************************** */

template <typename Data>
class MutableMappableContainer : virtual public MappableContainer<Data>{
                                  // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MutableMappableContainer() specifiers
  virtual ~MutableMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  MutableMappableContainer & operator = (const MutableMappableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  MutableMappableContainer & operator = (MutableMappableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const MutableMappableContainer &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const MutableMappableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using MutableMapFunctor = std::function<void(Data &)>;
  using MutableMapFunctor = std::function<void(Data &)>;

  // type Map(argument) specifiers;
  virtual void Map(MutableMapFunctor) = 0;

};

/* ************************************************************************** */

template <typename Data>
class MutablePreOrderMappableContainer : virtual public MutableMappableContainer<Data>, virtual public PreOrderMappableContainer<Data>{
                                          // Must extend MutableMappableContainer<Data>,
                                          //             PreOrderMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MutablePreOrderMappableContainer() specifiers
  virtual ~MutablePreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  MutablePreOrderMappableContainer & operator = (const MutablePreOrderMappableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  MutablePreOrderMappableContainer & operator = (MutablePreOrderMappableContainer &&)noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const MutablePreOrderMappableContainer &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const MutablePreOrderMappableContainer &) const noexcept = delete;
  /* ************************************************************************ */

  // Specific member function

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;
  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type PreOrderMap(argument) specifiers;
  virtual void PreOrderMap(MutableMapFunctor) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // type Map(argument) specifiers; // Override MutableMappableContainer member
  virtual void Map(MutableMapFunctor) override;

};

/* ************************************************************************** */

template <typename Data>
class MutablePostOrderMappableContainer : virtual public MutableMappableContainer<Data>, virtual public PostOrderMappableContainer<Data>{
                                          // Must extend MutableMappableContainer<Data>,
                                          //             PostOrderMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MutablePostOrderMappableContainer() specifiers
  virtual ~MutablePostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  MutablePostOrderMappableContainer & operator = (const MutablePostOrderMappableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  MutablePostOrderMappableContainer & operator = (MutablePostOrderMappableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const MutablePostOrderMappableContainer &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const MutablePostOrderMappableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;
  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type PostOrderMap(argument) specifiers;
  virtual void PostOrderMap(MutableMapFunctor) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // type Map(argument) specifiers; // Override MutableMappableContainer member
  virtual void Map(MutableMapFunctor) override;

};

/* ************************************************************************** */

template <typename Data>
class MutableInOrderMappableContainer : virtual public MutableMappableContainer<Data>, virtual public InOrderMappableContainer<Data>{
                                        // Must extend MutableMappableContainer<Data>,
                                        //             InOrderMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MutableInOrderMappableContainer() specifiers
  virtual ~MutableInOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  MutableInOrderMappableContainer & operator = (const MutableInOrderMappableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  MutableInOrderMappableContainer & operator = (MutableInOrderMappableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const MutableInOrderMappableContainer &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const MutableInOrderMappableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;
  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type InOrderMap(argument) specifiers;
  virtual void InOrderMap(MutableMapFunctor) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // type Map(argument) specifiers; // Override MutableMappableContainer member
  virtual void Map(MutableMapFunctor) override;

};

/* ************************************************************************** */

template <typename Data>
class MutableBreadthMappableContainer : virtual public MutableMappableContainer<Data>, virtual public BreadthMappableContainer<Data>{
                                        // Must extend MutableMappableContainer<Data>,
                                        //             BreadthMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MutableBreadthMappableContainer() specifiers
  virtual ~MutableBreadthMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  MutableBreadthMappableContainer & operator = (const MutableBreadthMappableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  MutableBreadthMappableContainer & operator = (MutableBreadthMappableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const MutableBreadthMappableContainer &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const MutableBreadthMappableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;
  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type BreadthMap(argument) specifiers;
  virtual void BreadthMap(MutableMapFunctor) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // type Map(argument) specifiers; // Override MutableMappableContainer member
  virtual void Map(MutableMapFunctor) override;

};

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif
