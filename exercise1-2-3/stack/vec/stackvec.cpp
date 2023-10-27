
namespace lasd {

/* ************************************************************************** */

    //Specific Costructors
    template<typename Data>
    StackVec<Data>::StackVec(const MappableContainer<Data> & container){
        unsigned long j = 0;
        Elements = new Data[container.Size()];
        size = container.Size();
        i = size;
        container.Map(
        [this, & j](const Data & newData) {
            Elements[j++] = newData;
        });
    }
    
    
    //Copy Constructor
    template<typename Data>
    StackVec<Data>::StackVec(const StackVec& stackvect){
        Elements = new Data[stackvect.size];
        size = stackvect.size;
        i = stackvect.i;
        for (unsigned long j = 0; j < size; j++)
            Elements[j] = stackvect.Elements[j];
    }
    
    //Move Constructor
    template<typename Data>
    StackVec<Data>::StackVec(StackVec && stack) noexcept : Vector<Data>(std::move(stack)) {
        std::swap(i, stack.i);
    };

    //Copy Assignment
    template<typename Data>
    StackVec<Data> & StackVec<Data>::operator = (const StackVec<Data> & stack) {
        Vector<Data>::operator = (stack);
        i = stack.i;
        return *this;
    }

    //Move Assignment
    template<typename Data>
    StackVec<Data> & StackVec<Data>::operator = (StackVec<Data> && stack) noexcept {
        Vector<Data>::operator = (std::move(stack));
        std::swap(i, stack.i);
        return *this;
    }

    //Comparison Operators
    template<typename Data>
    bool StackVec<Data>::operator == (const StackVec<Data> & stack) const noexcept {
        if(i == stack.i) {
            for(int j = 0; j < i; ++j) {
                if(Elements[j] != stack.Elements[j]) {
                    return false;
                }
            }
            return true;
        } else  {
            return false;
        }
    }

    template<typename Data>
    inline bool StackVec<Data>::operator != (const StackVec<Data> & stack) const noexcept {
        return !(*this == stack);
    }

    //Specific Member Functions (inherited from Stack)
    template<typename Data>
    Data StackVec<Data>::Top() const {
        if(!Empty()) {
            return Elements[i - 1];
        } else {
            throw std::length_error("Accesso ad uno stack vuoto");
        }
    }

    template<typename Data>
    Data & StackVec<Data>::Top() {
        if(!Empty()) {
            return Elements[i - 1];
        } else {
            throw std::length_error("Accesso ad uno stack vuoto");
        }
    }

    template<typename Data>
    void StackVec<Data>::Pop() {
        if(i != 0) {
            Reduce();
            --i;
        } else {
            throw std::length_error("Accesso ad uno stack vuoto");
        }
    }

    template<typename Data>
    Data StackVec<Data>::TopNPop() {
        if(i != 0) {
            Reduce();
            return std::move(Elements[--i]);
        } else {
            throw std::length_error("Accesso ad uno stack vuoto");
        }
    }

    template<typename Data>
    void StackVec<Data>::Push(const Data & data) {
        Expand();
        Elements[i++] = data;
    }

    template<typename Data>
    void StackVec<Data>::Push(Data && data) noexcept {
        Expand();
        Elements[i++] = std::move(data);
    }

    //Specific Member Functions (inherited from Container)
    template<typename Data>
    inline bool StackVec<Data>::Empty() const noexcept {
        return (i == 0);
    }

    template<typename Data>
    inline unsigned long StackVec<Data>::Size() const noexcept {
        return i;
    }

    //Specific Member Functions (inherited from ClearableContainer)
    template<typename Data>
    void StackVec<Data>::Clear() {
        i = 0;
        size = 0;
        //Vector<Data>::Resize(0);
        delete[] Elements;
        Elements = nullptr;
    }

    //Auxiliary Member Functions
    template<typename Data>
    void StackVec<Data>::Expand() {
        //if (i == size) {
        //    Vector<Data>::Resize(size * 2);
        //}
        /*if (i == size) {
            unsigned long temp;
            if(size == 0){
                temp = (size + 1) * 2;
            } else {
                temp = size * 2;
            }
            Vector<Data>::Resize(temp);
        }*/ 
        if (i == size) {
            Vector<Data>::Resize(size + 1);
        }     
    }

    template<typename Data>
    void StackVec<Data>::Reduce() {
        //if (i == size / 4) {
        //    Vector<Data>::Resize(size / 2);
        //}
        if (i == size / 4) {
            unsigned long temp;
            if(size == 0){
                temp = (size + 1) / 2;
            } else {
                temp = size / 2;
            }
        }
        /*if (i == size / 4) {
            Vector<Data>::Resize(size / 2);
        }*/
    }


/* ************************************************************************** */

}
