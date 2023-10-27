
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  // ...
  unsigned long size = 0;

public:

  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */
  
  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  Container & operator = (const Container &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  Container & operator = (Container &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator = (const Container &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const Container &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Empty() specifiers; // (concrete function should not throw exceptions)
  inline virtual bool Empty() const noexcept {
    return (size == 0);
  }

  // type Size() specifiers; // (concrete function should not throw exceptions)
  inline virtual unsigned long Size() const noexcept {
    return size;
  }

};

/* ************************************************************************** */

class ClearableContainer: virtual public Container {
                            // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~ClearableContainer() specifiers
  virtual ~ClearableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  ClearableContainer & operator = (const ClearableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  ClearableContainer & operator = (ClearableContainer &&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator = (const ClearableContainer &) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const ClearableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function
  // type Clear() specifiers;
  virtual void Clear() = 0;

};

/* ************************************************************************** */

class ResizableContainer : virtual public ClearableContainer {
                            // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~ResizableContainer() specifiers
  virtual ~ResizableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  ResizableContainer & operator = (const ResizableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  ResizableContainer & operator = (ResizableContainer &&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const ResizableContainer &) const noexcept = delete;
  
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const ResizableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function
  // type Resize(argument) specifiers;
  virtual void Resize(unsigned long) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)
  // type Clear() specifiers; // Override ClearableContainer member
  inline void Clear() override {
    Resize(0);
  }

};

/* ************************************************************************** */

}

#endif
