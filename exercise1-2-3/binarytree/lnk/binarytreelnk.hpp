
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual public MutableBinaryTree<Data> {
                      // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  using Container::size;

public:

  // using BinaryTree<Data>::???;
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

  // ...

protected:

  struct NodeLnk : virtual MutableNode { // Must extend MutableNode

  private:

    // ...

  public:

    // ...
    NodeLnk * left = nullptr;
    NodeLnk * right = nullptr;
    Data element;

    //Specific Constructors
    NodeLnk(const Data & data) noexcept : element(data) {};
    NodeLnk(Data && data) noexcept;

    //Copy Constructor
    NodeLnk(const NodeLnk &);

    //Move Constructor
    NodeLnk(NodeLnk &&) noexcept;

    //Destructor
    virtual ~NodeLnk();

    //Copy Assignment
    NodeLnk & operator = (const NodeLnk &);

    //Move Assignment
    NodeLnk & operator = (NodeLnk &&) noexcept;

    //Comparison Operators
    bool operator == (const NodeLnk &) const noexcept;
    inline bool operator != (const NodeLnk &) const noexcept;

    //Specific member function inherited from Node
    inline const Data & Element() const noexcept override;
    inline Data & Element() noexcept override;

    inline bool IsLeaf() const noexcept override;
    
    inline bool HasLeftChild() const noexcept override;
    inline bool HasRightChild() const noexcept override;

    virtual Node & LeftChild() const override;
    virtual Node & RightChild() const override;

    virtual MutableNode & LeftChild() override;
    virtual MutableNode & RightChild() override;

  public:

    // ...

  };

public:

  // Default constructor
  // BinaryTreeLnk() specifiers;
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a MappableContainer
  BinaryTreeLnk(const MappableContainer<Data> &);
  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a MutableMappableContainer
  BinaryTreeLnk(MutableMappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeLnk(argument) specifiers;
  BinaryTreeLnk(const BinaryTreeLnk &);

  // Move constructor
  // BinaryTreeLnk(argument) specifiers;
  BinaryTreeLnk(BinaryTreeLnk &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeLnk() specifiers;
  virtual ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeLnk & operator = (const BinaryTreeLnk &);

  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeLnk & operator = (BinaryTreeLnk &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator == (const BinaryTreeLnk &) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator != (const BinaryTreeLnk &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
  Node & Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)
  MutableNode & Root() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;

  protected:

  NodeLnk * root = nullptr;

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
