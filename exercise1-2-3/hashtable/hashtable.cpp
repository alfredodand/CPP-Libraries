#include<string>
#include <cmath>

namespace lasd {

/* ************************************************************************** */

template<>
class Hashable<int>{
    public:
    unsigned long operator()(const int & data) const noexcept{
        return (data * data);
    }
};

template<>
class Hashable<double>{
    public:
    unsigned long operator()(const double & data) const noexcept{
        long intPart = std::floor(data);
        long fract = pow(2,24) * (data - intPart);
        return (intPart * fract);
    }
};

template<>
class Hashable<std::string>{
    public:
    unsigned long operator()(const std::string & data) const noexcept{
        unsigned long sum = 0;
        //unsigned long hash = 5381; //hash di stringa vuota
        //for(unsigned long i = 0; i < data.length(); ++i)
        for(unsigned long i = 0; i < data.length(); i++)
            sum += data[i];
            //sum = (sum << 5) + data[i];
        return sum;
    }
};

//Constructor
template <typename Data>
HashTable<Data>::HashTable() {
    a = distributorA(generateRandom);
    b = distributorB(generateRandom);
}

//Copy Constructor
template <typename Data>
HashTable<Data>::HashTable(const HashTable & ht) {
    size = ht.size;
    a = ht.a;
    b = ht.b;
    tableSize = ht.tableSize;
}

//Move Constructor
template <typename Data>
HashTable<Data>::HashTable(HashTable && ht) noexcept {
    std::swap(size, ht.size);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(tableSize, ht.tableSize);
}

// //Copy Assignment
// template <typename Data>
// HashTable & HashTable<Data>::operator = (const HashTable & ht){
//     size = ht.size;
//     a = ht.a;
//     b = ht.b;
//     tableSize = ht.tableSize;
//     return *this;
// }

// //Move Assignment
// template <typename Data>
// HashTable & HashTable<Data>::operator = (HashTable && ht) noexcept{
//     std::swap(size, ht.size);
//     std::swap(a, ht.a);
//     std::swap(b, ht.b);
//     std::swap(tableSize, ht.tableSize);
//     return *this;
// }

// Auxiliary member functions
template<typename Data>
unsigned long HashTable<Data>::HashKey(const Data & data) const noexcept{
    return HashKey(hash.operator()(data));
}

template<typename Data>
unsigned long HashTable<Data>::HashKey(unsigned long k) const noexcept{
    return ((a * k + b) % prime) % tableSize;
}

/* ************************************************************************** */

}
