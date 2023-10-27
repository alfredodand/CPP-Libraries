#include "../queue/lst/queuelst.hpp"
namespace lasd {

/* ************************************************************************** */

//Comparison Operator NODE
template<typename Data>
bool BinaryTree<Data>::Node::operator == (const Node& nodo) const noexcept{
    return element == nodo.element;
}

template<typename Data>
bool BinaryTree<Data>::Node::operator != (const Node& nodo) const noexcept{
    return !(*this == nodo);
}

//Funzione ausiliaria
template<typename Data>
bool BinaryTree<Data>::Compare(Node & current1, Node & current2) const noexcept{
    if (current1.Element() != current2.Element()) {
        return false;
    }
    
    bool result1 = false, result2 = false;
    
    if(current1.HasLeftChild() && current2.HasLeftChild()) {
    result1 = Compare(current1.LeftChild(), current2.LeftChild());
    } else if (!current1.HasLeftChild() && !current2.HasLeftChild()) {
        result1 = true;
    } else {
        result1 = false;
    }
    
    if (current1.HasRightChild() && current2.HasRightChild() && result1) {
        result2 = Compare(current1.RightChild(), current2.RightChild());
    } else if (!current1.HasRightChild() && !current2.HasRightChild()) {
        result2 = true;
    }
    
    return result1 && result2;
}

//Comparison Operator TREE
template<typename Data>
bool BinaryTree<Data>::operator == (const BinaryTree & tree) const noexcept{
    if(size != 0){
        if (size == tree.size){
            return Compare(Root(), tree.Root());
        }
    }
    if(size == 0 && tree.size == 0){
        return true;
    }
    return false;
}

template<typename Data>
bool BinaryTree<Data>::operator != (const BinaryTree& tree) const noexcept{
    return !(*this == tree);
}

// Specific member function (inherited from MappableContainer)
template<typename Data>
void BinaryTree<Data>::Map(MapFunctor funct) const{
    if(!Container::Empty())
        PreOrderMap(funct);
}

// Specific member function (inherited from FoldableContainer)
template<typename Data>
void BinaryTree<Data>::Fold(FoldFunctor funct, void* acc) const{
    if(!Container::Empty())
        PreOrderFold(funct, acc, Root());
}

template<typename Data>
void BinaryTree<Data>::PreOrderFold(FoldFunctor funct, void* acc, Node & current) const{
    funct(current.Element(), acc);
    if(current.HasLeftChild())
        PreOrderFold(funct, acc, current.LeftChild());
    if(current.HasRightChild())
        PreOrderFold(funct, acc, current.RightChild());
}

// Specific member function (inherited from PreOrderMappableContainer)
template<typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor funct) const{
    if(!Container::Empty())
        PreOrderMap(funct, &Root());

}

// Specific member function (inherited from PostOrderMappableContainer)
template<typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor funct) const{
    if(!Container::Empty())
        PostOrderMap(funct, &Root());
    
}

// Specific member function (inherited from InOrderMappableContainer)
template<typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor funct) const{
    if(!Container::Empty())
        InOrderMap(funct, &Root());   
}

// Specific member function (inherited from BreadthMappableContainer)
template<typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor funct) const{
    if(!Container::Empty())
        BreadthMap(funct, &Root());   
}

// Auxiliary member function (for PreOrderMappableContainer)
template<typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor funct, const Node * current) const{
    funct(current->Element());
    if(current->HasLeftChild())
        PreOrderMap(funct, &current->LeftChild());
    if(current->HasRightChild())
        PreOrderMap(funct, &current->RightChild());
}

// Auxiliary member function (for PostOrderMappableContainer)
template<typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor funct, const Node * current) const{
    if(current->HasLeftChild())
        PostOrderMap(funct, &current->LeftChild());
    if(current->HasRightChild())
        PostOrderMap(funct, &current->RightChild());
    funct(current->Element());
}

// Auxiliary member function (for InOrderMappableContainer)
template<typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor funct, const Node * current) const{ 
    if(current->HasLeftChild())
        InOrderMap(funct, &current->LeftChild());
    funct(current->Element());
    if(current->HasRightChild())
        InOrderMap(funct, &current->RightChild());
}

// Auxiliary member function (for BreadthMappableContainer)
template<typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor funct, Node * current) const{
    QueueLst<Node*> queue;
    Node * temp = current;
    queue.Enqueue(temp);
    while (!queue.Empty())
    {
        temp = queue.Head();
        funct(temp->Element());
        if(temp->HasLeftChild())
            queue.Enqueue(& temp->LeftChild());
        if(temp->HasRightChild())
            queue.Enqueue(& temp->RightChild());
        queue.Dequeue();
    }
}

// Specific member function (inherited from MutableMappableContainer)
template<typename Data>
void MutableBinaryTree<Data>::Map(MutableMapFunctor funct){
    if(!Container::Empty())
        PreOrderMap(funct);
}

// Specific member function (inherited from MutablePreOrderMappableContainer)
template<typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MutableMapFunctor funct){
    if(!Container::Empty())
        PreOrderMap(funct, &Root());

}

// Specific member function (inherited from MutablePostOrderMappableContainer)
template<typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MutableMapFunctor funct){
    if(!Container::Empty())
        PostOrderMap(funct, &Root());
    
}

// Specific member function (inherited from MutableInOrderMappableContainer)
template<typename Data>
void MutableBinaryTree<Data>::InOrderMap(MutableMapFunctor funct){
    if(!Container::Empty())
        InOrderMap(funct, &Root());   
}

// Specific member function (inherited from MutableBreadthMappableContainer)
template<typename Data>
void MutableBinaryTree<Data>::BreadthMap(MutableMapFunctor funct){
    if(!Container::Empty())
        BreadthMap(funct, &Root());   
}

// Auxiliary member function (for MutablePreOrderMappableContainer)
template<typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MutableMapFunctor funct, MutableNode * current){
    funct(current->Element());
    if(current->HasLeftChild())
        PreOrderMap(funct, &current->LeftChild());
    if(current->HasRightChild())
        PreOrderMap(funct, &current->RightChild());
}

// Auxiliary member function (for MutablePostOrderMappableContainer)
template<typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MutableMapFunctor funct, MutableNode * current){
    if(current->HasLeftChild())
        PostOrderMap(funct, &current->LeftChild());
    if(current->HasRightChild())
        PostOrderMap(funct, &current->RightChild());
    funct(current->Element());
}

// Auxiliary member function (for MutableInOrderMappableContainer)
template<typename Data>
void MutableBinaryTree<Data>::InOrderMap(MutableMapFunctor funct, MutableNode * current){ 
    if(current->HasLeftChild())
        InOrderMap(funct, &current->LeftChild());
    funct(current->Element());
    if(current->HasRightChild())
        InOrderMap(funct, &current->RightChild());
}

// Auxiliary member function (for MutableBreadthMappableContainer)
template<typename Data>
void MutableBinaryTree<Data>::BreadthMap(MutableMapFunctor funct, MutableNode * current){
    QueueLst<MutableNode*> queue;
    //BinaryTree<Data>::Node * temp = & current;
    queue.Enqueue(current);
    while (!queue.Empty())
    {
        current = queue.Head();
        funct(current->Element());
        if(current->HasLeftChild())
            queue.Enqueue(& current->LeftChild());
        if(current->HasRightChild())
            queue.Enqueue(& current->RightChild());
        queue.Dequeue();
    }
}

// Specific Constructor BTPreOrderIterator
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data> & tree){
    // try {
    //     root = & tree.Root();
    // } catch(const std::exception & e) {
    //     root = nullptr;
    // }
    // current = root;

    if(tree.Size() != 0){
        root = &tree.Root();
        current = root;
    }
}

// Copy Constructor BTPreOrderIterator
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data> & iterator){
    current = iterator.current;
    root = iterator.root;
    stk = iterator.stk;
}

// Move Constructor BTPreOrderIterator
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data> && iterator) noexcept{
    std::swap(current, iterator.current);
    root = iterator.root;
    std::swap(iterator.stk, stk);
}

//Copy Assignment BTPreOrderIterator
template<typename Data>
BTPreOrderIterator<Data> & BTPreOrderIterator<Data>::operator = (const BTPreOrderIterator<Data> & iterator){
    current = iterator.current;
    root = iterator.root;
    stk = iterator.stk;
}

//Move Assignment BTPreOrderIterator
template<typename Data>
BTPreOrderIterator<Data> & BTPreOrderIterator<Data>::operator = (BTPreOrderIterator<Data> && iterator) noexcept{
    std::swap(current, iterator.current);
    root = iterator.root;
    std::swap(iterator.stk, stk);
}

//Comparison Operators BTPreOrderIterator
template<typename Data>
bool BTPreOrderIterator<Data>::operator == (const BTPreOrderIterator<Data> & iterator) const noexcept{
    if(iterator.root == root && iterator.current == current && stk == iterator.stk){
        return true;
    }
    return false;
}

//Comparison Operators BTPreOrderIterator
template<typename Data>
bool BTPreOrderIterator<Data>::operator != (const BTPreOrderIterator<Data> & iterator) const noexcept{
    return !(*this == iterator);
}

// Specific member functions (inherited from Iterator)
template<typename Data>
Data & BTPreOrderIterator<Data>::operator*() const{
    if(!Terminated()){
        return current->Element();
    } else {
        throw std::out_of_range("Out of range");
    }
}

// Specific member functions (inherited from Iterator)
template<typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept{
    if(current == nullptr)
        return true;
    return false;
}

// Specific member functions (inherited from ForwardIterator)
template<typename Data>
void BTPreOrderIterator<Data>::operator++(){
    if(!Terminated()){
        // current = stk.Top();
        // stk.Pop();
        if(current->HasLeftChild()){
                if(current->HasRightChild()){
                    stk.Push(&current->RightChild());
                }
            current = &current->LeftChild();
        }else{
            if(current->HasRightChild()){
                current = &current->RightChild();
            } else if(!stk.Empty()){
                current = stk.TopNPop();
            } else {
                current = nullptr;
            }
        }
    } else {
        throw std::out_of_range("Out of range");
    }
}

// Specific member functions (inherited from ResettableIterator)
template<typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {
    current = root;
    stk.Clear();
}

// // Specific Constructor BTPreOrderMutableIterator
// template<typename Data>
// BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const MutableBinaryTree<Data> & tree){
//     try {
//         root = & tree.Root();
//     } catch(const std::exception & e) {
//         root = nullptr;
//     }
//     current = root;
// }

// Copy Constructor BTPreOrderMutableIterator
template<typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const BTPreOrderMutableIterator<Data> & iterator){
    current = iterator.current;
    root = iterator.root;
    stk = iterator.stk;
}

// Move Constructor BTPreOrderMutableIterator
template<typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(BTPreOrderMutableIterator<Data> && iterator) noexcept : BTPreOrderIterator<Data>(std::move(iterator)){
    // std::swap(current, iterator.current);
    // root = iterator.root;
    // std::swap(iterator.stk, stk);
}

//Copy Assignment BTPreOrderMutableIterator
template<typename Data>
BTPreOrderMutableIterator<Data> & BTPreOrderMutableIterator<Data>::operator = (const BTPreOrderMutableIterator<Data> & iterator){
    current = iterator.current;
    root = iterator.root;
    stk = iterator.stk;
}

//Move Assignment BTPreOrderMutableIterator
template<typename Data>
BTPreOrderMutableIterator<Data> & BTPreOrderMutableIterator<Data>::operator = (BTPreOrderMutableIterator<Data> && iterator) noexcept{
    std::swap(current, iterator.current);
    std::swap(root, iterator.root);
    std::swap(iterator.stk, stk);
}

//Comparison Operators BTPreOrderMutableIterator
template<typename Data>
bool BTPreOrderMutableIterator<Data>::operator == (const BTPreOrderMutableIterator<Data> & iterator) const noexcept{
    if(iterator.root == root && iterator.current == current && stk == iterator.stk){
        return true;
    }
    return false;
}

//Comparison Operators BTPreOrderMutableIterator
template<typename Data>
bool BTPreOrderMutableIterator<Data>::operator != (const BTPreOrderMutableIterator<Data> & iterator) const noexcept{
    return !(*this == iterator);
}

//Funzione ausiliaria BTPostOrderIterator
template<typename Data>
void BTPostOrderIterator<Data>::LeafFarLeft(){
    if(!Terminated()){
        if(current->HasLeftChild()){
            stk.Push(current);
            current = & current->LeftChild();
            LeafFarLeft();
        }else if(current->HasRightChild()){
            stk.Push(current);
            current = & current->RightChild();
            LeafFarLeft();
        }
    }
}

//Specific Constructor BTPostOrderIterator
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data> & tree){
    // try {
    //     root = &tree.Root();
    // }
    // catch(const std::exception& e) {
    //     root = nullptr;
    // }
    // current = root;
    // // stk.Push(current);
    // LeafFarLeft();

    if(tree.Size() != 0){
        root = &tree.Root();
        current = root;
        LeafFarLeft();
    }
}

//Copy Constructor BTPostOrderIterator
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data> & iterator){
    current = iterator.current;
    root = iterator.root;
    stk = iterator.stk;
}

//Move Constructor BTPostOrderIterator
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data> && iterator) noexcept{
    std::swap(current, iterator.current);
    root = iterator.root;
    std::swap(iterator.stk, stk);
}

//Copy Assignment
template<typename Data>
BTPostOrderIterator<Data> & BTPostOrderIterator<Data>::operator = (const BTPostOrderIterator<Data> & iterator){
    current = iterator.current;
    root = iterator.root;
    stk = iterator.stk;
}

//Move Assignment
template<typename Data>
BTPostOrderIterator<Data> & BTPostOrderIterator<Data>::operator = (BTPostOrderIterator<Data> && iterator) noexcept{
    std::swap(current, iterator.current);
    root = iterator.root;
    std::swap(iterator.stk, stk);
}

//Comparison Operator
template<typename Data>
bool BTPostOrderIterator<Data>::operator == (const BTPostOrderIterator<Data> & iterator) const noexcept{
    if(iterator.root == root && iterator.current == current && stk == iterator.stk)
        return true;
    return false;
}

//Comparison Operator
template<typename Data>
bool BTPostOrderIterator<Data>::operator != (const BTPostOrderIterator<Data> & iterator) const noexcept{
    return !(*this == iterator);
}

// Specific member functions (inherited from Iterator)
template<typename Data>
Data & BTPostOrderIterator<Data>::operator*() const{
    if(!Terminated()){
        return current->Element();
    }else{
        throw std::out_of_range("Out of range");
    }
}

// Specific member functions (inherited from Iterator)
template<typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept{
    if(current == nullptr)
        return true;
    return false;
}

// Specific member functions (inherited from ForwardIterator)
template<typename Data>
void BTPostOrderIterator<Data>::operator++(){
    if(!Terminated()){
        if(!stk.Empty()){
            if(stk.Top()->HasRightChild() && &stk.Top()->RightChild() == current){
                current = stk.TopNPop();
            }
            else if(stk.Top()->HasLeftChild() && &stk.Top()->LeftChild() == current && stk.Top()->HasRightChild()){ 
                current = &stk.Top()->RightChild();
                LeafFarLeft();
            }
            else
                current = stk.TopNPop();
        }
        else
            current = nullptr;
    } else {
        throw std::out_of_range("Out of range");
    }
}

// Specific member functions (inherited from ResettableIterator)
template<typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept{
    current = root;
    stk.Clear();
    LeafFarLeft();
}

//Funzione ausiliaria BTPostOrderMutableIterator
template<typename Data>
void BTPostOrderMutableIterator<Data>::LeafFarLeft(){
    if(!(BTPostOrderIterator<Data>::Terminated())){
        if(current->HasLeftChild()){
            stk.Push(current);
            current = & current->LeftChild();
            LeafFarLeft();
        }else if(current->HasRightChild()){
            stk.Push(current);
            current = & current->RightChild();
            LeafFarLeft();
        }
    }
}

//Specific Constructor BTPostOrderMutableIterator
// template<typename Data>
// BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(MutableBinaryTree<Data> & tree){
//     try {
//         root = & tree.Root();
//     } catch(const std::exception& e) {
//         root = nullptr;
//     }
//     current = root;
//     // stk.Push(current);
//     LeafFarLeft();
// }

//Copy Constructor BTPostOrderMutableIterator
template<typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data> & iterator){
    current = iterator.current;
    root = iterator.root;
    stk = iterator.stk;
}

//Move Constructor BTPostOrderMutableIterator
template<typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(BTPostOrderMutableIterator<Data> && iterator) noexcept : BTPostOrderIterator<Data>(std::move(iterator)){
    // std::swap(current, iterator.current);
    // root = iterator.root;
    // std::swap(iterator.stk, stk);
}

//Copy Assignment
template<typename Data>
BTPostOrderMutableIterator<Data> & BTPostOrderMutableIterator<Data>::operator = (const BTPostOrderMutableIterator<Data> & iterator){
    current = iterator.current;
    root = iterator.root;
    stk = iterator.stk;
}

//Move Assignment
template<typename Data>
BTPostOrderMutableIterator<Data> & BTPostOrderMutableIterator<Data>::operator = (BTPostOrderMutableIterator<Data> && iterator) noexcept{
    std::swap(current, iterator.current);
    root = iterator.root;
    std::swap(iterator.stk, stk);
}

//Comparison Operator
template<typename Data>
bool BTPostOrderMutableIterator<Data>::operator == (const BTPostOrderMutableIterator<Data> & iterator) const noexcept{
    if(iterator.root == root && iterator.current == current && stk == iterator.stk)
        return true;
    return false;
}

//Comparison Operator
template<typename Data>
bool BTPostOrderMutableIterator<Data>::operator != (const BTPostOrderMutableIterator<Data> & iterator) const noexcept{
    return !(*this == iterator);
}

//Funzione ausiliaria BTInOrderIterator
template<typename Data>
void BTInOrderIterator<Data>::FarLeft(){
    if(!Terminated()){
        while(current->HasLeftChild()){
            stk.Push(current); 
            current = &current->LeftChild();
        }
    }
}

//Specific Constructor BTInOrderIterator
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data> & tree){
    // try {
    //     root = &tree.Root();
    // } catch(const std::exception& e) {
    //     root = nullptr;
    // }
    // current = root;
    // FarLeft();

    if(tree.Size() != 0){
        root = &tree.Root();
        current = root;
        FarLeft();
    }
}

//Copy Constructor BTInOrderIterator
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data> & iterator){
    current = iterator.current;
    root = iterator.root;
    stk = iterator.stk;
}

//Move Constructor BTInOrderIterator
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data> && iterator) noexcept{
    std::swap(current, iterator.current);
    root = iterator.root;
    std::swap(iterator.stk, stk);
}

//Copy Assignment BTInOrderIterator
template<typename Data>
BTInOrderIterator<Data> & BTInOrderIterator<Data>::operator = (const BTInOrderIterator<Data> & it){
    current = it.current;
    root = it.root;
    stk = it.stk;
}

//Move Assignment BTInOrderIterator
template<typename Data>
BTInOrderIterator<Data> & BTInOrderIterator<Data>::operator = (BTInOrderIterator<Data> && iterator)noexcept{
    std::swap(current, iterator.current);
    root = iterator.root;
    std::swap(iterator.stk, stk);
}

//Comparison Operator BTInOrderIterator
template<typename Data>
bool BTInOrderIterator<Data>::operator == (const BTInOrderIterator<Data> & it) const noexcept{
    if(it.root == root && it.current == current && stk == it.stk)
        return true;
    return false;
}

template<typename Data>
bool BTInOrderIterator<Data>::operator != (const BTInOrderIterator<Data> & it) const noexcept{
    return !(*this == it);
}

// Specific member functions (inherited from Iterator)
template<typename Data>
Data & BTInOrderIterator<Data>::operator*() const{
    if(!Terminated()){
        return current->Element();
    }else{
        throw std::out_of_range("Out of range");
    }
}

// Specific member functions (inherited from Iterator)
template<typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept{
    if(current == nullptr) 
        return true;
    return false;
}

// Specific member functions (inherited from ForwardIterator)
template<typename Data>
void BTInOrderIterator<Data>::operator++(){
    if(!Terminated()){
        if(current->HasRightChild()){
            current = &current->RightChild();
            FarLeft();
        }else if(!stk.Empty()){
            current = stk.TopNPop();
        }else{
            current = nullptr;
        }
    } else {
        throw std::out_of_range("Out of range");
    }
}

// Specific member functions (inherited from ResettableIterator)
template<typename Data>
void BTInOrderIterator<Data>::Reset() noexcept{
    current = root;
    stk.Clear();
    FarLeft();
}

//Funzione ausiliaria BTInOrderMutableIterator
template<typename Data>
void BTInOrderMutableIterator<Data>::FarLeft(){
    if(!(BTInOrderIterator<Data>::Terminated())){
        while(current->HasLeftChild()){
            stk.Push(current); 
            current = &current->LeftChild();
        }
    }
}

// //Specific Constructor BTInOrderMutableIterator
// template<typename Data>
// BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(MutableBinaryTree<Data> & tree){
//     try {
//         root = &tree.Root();
//     } catch(const std::exception& e) {
//         root = nullptr;
//     }
//     current = root;
//     FarLeft();
// }

//Copy Constructor BTInOrderMutableIterator
template<typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const BTInOrderMutableIterator<Data> & iterator){
    current = iterator.current;
    root = iterator.root;
    stk = iterator.stk;
}

//Move Constructor BTInOrderMutableIterator
template<typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(BTInOrderMutableIterator<Data> && iterator) noexcept : BTInOrderIterator<Data>(std::move(iterator)){
    // std::swap(current, iterator.current);
    // root = iterator.root;
    // std::swap(iterator.stk, stk);
}

//Copy Assignment BTInOrderMutableIterator
template<typename Data>
BTInOrderMutableIterator<Data> & BTInOrderMutableIterator<Data>::operator = (const BTInOrderMutableIterator<Data> & it){
    current = it.current;
    root = it.root;
    stk = it.stk;
}

//Move Assignment BTInOrderMutableIterator
template<typename Data>
BTInOrderMutableIterator<Data> & BTInOrderMutableIterator<Data>::operator = (BTInOrderMutableIterator<Data> && iterator)noexcept{
    std::swap(current, iterator.current);
    root = iterator.root;
    std::swap(iterator.stk, stk);
}

//Comparison Operator BTInOrderMutableIterator
template<typename Data>
bool BTInOrderMutableIterator<Data>::operator == (const BTInOrderMutableIterator<Data> & it) const noexcept{
    if(it.root == root && it.current == current && stk == it.stk)
        return true;
    return false;
}

template<typename Data>
bool BTInOrderMutableIterator<Data>::operator != (const BTInOrderMutableIterator<Data> & it) const noexcept{
    return !(*this == it);
}

//Specific Constructor BTBreadthIterator
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data> & tree){
    // try {
    //     root = &tree.Root();
    // } catch(const std::exception & e) {
    //     root = nullptr;
    // }
    // current = root;
    if(tree.Size() != 0){
        root = &tree.Root();
        current = root;
    }
}

//Copy Constructor BTBreadthIterator
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data> & iterator){
    current = iterator.current;
    root = iterator.root;
    queue = iterator.queue;
}

//Move Constructor BTBreadthIterator
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data> && iterator) noexcept{
    std::swap(current, iterator.current);
    root = iterator.root;
    std::swap(iterator.queue, queue);
}

//Copy Assignment BTBreadthIterator
template<typename Data>
BTBreadthIterator<Data> & BTBreadthIterator<Data>::operator = (const BTBreadthIterator<Data> & it){
    current = it.current;
    root = it.root;
    queue = it.queue;
}

//Move Assignment BTBreadthIterator
template<typename Data>
BTBreadthIterator<Data> & BTBreadthIterator<Data>::operator = (BTBreadthIterator<Data> && it) noexcept{
    std::swap(current, it.current);
    root = it.root;
    std::swap(it.queue, queue);
}

//Comparison Operator BTBreadthIterator
template<typename Data>
bool BTBreadthIterator<Data>::operator == (const BTBreadthIterator<Data> & it) const noexcept{
    if(it.root == root && it.current == current && queue == it.queue){
        return true;
    }
    return false;
}

template<typename Data>
bool BTBreadthIterator<Data>::operator != (const BTBreadthIterator<Data> & it) const noexcept{
    return !(*this == it);
}

// Specific member functions (inherited from Iterator)
template<typename Data>
Data & BTBreadthIterator<Data>::operator*() const{
    if(!Terminated()){
        return current->Element();
    } else {
        throw std::out_of_range("Out of range");
    }
}

template<typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept{
    if(current == nullptr){
        return true;
    }
    return false;
}

// Specific member functions (inherited from ForwardIterator)
template<typename Data>
void BTBreadthIterator<Data>::operator++(){
    if(!Terminated()){
        if(current != nullptr){
            if(current->HasLeftChild() || current->HasRightChild() || !queue.Empty()){
                if(current->HasLeftChild()){
                    queue.Enqueue(&current->LeftChild());
                }
                if(current->HasRightChild()){
                    queue.Enqueue(&current->RightChild());
                }
                current = queue.HeadNDequeue();
            } else {
                current = nullptr;
            }
        } else {
            throw std::out_of_range("Out of range");
        }
    }
}

// Specific member functions (inherited from ResettableIterator)
template<typename Data>
void BTBreadthIterator<Data>::Reset() noexcept{
    current = root;
    queue.Clear();
}

//Specific Constructor BTBreadthMutableIterator
// template<typename Data>
// BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(MutableBinaryTree<Data> & tree){
//     try {
//         root = &tree.Root();
//     } catch(std::exception & e) {
//         root = nullptr;
//     }
//     current = root;
// }

//Copy Constructor BTBreadthMutableIterator
template<typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(const BTBreadthMutableIterator<Data> & iterator){
    current = iterator.current;
    root = iterator.root;
    queue = iterator.queue;
}

//Move Constructor BTBreadthMutableIterator
template<typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(BTBreadthMutableIterator<Data> && iterator) noexcept : BTBreadthIterator<Data>(std::move(iterator)){
    // std::swap(current, iterator.current);
    // root = iterator.root;
    // std::swap(iterator.queue, queue);
}

//Copy Assignment BTBreadthMutableIterator
template<typename Data>
BTBreadthMutableIterator<Data> & BTBreadthMutableIterator<Data>::operator = (const BTBreadthMutableIterator<Data> & it){
    current = it.current;
    root = it.root;
    queue = it.queue;
}

//Move Assignment BTBreadthMutableIterator
template<typename Data>
BTBreadthMutableIterator<Data> & BTBreadthMutableIterator<Data>::operator = (BTBreadthMutableIterator<Data> && it) noexcept{
    std::swap(current, it.current);
    root = it.root;
    std::swap(it.queue, queue);
}

//Comparison Operator BTBreadthMutableIterator
template<typename Data>
bool BTBreadthMutableIterator<Data>::operator == (const BTBreadthMutableIterator<Data> & it) const noexcept{
    if(it.root == root && it.current == current && queue == it.queue){
        return true;
    }
    return false;
}

template<typename Data>
bool BTBreadthMutableIterator<Data>::operator != (const BTBreadthMutableIterator<Data> & it) const noexcept{
    return !(*this == it);
}

/* ************************************************************************** */

}
