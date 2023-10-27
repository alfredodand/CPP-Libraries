
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template<typename Data>
bool FoldableContainer<Data>::Exists(const Data& elementToFind) const noexcept{
    bool exist = false;
    Data temp = elementToFind;
    Fold({
        [this, &temp](const Data & dat, void * exis){
            if(dat == temp){
                *((bool*)exis) = true;
            }
        }
    }, & exist);
    return exist;
}

template <typename Data>
void PreOrderFoldableContainer<Data>::Fold(FoldFunctor fun, void * acc) const{
    PreOrderFold(fun, acc);
}

template <typename Data>
void PostOrderFoldableContainer<Data>::Fold(FoldFunctor fun, void * acc) const{
    PostOrderFold(fun, acc);
}

template <typename Data>
void InOrderFoldableContainer<Data>::Fold(FoldFunctor fun, void * acc) const{
    InOrderFold(fun, acc);
}

template <typename Data>
void BreadthFoldableContainer<Data>::Fold(FoldFunctor fun, void * acc) const{
    BreadthFold(fun, acc);
}

/* ************************************************************************** */

}
