
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

    template <typename Data>
    const Data & LinearContainer<Data>::operator[](const unsigned long i) const{
        if(i < Container::Size()) {
            return operator[](i);
        } else {
            throw std::out_of_range("Accesso all'indice " + std::to_string(i) + "; Dimensione reale = " + std::to_string(Container::Size()));
        }
    }

    template <typename Data>
    Data & LinearContainer<Data>::operator[](const unsigned long i){
        if(i < Container::Size()) {
            return operator[](i);
        } else {
            throw std::out_of_range("Accesso all'indice " + std::to_string(i) + "; Dimensione reale = " + std::to_string(Container::Size()));
        }
    }

    template <typename Data>
    inline const Data & LinearContainer<Data>::Front() const {
        return operator[](0);
    }

    template <typename Data>
    inline Data & LinearContainer<Data>::Front() {
        return operator[](0);
    }

    template <typename Data>
    inline const Data & LinearContainer<Data>::Back() const {
        return operator[](Container::Size() - 1);
    }

    template <typename Data>
    inline Data & LinearContainer<Data>::Back() {
        return operator[](Container::Size() - 1);
    }

    //Specific member function inherited from FoldableContainer
    template <typename Data>
    inline void LinearContainer<Data>::Fold(FoldFunctor fun, void * acc) const {
        PreOrderFold(fun, acc);
    }

    //Specific member function inherited from PreOrderFoldableContainer
    template <typename Data>
    inline void LinearContainer<Data>::PreOrderFold(FoldFunctor fun, void * acc) const {
        for(int i = 0; i < Container::Size(); ++i) {
            fun(operator[](i), acc);
        }
    }

    //Specific member function inherited from PostOrderFoldableContainer
    template <typename Data>
    inline void LinearContainer<Data>::PostOrderFold(FoldFunctor fun, void * acc) const {
        int i = Container::Size();
        while(i > 0) {
            fun(operator[](--i), acc);
        }
    }

    //Specific member function inherited from MappableContainer
    template <typename Data>
    inline void LinearContainer<Data>::Map(MapFunctor fun) const {
        PreOrderMap(fun);
    }

    //Specific member function inherited from PreOrderMappableContainer
    template <typename Data>
    inline void LinearContainer<Data>::PreOrderMap(MapFunctor fun) const {
        for(int i = 0; i < Container::Size(); ++i) {
            fun(operator[](i));
        }
    }

    //Specific member function inherited from PostOrderMappableContainer
    template <typename Data>
    inline void LinearContainer<Data>::PostOrderMap(MapFunctor fun) const {
        int i = Container::Size();
        while(i > 0) {
            fun(operator[](--i));
        }
    }

    //Specific member function inherited from MutableMappableContainer
    template <typename Data>
    inline void LinearContainer<Data>::Map(MutableMapFunctor fun) {
        PreOrderMap(fun);
    }

    //Specific member function inherited from MutableMappableContainer
    template <typename Data>
    inline void LinearContainer<Data>::PreOrderMap(MutableMapFunctor fun) {
        for(int i = 0; i < Container::Size(); ++i) {
            fun(operator[](i));
        }
    }

    //Specific member function inherited from MutableMappableContainer
    template <typename Data>
    inline void LinearContainer<Data>::PostOrderMap(MutableMapFunctor fun) {
        int i = Container::Size();
        while(i > 0) {
            fun(operator[](--i));
        }
    }

}
