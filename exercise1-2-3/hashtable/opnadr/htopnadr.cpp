#include "htopnadr.hpp"
#include "math.h"

namespace lasd {

/* ************************************************************************** */

//Constructor
template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(){
    table.Resize(tableSize);
    status.Resize(tableSize);
    ResetStatus();
}

//Specific Constructors
template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long givenSize){
    unsigned long newSize = 0;
    double log = ceil(log2(givenSize));
    newSize = pow(2, log);
    table.Resize(newSize);
    status.Resize(newSize);
    tableSize = newSize;
    ResetStatus();
}

template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const MappableContainer<Data> & container){
    unsigned long newSize = 0;
    if(container.Size() > tableSize){        
        double log = ceil(log2(container.Size()));
        newSize = pow(2, log);
        table.Resize(newSize);
        status.Resize(newSize);
        tableSize = newSize;
        ResetStatus();
    }
    DictionaryContainer<Data>::InsertAll(container);
}

template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long givenSize, const MappableContainer<Data> & container){
    unsigned long newSize = 0;
    if(container.Size() > givenSize){
        double log = ceil(log2(container.Size()));
        newSize = pow(2, log);
        table.Resize(newSize);
        status.Resize(newSize);
        tableSize = newSize;
    } else {
        double log = ceil(log2(givenSize));
        newSize = pow(2, log);
        table.Resize(newSize);
        status.Resize(newSize);
        std::swap(tableSize, newSize);
    }
    ResetStatus();
    DictionaryContainer<Data>::InsertAll(container);
}

template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MutableMappableContainer<Data> && container){
    unsigned long newSize = 0;
    if(container.Size() > tableSize){        
        double log = ceil(log2(container.Size()));
        newSize = pow(2, log);
        table.Resize(newSize);
        status.Resize(newSize);
        tableSize = newSize;
        ResetStatus();
    }
    DictionaryContainer<Data>::InsertAll(container);
}

template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long givenSize, MutableMappableContainer<Data> && container){
    unsigned long newSize = 0;
    if(container.Size()>givenSize){
        double log = ceil(log2(container.Size()));
        newSize = pow(2, log);
        table.Resize(newSize);
        status.Resize(newSize);
        tableSize = newSize;
    }
    else {
        double log = ceil(log2(givenSize));
        newSize = pow(2, log);
        table.Resize(newSize);
        status.Resize(newSize);
        std::swap(tableSize, newSize);
    }
    ResetStatus();
    DictionaryContainer<Data>::InsertAll(container);
}

//Copy Constructor
template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data> & hashtable){
    table.Resize(hashtable.tableSize);
    status.Resize(hashtable.tableSize);
    for (unsigned long i = 0; i < hashtable.tableSize; i++){
        table[i] = hashtable.table[i];
        status[i] = hashtable.status[i];
    }
    size = hashtable.size;
    tableSize = hashtable.tableSize;
    HashTable<Data>::a = hashtable.a;
    HashTable<Data>::b = hashtable.b;
}

//Move Constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data> && hashtable) noexcept{
    table.Resize(hashtable.tableSize);
    status.Resize(hashtable.tableSize);
    std::swap(table, hashtable.table);
    std::swap(status, hashtable.status);
    std::swap(size, hashtable.size);
    std::swap(tableSize, hashtable.tableSize);
    HashTable<Data>::a = hashtable.a;
    HashTable<Data>::b = hashtable.b;
}

//Copy Assignment
template<typename Data>
HashTableOpnAdr<Data> & HashTableOpnAdr<Data>::operator = (const HashTableOpnAdr<Data> & hashtable){
    Clear();
    table.Resize(hashtable.tableSize);
    status.Resize(hashtable.tableSize);
    for (unsigned long i = 0; i < hashtable.tableSize; i++){
        table[i] = hashtable.table[i];
        status[i] = hashtable.status[i];
    }
    size = hashtable.size;
    tableSize = hashtable.tableSize;
    HashTable<Data>::a = hashtable.a;
    HashTable<Data>::b = hashtable.b;
    ResetStatus();
    return *this;
}

//Move Assignment
template<typename Data>
HashTableOpnAdr<Data> & HashTableOpnAdr<Data>::operator = (HashTableOpnAdr<Data> && hashtable) noexcept{
    Clear();
    table.Resize(hashtable.tableSize);
    status.Resize(hashtable.tableSize);
    std::swap(table, hashtable.table);
    std::swap(status, hashtable.status);
    std::swap(size, hashtable.size);
    std::swap(tableSize, hashtable.tableSize);
    HashTable<Data>::a = hashtable.a;
    HashTable<Data>::b = hashtable.b;
    ResetStatus();
    return *this;
}

//Comparison Operators
template<typename Data>
bool HashTableOpnAdr<Data>::operator == (const HashTableOpnAdr<Data> & hashtable2) const noexcept{
    if(size == hashtable2.size){
        for (unsigned long i = 0; i < tableSize; i++){
            if(status[i] == 'f'){
                if(!hashtable2.Exists(table[i]))
                    return false;
            }
        }
        return true;
    }else{
        return false;
    }
}

template<typename Data>
bool HashTableOpnAdr<Data>::operator != (const HashTableOpnAdr<Data> & hashtable2) const noexcept{
    return !(*this == hashtable2);
}

// Specific member functions (inherited from DictionaryContainer)
template<typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data & data) {    
    unsigned long i = 0;
    unsigned long index = 0;
    if(size == tableSize/2)
        Resize(tableSize*2);

    while (i < tableSize)
    {
        index = HashKey(data, i);
        if(table[index] == data && status[index] == 'f')
            return false;
        if(status[index] == 'e' || status[index] == 'd'){
            RemoveFromIndex(i, data);
            size++;
            status[index] = 'f';
            table[index] = data;
            return true;
        }else
            i++;
    }

    return false;
} 

template<typename Data>
bool HashTableOpnAdr<Data>::Insert(Data && data) noexcept {
    unsigned long i = 0;
    unsigned long index = 0;

    if(size == tableSize/2)
        Resize(tableSize*2);

    while (i < tableSize)
    {
        index = HashKey(data, i);
        if(table[index] == data && status[index] == 'f')
            return false;
        if(status[index] == 'e' || status[index] == 'd'){
            RemoveFromIndex(i, data);
            size++;
            table[index] = std::move(data);
            status[index] = 'f';
            return true;
        }else
            i++;
    }
    return false;

}

template<typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data & data){
    return RemoveFromIndex(0, data);
}

// Specific member functions (inherited from TestableContainer)
template<typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data & data) const noexcept{
    unsigned long i = 0;
    unsigned long index = 0;
    while (i < tableSize)
    {
        index = HashKey(data, i);
        if(status[index] == 'f' && table[index] == data){
            return true;
        }else if(status[index] == 'd' || status[index] == 'f')
            i++;
        else
            return false;
    }
    return false;
}

// Specific member functions (inherited from ResizableContainer)
template<typename Data>
void HashTableOpnAdr<Data>::Resize(const unsigned long tmpSize){
    unsigned long newSize = 0;
    Vector<Data> tmp(table);
    Vector<char> tmpStatus(status);
    
    if(tmpSize > size){
        double log = ceil(log2(tmpSize));
        newSize = pow(2, log);
    }
    else
        newSize = tableSize * 2;

    status.Clear();
    status.Resize(newSize);
    ResetStatus();
    table.Clear();
    table.Resize(newSize);
    tableSize = newSize;
    size = 0;

    for (unsigned long i = 0; i < tmpStatus.Size(); i++) {
        if(tmpStatus[i] == 'f'){
            Insert(tmp[i]);
        }
    }
}

// Specific member functions (inherited from ClearableContainer)
template<typename Data>
void HashTableOpnAdr<Data>::Clear() {
    tableSize = 1024;
    size = 0;
    table.Clear();
    table.Resize(tableSize);
    status.Clear();
    status.Resize(tableSize);
    ResetStatus();
   
}

// Auxiliary member functions
template<typename Data>
unsigned long HashTableOpnAdr<Data>::HashKey(const Data & key, const unsigned long index) const{
    //Doppio hashing (da qualche errore già nel simpletest)

    // std::random_device rd;
    // std::mt19937 rng(rd());
    // std::uniform_int_distribution<int> generateRandom(0, prime);

    // unsigned long f1 = HashTable<Data>::HashKey(HashTable<Data>::HashKey(key));
    // unsigned long c = generateRandom(rng);
    // unsigned long d = generateRandom(rng);
    // unsigned long keylong = HashTable<Data>::HashKey(key);
    // unsigned long f2 = ((c*keylong + d) % prime) % tableSize;
    // return (f1 + (f2 * index)) % tableSize;

    //probing lineare
    unsigned long f1 = HashTable<Data>::HashKey(HashTable<Data>::HashKey(key));
    return (f1 + (index * 43891)) % tableSize; //43891 è un numero primo - sicuramente coprimo con tableSize, ciò permette mediante probing lineare di coprire tutta la tabella

    // probing quadratico (segnala qualche errore una volta ogni 40 circa, ha abortito l'esecuzione una volta dopo più di 60 esecuzioni consecutive)
    // unsigned long f1 = HashTable<Data>::HashKey(HashTable<Data>::HashKey(key));
    // return (f1 + ((index * index) + 1)/2) % tableSize;

}

template<typename Data>
void HashTableOpnAdr<Data>::ResetStatus(){
    for (unsigned long i = 0; i < status.Size(); i++)
        status[i] = 'e';
}

template<typename Data>
bool HashTableOpnAdr<Data>::RemoveFromIndex(const unsigned long j, const Data & dato) {
    unsigned long i = j;
    unsigned long index = 0;
    while (i < tableSize)
    {
        index = HashKey(dato, i);
        if(status[index] == 'f' && table[index] == dato){
            status[index] = 'd';
            size--;
            return true;
        }else if(status[index] == 'e')
            return false;
        else
            i++;
    }  
    return false;
}

/* ************************************************************************** */

}
