
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertAll(const MappableContainer<Data> & x) {
        bool inserted = true;
        x.Map(
            [this, & inserted](const Data & data) {
                inserted = Insert(data);
            }
        );
        return inserted;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data> && x) {
        bool inserted = true;
        x.Map(
            [this, & inserted](const Data & data) {
                inserted = Insert(std::move(data));
            }
        );
        return inserted;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::RemoveAll(const MappableContainer<Data> & x) {
        bool removed = true;
        x.Map(
            [this, & removed](const Data & data) {
                removed = Remove(data);
            }
        );
        return removed;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertSome(const MappableContainer<Data> & x) {
        bool inserted = true;
        x.Map(
            [this, & inserted](const Data & data) {
                inserted = Insert(data);
            }
        );
        return inserted;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data> && x) {
        bool inserted = true;
        x.Map(
            [this, & inserted](const Data & data) {
                inserted = Insert(std::move(data));
            }
        );
        return inserted;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::RemoveSome(const MappableContainer<Data> & x) {
        bool removed = true;
        x.Map(
            [this, & removed](const Data & data) {
                removed = Remove(data);
            }
        );
        return removed;
    }

/* ************************************************************************** */

}
