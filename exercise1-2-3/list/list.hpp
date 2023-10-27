
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/dictionary.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public ClearableContainer, virtual public DictionaryContainer<Data>, virtual public LinearContainer<Data>{
              // Must extend ClearableContainer,
              //             DictionaryContainer<Data>,
              //             LinearContainer<Data>

private:

  // ...

protected:

  // using Container::???;
  using Container::size;

  struct Node {

    // Data
    Data element;
    // ...
    Node * next = nullptr;


    /* ********************************************************************** */

    // Specific constructors
    inline Node() = default;
    // ...
    inline Node(const Data & data) : element(data) {};
    inline Node(Data &&) noexcept;

    /* ********************************************************************** */

    // Copy constructor
    inline Node(const Node & node) : element(node.element) {};
    // ...

    // Move constructor
    inline Node(Node && node) noexcept;
    // ...

    /* ********************************************************************** */

    // Destructor
    virtual ~Node();
    // ...

    /* ********************************************************************** */

    // Comparison operators
    bool operator == (const Node &) const noexcept;
    inline bool operator != (const Node &) const noexcept;
    // ...

    /* ********************************************************************** */

    // Specific member functions
    virtual Node * Clone(Node *);
    // ...

  };

  // ...
  Node * head = nullptr;
  Node * tail = nullptr;

public:

  // Default constructor
  // List() specifiers;
  List() = default;

  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a MappableContainer
  List(const MappableContainer<Data> &);

  // List(argument) specifiers; // A list obtained from a MutableMappableContainer
  List(MutableMappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  // List(argument) specifiers;
  List(const List &);

  // Move constructor
  // List(argument) specifiers;
  List(List &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~List() specifiers;
  virtual ~List();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  List & operator = (const List &);

  // Move assignment
  // type operator=(argument) specifiers;
  List & operator = (List &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator == (const List &) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator != (const List &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type InsertAtFront(argument) specifier; // Copy of the value
  void InsertAtFront(const Data &);
  // type InsertAtFront(argument) specifier; // Move of the value
  void InsertAtFront(Data &&) noexcept;
  // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
  void RemoveFromFront();
  // type FrontNRemove() specifier; // (must throw std::length_error when empty)
  Data FrontNRemove();

  // type InsertAtBack(argument) specifier; // Copy of the value
  void InsertAtBack(const Data &);

  // type InsertAtBack(argument) specifier; // Move of the value
  void InsertAtBack(Data &&) noexcept;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifier; // Copy of the value
  bool Insert(const Data & data);

  // type Insert(argument) specifier; // Move of the value
  bool Insert(Data && data) noexcept;

  // type Remove(argument) specifier;
  bool Remove(const Data & data);

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

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  inline void Fold(FoldFunctor, void *) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderFoldableContainer)

  // type PreOrderFold(arguments) specifiers; // Override PreOrderFoldableContainer member
  inline void PreOrderFold(FoldFunctor, void *) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderFoldableContainer)

  // type PostOrderFold(arguments) specifiers; // Override PostOrderFoldableContainer member
  inline void PostOrderFold(FoldFunctor, void *) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFunctor;
  using typename MappableContainer<Data>::MapFunctor;


  // type Map(argument) specifiers; // Override MappableContainer member
  inline void Map(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member
  void PreOrderMap(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member
  void PostOrderMap(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;
  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type Map(argument) specifiers; // Override MutableMappableContainer member
  void Map(MutableMapFunctor) override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override MutablePreOrderMappableContainer member
  void PreOrderMap(MutableMapFunctor) override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override MutablePostOrderMappableContainer member
  void PostOrderMap(MutableMapFunctor) override;

protected:

  // Auxiliary member functions (for PreOrderFoldableContainer & PostOrderFoldableContainer)

  // type PreOrderFold(arguments) specifiers; // Accessory function executing from one point of the list onwards
  void PreOrderFold(FoldFunctor, void *, const Node *) const;

  // type PostOrderFold(arguments) specifiers; // Accessory function executing from one point of the list onwards
  void PostOrderFold(FoldFunctor, void *, const Node *) const;

  /* ************************************************************************ */

  // Auxiliary member functions (for PreOrderMappableContainer & PostOrderMappableContainer)

  // type PreOrderMap(arguments) specifiers; // Accessory function executing from one point of the list onwards
  void PreOrderMap(MapFunctor, const Node *) const;

  // type PostOrderMap(arguments) specifiers; // Accessory function executing from one point of the list onward
  void PostOrderMap(MapFunctor, const Node *) const;

  /* ************************************************************************ */

  // Auxiliary member functions (for MutablePreOrderMappableContainer & MutablePostOrderMappableContainer)

  // type PreOrderMap(arguments) specifiers; // Accessory function executing from one point of the list onwards
  void PreOrderMap(MutableMapFunctor, Node *);

  // type PostOrderMap(arguments) specifiers; // Accessory function executing from one point of the list onward
  void PostOrderMap(MutableMapFunctor, Node *);

  /* ************************************************************************ */

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
