
namespace lasd {

/* ************************************************************************** */

    //Move Constructor
    template<typename Data>
    QueueLst<Data>::QueueLst(QueueLst<Data> && queue) noexcept{
        std::swap(head, queue.head);
        std::swap(tail, queue.tail);
        std::swap(size, queue.size);
    }

    //Copy Assignment
    template <typename Data>
    inline QueueLst<Data> & QueueLst<Data>::operator = (const QueueLst<Data> & queue) {
        List<Data>::operator = (queue);
        return *this;
    }

    //Move Assignment
    template <typename Data>
    inline QueueLst<Data> & QueueLst<Data>::operator = (QueueLst<Data> && queue) noexcept {
        List<Data>::operator = (std::move(queue));
        return *this;
    }

    //Comparison Operators
    template <typename Data>
    inline bool QueueLst<Data>::operator == (const QueueLst<Data> & queue) const noexcept {
        return List<Data>::operator == (queue);
    }

    template <typename Data>
    inline bool QueueLst<Data>::operator != (const QueueLst<Data> & queue) const noexcept {
        return List<Data>::operator != (queue);
    }

    //Specific member functions (inherited from Queue)
    template <typename Data>
    inline const Data & QueueLst<Data>::Head() const {
        return List<Data>::Front();
    }

    template <typename Data>
    inline Data & QueueLst<Data>::Head() {
        return List<Data>::Front();
    }

    template <typename Data>
    inline void QueueLst<Data>::Dequeue() {
        return List<Data>::RemoveFromFront();
    }

    template <typename Data>
     inline Data QueueLst<Data>::HeadNDequeue() {
        return List<Data>::FrontNRemove();
    }

    template <typename Data>
     inline void QueueLst<Data>::Enqueue(const Data & data) {
        return List<Data>::InsertAtBack(data);
    }

    template <typename Data>
     inline void QueueLst<Data>::Enqueue(Data && data) {
        return List<Data>::InsertAtBack(data);
    }

/* ************************************************************************** */

}
