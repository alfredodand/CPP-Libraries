
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : virtual public PreOrderMappableContainer<Data>, virtual public PostOrderMappableContainer<Data>, 
								  virtual public InOrderMappableContainer<Data>, virtual public BreadthMappableContainer<Data> {
					// Must extend PreOrderMappableContainer<Data>,
					//             PostOrderMappableContainer<Data>,
					//             InOrderMappableContainer<Data>,
					//             BreadthMappableContainer<Data>

private:

  // ...

protected:

  using Container::size;

public:

  struct Node {

  protected:

	// Comparison operators
	// type operator==(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.
	bool operator == (const Node &) const noexcept;
	// type operator!=(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.
	bool operator != (const Node &) const noexcept;

  public:

  Data element;

	// friend class BinaryTree<Data>;
	friend class BinaryTree<Data>; //per avere accesso ai campi protetti del nodo da BinaryTree

	/* ********************************************************************** */

	// Destructor
	// ~Node() specifiers
	virtual ~Node() = default;

	/* ********************************************************************** */

	// Copy assignment
	// type operator=(argument); // Copy assignment of abstract types should not be possible.
	Node & operator = (const Node &) = delete;

	// Move assignment
	// type operator=(argument); // Move assignment of abstract types should not be possible.
	Node & operator = (Node &&) noexcept = delete;

	/* ********************************************************************** */

	// Specific member functions

	// type Element() specifiers; // Immutable access to the element (concrete function should not throw exceptions)
	virtual const Data & Element() const noexcept = 0;

	// type Element() specifiers; // Mutable access to the element (concrete function should not throw exceptions)
	virtual Data & Element() noexcept = 0;

	// type IsLeaf() specifiers; // (concrete function should not throw exceptions)
	virtual bool IsLeaf() const noexcept = 0;

	// type HasLeftChild() specifiers; // (concrete function should not throw exceptions)
	virtual bool HasLeftChild() const noexcept = 0;

	// type HasRightChild() specifiers; // (concrete function should not throw exceptions)
	virtual bool HasRightChild() const noexcept = 0;

	// type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
	virtual Node & LeftChild() const = 0;
	// type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
	virtual Node & RightChild() const = 0;

  };

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTree() specifiers
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  BinaryTree & operator = (const BinaryTree &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
   BinaryTree & operator = (BinaryTree &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract binary tree is possible.
  bool operator == (const BinaryTree &) const noexcept;
  // type operator!=(argument) specifiers; // Comparison of abstract binary tree is possible.
  bool operator != (const BinaryTree &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)
  virtual Node & Root() const = 0; 

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  virtual void Fold(FoldFunctor, void *) const override;

  virtual void PreOrderFold(FoldFunctor, void*) const override;
  virtual void PostOrderFold(FoldFunctor, void*) const override;
  virtual void InOrderFold(FoldFunctor, void*) const override; 
  virtual void BreadthFold(FoldFunctor, void*) const override; 

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFunctor;
  using typename MappableContainer<Data>::MapFunctor;

  // type Map(arguments) specifiers; // Override MappableContainer member
  virtual void Map(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(arguments) specifiers; // Override PreOrderMappableContainer member
  virtual void PreOrderMap(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(arguments) specifiers; // Override PostOrderMappableContainer member
  virtual void PostOrderMap(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderMappableContainer)

  // type InOrderMap(arguments) specifiers; // Override InOrderMappableContainer member
  virtual void InOrderMap(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member
  virtual void BreadthMap(MapFunctor) const override;

protected:
  virtual void PreOrderFold(FoldFunctor, void*, Node&) const;
  virtual void PostOrderFold(FoldFunctor, void*, Node&) const;
  virtual void InOrderFold(FoldFunctor, void*, Node&) const; 
  virtual void BreadthFold(FoldFunctor, void*, Node&) const;

  //funzione ausiliaria
  bool Compare(Node &, Node &) const noexcept;

  // Auxiliary member function (for PreOrderMappableContainer)

  // type PreOrderMap(arguments) specifiers; // Accessory function executing from one node of the tree
  void PreOrderMap(MapFunctor, const Node *) const;

  /* ************************************************************************ */

  // Auxiliary member function (for PostOrderMappableContainer)

  // type PostOrderMap(arguments) specifiers; // Accessory function executing from one node of the tree
  void PostOrderMap(MapFunctor, const Node *) const;

  /* ************************************************************************ */

  // Auxiliary member function (for InOrderMappableContainer)

  // type InOrderMap(arguments) specifiers; // Accessory function executing from one node of the tree
  void InOrderMap(MapFunctor, const Node *) const;

  /* ************************************************************************ */

  // Auxiliary member function (for BreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Accessory function executing from one node of the tree
  void BreadthMap(MapFunctor, Node *) const;

};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree : virtual public ClearableContainer, virtual public BinaryTree<Data>, 
										virtual public MutablePreOrderMappableContainer<Data>,
										virtual public MutablePostOrderMappableContainer<Data>,
										virtual public MutableInOrderMappableContainer<Data>,
										virtual public MutableBreadthMappableContainer<Data> {
						  // Must extend ClearableContainer,
						  //             BinaryTree<Data>,
						  //             MutablePreOrderMappableContainer<Data>,
						  //             MutablePostOrderMappableContainer<Data>,
						  //             MutableInOrderMappableContainer<Data>,
						  //             MutableBreadthMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  using typename BinaryTree<Data>::Node;

  struct MutableNode : virtual public Node {
						// Must extend Node

	// friend class MutableBinaryTree<Data>;
	friend class MutableBinaryTree<Data>;

	/* ********************************************************************** */

	// Destructor
	// ~MutableNode() specifiers
	virtual ~MutableNode() = default;

	/* ********************************************************************** */

	// Copy assignment
	// type operator=(argument); // Copy assignment of abstract types should not be possible.
	MutableNode & operator = (const MutableNode &) = delete;

	// Move assignment
	// type operator=(argument); // Move assignment of abstract types should not be possible.
	MutableNode & operator = (MutableNode &&) noexcept = delete;

	/* ********************************************************************** */

	// Specific member functions

	// type Element() specifiers; // Mutable access to the element (concrete function should not throw exceptions)
	inline virtual Data & Element() noexcept = 0;

	// type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
	virtual MutableNode & LeftChild() = 0;

	// type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
	virtual MutableNode & RightChild() = 0;

  };

  /* ************************************************************************ */

  // Destructor
  // ~MutableBinaryTree() specifiers
  virtual ~MutableBinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  MutableBinaryTree & operator = (const MutableBinaryTree &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  MutableBinaryTree & operator = (MutableBinaryTree &&) noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)
  virtual MutableNode & Root() = 0; 

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;
  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type Map(arguments) specifiers; // Override MutableMappableContainer member
  virtual void Map(MutableMapFunctor) override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePreOrderMappableContainer)

  // type PreOrderMap(arguments) specifiers; // Override MutablePreOrderMappableContainer member
  virtual void PreOrderMap(MutableMapFunctor) override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePostOrderMappableContainer)

  // type PostOrderMap(arguments) specifiers; // Override MutablePostOrderMappableContainer member
  virtual void PostOrderMap(MutableMapFunctor) override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableInOrderMappableContainer)

  // type InOrderMap(arguments) specifiers; // Override MutableInOrderMappableContainer member
  virtual void InOrderMap(MutableMapFunctor) override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Override MutableBreadthMappableContainer member
  virtual void BreadthMap(MutableMapFunctor) override;

protected:

  // Auxiliary member function (for MutablePreOrderMappableContainer)

  // type PreOrderMap(arguments) specifiers; // Accessory function executing from one node of the tree
  void PreOrderMap(MutableMapFunctor, MutableNode *);

  /* ************************************************************************ */

  // Auxiliary member function (for MutablePostOrderMappableContainer)

  // type PostOrderMap(arguments) specifiers; // Accessory function executing from one node of the tree
  void PostOrderMap(MutableMapFunctor, MutableNode *);

  /* ************************************************************************ */

  // Auxiliary member function (for MutableInOrderMappableContainer)

  // type InOrderMap(arguments) specifiers; // Accessory function executing from one node of the tree
  void InOrderMap(MutableMapFunctor, MutableNode *);

  /* ************************************************************************ */

  // Auxiliary member function (for MutableBreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Accessory function executing from one node of the tree
  void BreadthMap(MutableMapFunctor, MutableNode *);

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data> {
						   // Must extend ForwardIterator<Data>,
						   //             ResettableIterator<Data>

private:

  // ...

  StackLst<typename BinaryTree<Data>::Node*> stk;
  typename  BinaryTree<Data>::Node * current = nullptr;
  typename BinaryTree<Data>::Node * root;

protected:

  // ...

public:

  // Specific constructors
  // BTPreOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTPreOrderIterator(const BinaryTree<Data> &); 

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(const BTPreOrderIterator<Data> &);
  

  // Move constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(BTPreOrderIterator<Data> &&) noexcept;
  

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderIterator() specifiers;
  virtual ~BTPreOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator & operator = (const BTPreOrderIterator&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator & operator = (BTPreOrderIterator &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const BTPreOrderIterator &) const noexcept;
  
  // type operator!=(argument) specifiers;
  bool operator != (const BTPreOrderIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data & operator*() const; 

  // type Terminated() specifiers; // (should not throw exceptions)
  bool Terminated() const noexcept;  

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  void operator++();

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept;

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTPreOrderIterator<Data> {
								  // Must extend MutableIterator<Data>,
								  //             BTPreOrderIterator<Data>

private:

  // ...
  StackLst<typename MutableBinaryTree<Data>::MutableNode*> stk;
  typename MutableBinaryTree<Data>::MutableNode * current = nullptr;
  typename MutableBinaryTree<Data>::MutableNode * root;

protected:

  // ...

public:

  // Specific constructors
  // BTPreOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  BTPreOrderMutableIterator(MutableBinaryTree<Data> & tree) : BTPreOrderIterator<Data>(tree) {};

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderMutableIterator(argument) specifiers;
  BTPreOrderMutableIterator(const BTPreOrderMutableIterator<Data> & iterator) : BTPreOrderIterator<Data>(iterator) {};

  // Move constructor
  // BTPreOrderMutableIterator(argument) specifiers;
  BTPreOrderMutableIterator(BTPreOrderMutableIterator<Data> && iterator) noexcept : BTPreOrderIterator<Data>(std::move(iterator)) {};

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderMutableIterator() specifiers;
  virtual ~BTPreOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPreOrderMutableIterator & operator = (const BTPreOrderMutableIterator & iterator){
    return BTPreOrderIterator<Data>::operator=(iterator);
  }

  // Move assignment
  // type operator=(argument) specifiers;
  BTPreOrderMutableIterator & operator = (BTPreOrderMutableIterator && iterator) noexcept{
    return BTPreOrderIterator<Data>::operator=(std::move(iterator));
  }

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const BTPreOrderMutableIterator & iterator) const noexcept{
    return BTPreOrderIterator<Data>::operator==(iterator);
  }

  // type operator!=(argument) specifiers;
  bool operator != (const BTPreOrderMutableIterator & iterator) const noexcept{
    return BTPreOrderIterator<Data>::operator!=(iterator);
  }

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data & operator*() override {
	if(current != nullptr){
	  return const_cast<Data&>(current->element);
	} else {
	  throw std::out_of_range("Iteratore terminato");
	}
  };
};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data> {
							// Must extend ForwardIterator<Data>,
							//             ResettableIterator<Data>

private:

  // ...

  StackLst<typename BinaryTree<Data>::Node*> stk;
  typename BinaryTree<Data>::Node * current = nullptr;
  typename BinaryTree<Data>::Node * root;

protected:

  // ...

public:

  // Specific constructors
  // BTPostOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTPostOrderIterator(const BinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderIterator(argument) specifiers; 
  BTPostOrderIterator(const BTPostOrderIterator<Data> &);

  // Move constructor
  // BTPostOrderIterator(argument) specifiers;
  BTPostOrderIterator(BTPostOrderIterator<Data> &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderIterator() specifiers;
  virtual ~BTPostOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPostOrderIterator & operator = (const BTPostOrderIterator &);

  // Move assignment
  // type operator=(argument) specifiers;
  BTPostOrderIterator & operator = (BTPostOrderIterator &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const BTPostOrderIterator &) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator != (const BTPostOrderIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data & operator*() const; 

  // type Terminated() specifiers; // (should not throw exceptions)
  bool Terminated() const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated) 
  void operator++(); 

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept;

  //Funzione ausiliaria
  void LeafFarLeft();

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTPostOrderIterator<Data> {
								  // Must extend MutableIterator<Data>,
								  //             BTPostOrderIterator<Data>

private:

  // ...
  StackLst<typename MutableBinaryTree<Data>::MutableNode*> stk;
  typename MutableBinaryTree<Data>::MutableNode * current = nullptr;
  typename MutableBinaryTree<Data>::MutableNode * root;

protected:

  // ...

public:

  // Specific constructors
  // BTPostOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  BTPostOrderMutableIterator(MutableBinaryTree<Data> & tree) : BTPostOrderIterator<Data>(tree) {};

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderMutableIterator(argument) specifiers;
  BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data> & iterator) : BTPostOrderIterator<Data>(iterator) {};


  // Move constructor
  // BTPostOrderMutableIterator(argument) specifiers;
  BTPostOrderMutableIterator(BTPostOrderMutableIterator<Data> && iterator) noexcept : BTPostOrderIterator<Data>(std::move(iterator)) {};

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderMutableIterator() specifiers;
  virtual ~BTPostOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPostOrderMutableIterator & operator = (const BTPostOrderMutableIterator & iterator){
    return BTPostOrderIterator<Data>::operator=(iterator);
  }

  // Move assignment
  // type operator=(argument) specifiers;
  BTPostOrderMutableIterator & operator = (BTPostOrderMutableIterator && iterator) noexcept{
    return BTPostOrderIterator<Data>::operator=(std::move(iterator));
  }

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const BTPostOrderMutableIterator & iterator) const noexcept{
    return BTPostOrderIterator<Data>::operator==(iterator);
  }

  // type operator!=(argument) specifiers;
  bool operator != (const BTPostOrderMutableIterator & iterator) const noexcept{
    return BTPostOrderIterator<Data>::operator!=(iterator);
  }

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data & operator*() override {
	if(current != nullptr){
	  return const_cast<Data&>(current->element);
	} else {
	  throw std::out_of_range("Iteratore terminato");
	}
  };

  //Funzione ausiliaria
  void LeafFarLeft();

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>{
						  // Must extend ForwardIterator<Data>,
						  //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...

  StackLst<typename BinaryTree<Data>::Node*> stk;
  typename BinaryTree<Data>::Node * current = nullptr;
  typename BinaryTree<Data>::Node * root;

public:

  // Specific constructors
  // BTInOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTInOrderIterator(const BinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderIterator(argument) specifiers;
  BTInOrderIterator(const BTInOrderIterator<Data> &);

  // Move constructor
  // BTInOrderIterator(argument) specifiers;
  BTInOrderIterator(BTInOrderIterator<Data> &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderIterator() specifiers;
  virtual ~BTInOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTInOrderIterator & operator = (const BTInOrderIterator &);

  // Move assignment
  // type operator=(argument) specifiers;
  BTInOrderIterator & operator = (BTInOrderIterator &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const BTInOrderIterator &) const noexcept;
  
  // type operator!=(argument) specifiers;
  bool operator != (const BTInOrderIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data & operator*() const;

  // type Terminated() specifiers; // (should not throw exceptions)
  bool Terminated() const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated) 
  void operator++(); 

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept;

protected:

  //Funzione ausiliaria
  void FarLeft();

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTInOrderIterator<Data> {
								  // Must extend MutableIterator<Data>,
								  //             BTInOrderIterator<Data>

private:

  // ...

protected:

  // ...
  StackLst<typename MutableBinaryTree<Data>::MutableNode*> stk;
  typename MutableBinaryTree<Data>::MutableNode * current = nullptr;
  typename MutableBinaryTree<Data>::MutableNode * root;

public:

  // Specific constructors
  // BTInOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  BTInOrderMutableIterator(MutableBinaryTree<Data> & tree) : BTInOrderIterator<Data>(tree) {};

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderMutableIterator(argument) specifiers;
  BTInOrderMutableIterator(const BTInOrderMutableIterator<Data> & iterator) : BTInOrderIterator<Data>(iterator) {};

  // Move constructor
  // BTInOrderMutableIterator(argument) specifiers;
  BTInOrderMutableIterator(BTInOrderMutableIterator<Data> && iterator) noexcept : BTInOrderIterator<Data>(std::move(iterator)) {};

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderMutableIterator() specifiers;
  virtual ~BTInOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTInOrderMutableIterator & operator = (const BTInOrderMutableIterator & iterator){
    return BTInOrderIterator<Data>::operator=(iterator);
  }

  // Move assignment
  // type operator=(argument) specifiers;
  BTInOrderMutableIterator & operator = (BTInOrderMutableIterator && iterator) noexcept{
    return BTInOrderIterator<Data>::operator=(std::move(iterator));
  }

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const BTInOrderMutableIterator & iterator) const noexcept{
    return BTInOrderIterator<Data>::operator==(iterator);
  }

  // type operator!=(argument) specifiers;
  bool operator != (const BTInOrderMutableIterator & iterator) const noexcept{
    return BTInOrderIterator<Data>::operator!=(iterator);
  }

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data & operator*() override {
	if(current != nullptr){
	  return const_cast<Data&>(current->element);
	} else {
	  throw std::out_of_range("Iteratore terminato");
	}
  };

protected:

  //Funzione ausiliaria
  void FarLeft();

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>{
						  // Must extend ForwardIterator<Data>,
						  //             ResettableIterator<Data>

private:

  // ...

  QueueLst<typename BinaryTree<Data>::Node*> queue;
  typename BinaryTree<Data>::Node * current = nullptr;
  typename BinaryTree<Data>::Node * root;

protected:

  // ...

public:

  // Specific constructors
  // BTBreadthIterator(argument) specifiers; // An iterator over a given binary tree
  BTBreadthIterator(const BinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthIterator(argument) specifiers; 
  BTBreadthIterator(const BTBreadthIterator<Data> &);

  // Move constructor
  // BTBreadthIterator(argument) specifiers;
  BTBreadthIterator(BTBreadthIterator<Data> &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthIterator() specifiers;
  virtual ~BTBreadthIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTBreadthIterator & operator = (const BTBreadthIterator &);

  // Move assignment
  // type operator=(argument) specifiers;
  BTBreadthIterator & operator = (BTBreadthIterator &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const BTBreadthIterator &) const noexcept;
  
  // type operator!=(argument) specifiers;
  bool operator != (const BTBreadthIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data & operator*() const; 

  // type Terminated() specifiers; // (should not throw exceptions)
  bool Terminated() const noexcept; 

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  void operator++(); 

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept;

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator : virtual public MutableIterator<Data>, virtual public BTBreadthIterator<Data>{
								  // Must extend MutableIterator<Data>,
								  //             BTBreadthIterator<Data>

private:

  // ...

protected:

  // ...
  QueueLst<typename MutableBinaryTree<Data>::MutableNode*> queue;
  typename MutableBinaryTree<Data>::MutableNode * current = nullptr;
  typename MutableBinaryTree<Data>::MutableNode * root;

public:

  // Specific constructors
  // BTBreadthMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  BTBreadthMutableIterator(MutableBinaryTree<Data> & tree) : BTBreadthIterator<Data>(tree) {};

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthMutableIterator(argument) specifiers;
  BTBreadthMutableIterator(const BTBreadthMutableIterator<Data> & iterator) : BTBreadthIterator<Data>(iterator) {};

  // Move constructor
  // BTBreadthMutableIterator(argument) specifiers;
  BTBreadthMutableIterator(BTBreadthMutableIterator<Data> && iterator) noexcept : BTBreadthIterator<Data>(std::move(iterator)) {};

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthMutableIterator() specifiers;
  virtual ~BTBreadthMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTBreadthMutableIterator & operator = (const BTBreadthMutableIterator & iterator){
    return BTBreadthIterator<Data>::operator=(iterator);
  }

  // Move assignment
  // type operator=(argument) specifiers;
  BTBreadthMutableIterator & operator = (BTBreadthMutableIterator && iterator) noexcept{
    return BTBreadthIterator<Data>::operator=(std::move(iterator));
  }

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const BTBreadthMutableIterator & iterator) const noexcept{
    return BTBreadthIterator<Data>::operator==(iterator);
  }

  // type operator!=(argument) specifiers;
  bool operator != (const BTBreadthMutableIterator & iterator) const noexcept{
    return BTBreadthIterator<Data>::operator!=(iterator);
  }

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data & operator*() override {
	if(current != nullptr){
	  return const_cast<Data&>(current->element);
	} else {
	  throw std::out_of_range("Iteratore terminato");
	}
  };

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
