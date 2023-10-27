
namespace lasd {

/* ************************************************************************** */

//Specific Constructors
template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long givenSize){
    table.Resize(givenSize);
    std::swap(tableSize, givenSize);
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const MappableContainer<Data> & container){
    //se minore la dimensione della tabella non cambia
    if(container.Size() > tableSize){
        table.Resize(container.Size());
        tableSize = container.Size();
    }
    DictionaryContainer<Data>::InsertAll(container);
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long givenSize, const MappableContainer<Data> & container){
    table.Resize(givenSize);
    std::swap(tableSize, givenSize);
    DictionaryContainer<Data>::InsertAll(container);
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MutableMappableContainer<Data> && container){
    if(container.Size() > tableSize){
        table.Resize(container.Size());
        tableSize = container.Size();
    }
    DictionaryContainer<Data>::InsertAll(container);
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long givenSize, MutableMappableContainer<Data> && container){
    table.Resize(givenSize);
    std::swap(tableSize, givenSize);
    DictionaryContainer<Data>::InsertAll(container);
}

//Copy Constructor
template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data> & ht){
    table.Resize(ht.tableSize);
    for (unsigned long i = 0; i < ht.tableSize; i++){
        table[i] = ht.table[i];
    }
    size = ht.size;
    tableSize = ht.tableSize;
    HashTable<Data>::a = ht.a;
    HashTable<Data>::b = ht.b;
}

//Move Constructor
template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data> && ht) noexcept{
    table.Resize(ht.tableSize);
    std::swap(table, ht.table);
    std::swap(size, ht.size);
    std::swap(tableSize, ht.tableSize);
    HashTable<Data>::a = ht.a;
    HashTable<Data>::b = ht.b;
}

//Copy Assignment
template<typename Data>
HashTableClsAdr<Data> & HashTableClsAdr<Data>::operator = (const HashTableClsAdr<Data> & hashtable){
    Clear();
    Resize(hashtable.tableSize);
    size = hashtable.size;
    table = hashtable.table;
    return *this;
}

//Move Assignment
template<typename Data>
HashTableClsAdr<Data> & HashTableClsAdr<Data>::operator = (HashTableClsAdr<Data> && hashtable) noexcept{
    Clear();
    Resize(hashtable.tableSize);
    std::swap(size, hashtable.size);
    std::swap(table, hashtable.table);
    return *this;
}

//Comparison Operators
template<typename Data>
bool HashTableClsAdr<Data>::operator == (const HashTableClsAdr<Data> & hashtable) const noexcept{
    if(size == hashtable.size){
        for (unsigned long i = 0; i < tableSize; i++){
            BTPreOrderIterator it(hashtable.table[i]);
            
            for (; !it.Terminated(); ++it){
                unsigned long index = HashKey(*it);
                if(!table[index].Exists(*it)){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
    // bool isEqual = false;
    // if(size == hashtable.size){
    //     Fold(&Compare<Data>, & hashtable, & isEqual);
    //     return isEqual;
    // }
    // return false;
}

template<typename Data>
bool HashTableClsAdr<Data>::operator != (const HashTableClsAdr<Data> & hashtable) const noexcept{
    return !(*this == hashtable);
}

//Specific member functions (inherited from DictionaryContainer)
template<typename Data>
bool HashTableClsAdr<Data>::Insert(const Data & data){
    unsigned long index = HashKey(data);
    if(table[index].Insert(data)){
        size++;
        return true;
    }
    return false;
}

template<typename Data>
bool HashTableClsAdr<Data>::Insert(Data && data) noexcept{
    unsigned long index = HashKey(std::move(data));
    if(table[index].Insert(std::move(data))){
        size++;
        return true;
    }
    return false;
} 

template<typename Data>
bool HashTableClsAdr<Data>::Remove(const Data & data){
    unsigned long index = HashKey(data);
    if(table[index].Remove(data)){
        size--;
        return true;
    }
    return false;
}

// Specific member functions (inherited from ResizableContainer)
template<typename Data>
void HashTableClsAdr<Data>::Resize(const unsigned long newSize){
    //se la size è sotto quella minima mia, devo settarla alla mia
    unsigned long dimensione = newSize;
    if(newSize < 128){        
        dimensione = HashTable<Data>::myTableSize;
    }
    Vector<BST<Data>> table2(table);
    table.Clear();
    table.Resize(dimensione);
    tableSize = dimensione;
    size = 0;
    for (unsigned long i = 0; i < table2.Size(); i++){
        BTPreOrderIterator<Data> it(table2[i]);
        for (; !it.Terminated(); ++it){
            Insert(*it);
        }
    }
}

// Specific member functions (inherited from TestableContainer)
template<typename Data>
bool HashTableClsAdr<Data>::Exists(const Data & data) const noexcept {

    for(unsigned long i = 0; i < tableSize; ++i){
        const BST<Data> & bst = table[i];
        BTPreOrderIterator it(bst);
        for (; !it.Terminated(); ++it) {
            unsigned long index = HashKey(*it);
            if(table[index].Exists(data)){
                return true;
            }
        }
    }
    return false;
}

// Specific member functions (inherited from ClearableContainer)
template<typename Data>
void HashTableClsAdr<Data>::Clear() noexcept {
    table.Clear();
    table.Resize(HashTable<Data>::myTableSize);
    tableSize = HashTable<Data>::myTableSize;
    size = 0;
}

/* ************************************************************************** */

}
