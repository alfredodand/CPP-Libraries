
#include <stdexcept>
#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template <typename Data>
    void MappableContainer<Data>::Fold(FoldFunctor fun, void * acc) const {
        Fold(fun, acc);
    }

    template <typename Data>
    void PreOrderMappableContainer<Data>::Map(MapFunctor fun) const  {
        PreOrderMap(fun);
    }

    template <typename Data>
    void PreOrderMappableContainer<Data>::Fold(FoldFunctor fun, void * acc) const  {
        PreOrderFold(fun, acc);
    }

    template <typename Data>
    void PreOrderMappableContainer<Data>::PreOrderFold(FoldFunctor fun, void * acc) const {
        Map(
            [acc, &fun](const Data & x){
                fun(x, acc);
            }
        );
    }

    template <typename Data>
    void PostOrderMappableContainer<Data>::Map(MapFunctor fun) const  {
        PostOrderMap(fun);
    }

    template <typename Data>
    void PostOrderMappableContainer<Data>::Fold(FoldFunctor fun, void * acc) const  {
        PostOrderFold(fun, acc);
    }

    template <typename Data>
    void PostOrderMappableContainer<Data>::PostOrderFold(FoldFunctor fun, void * acc) const {
        Map(
            [acc, &fun](const Data & x){
                fun(x, acc);
            }
        );
    }

    template <typename Data>
    void InOrderMappableContainer<Data>::Map(MapFunctor fun) const  {
        InOrderMap(fun);
    }

    template <typename Data>
    void InOrderMappableContainer<Data>::Fold(FoldFunctor fun, void * acc) const  {
        InOrderFold(fun, acc);
    }

    template <typename Data>
    void InOrderMappableContainer<Data>::InOrderFold(FoldFunctor fun, void * acc) const {
        Map(
            [acc, &fun](const Data & x){
                fun(x, acc);
            }
        );
    }

    template <typename Data>
    void BreadthMappableContainer<Data>::Map(MapFunctor fun)  const {
        BreadthMap(fun);
    }

    template <typename Data>
    void BreadthMappableContainer<Data>::Fold(FoldFunctor fun, void * acc) const  {
        BreadthFold(fun, acc);
    }

    template <typename Data>
    void BreadthMappableContainer<Data>::BreadthFold(FoldFunctor fun, void * acc) const {
        Map(
            [acc, &fun](const Data & x){
                fun(x, acc);
            }
        );
    }

    template <typename Data>
    void MutablePreOrderMappableContainer<Data>::Map(MutableMapFunctor fun)  {
        PreOrderMap(fun);
    }

    template <typename Data>
    void MutablePostOrderMappableContainer<Data>::Map(MutableMapFunctor fun)  {
        PostOrderMap(fun);
    }

    template <typename Data>
    void MutableInOrderMappableContainer<Data>::Map(MutableMapFunctor fun)  {
        InOrderMap(fun);
    }

    template <typename Data>
    void MutableBreadthMappableContainer<Data>::Map(MutableMapFunctor fun)  {
        BreadthMap(fun);
    }

/* ************************************************************************** */

;}
