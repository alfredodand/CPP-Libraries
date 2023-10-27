#include "queuevec.hpp"

namespace lasd {

/* ************************************************************************** */

//Specific Constructor
template<typename Data>
QueueVec<Data>::QueueVec(const MappableContainer<Data> & container){
    unsigned long j = 0;
    Elements = new Data[container.Size()];
    size = container.Size();
    tail = container.Size();
    head = 0;
    realsize = container.Size();
    container.Map(
        [this, & j](const Data & newData) {
            Elements[j++] = newData ;
        });
}

//Copy Constructor
template<typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data> & queue){
    Elements = new Data[queue.size];
    size = queue.size;
    tail = queue.realsize;
    realsize = queue.realsize;
    head = 0;
    for (unsigned long i = 0, j = queue.head; i < tail; i++){
        Elements[i] = queue.Elements[j];
        j = (j + 1) % queue.size;
    }    
}

// Move Construsctor
template<typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data> && queue) noexcept{
    /*Elements = new Data[queue.size];
    std::swap(size, queue.size);
    std::swap(head, queue.head);
    tail = size;
    head = 0;
    for (unsigned long i = 0, j = head; i < tail; i++){
        std::swap(Elements[i], queue.Elements[j]);
        j = (j + 1) % size;
    }*/

    Elements = new Data[queue.size];
    std::swap(size, queue.size);
    std::swap(realsize, queue.realsize);
    std::swap(head, queue.head);
    tail = realsize;
    head = 0;
    for (unsigned long i = 0, j = head; i < tail; i++){
        std::swap(Elements[i], queue.Elements[j]);
        j = (j + 1) % size;
    }
}


//Copy Assignment
template <typename Data>
QueueVec<Data> & QueueVec<Data>::operator = (const QueueVec<Data> & queue) {
    //Vector<Data>::operator = (queue);
    //head = queue.head;
    //tail = queue.tail;
    //return *this;

    //Clear();

    delete[] Elements;
    unsigned long j = 0;
    Elements = new Data[queue.size];
    size = queue.size;
    tail = queue.realsize;
    realsize = queue.realsize;
    head = 0;
    for (unsigned long i = 0, j = queue.head; i < tail; i++){
        Elements[i] = queue.Elements[j];
        ++j %= size;
    }        
    return *this;
}

//Move Assignment
template <typename Data>
QueueVec<Data> & QueueVec<Data>::operator = (QueueVec<Data> && queue) noexcept {
    //Vector<Data>::operator = (std::move(queue));
    //head = std::move(queue.head);
    //tail = std::move(queue.tail);
    //return *this;

    //Clear();
    delete[] Elements;
    unsigned long j = 0;
    Elements = new Data[queue.size];
    size = std::move(queue.size);
    tail = std::move(queue.realsize);
    realsize = std::move(queue.realsize);
    head = 0;
    for (unsigned long i = 0, j = queue.head; i < tail; i++){
        Elements[i] = std::move(queue.Elements[j]);
        j = (j + 1) % queue.size;
    }        
    return *this;
}

//Comparison Operators
template <typename Data>
bool QueueVec<Data>::operator == (const QueueVec<Data> & queue) const noexcept {
    if(realsize == queue.realsize) {
        for(int i = head, j = queue.head; i < tail; ++i %= size, ++j %= queue.size) {
            if(Elements[i] != queue.Elements[j]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

template <typename Data>
inline bool QueueVec<Data>::operator != (const QueueVec<Data> & queue) const noexcept {
    return !(*this == queue);
}

template <typename Data>
const Data & QueueVec<Data>::Head() const {
    if(!Empty()) {
        return Elements[head];
    } else {
        throw std::length_error("Accesso ad una coda vuota");
    }
}

template <typename Data>
Data & QueueVec<Data>::Head() {
    if(!Empty()) {
        return Elements[head];
    } else {
        throw std::length_error("Accesso ad una coda vuota");
    }
}

template <typename Data>
void QueueVec<Data>::Dequeue() {
    if(head != tail) {
        if(realsize > size/4){
            head = (head + 1) % size;
        } else {
            Reduce();
            head = (head + 1) % size;
        }
    } else {
        throw std::length_error("Accesso ad una coda vuota");
    }
    realsize--;
}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue() {
    if(head != tail) {
        Data tmp = Head();
        Dequeue();
        return tmp;
    } else {
        throw std::length_error("Accesso ad una coda vuota");
    }
}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data & data) {
    // Expand();
    // Elements[tail] = data;
    // tail++;
    // tail %= size;
    // //size++;
    if(size != 0){
        if((tail + 1) % size == head)
            Expand();
    }else{
        Expand();
    }
    Elements[tail] = data;
    tail = (tail + 1) % size;
    realsize++;
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data && data) {
    // Expand();
    // Elements[tail++] = std::move(data);
    // tail %= size;
    // //size++;
    if(size != 0){
        if((tail + 1) % size == head)
            Expand();
    }else{
        Expand();
    }
    Elements[tail] = std::move(data);
    tail = (tail + 1) % size; 
    realsize++;
}

//Specific Member Functions (inherited from Container)

template <typename Data>
inline bool QueueVec<Data>::Empty() const noexcept {
    //return (head == tail);
    return (realsize == 0);
}

template <typename Data>
inline unsigned long QueueVec<Data>::Size() const noexcept {
    // if(size != 0) {
    //     return ((((size + tail) - head) % size) + 1);
    // }
    // return 0; 
    return realsize;   
}

//Specific Member Functions (inherited from ClearableContainer)
template <typename Data>
void QueueVec<Data>::Clear() {
    head = 0;
    tail = 0;
    size = 0;
    realsize = 0;
    delete[] Elements;
    Elements = nullptr;
    Vector<Data>::Resize(2);
}

//Auxiliary member functions
template <typename Data>
void QueueVec<Data>::Expand() {
    // unsigned long n = Size();
    // if(n + 1 == size) {
    //     Resize(size * 2, n);
    // } else if(size == 0){
    //     Vector<Data>::Resize(2);
    // }
    /*Vector<Data>::Resize (size + 1);*/
    unsigned long tmp, newsize;
    if(size == 0)
        tmp = (size + 1) * 2;
    else
        tmp = size * 2;
    newsize = tmp;
    Data * Elements2 = new Data[tmp];
    SwapVectors(Elements2, newsize);
}

template <typename Data>
void QueueVec<Data>::Reduce() {
    /*unsigned long n = Size();
    if(n + 1 == size / 4) {
        Resize(size / 2, n);
    }*/
    unsigned long tmp, newsize;
    tmp = size / 2;
    newsize = tmp;
    Data * Elements2 = new Data[tmp];
    SwapVectors(Elements2 , newsize);
}

// template <typename Data>
// void QueueVec<Data>::Resize(unsigned long newsize, unsigned long n) {
//     Data * Temp = new Data[newsize];
//     unsigned long max = (n <= newsize) ? n : newsize;
//     for (int i = head, j = 0; j < max; ++i %= size, ++j) {
//         std::swap(Elements[i], Temp[j]);
//     }
//     std::swap(Elements, Temp);
//     delete[] Temp;
//     Temp = nullptr;
//     head = 0;
//     tail = n;
//     size = newsize;
// }

template<typename Data>
void QueueVec<Data>::SwapVectors(Data * TmpElements, unsigned long newsize) {
    for(unsigned long i = 0, j = head; i < realsize; i++){
        std::swap(Elements[j], TmpElements[i]);
        j = (j + 1) % size;
    }
        
    size = newsize;
    head = 0;
    tail = realsize;
    std::swap(Elements, TmpElements);
    delete[] TmpElements;
} 

/* ************************************************************************** */

}
