# CPP-Libraries

A comprehensive collection of custom C++ implementations of fundamental data structures and a series of educational examples demonstrating advanced C++ language features.

## 📚 Core Libraries (`exercise1-2-3`)

The main part of this repository focuses on the implementation of a robust container hierarchy. The libraries are designed using an interface-driven approach to ensure consistency and flexibility.

### Container Hierarchy
The implementations follow a structured hierarchy of interfaces:
- **Container**: The base interface for all collections.
- **Linear**: For sequences with a defined order.
- **Foldable**: For containers that can be reduced to a single value.
- **Mappable**: For containers that support mapping functions.
- **Dictionary**: For key-value pair storage.
- **Testable**: Interface used for automated validation and testing.

### Implemented Data Structures
- **Vector**: A dynamic array implementation providing efficient random access.
- **List**: A doubly-linked list implementation for efficient insertions and deletions.
- **Stack**: LIFO (Last-In, First-Out) structure, implemented with both Vector and List backends.
- **Queue**: FIFO (First-In, First-Out) structure, implemented with both Vector and List backends.
- **Binary Tree**: General binary tree implementation, available in both Linked and Vector representations.
- **BST (Binary Search Tree)**: An optimized binary tree for efficient searching, insertion, and deletion.
- **Hash Table**: A high-performance map implementation featuring multiple collision resolution strategies:
  - **Closed Addressing** (Chaining)
  - **Open Addressing**

---

## 🎓 Examples

The `examples/` directory contains a curated set of small projects designed to illustrate specific C++ concepts:
- **Basic & Structured**: Minimal programs, basic types, and structured data.
- **Memory Management**: Manual allocation and pointer usage.
- **C++ Fundamentals**: I/O streams, `std::string`, and class design.
- **Advanced Topics**: 
  - Exception handling
  - Function pointers
  - Templates and Generic Programming

---

## 🚀 Getting Started

### Requirements
- **Compiler**: `g++` supporting the **C++20** standard.
- **OS**: Linux or macOS (due to the use of shell scripts).

### Compilation & Execution
To compile and run the main library tests:

1. Navigate to the `exercise1-2-3` directory:
   ```bash
   cd exercise1-2-3
   ```
2. Execute the build script:
   ```bash
   chmod +x build.sh
   ./build.sh
   ```
3. Run the generated binary:
   ```bash
   ./main
   ```

### Technical Notes
The build process uses the following flags for maximum performance and reliability:
- `-O3`: High-level optimization.
- `-std=c++20`: Enables the latest C++20 features.
- `-fsanitize=address`: Enables AddressSanitizer to detect memory leaks and buffer overflows during development.
