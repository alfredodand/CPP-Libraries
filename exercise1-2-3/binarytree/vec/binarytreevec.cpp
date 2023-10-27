
namespace lasd {

/* ************************************************************************** */

//Specific Constructors NodeVec
template<typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Vector<BinaryTreeVec<Data>::NodeVec*> & vec, unsigned long pos, const Data & element) : vect(vec){
    this->pos = pos;
    this->element = element;
}

template<typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Vector<BinaryTreeVec<Data>::NodeVec*> & vec, unsigned long pos, Data && element) : vect(std::move(vec)) {
    std::swap(this.pos = pos);
    std::swap(this.element, element);
}

template<typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const NodeVec& nodo){
    this->vect = nodo.vect;
    this->pos = nodo.pos;
    this->element = nodo.element;
}


template<typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(NodeVec&& nodo){
    std::swap(this->vect, nodo.vect);
    std::swap(this->pos, nodo.pos);
    std::swap(this->element, nodo.element);
}

//Destructor NodeVec
// template<typename Data>
// BinaryTreeVec<Data>::NodeVec::~NodeVec(){
//     for(unsigned long i = 0; i < vect.Size(); i++){
//         delete Elements[i];
//     }
// }

//Specific member functions
template<typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept{
    return element;
}

template<typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept{
    return element;
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{
    if(2 * pos + 1 < vect.Size()){
        if(vect[2 * pos + 1] != nullptr)
            return true;
    }
    return false;
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{
    if(2 * pos + 2 < vect.Size()){
        if(vect[2* pos + 2] != nullptr)
            return true;
    }
    return false;
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept{
    if(!(HasLeftChild() && HasRightChild()))
        return true;
    return false;
}

template<typename Data>
typename BinaryTreeVec<Data>::Node & BinaryTreeVec<Data>::NodeVec::LeftChild() const{
    if(HasLeftChild())
        return *vect[2 * pos + 1];
    else
        throw std::out_of_range("Out of range");
}


template<typename Data>
typename BinaryTreeVec<Data>::Node & BinaryTreeVec<Data>::NodeVec::RightChild() const{
    if(HasRightChild())
        return *vect[2 * pos + 2];
    else
        throw std::out_of_range("Out of range");
}

template<typename Data>
typename MutableBinaryTree<Data>::MutableNode & BinaryTreeVec<Data>::NodeVec::LeftChild(){
    if(HasLeftChild())
        return *vect[2 * pos + 1];
    else
        throw std::out_of_range("Out of range");
}

template<typename Data>
typename MutableBinaryTree<Data>::MutableNode & BinaryTreeVec<Data>::NodeVec::RightChild(){
    if(HasRightChild())
        return *vect[2 * pos + 2];
    else
        throw std::out_of_range("Out of range");
}

//Specific Constructors BinaryTreeVec
template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const MappableContainer<Data> & container){
    // Elements.Resize(container.Size());
    // for (unsigned long i = 0; i < container.Size(); i++)
    //     Elements[i] = new NodeVec(Elements, i, container);
    // size = container.Size();

    unsigned long j = 0;
    Elements.Resize(container.Size());
    size = container.Size();
    container.Map(
        [this, & j](const Data & newData) {
            (Elements)[j++] = new NodeVec(Elements, j, newData);
        }
    );
}

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MutableMappableContainer<Data> && container){
    // Elements.Resize(container.Size());
    // for (unsigned long i = 0; i < container.Size(); i++)
    //     Elements[i] = new NodeVec(Elements, i, container[i]);
    // size = container.Size();

    unsigned long j = 0;
    Elements.Resize(container.Size());
    size = container.Size();
    container.Map(
        [this, & j](Data && newData) {
            (Elements)[j++] = new NodeVec(std::move(Elements, j, newData));
        }
    );
}

//Copy Constructor
template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& tree){
    //Clear();
    Elements.Resize(tree.size);
    Elements = tree.Elements;
    size = tree.size;
}

//Move Constructor
template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& tree) noexcept{
    //Elements.Resize(tree.size);
    std::swap(Elements, tree.Elements);
    std::swap(size, tree.size);
    // for(int i = 0; i<size; i++){Elements[i]->vect = this->Elements;}
    // for(int i = 0; i<tree.size; i++){tree.Elements[i]->vect = tree.Elements;}
}

//Destructor BinaryTreeVec
template<typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec(){
    // if(size > 0) {
    //     for(unsigned int i = 0; i < size; i++) {
    //         delete (Elements)[i];
    //     }
    //     // Elements.Clear();
    //     // size = 0;
    // }

    // for(unsigned int i = Elements.Size() - 1; i > 0; i--) {        
    //     delete (Elements)[i];
    // }

    Clear();
    
    // if(size > 0){
    //     for(unsigned int i = 0; i < Elements.Size(); i++) {
    //         for(unsigned int i = 0; i < size; i++) {
    //             delete (Elements)[i];
    //         }
    //         Elements.Clear();
    //         size = 0;
    //     }   
    // }
}

//Comparison Operators
template<typename Data>
bool BinaryTreeVec<Data>::operator == (const BinaryTreeVec & btv) const noexcept {
    return (BinaryTree<Data>::operator == (btv));
}

template<typename Data>
bool BinaryTreeVec<Data>::operator != (const BinaryTreeVec & btv) const noexcept{
    return !(*this == btv);
}

//Copy Assignment
template<typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator = (const BinaryTreeVec<Data>& tree){
    //Clear();
    Elements.Resize(tree.size);
    Elements = tree.Elements;
    size = tree.size;
    return *this;
}

//Move Assignment
template<typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator = (BinaryTreeVec<Data>&& tree) noexcept{
    // Clear();
    Elements.Resize(tree.size);
    std::swap(Elements, tree.Elements);
    std::swap(size, tree.size);
    // for(int i = 0; i<size; i++){Elements[i]->vect = this->Elements;}
    // for(int i = 0; i<tree.size; i++){tree.Elements[i]->vect = tree.Elements;}
    return *this;
}

// Specific member functions (inherited from BinaryTree)
template<typename Data>
typename BinaryTree<Data>::Node & BinaryTreeVec<Data>::Root() const {
    if(!Container::Empty())
        return *Elements[0];
    else
        throw std::length_error("L'albero è vuoto");
}

// Specific member functions (inherited from MutableBinaryTree)
template<typename Data>
typename MutableBinaryTree<Data>::MutableNode & BinaryTreeVec<Data>::Root() {
    if(!Container::Empty())
        return *Elements[0];
    else
        throw std::length_error("L'albero è vuoto");
}

// Specific member function (inherited from ClearableContainer)
template<typename Data>
void BinaryTreeVec<Data>::Clear() noexcept{
    Elements.Resize(0);
    Elements.Clear();
    size = 0;
    // if(size > 0) {
    //     for(unsigned int i = 0; i < size; i++) {
    //         delete (Elements)[i];
    //     }
    //     Elements.Clear();
    //     size = 0;
    // } 
    // for(unsigned long i = 0; i < size; i++){
    //     delete(Elements)[i];
    // } 
}

// Specific member functions (inherited from BreadthFoldableContainer)
template<typename Data>
void BinaryTreeVec<Data>::BreadthFold(FoldFunctor funct, void* acc) const{
    for (unsigned long i = 0; i < size; ++i)
        funct(Elements[i]->Element(), acc);  
}

// Specific member functions (inherited from BreadthMappableContainer)
template<typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFunctor funct) const{
    for (unsigned long i = 0; i < size; ++i)
        funct(Elements[i]->Element());  
}

// Specific member functions (inherited from MutableBreadthMappableContainer)
template<typename Data>
void BinaryTreeVec<Data>::BreadthMap(MutableMapFunctor funct){
    for (unsigned long i = 0; i < size; ++i)
        funct(Elements[i]->Element());  
}

/* ************************************************************************** */

}
