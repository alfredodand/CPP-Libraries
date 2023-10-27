
namespace lasd {

/* ************************************************************************** */

    //Copy Constructor
    template<typename Data>
    StackLst<Data>::StackLst(const StackLst<Data> & stk){
        unsigned long i = stk.size - 1;
        unsigned long j = 0;
        while (j < stk.size){
            Push(stk[i]);
            i--;
            j++;
        }
    }

    //Move Constructor
    template<typename Data>
    StackLst<Data>::StackLst(StackLst<Data> && stk) noexcept {
        std::swap(size, stk.size);
        std::swap(tail, stk.tail);
        std::swap(head, stk.head);
    }
    
    //Copy Assignment
    template<typename Data>
    inline StackLst<Data> & StackLst<Data>::operator = (const StackLst<Data> & stack) {
        List<Data>::operator = (stack);
        return *this;
    }

    //Move Assignment
    template<typename Data>
    inline StackLst<Data> & StackLst<Data>::operator = (StackLst<Data> && stack) noexcept {
        List<Data>::operator = (std::move(stack));
        return *this;
    }

    //Comparison Operators
    template<typename Data>
    inline bool StackLst<Data>::operator == (const StackLst<Data> & stack) const noexcept {
        return List<Data>::operator == (stack);
    }

    template<typename Data>
    inline bool StackLst<Data>::operator != (const StackLst<Data> & stack) const noexcept {
        return List<Data>::operator != (stack);
    }

    //Specific Member Functions (inherited from Stack)
    template<typename Data>
    inline Data StackLst<Data>::Top() const {
        return List<Data>::Front();
    }

    template<typename Data>
    inline Data & StackLst<Data>::Top() {
        return List<Data>::Front();
    }

    template<typename Data>
    inline void StackLst<Data>::Pop() {
        return List<Data>::RemoveFromFront();
    }

    template<typename Data>
    inline Data StackLst<Data>::TopNPop() {
        return List<Data>::FrontNRemove();
    }

    template<typename Data>
    inline void StackLst<Data>::Push(const Data & data) {
        return List<Data>::InsertAtFront(data);
    }

    template<typename Data>
    inline void StackLst<Data>::Push(Data && data) noexcept {
        return List<Data>::InsertAtFront(data);
    }


/* ************************************************************************** */

}
