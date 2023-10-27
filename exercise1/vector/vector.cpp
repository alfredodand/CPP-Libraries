
namespace lasd {

// Constructors
template<typename Data>
Vector<Data>::Vector(const unsigned long newSize) {
    size = newSize;
    Elements = new Data[size] {};
}

template<typename Data>
Vector<Data>::Vector(const MappableContainer<Data> & con) {
    unsigned long i = 0;
    size = con.Size();
    Elements = new Data[size];
    con.Map(
        [this, & i](const Data & newData) {
            Elements[i++] = newData;
        }
    );
    
}

template<typename Data>
Vector<Data>::Vector(MutableMappableContainer<Data> && con) {
    unsigned long i = 0;
    size = con.Size();
    Elements = new Data[size];
    con.Map(
        [this, & i](Data & newData) {
            Elements[i++] = std::move(newData);
        }
    );
    
}

//Copy Constructor
template<typename Data>
Vector<Data>::Vector(const Vector<Data> & vec) {
    size = vec.size;
    Elements = new Data[size];
    std::copy(vec.Elements, vec.Elements + size, Elements);
}

//Move Constructor
template<typename Data>
Vector<Data>::Vector(Vector<Data> && vec) noexcept {
    std::swap(size, vec.size);
    std::swap(Elements, vec.Elements);
}

//Destructor
template<typename Data>
Vector<Data>::~Vector() {
    size = 0;
    delete[] Elements;
}

//Copy Assignment
template<typename Data>
Vector<Data>& Vector<Data>::operator = (const Vector<Data> & vec) {
    Vector<Data> * temp = new Vector<Data>(vec);
    std::swap(*temp, *this);
    delete temp;
    return *this;
}

//Move Assignment
template<typename Data>
Vector<Data> & Vector<Data>::operator = (Vector<Data> && vec) noexcept {
    std::swap(size, vec.size);
    std::swap(Elements, vec.Elements);
    return *this;
}

//Comparison Operators
template<typename Data>
bool Vector<Data>::operator == (const Vector<Data> & vec) const noexcept {
    if(size == vec.size){
        for(unsigned long i; i < size; ++i){
            if(Elements[i] != vec.Elements[i]){
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

template<typename Data>
inline bool Vector<Data>::operator != (const Vector<Data> & vec) const noexcept {
    return !(*this == vec);
}

//Specific member function inherited from ClearableContainer
template<typename Data>
void Vector<Data>::Clear() {
    size = 0;
    i = 0;
    delete[] Elements;
    Elements = nullptr;    
}

//Specific member function inherited from ResizableContainer
template<typename Data>
void Vector<Data>::Resize(unsigned long newSize) {
    if(newSize == 0){
        Clear();
    } else if (size != newSize) {
        Data * Temp = new Data[newSize];
        unsigned long min;
        if (size < newSize) {
            min = size;
        } else {
            min = newSize;
        }
        for(int i = 0; i < min; ++i) {
            std::swap(Elements[i], Temp[i]);
        }
        std::swap(Elements, Temp);
        size = newSize;
        newSize = 0;
        delete[] Temp;
        Temp = nullptr;
    }
}

//Specific member function inherited from LinearContainer
template<typename Data>
const Data & Vector<Data>::operator[](const unsigned long i) const {
    if(i < size){
        return Elements[i];
    } else {
        throw std::out_of_range("Accesso all'indice " + std::to_string(i) + " - Dimensione del vettore: " + std::to_string(size));
    }
}

template<typename Data>
Data & Vector<Data>::operator[](const unsigned long i) {
    if(i < size){
        return Elements[i];
    } else {
        throw std::out_of_range("Accesso all'indice " + std::to_string(i) + " - Dimensione del vettore: " + std::to_string(size));
    }
}

template<typename Data>
const Data & Vector<Data>::Front() const {
    if(size != 0) {
        return Elements[0];
    } else {
        throw std::length_error("Accesso ad un vettore vuoto");
    }
}

template<typename Data>
Data & Vector<Data>::Front() {
    if(size != 0) {
        return Elements[0];
    } else {
        throw std::length_error("Accesso ad un vettore vuoto");
    }
}

template<typename Data>
const Data & Vector<Data>::Back() const {
    if(size != 0) {
        return Elements[size - 1];
    } else {
        throw std::length_error("Accesso ad un vettore vuoto");
    }
}

template<typename Data>
Data & Vector<Data>::Back() {
    if(size != 0) {
        return Elements[size - 1];
    } else {
        throw std::length_error("Accesso ad un vettore vuoto");
    }
}

//Specific member function inherited from SortableLinearContainer
template<typename Data>
void Vector<Data>::Sort() noexcept {
    QuickSort(0, size - 1);
}

template<typename Data>
void Vector<Data>::QuickSort(unsigned long x, unsigned long y) noexcept {
    if(x < y){
        unsigned long z = Partition(x, y);
        QuickSort(x, z - 1);
        QuickSort(z + 1, y);
    } 
}

template<typename Data>
unsigned long Vector<Data>::Partition(unsigned long x, unsigned long y) noexcept {
    Data a = Elements[x];
    unsigned long i = x - 1;
    for(unsigned long j = x; j < y; j++){
        if(Elements[j] <= a){
            i++;
            std::swap(Elements[i], Elements[j]);
        }
    }
    std::swap(Elements[i + 1], Elements[y]);
    return i + 1;
}

}
