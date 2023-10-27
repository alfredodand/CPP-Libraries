
namespace lasd {

/* ************************************************************************** */

    //Specific Constructor (NODE)
    template <typename Data>
    List<Data>::Node::Node(Data && data) noexcept {
        std::swap(element, data);
    }

    //Move Constructor (NODE)
    template <typename Data>
    List<Data>::Node::Node(Node && node) noexcept {
        std::swap(element, node.element);
        std::swap(next, node.next);
    }

    //Destructor (NODE)
    template <typename Data>
    List<Data>::Node::~Node() {
        delete next;
    }

    //Comparison Operators (NODE)
    template <typename Data>
    bool List<Data>::Node::operator == (const Node & node) const noexcept {
       return (element == node.element) && ((next == nullptr && node.next == nullptr) || (next != nullptr && node.next != nullptr) && (*next == *node.next));
    }

    template <typename Data>
    inline bool List<Data>::Node::operator != (const Node & node) const noexcept {
        return !(*this == node);
    }

    //Specific Member Functiosn (NODE)
    template <typename Data>
    typename List<Data>::Node * List<Data>::Node::Clone(Node * tail) {
        if(next == nullptr) {
            return tail;
        } else {
            Node * node = new Node(element);
            node -> next = next -> Clone(tail);
            return node;
        }
    }

    //Specific Constructors
    template <typename Data>
    List<Data>::List(const MappableContainer<Data> & con) {
        con.Map(
            [this](const Data & data) {
                InsertAtBack(data);
            }
        );
    }

    template <typename Data>
    List<Data>::List(MutableMappableContainer<Data> && con) {
        con.Map(
            [this](Data & data) {
                InsertAtBack(std::move(data));
            }
        );
    }

    //Copy Constructor
    template <typename Data>
    List<Data>::List(const List<Data> & list) {
        if(list.tail != nullptr) {
            tail = new Node(*list.tail);
            head = list.head -> Clone(tail);
            size = list.size;
        }
    }

    //Move Constructor
    template <typename Data>
    List<Data>::List(List<Data> && list) noexcept {
        std::swap(head, list.head);
        std::swap(tail, list.tail);
        std::swap(size, list.size);
    }

    //Destructor
    template <typename Data>
    List<Data>::~List() {
        delete head;
    }

    //Copy Assignment
    template <typename Data>
    List<Data> & List<Data>::operator = (const List<Data> & list) {
        /*if(size <= list.size) {
            if(tail == nullptr) {
                List<Data> * temp = new List<Data>(list);
                std::swap(*temp, *this);
                delete temp;
            } else {
                Node * current = head;
                Node * ncurrent = list.head->next;
                for (; ncurrent != nullptr; ncurrent = ncurrent->next) {
                    current->next = new Node(ncurrent->element);
                    current = current->next;
                }
                if (ncurrent == nullptr) {
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                }
            }
        } else {
            if(list.tail == nullptr) {
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                Node * current = head;
                for(Node * ncurrent = list.head; ncurrent != nullptr; ncurrent = ncurrent -> next, tail = current, current = current -> next){
                    current -> element = ncurrent -> element;
                }
                delete current;
                tail->next = nullptr;
            }
        }
        size = list.size;
        return * this;*/

        Clear();
        for (unsigned long i = 0; i < list.size; i++){
            InsertAtBack(list[i]);
        }
        return *this;
    }

    //Move Assignment
    template <typename Data>
    List<Data> & List <Data>::operator = (List<Data> && list) noexcept {
        std::swap(head, list.head);
        std::swap(tail, list.tail);
        std::swap(size, list.size);
        return *this;
    }

    //Comparison Operators
    template <typename Data>
    inline bool List<Data>::operator == (const List<Data> & list) const noexcept {
        if (size != list.size) {
            return false;
        } else {
            Node *curr = head;
            Node *otherCurr = list.head;
            while (curr != nullptr && otherCurr != nullptr) {
                if (curr->element != otherCurr->element) {
                    return false;
                }
                curr = curr->next;
                otherCurr = otherCurr->next;
            }
            return true;
        }
    }

    template <typename Data>
    inline bool List<Data>::operator != (const List<Data> & list) const noexcept {
        return !(*this == list);
    }

    //Specific Member Function
    template <typename Data>
    void List<Data>::InsertAtFront(const Data & list) {
        Node * begin = new Node(list);
        begin -> next = head;
        head = begin;
        if(tail == nullptr) {
            tail = head;
        }
        ++size;
    }

    template <typename Data>
    void List<Data>::InsertAtFront(Data && list) noexcept {
        Node * begin = new Node(std::move(list));
        begin -> next = head;
        head = begin;
        if(tail == nullptr) {
            tail = head;
        }
        ++size;
    }

    template <typename Data>
    void List<Data>::RemoveFromFront() {
        if(head != nullptr) {
            Node * front = head;
            if(tail == head) {
                head = tail = nullptr;
            } else {
                head = head -> next;
            }
            --size;
            front -> next = nullptr;
            delete front;
        } else {
            throw std::length_error("Accesso ad una lista vuota1");
        }
    }

    template <typename Data>
    Data List<Data>::FrontNRemove() {
        if(head != nullptr) {
            Node * front = head;
            if(tail == head){
                head = tail = nullptr;
            } else {
                head = head -> next;
            }
            --size;
            front -> next = nullptr;
            Data data(std::move(front -> element));
            delete front;
            return data;
        } else {
            throw std::length_error("Accesso ad una lista vuota2");
        }
    }

    template <typename Data>
    void List<Data>::InsertAtBack(const Data & data) {
        Node * end = new Node(data);
        if (tail == nullptr) {
            head = end;
        } else {
            tail -> next = end;
        }
        tail = end;
        ++size;
    }

    template <typename Data>
    void List<Data>::InsertAtBack(Data && data) noexcept {
        Node * end = new Node(std::move(data));
        if (tail == nullptr) {
            head = end;
        } else {
            tail -> next = end;
        }
        tail = end;
        ++size;
    }

    //Specific Member Function iherited from ClearableContainer
    template <typename Data>
    void List<Data>::Clear(){
        delete head;
        head = tail = nullptr;
        size = 0;
    }

    //Specific Member Function iherited from DictionaryContainer
    template <typename Data>
    bool List<Data>::Insert(const Data & data) {
        for(Node * cur = head; cur != nullptr; cur = cur -> next) {
            if(cur -> element == data) {
                return false;
            }
        }
        InsertAtBack(data);
        return true;
    }

    template <typename Data>
    bool List<Data>::Insert(Data && data) noexcept {
        for(Node * cur = head; cur != nullptr; cur = cur -> next) {
            if(cur -> element == data) {
                return false;
            }
        }
        InsertAtBack(std::move(data));
        return true;
    }

    template <typename Data>
    bool List<Data>::Remove(const Data & data) {
        Node * last = nullptr;
        for(Node * * current = &head; current != nullptr; last = * current, current = &((*current) -> next)) {
            if((*current) -> element == data) {
                Node * node = * current;
                * current = node -> next;
                node -> next = nullptr;
                delete node;
                size--;
                if(tail == node) {
                    tail = last;
                }
                return true;
            }
        }
        return false;
    }

    //Specific Member Function iherited from LinearContainer
    template <typename Data>
    const Data & List<Data>::operator[](const unsigned long i) const {
        if(i < size) {
            Node * current = head;
            for (int j = 0; j < i; j++, current = current -> next) {}
            return current -> element;
        } else {
            throw std::out_of_range("Accesso all'indice " + std::to_string(i) + "ma la dimensione Lista = " + std::to_string(size));
        }
    }

    template <typename Data>
    Data & List<Data>::operator[](const unsigned long i) {
        if(i < size) {
            Node * current = head;
            for (int j = 0; j < i; j++, current = current -> next) {}
            return current -> element;
        } else {
            throw std::out_of_range("Accesso all'indice " + std::to_string(i) + "ma la dimensione Lista = " + std::to_string(size));
        }
    }

    template <typename Data>
    const Data & List<Data>::Front() const {
        if(head != nullptr) {
            return head -> element;
        } else {
            throw std::length_error("Accesso ad una lista vuota3");
        }
    }

    template <typename Data>
    Data & List<Data>::Front() {
        if(head != nullptr) {
            return head->element;
        } else {
            throw std::length_error("Accesso ad una lista vuota4");
        }
    }

    template <typename Data>
    const Data & List<Data>::Back() const {
        if(tail != nullptr) {
            return tail -> element;
        } else {
            throw std::length_error("Accesso ad una lista vuota5");
        }
    }

    template <typename Data>
    Data & List<Data>::Back() {
        if(tail != nullptr) {
            return tail -> element;
        } else {
            throw std::length_error("Accesso ad una lista vuota6");
        }
    }

    //Specific Member Function iherited from FoldableContainer
    template <typename Data>
    inline void List<Data>::Fold(FoldFunctor fun, void * accumulatore) const{
        PreOrderFold(fun, accumulatore, head);
    }

    //Specific Member Function iherited from PreOrderFoldableContainer
    template <typename Data>
    inline void List<Data>::PreOrderFold(FoldFunctor fun, void * accumulatore) const{
        PreOrderFold(fun, accumulatore, head);
    }

    //Specific Member Function iherited from PostOrderFoldableContainer
    template <typename Data>
    inline void List<Data>::PostOrderFold(FoldFunctor fun, void * accumulatore) const{
        PostOrderFold(fun, accumulatore, head);
    }

    //Specific Member Function iherited from MappableContainer
    template <typename Data>
    inline void List<Data>::Map(MapFunctor fun) const {
        PreOrderMap(fun, head);
    }

    //Specific Member Function iherited from PreOrderMappableContainer
    template <typename Data>
    inline void List<Data>::PreOrderMap(MapFunctor fun) const {
        PreOrderMap(fun, head);
    }

    //Specific Member Function iherited from PostOrderMappableContainer
    template <typename Data>
    inline void List<Data>::PostOrderMap(MapFunctor fun) const {
        PostOrderMap(fun, head);
    }

    //Specific Member Function iherited from MutableMappableContainer
    template <typename Data>
    void List<Data>::Map(MutableMapFunctor fun) {
        PreOrderMap(fun, head);
    }

    //Specific Member Function iherited from MutablePreOrderMappableContainer
    template <typename Data>
    void List<Data>::PreOrderMap(MutableMapFunctor fun) {
        PreOrderMap(fun, head);
    }

    //Specific Member Function iherited from MutablePostOrderMappableContainer
    template <typename Data>
    void List<Data>::PostOrderMap(MutableMapFunctor fun) {
        PostOrderMap(fun, head);
    }

    //Auxiliary member functions (for PreOrderFoldableContainer & PostOrderFoldableContainer)
    template <typename Data>
    void List<Data>::PreOrderFold(FoldFunctor fun, void * accumulatore, const Node * current) const {
        for(; current != nullptr; current = current -> next) {
            fun(current -> element, accumulatore);
        }
    }

    template <typename Data>
    void List<Data>::PostOrderFold(FoldFunctor fun, void * accumulatore, const Node * current) const {
        if(current != nullptr) {
            PostOrderFold(fun, accumulatore, current -> next);
            fun(current -> element, accumulatore);
        }
    }

    //Auxiliary member functions (for PreOrderMappableContainer & PostOrderMappableContainer
    template <typename Data>
    void List<Data>::PreOrderMap(MapFunctor fun, const Node * current) const {
        for(; current != nullptr; current = current -> next) {
            fun(current -> element);
        }
    }

    template <typename Data>
    void List<Data>::PostOrderMap(MapFunctor fun, const Node * current) const {
        if(current != nullptr) {
            PostOrderMap(fun, current -> next);
            fun(current -> element);
        }
    }

    // Auxiliary member functions (for MutablePreOrderMappableContainer & MutablePostOrderMappableContainer)
    template <typename Data>
    void List<Data>::PreOrderMap(MutableMapFunctor fun, Node * current) {
        for(; current != nullptr; current = current -> next) {
            fun(current -> element);
        }
    }

    template <typename Data>
    void List<Data>::PostOrderMap(MutableMapFunctor fun, Node * current) {
        if(current != nullptr) {
            PostOrderMap(fun, current -> next);
            fun(current -> element);
        }
    }



/* ************************************************************************** */

}