
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data>{//, virtual protected Vector<Data>{
                      // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  // ...
  // using Vector<Data>::size;
  // using Vector<Data>::Elements;
  

public:

  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

protected:

  struct NodeVec : virtual public MutableNode{ // Must extend MutableNode

  public:
    using BinaryTree<Data>::Node::element;
    unsigned long pos;
    Vector<NodeVec*> &vect; //riferimento al vettore della classe BinaryTreeVec

    //BinaryTreeVec * Tree = nullptr;

    //Constructor
    NodeVec() = default;

    NodeVec(Vector<NodeVec*>&, ulong, const Data&);
    NodeVec(Vector<NodeVec*>&, ulong, Data&&);
    NodeVec(const NodeVec&);
    NodeVec(NodeVec&&);

    //Destructor
    virtual ~NodeVec() = default;

    //Specific member functions
    inline const Data & Element() const noexcept override;
    inline Data & Element() noexcept override;

    inline bool IsLeaf() const noexcept override;
    
    inline bool HasLeftChild() const noexcept override;
    inline bool HasRightChild() const noexcept override;

    inline virtual Node & LeftChild() const override;
    inline virtual Node & RightChild() const override;

    inline virtual MutableNode & LeftChild() override;
    inline virtual MutableNode & RightChild() override;
  };

protected:
  Vector<NodeVec*> Elements;
  using BinaryTree<Data>::size;

public:

  // Default constructor
  // BinaryTreeVec() specifiers;
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a MappableContainer
  BinaryTreeVec(const MappableContainer<Data> &);

  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a MutableMappableContainer
  BinaryTreeVec(MutableMappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(const BinaryTreeVec<Data> &);

  // Move constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(BinaryTreeVec<Data> &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeVec() specifiers;
  virtual ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec & operator = (const BinaryTreeVec &);

  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec & operator = (BinaryTreeVec &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const BinaryTreeVec &) const noexcept; 

  // type operator!=(argument) specifiers;
  bool operator != (const BinaryTreeVec &) const noexcept; 

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
  void Clear() noexcept override; 

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)

  // type BreadthFold(arguments) specifiers; // Override BreadthFoldableContainer member
  using typename FoldableContainer<Data>::FoldFunctor;   
  void BreadthFold(FoldFunctor, void* ) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member
  using typename MappableContainer<Data>::MapFunctor;
  void BreadthMap(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableBreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Override MutableBreadthMappableContainer member
  using typename MutableMappableContainer<Data>::MutableMapFunctor;
  void BreadthMap(MutableMapFunctor) override;
  

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
