
namespace lasd {

/* ************************************************************************** */

//Specific Constructor
template<typename Data>
BST<Data>::BST(const MappableContainer<Data> & container){
    // for (unsigned long i = 0; i < container.Size(); i++)
    //     Insert(container[i]);

    container.Map(
    [this](const Data & newData) {
        Insert(newData);
    });
}

template<typename Data>
BST<Data>::BST(MutableMappableContainer<Data> && container) noexcept{
    // for (unsigned long i = 0; i < container.Size(); i++)
    //     Insert(std::move(container[i]));

    container.Map(
    [this](const Data & newData) {
        Insert(std::move(newData));
    });
}

//Copy Assignment
template<typename Data>
BST<Data> & BST<Data>::operator = (const BST & bst){
    BinaryTreeLnk<Data>::operator = (bst);
    return *this;
}

//Move Assignment
template<typename Data>
BST<Data> & BST<Data>::operator = (BST && bst) noexcept{
    BinaryTreeLnk<Data>::operator = (std::move(bst));
    return *this;
}

//Comparison Operators
template<typename Data>
bool BST<Data>::operator == (const BST<Data> & bst) const noexcept{
    BTInOrderIterator<Data> it1(bst);
    BTInOrderIterator<Data> it2(*this);
    if(bst.size == size){
        for (unsigned long i = 0; i < size; i++)
        {
            if(*it1 != *it2){
                return false;
            }
            ++it1; 
            ++it2;
        }
        return true;
    }
    return false;
}

template<typename Data>
bool BST<Data>::operator != (const BST<Data> & bst) const noexcept{
    return !(*this == bst);
}

// Specific member functions
template<typename Data>
const Data & BST<Data>::Min() const{
    if(size != 0){
        return FindPointerToMin(root)->Element();
    } else {
        throw std::length_error("BST vuoto");
    }
}

template<typename Data>
Data BST<Data>::MinNRemove(){
    Data min;
    if(size != 0){
        NodeLnk * & temp = FindPointerToMin(root);
        if(temp != nullptr){
            min = DataNDelete(temp);
        }     
        return min;
    } else {
        throw std::length_error("BST vuoto");
    }
}

template<typename Data>
void BST<Data>::RemoveMin(){
    NodeLnk * detachedNode;
    if(size != 0){
        NodeLnk * & temp = FindPointerToMin(root);
        if(temp != nullptr){
            detachedNode = Detach(temp);
        }
        delete(detachedNode); 
    } else {
        throw std::length_error("BST vuoto");
    }
}

template<typename Data>
const Data & BST<Data>::Max() const{
    if(size != 0){
        return FindPointerToMax(root)->Element();
    } else {
        throw std::length_error("BST vuoto");
    }
}

template<typename Data>
Data BST<Data>::MaxNRemove(){
    Data max;
    if(size != 0){
        NodeLnk * & temp = FindPointerToMax(root);
        if(temp != nullptr){
            max = DataNDelete(temp);
        }
        return max;
    } else {
        throw std::length_error("BST vuoto");
    }
}

template<typename Data>
void BST<Data>::RemoveMax(){
    NodeLnk * detachedNode;
    if(size != 0){
        NodeLnk * & temp = FindPointerToMax(root);
        if(temp != nullptr){
            detachedNode = Detach(temp);
        }   
        delete(detachedNode); 
    } else {
        throw std::length_error("BST vuoto");
    }
}

template<typename Data>
const Data & BST<Data>::Predecessor(const Data & element) const{
    NodeLnk * const * temp = FindPointerToPredecessor(root, element);
    if(temp != nullptr){
        return (*temp)->Element();
    } else {
        throw std::length_error("Predecessor Not Found");
    }
}

template<typename Data>
Data BST<Data>::PredecessorNRemove(const Data & element){
    Data result;
    if(size != 0){
        NodeLnk * * temp = FindPointerToPredecessor(root, element);
        if(temp != nullptr){
            result = DataNDelete(*temp);
        } 
        return result;
    } else {
        throw std::length_error("BST is empty!");
    }
}

template<typename Data>
void BST<Data>::RemovePredecessor(const Data & element){
    NodeLnk * detachedNode;
    if(size != 0){
        NodeLnk * * temp = FindPointerToPredecessor(root, element);
        if(temp != nullptr){
            detachedNode = Detach(*temp);
        }   
        delete(detachedNode);    
    } else {
        throw std::length_error("BST is empty!");
    }
}

template<typename Data>
const Data & BST<Data>::Successor(const Data & element) const{
    NodeLnk * const * temp = FindPointerToSuccessor(root, element);
    if(temp != nullptr){
        return (*temp)->Element();
    } else {
        throw std::length_error("Successor Not Found");
    }
}

template<typename Data>
Data BST<Data>::SuccessorNRemove(const Data & element){
    Data result;
    if(size != 0){
        NodeLnk * * temp = FindPointerToSuccessor(root, element);
        if(temp != nullptr){
            result = DataNDelete(*temp);
        } 
        return result;
    } else {
        throw std::length_error("BST is empty!");
    }
}

template<typename Data>
void BST<Data>::RemoveSuccessor(const Data & element){
    NodeLnk * detachedNode;
    if(size != 0){
        NodeLnk * * temp = FindPointerToSuccessor(root, element);
        if(temp != nullptr){
            detachedNode = Detach(*temp);
        }
        delete(detachedNode);    
    } else {
        throw std::length_error("BST is empty!");
    }
}

template<typename Data>
bool BST<Data>::Insert(const Data & element){
    NodeLnk * newNodo = new NodeLnk(element);
    if(size == 0){
        size++;
        root = newNodo;
        return true;
    } else {
        unsigned long oldSize = size;
        Insertion(newNodo, root);

        if(oldSize + 1 == size){
            return true;
        } else {
            return false;
        }
    }
}

template<typename Data>
bool BST<Data>::Insert(Data && element) noexcept{
    NodeLnk * newNodo = new NodeLnk(std::move(element));
    if(size == 0){
        size++;
        root = newNodo;
        return true;
    } else {
        unsigned long oldSize = size;
        Insertion(newNodo, root);

        if(oldSize + 1 == size){
            return true;
        } else {
            return false;
        }
    }
}

template<typename Data>
bool BST<Data>::Remove(const Data & element){
    NodeLnk * & temp = FindPointerTo(root, element);
    NodeLnk * detachedNode;
    if(temp != nullptr){
        delete(Detach(temp));
        return true;
    }
    return false;
}

template<typename Data>
bool BST<Data>::Exists(const Data & element) const noexcept{
    if(FindPointerTo(root, element) != nullptr){
        return true;
    }
    return false;
}

template<typename Data>
Data BST<Data>::DataNDelete(typename BinaryTreeLnk<Data>::NodeLnk* & node){
    NodeLnk * detachedNode;
    Data result;

    if(node != nullptr){
        result = node->element;
        if(node->HasLeftChild() && node->HasRightChild()){
            detachedNode = DetachMin(node);
            node->element = detachedNode->element;
        } else if(node->HasLeftChild() && !node->HasRightChild()){
            detachedNode = Skip2Left(node);
        } else if(!node->HasLeftChild() && node->HasRightChild()){
            detachedNode = Skip2Right(node);
        } else if(node->IsLeaf()){
            detachedNode = node;
            node = nullptr;
            size--;
        }
    }
    delete(detachedNode);

    return result;    
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::Detach(typename BinaryTreeLnk<Data>::NodeLnk* & node) noexcept{
    NodeLnk * detachedNode;

    if(node != nullptr){
        if(node->HasLeftChild() && node->HasRightChild()){
            detachedNode = DetachMin(node->right);
            node->element = detachedNode->element;
        } else if(node->HasLeftChild() && !node->HasRightChild()){
            detachedNode = Skip2Left(node);
        } else if(!node->HasLeftChild() && node->HasRightChild()){
            detachedNode = Skip2Right(node);
        } else if(node->IsLeaf()){
            detachedNode = node;
            node = nullptr;
            size--;
        }
    }
    return detachedNode;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::DetachMin(typename BinaryTreeLnk<Data>::NodeLnk* & node) noexcept{
    NodeLnk * & minOfSubTree = FindPointerToMin(node);
    NodeLnk * temp = minOfSubTree;
    if (minOfSubTree->HasRightChild()){
        Skip2Right(minOfSubTree);
        size--;
    } else {
        minOfSubTree = nullptr;
    }    
    return temp;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::DetachMax(typename BinaryTreeLnk<Data>::NodeLnk* & node) noexcept{
    NodeLnk * & maxOfSubTree = FindPointerToMax(node);
    NodeLnk * temp = maxOfSubTree;
    if (maxOfSubTree->HasRightChild()){
        Skip2Left(maxOfSubTree);
        size--;
    } else {
        maxOfSubTree = nullptr;
    }
    return temp;    
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::Insertion(typename BinaryTreeLnk<Data>::NodeLnk* newNodo, typename BinaryTreeLnk<Data>::NodeLnk * current) noexcept{
    if(current != nullptr){
        if(current->Element() < newNodo->Element()){
            current->right = Insertion(newNodo, current->right);
        } else if(current->Element() > newNodo->Element()){
            current->left = Insertion(newNodo, current->left);
        }
    } else {
        current = newNodo;
        size++;
    }
    return current;
}

template<typename Data> //input : riferimento al puntatore a nodo
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::Skip2Left(typename BinaryTreeLnk<Data>::NodeLnk* & node) noexcept{
    NodeLnk * current = nullptr;
    if(node != nullptr){
        std::swap(current, node->left);
        std::swap(node, current);
        size--;
    }
    return current;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::Skip2Right(typename BinaryTreeLnk<Data>::NodeLnk* & node) noexcept{
    NodeLnk * current = nullptr;
    if(node != nullptr){
        std::swap(current, node->right);
        std::swap(node, current);
        size--;
    }
    return current;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* & BST<Data>::FindPointerToMin(typename BinaryTreeLnk<Data>::NodeLnk* & node) noexcept{
    return const_cast<NodeLnk* &>(static_cast<const BST<Data>*> (this)->FindPointerToMin(node));
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(typename BinaryTreeLnk<Data>::NodeLnk* const& node) const noexcept{
    NodeLnk * const* temp = &node;
    NodeLnk * current = node;
    if(current != nullptr){
        while(current->HasLeftChild()){
            temp = &current->left;
            current = current->left;
        }
    }
    return *temp;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* & BST<Data>::FindPointerToMax(typename BinaryTreeLnk<Data>::NodeLnk* & node) noexcept{
    return const_cast<NodeLnk* &>(static_cast<const BST<Data>*> (this)->FindPointerToMax(node));
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(typename BinaryTreeLnk<Data>::NodeLnk* const& node) const noexcept{
    NodeLnk * const* temp = &node;
    NodeLnk * current = node;
    if(current != nullptr){
        while(current->HasRightChild()){
            temp = &current->right;
            current = current->right;
        }
    }
    return *temp;    
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* & BST<Data>::FindPointerTo(typename BinaryTreeLnk<Data>::NodeLnk* & node, const Data & dato) noexcept{
    return const_cast<NodeLnk* &>(static_cast<const BST<Data>*> (this)->FindPointerTo(node, dato));
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const & BST<Data>::FindPointerTo(typename BinaryTreeLnk<Data>::NodeLnk* const & node, const Data & dato) const noexcept{
    NodeLnk * const* temp = &node;
    NodeLnk * current = node;
    bool found = false;
    if(current != nullptr){
        while(found == false && current != nullptr){
            if(current->Element() > dato){
                    temp = &current->left;
                    current = current->left;
            }else if(current->Element() < dato){
                    temp = &current->right;
                    current = current->right;              
            }else{
                found = true;
            }
        }
    }

    return *temp; 
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk * * BST<Data>::FindPointerToPredecessor(typename BinaryTreeLnk<Data>::NodeLnk* & node, const Data & dato) noexcept{
    return const_cast<NodeLnk**>(static_cast<const BST<Data>*> (this)->FindPointerToPredecessor(node, dato));
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const* BST<Data>::FindPointerToPredecessor(typename BinaryTreeLnk<Data>::NodeLnk* const& node, const Data & data) const noexcept{
    NodeLnk* const* estimation = nullptr;
    NodeLnk* const* temp = &node;
    
    while(true){
        NodeLnk& current = * * temp;
        if(current.element < data){
            estimation = temp;
            if(!current.HasRightChild())
                return estimation;
            else
                temp = &current.right;        
        }else if(current.element > data){
            if(!current.HasLeftChild())
                return estimation;
            else
                temp = &current.left;                
        }else{
            if(current.HasLeftChild())
                estimation = &FindPointerToMax(current.left);
            return estimation;
        }
    }
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk * * BST<Data>::FindPointerToSuccessor(typename BinaryTreeLnk<Data>::NodeLnk* & node, const Data & dato) noexcept{
    return const_cast<NodeLnk**>(static_cast<const BST<Data>*> (this)->FindPointerToSuccessor(node, dato));
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const* BST<Data>::FindPointerToSuccessor(typename BinaryTreeLnk<Data>::NodeLnk* const& node, const Data & data) const noexcept{
    NodeLnk* const* estimation = nullptr;
    NodeLnk* const* temp = &node;
    
    while(true){
        NodeLnk& current = * * temp;
        if(current.element > data){
            estimation = temp;
            if(!current.HasLeftChild())
                return estimation;
            else
                temp = &current.left;        
        }else if(current.element < data){
            if(!current.HasRightChild())
                return estimation;
            else
                temp = &current.right;                
        }else{
            if(current.HasRightChild())
                estimation = &FindPointerToMin(current.right);
            return estimation;
        }
    }
 
}
/* ************************************************************************** */

}
