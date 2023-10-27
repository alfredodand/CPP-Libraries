
namespace lasd {

/* ************************************************************************** */

//Specific Constructor NodeLnk
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data && data) noexcept {
    std::swap(element, data);
}

//Copy Constructor NodeLnk
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk & node){
    element = node.element;
    if(node.left != nullptr){
        left = new NodeLnk(*node.left);
    }
    if(node.right != nullptr){
        right = new NodeLnk(*node.right);
    }
}

//Move Constructor NodeLnk
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk && node) noexcept{
    std::swap(left, node.left);
    std::swap(right, node.right);
    std::swap(element, node.element);
}

//Destructor NodeLnk
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
    delete left;
    delete right;
}

template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() {
    if (root != nullptr) {
        delete root;
        root = nullptr;
    }
}

//Copy Assignment NodeLnk
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk & BinaryTreeLnk<Data>::NodeLnk::operator = (const NodeLnk & node) {
    element = node.element;
    if(left == nullptr){
        if(node.left != nullptr){
            left = new NodeLnk(*node.left);
        }
    } else {
        if(node.left != nullptr){
            *left = *node.left;
        } else {
            delete left;
            left = nullptr;
        }
    }
    if(right == nullptr){
        if(node.right != nullptr){
            right = new NodeLnk(*node.right);
        }
    } else {
        if(node.right != nullptr){
            *right = *node.right;
        } else {
            delete right;
            right = nullptr;
        }
    }
    return *this;
}

//Move Assignment NodeLnk
template <typename Data>
inline typename BinaryTreeLnk<Data>::NodeLnk & BinaryTreeLnk<Data>::NodeLnk::operator = (NodeLnk && node) noexcept {
    std::swap(element, node.element);
    std::swap(left, node.left);
    std::swap(right, node.right);

    return *this;
}

//Comparison Operators NodeLnk
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator == (const NodeLnk & node) const noexcept {
    return (element == node.element) \
    &&  ((left == nullptr && node.left == nullptr) || (left != nullptr && node.left != nullptr) && (*left == *node.left)) \
    &&  ((right == nullptr && node.right == nullptr) || (right != nullptr && node.right != nullptr) && (*right == *node.right));
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator != (const NodeLnk & node) const noexcept {
    return !(*this == node);
}

//Specific member function inherited from Node
template <typename Data>
inline const Data & BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept {
    return element;
}

template <typename Data>
inline Data & BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
    return element;
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept {
    //return ((left == nullptr) && (right == nullptr));
    if(!(HasLeftChild() && HasRightChild()))
        return true;
    return false;
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
    if(left != nullptr)
        return true;
    return false;
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
    if(right != nullptr)
        return true;
    return false;
}

template <typename Data>
inline typename BinaryTreeLnk<Data>::Node & BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
    if(left != nullptr){
        return *left;
    } else {
        throw std::out_of_range("Non esiste figio sinistro");
    }
}

template <typename Data>
inline typename BinaryTreeLnk<Data>::Node & BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
    if(right != nullptr){
        return *right;
    } else {
        throw std::out_of_range("Non esiste figio destro");
    }
}

template <typename Data>
inline typename BinaryTreeLnk<Data>::MutableNode & BinaryTreeLnk<Data>::NodeLnk::LeftChild() {
    if(left != nullptr){
        return *left;
    } else {
        throw std::out_of_range("Non esiste figio sinistro");
    }
}

template <typename Data>
inline typename BinaryTreeLnk<Data>::MutableNode & BinaryTreeLnk<Data>::NodeLnk::RightChild() {
    if(right != nullptr){
        return *right;
    } else {
        throw std::out_of_range("Non esiste figio destro");
    }
}

//Specific Constructors BinaryTreeLnk
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const MappableContainer<Data> & container) {
    size = container.Size();
    QueueVec<NodeLnk * *> Queue;
    Queue.Enqueue(&root);
    container.Map(
        [& Queue](const Data & data) {
            NodeLnk * & cur = * Queue.HeadNDequeue();
            cur = new NodeLnk(data);
            Queue.Enqueue(&cur->left);
            Queue.Enqueue(&cur->right);
        }
    );
}//;

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MutableMappableContainer<Data> && container) {
    size = container.Size();
    QueueVec<NodeLnk * *> Queue;
    Queue.Enqueue(&root);
    container.Map(
        [& Queue](const Data & data) {
            NodeLnk * & cur = * Queue.HeadNDequeue();
            cur = new NodeLnk(std::move(data));
            Queue.Enqueue(&cur->left);
            Queue.Enqueue(&cur->right);
        }
    );
}//;

//Copy Constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk & btl) {
    if(btl.root != nullptr){
        root = new NodeLnk(*btl.root);
        size = btl.size;
    }
}//;

//Move Constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk && btl) noexcept {
    std::swap(root, btl.root);
    std::swap(size, btl.size);
}//;

//Copy Assignment
template <typename Data>
BinaryTreeLnk<Data> & BinaryTreeLnk<Data>::operator = (const BinaryTreeLnk<Data> & btl) {
    if(root == nullptr){
        if(btl.root != nullptr){
            root = new NodeLnk(*btl.root);
        }
    } else {
        if(btl.root == nullptr){
            delete root;
            root = nullptr;
        } else {
            *root = *btl.root;
        }
    }
    size = btl.size;
    return *this;
}

//Move Assignment
template <typename Data>
BinaryTreeLnk<Data> & BinaryTreeLnk<Data>::operator = (BinaryTreeLnk<Data> && btl) noexcept {
    std::swap(root, btl.root);
    std::swap(size, btl.size);

    return *this;
}

//Comparison Operators
template <typename Data>
bool BinaryTreeLnk<Data>::operator == (const BinaryTreeLnk<Data> & btl) const noexcept {
    return (size == btl.size) && ((root == nullptr && btl.root == nullptr) || (root != nullptr && btl.root != nullptr) && *root == *btl.root);
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator != (const BinaryTreeLnk<Data> & btl) const noexcept {
    return !(*this == btl);
}

// Specific member functions (inherited from BinaryTree)
template <typename Data>
typename BinaryTreeLnk<Data>::Node & BinaryTreeLnk<Data>::Root() const {
    if(root != nullptr){
        return *root;
    } else {
        throw std::length_error("Accesso ad un albero vuoto");
    }
}

template <typename Data>
typename BinaryTreeLnk<Data>::MutableNode & BinaryTreeLnk<Data>::Root() {
    if(root != nullptr){
        return *root;
    } else {
        throw std::length_error("Accesso ad un albero vuoto");
    }
}

template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
    delete root;
    root = nullptr;
    size = 0;
}

/* ************************************************************************** */

}
