#include <iostream>

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/foldable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"

#include "../list/list.hpp"

#include "../queue/queue.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"

#include "../stack/stack.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"

#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"

#include "../bst/bst.hpp"



/* ************************************************************************** */

bool Empty(const lasd::Container & vector){
    return vector.Empty();
}

unsigned long Size(const lasd::Container & vector){
    return vector.Size();
}

template <typename Data>
unsigned long Indice(const lasd::Vector<Data> & vector, int i){
    return vector.operator[](i);
}

template <typename Data>
unsigned long IndiceStack(const lasd::StackVec<Data> & stack, int i){
    return stack.operator[](i);
}

template <typename Data>
unsigned long IndiceQueue(const lasd::QueueVec<Data> & queue, int i){
    return queue.operator[](i);
}

template <typename Data>
unsigned long Primo(const lasd::Vector<Data> & vector){
    return vector.Front();
}

template <typename Data>
unsigned long Ultimo(const lasd::Vector<Data> & vector){
    return vector.Back();
}

template <typename Data>
unsigned long Indice(const lasd::List<Data> & list, int i){
    return list.operator[](i);
}

template <typename Data>
void MapPrint(const Data & data) {
  std::cout << data << " ";
}

template <typename Data>
void FoldAdd(const Data & data, void* acc) {
  *((Data*) acc) += data;
}

template <typename Data>
void Map(const lasd::MappableContainer<Data>& con, typename lasd::MappableContainer<Data>::MapFunctor fun) {
  con.Map(fun);
}

template <typename Data>
void PreOrderMap(const lasd::PreOrderMappableContainer<Data>& con, typename lasd::MappableContainer<Data>::MapFunctor fun) {
  con.PreOrderMap(fun);
}

template <typename Data>
void InOrderMap(const lasd::InOrderMappableContainer<Data>& con, typename lasd::MappableContainer<Data>::MapFunctor fun) {
  con.InOrderMap(fun);
}

template <typename Data>
long Fold(const lasd::FoldableContainer<Data> & con, typename lasd::FoldableContainer<Data>::FoldFunctor fun, const long & value) {
  long val = value;
  con.Fold(fun, & val);
  return val;
}

template <typename Data>
long PreOrderFold(const lasd::PreOrderFoldableContainer<Data> & con, typename lasd::FoldableContainer<Data>::FoldFunctor fun, const long & value) {
  long val = value;
  con.PreOrderFold(fun, & val);
  return val;
}

template <typename Data>
long PostOrderFold(const lasd::PostOrderFoldableContainer<Data> & con, typename lasd::FoldableContainer<Data>::FoldFunctor fun, const long & value) {
  long val = value;
  con.PostOrderFold(fun, & val);
  return val;
}

template <typename Data>
long InOrderFold(const lasd::InOrderFoldableContainer<Data> & con, typename lasd::FoldableContainer<Data>::FoldFunctor fun, const long & value) {
  long val = value;
  con.InOrderFold(fun, & val);
  return val;
}

template <typename Data>
long BreadthFold(const lasd::BreadthFoldableContainer<Data> & con, typename lasd::FoldableContainer<Data>::FoldFunctor fun, const long & value) {
  long val = value;
  con.BreadthFold(fun, & val);
  return val;
}

void personalLasdTest() {
    bool checked;
    unsigned long numero;
    std::string corretto;

    std::cout << std::endl << "~*~#~*~ Personal LASD Test ~*~#~*~ " << std::endl;
  
    //Vector
    std::cout << std::endl << "~~~~~ VECTOR TEST ~~~~~" << std::endl << std::endl;

    lasd::Vector<int> vec(10);
    checked = Empty(vec);
    corretto = (checked == 0) ? "Correct!" : "Error!";
    std::cout << "Empty (Array[10]): " << checked << " - " << corretto << std::endl;

    numero = Size(vec);
    corretto = (numero == 10) ? "Correct!" : "Error!";
    std::cout << "Size (Array[10]): " << numero << " - " << corretto << std::endl;

    vec.Resize(4);
    checked = Empty(vec);
    corretto = (checked == 0) ? "Correct!" : "Error!";
    std::cout << "Empty (Array[4]): " << checked << " - " << corretto << std::endl;

    numero = Size(vec);
    corretto = (numero == 4) ? "Correct!" : "Error!";
    std::cout << "Size (Array[4]): " << numero << " - " << corretto << std::endl;

    vec[0] = 2;
    numero = Indice(vec, 0);
    corretto = (numero == 2) ? "Correct!" : "Error!";
    std::cout << "Indice 0 (Array[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;

    vec[1] = 3;
    numero = Indice(vec, 1);
    corretto = (numero == 3) ? "Correct!" : "Error!";
    std::cout << "Indice 1 (Array[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;

    vec[2] = 1;
    numero = Indice(vec, 2);
    corretto = (numero == 1) ? "Correct!" : "Error!";
    std::cout << "Indice 2 (Array[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;

    vec[3] = 4;
    numero = Indice(vec, 3);
    corretto = (numero == 4) ? "Correct!" : "Error!";
    std::cout << "Indice 3 (Array[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;

    numero = Primo(vec);
    corretto = (numero == 2) ? "Correct!" : "Error!";
    std::cout << "Primo elemento (Array[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;

    numero = Ultimo(vec);
    corretto = (numero == 4) ? "Correct!" : "Error!";
    std::cout << "Ultimo elemento (Array[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;
    
    lasd::Vector<int> vecCopy = vec.operator=(vec);
    numero = Indice(vecCopy, 0);
    corretto = (numero == 2) ? "Correct!" : "Error!";
    std::cout << "Indice 0 (CopiaArray[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;

    numero = Indice(vecCopy, 1);
    corretto = (numero == 3) ? "Correct!" : "Error!";
    std::cout << "Indice 1 (CopiaArray[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;

    numero = Indice(vecCopy, 2);
    corretto = (numero == 1) ? "Correct!" : "Error!";
    std::cout << "Indice 2 (CopiaArray[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;

    numero = Indice(vecCopy, 3);
    corretto = (numero == 4) ? "Correct!" : "Error!";
    std::cout << "Indice 3 (CopiaArray[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;

    checked = vec.operator==(vecCopy);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Array == CopiaArray: " << checked << " - " << corretto << std::endl;

    vec.Clear();
    checked = Empty(vec);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Array svuotato: " << checked << " - " << corretto << std::endl;

    vecCopy.Clear();
    checked = Empty(vecCopy);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "CopiaArray svuotata: " << checked << " - " << corretto << std::endl;    



    //List
    std::cout << std::endl << std::endl << "~~~~~ LIST TEST ~~~~~" << std::endl << std::endl;

    lasd::List<int> lst;
    checked = Empty(lst);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Empty (List[0]): " << checked << " - " << corretto << std::endl;

    numero = Size(lst);
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "Size (List[0]): " << numero << " - " << corretto << std::endl;

    lst.InsertAtFront(2);
    lst.InsertAtFront(1);
    lst.InsertAtBack(3);

    checked = Empty(lst);
    corretto = (checked == 0) ? "Correct!" : "Error!";
    std::cout << "Empty (List[3] {1, 2, 3}): " << checked << " - " << corretto << std::endl;

    numero = Size(lst);
    corretto = (numero == 3) ? "Correct!" : "Error!";
    std::cout << "Size (List[3] {1, 2, 3}): " << numero << " - " << corretto << std::endl;

    numero = lst.Front();
    corretto = (numero == 1) ? "Correct!" : "Error!";
    std::cout << "Front (List[3] {1, 2, 3}): " << numero << " - " << corretto << std::endl;

    numero = lst.Back();
    corretto = (numero == 3) ? "Correct!" : "Error!";
    std::cout << "Back (List[3] {1, 2, 3}): " << numero << " - " << corretto << std::endl;

    lasd::List<int> lstCopy = lst.operator=(lst);
    checked = lst.operator==(lstCopy);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "List == CopiaList: " << checked << " - " << corretto << std::endl;

    lst.Clear();
    checked = Empty(lst);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Lista svuotata: " << checked << " - " << corretto << std::endl;
    
    lstCopy.Clear();
    checked = Empty(lstCopy);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "CopiaLista svuotata: " << checked << " - " << corretto << std::endl;

    try {
        numero = lst.Front();
        std::cout << "Front (Lista vuota): " << numero << " - " << corretto << std::endl;
    } catch(std::length_error exc) {
        std::cout << "Front (Lista vuota): Lista vuota" << std::endl;
    } catch(std::exception exc) {
        std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
    }

    try {
        numero = lst.Back();
        std::cout << "Back (Lista vuota): " << numero << " - " << corretto << std::endl;
    } catch(std::length_error exc) {
        std::cout << "Back (Lista vuota): Lista vuota" << std::endl;
    } catch(std::exception exc) {
        std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
    }



    //Stack
    std::cout << std::endl << std::endl << "~~~~~ STACK TEST ~~~~~" << std::endl;

    //StackVec
    std::cout << std::endl << "~~~ StackVec ~~~" << std::endl << std::endl;
    
    lasd::StackVec<int> stkv;
    checked = Empty(stkv);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Empty (StackArray[0]): " << checked << " - " << corretto << std::endl;

    numero = stkv.Size();
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "Size (StackArray[0]): " << numero << " - " << corretto << std::endl;

    stkv.Resize(4);
    checked = Empty(stkv);
    corretto = (checked == 0) ? "Correct!" : "Error!";
    std::cout << "Empty (StackArray[4]): " << checked << " - " << corretto << std::endl;

    stkv.Push(2);
    numero = IndiceStack(stkv, 0);
    corretto = (numero == 2) ? "Correct!" : "Error!";
    std::cout << "Indice 0 (StackArray[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;

    stkv.Push(3);
    numero = IndiceStack(stkv, 1);
    corretto = (numero == 3) ? "Correct!" : "Error!";
    std::cout << "Indice 1 (StackArray[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;

    stkv.Push(1);
    numero = IndiceStack(stkv, 2);
    corretto = (numero == 1) ? "Correct!" : "Error!";
    std::cout << "Indice 2 (StackArray[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;

    stkv.Push(4);
    numero = IndiceStack(stkv, 3);
    corretto = (numero == 4) ? "Correct!" : "Error!";
    std::cout << "Indice 3 (StackArray[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;

    numero = stkv.Size();
    corretto = (numero == 4) ? "Correct!" : "Error!";
    std::cout << "Size (StackArray[4]): " << numero << " - " << corretto << std::endl;

    numero = stkv.Top();
    corretto = (numero == 4) ? "Correct!" : "Error!";
    std::cout << "Top (StackArray[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;

    numero = stkv.TopNPop();
    corretto = (numero == 4) ? "Correct!" : "Error!";
    std::cout << "TopNPop (StackArray[4] {2, 3, 1, 4}): " << numero << " - " << corretto << std::endl;

    numero = stkv.Size();
    corretto = (numero == 3) ? "Correct!" : "Error!";
    std::cout << "Size (StackArray[3]): " << numero << " - " << corretto << std::endl;

    numero = stkv.Top();
    corretto = (numero == 1) ? "Correct!" : "Error!";
    std::cout << "Top (StackArray[3] {2, 3, 1}): " << numero << " - " << corretto << std::endl;

    lasd::StackVec<int> stkvCopy = stkv.operator=(stkv);
    numero = IndiceStack(stkv, 0);
    corretto = (numero == 2) ? "Correct!" : "Error!";
    std::cout << "Indice 0 (CopiaStackArray[3] {2, 3, 1}): " << numero << " - " << corretto << std::endl;

    numero = IndiceStack(stkv, 1);
    corretto = (numero == 3) ? "Correct!" : "Error!";
    std::cout << "Indice 1 (CopiaStackArray[3] {2, 3, 1}): " << numero << " - " << corretto << std::endl;

    numero = IndiceStack(stkv, 2);
    corretto = (numero == 1) ? "Correct!" : "Error!";
    std::cout << "Indice 2 (CopiaStackArray[3] {2, 3, 1}): " << numero << " - " << corretto << std::endl;

    checked = stkv.operator==(stkvCopy);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "StackArray == CopiaStackArray: " << checked << " - " << corretto << std::endl;

    stkv.Clear();
    checked = Empty(stkv);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "StackArray svuotato: " << checked << " - " << corretto << std::endl;

    stkvCopy.Clear();
    checked = Empty(stkvCopy);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Copia svuotata: " << checked << " - " << corretto << std::endl;


    //StackLst
    std::cout << std::endl << std::endl << "~~~ StackLst ~~~" << std::endl << std::endl;

    lasd::StackLst<int> stkl;
    checked = Empty(stkl);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Empty (StackLista[0]): " << checked << " - " << corretto << std::endl;

    numero = stkl.Size();
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "Size (StackLista[0]): " << numero << " - " << corretto << std::endl;

    stkl.Push(1);
    stkl.Push(2);
    stkl.Push(3);

    checked = Empty(stkl);
    corretto = (checked == 0) ? "Correct!" : "Error!";
    std::cout << "Empty (StackLista[3] {1, 2, 3}): " << checked << " - " << corretto << std::endl;

    numero = stkl.Size();
    corretto = (numero == 3) ? "Correct!" : "Error!";
    std::cout << "Size (StackLista[3] {1, 2, 3}): " << numero << " - " << corretto << std::endl;

    numero = stkl.Top();
    corretto = (numero == 3) ? "Correct!" : "Error!";
    std::cout << "Top (StackLista[3] {1, 2, 3}): " << numero << " - " << corretto << std::endl;

    stkl.Pop();
    numero = stkl.Top();
    corretto = (numero == 2) ? "Correct!" : "Error!";
    std::cout << "TopNPop (StackLista[2] {1, 2}): " << numero << " - " << corretto << std::endl;

    numero = stkl.Size();
    corretto = (numero == 2) ? "Correct!" : "Error!";
    std::cout << "Size (StackLista[2] {1, 2}): " << numero << " - " << corretto << std::endl;

    lasd::StackLst<int> stklCopy = stkl.operator=(stkl);
    checked = stkl.operator==(stklCopy);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "StackLista == CopiaStackLista: " << checked << " - " << corretto << std::endl;

    stkl.Clear();
    checked = Empty(stkl);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "CopiaStackLista svuotata: " << checked << " - " << corretto << std::endl;

    stklCopy.Clear();
    checked = Empty(stklCopy);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "CopiaStackLista svuotata: " << checked << " - " << corretto << std::endl;



    //Queue
    std::cout << std::endl << std::endl << "~~~~~ QUEUE TEST ~~~~~" << std::endl;

    //QueueVec
    std::cout << std::endl << "~~~ QueueVec ~~~" << std::endl << std::endl;
    
    lasd::QueueVec<int> quev;
    checked = Empty(quev);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Empty (QueueArray[0]): " << checked << " - " << corretto << std::endl;

    numero = quev.Size();
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "Size (QueueArray[0]): " << numero << " - " << corretto << std::endl;


    quev.Enqueue(1);
    numero = IndiceQueue(quev, 0);
    corretto = (numero == 1) ? "Correct!" : "Error!";
    std::cout << "Indice 0 (QueueArray[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    quev.Enqueue(2);
    numero = IndiceQueue(quev, 1);
    corretto = (numero == 2) ? "Correct!" : "Error!";
    std::cout << "Indice 1 (QueueArray[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    quev.Enqueue(3);
    numero = IndiceQueue(quev, 2);
    corretto = (numero == 3) ? "Correct!" : "Error!";
    std::cout << "Indice 2 (QueueArray[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    quev.Enqueue(4);
    numero = IndiceQueue(quev, 3);
    corretto = (numero == 4) ? "Correct!" : "Error!";
    std::cout << "Indice 3 (QueueArray[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = quev.Size();
    corretto = (numero == 4) ? "Correct!" : "Error!";
    std::cout << "Size (QueueArray[4]): " << numero << " - " << corretto << std::endl;

    numero = quev.Head();
    corretto = (numero == 1) ? "Correct!" : "Error!";
    std::cout << "Head (QueueArray[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = quev.HeadNDequeue();
    corretto = (numero == 1) ? "Correct!" : "Error!";
    std::cout << "HeadNDequeue (QueueArray[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = quev.Size();
    corretto = (numero == 3) ? "Correct!" : "Error!";
    std::cout << "Size (QueueArray[3]): " << numero << " - " << corretto << std::endl;

    numero = quev.Head();
    corretto = (numero == 2) ? "Correct!" : "Error!";
    std::cout << "Head (QueueArray[3] {2, 3, 4}): " << numero << " - " << corretto << std::endl;

    lasd::QueueVec<int> quevCopy = quev;
    numero = IndiceQueue(quevCopy, 0);
    corretto = (numero == 2) ? "Correct!" : "Error!";
    std::cout << "Indice 0 (CopiaQueueArray[3] {2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = IndiceQueue(quevCopy, 1);
    corretto = (numero == 3) ? "Correct!" : "Error!";
    std::cout << "Indice 1 (CopiaQueueArray[3] {2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = IndiceQueue(quevCopy, 2);
    corretto = (numero == 4) ? "Correct!" : "Error!";
    std::cout << "Indice 2 (CopiaQueueArray[3] {2, 3, 4}): " << numero << " - " << corretto << std::endl;

    checked = quev.operator==(quevCopy);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "QueueArray == CopiaQueueArray: " << checked << " - " << corretto << std::endl;

    quev.Clear();
    checked = Empty(quev);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Queue svuotata: " << checked << " - " << corretto << std::endl;

    quevCopy.Clear();
    checked = Empty(quevCopy);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Copia svuotata: " << checked << " - " << corretto << std::endl;


    //QueueLst
    std::cout << std::endl << std::endl << "~~~ QueueLst ~~~" << std::endl << std::endl;

    lasd::QueueLst<int> quel;
    checked = Empty(quel);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Empty (ListArray[0]): " << checked << " - " << corretto << std::endl;

    numero = quel.Size();
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "Size (ListArray[0]): " << numero << " - " << corretto << std::endl;

    quel.Enqueue(1);
    quel.Enqueue(2);
    quel.Enqueue(3);

    checked = Empty(quel);
    corretto = (checked == 0) ? "Correct!" : "Error!";
    std::cout << "Empty (ListArray[3] {1, 2, 3}): " << checked << " - " << corretto << std::endl;

    numero = quel.Size();
    corretto = (numero == 3) ? "Correct!" : "Error!";
    std::cout << "Size (ListArray[3] {1, 2, 3}): " << numero << " - " << corretto << std::endl;

    checked = quel.Exists(3);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Empty (ListArray[3] {1, 2, 3}): " << checked << " - " << corretto << std::endl;

    numero = quel.Head();
    corretto = (numero == 1) ? "Correct!" : "Error!";
    std::cout << "Head (ListArray[3] {1, 2, 3}): " << numero << " - " << corretto << std::endl;

    quel.Dequeue();
    numero = quel.Head();
    corretto = (numero == 2) ? "Correct!" : "Error!";
    std::cout << "HeadNDequeue (ListArray[2] {2, 3}): " << numero << " - " << corretto << std::endl;

    numero = quel.Size();
    corretto = (numero == 2) ? "Correct!" : "Error!";
    std::cout << "Size (List Array[2] {2, 3}): " << numero << " - " << corretto << std::endl;

    lasd::StackLst<int> quelCopy = quel.operator=(quel);
    checked = quel.operator==(quelCopy);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "QueueLista == CopiaQueueLista: " << checked << " - " << corretto << std::endl;

    quel.Clear();
    checked = Empty(quel);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "QueueLista svuotata: " << checked << " - " << corretto << std::endl;

    quelCopy.Clear();
    checked = Empty(quelCopy);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "CopiaQueueLista svuotata: " << checked << " - " << corretto << std::endl;


    //Tree
    std::cout << std::endl << std::endl << "~~~~~ TREE TEST ~~~~~" << std::endl;

    //BinaryTree
    std::cout << std::endl << "~~~ BinaryTree ~~~" << std::endl << std::endl;

    //BinaryTreeVec
    std::cout << std::endl << "~~~ BinaryTreeVec ~~~" << std::endl << std::endl;

    lasd::Vector<int> vect(4);
    vect[0] = 1;
    vect[1] = 2;
    vect[2] = 3;
    vect[3] = 4;
    lasd::BinaryTreeVec<int> btv(vect);

    checked = btv.Empty();
    corretto = (checked == 0) ? "Correct!" : "Error!";
    std::cout << "Empty (BinaryTreeVec[4]): " << checked << " - " << corretto << std::endl;

    lasd::BinaryTreeVec<int> btvCopy = btv;
    checked = btv.operator==(btvCopy);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "BinaryTreeVec == CopiaBinaryTreeVec: " << checked << " - " << corretto << std::endl;

    std::cout<< "Map BinaryTreeVec: ";
    Map(btv, & MapPrint<int>);
    std::cout << " - Correct!" << std::endl << "Map PreOrder BinaryTreeVec: ";
    PreOrderMap(btv, & MapPrint<int>);
    std::cout << " - Correct!" << std::endl;

    numero = Fold(btv, & FoldAdd<int>, 0);
    corretto = (numero == 10) ? "Correct!" : "Error!";
    std::cout << "Fold (BinaryTreeVec[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;
  
    numero = PreOrderFold(btv, & FoldAdd<int>, 0);
    corretto = (numero == 10) ? "Correct!" : "Error!";
    std::cout << "PreOrderFold (BinaryTreeVec[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = PostOrderFold(btv, & FoldAdd<int>, 0);
    corretto = (numero == 10) ? "Correct!" : "Error!";
    std::cout << "PostOrderFold (BinaryTreeVec[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = InOrderFold(btv, & FoldAdd<int>, 0);
    corretto = (numero == 10) ? "Correct!" : "Error!";
    std::cout << "InOrderFold (BinaryTreeVec[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = BreadthFold(btv, & FoldAdd<int>, 0);
    corretto = (numero == 10) ? "Correct!" : "Error!";
    std::cout << "BreadthFold (BinaryTreeVec[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    btv.Clear();
    checked = btv.Empty();
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Empty (BinaryTreeVec[0]): " << checked << " - " << corretto << std::endl;

    std::cout<< "Map BinaryTreeVec: ";
    Map(btv, & MapPrint<int>);
    std::cout << " - Correct!" << std::endl << "Map PreOrder BinaryTreeVec: ";
    PreOrderMap(btv, & MapPrint<int>);
    std::cout << " - Correct!" << std::endl;

    numero = Fold(btv, & FoldAdd<int>, 0);
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "Fold (BinaryTreeVec[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;
  
    numero = PreOrderFold(btv, & FoldAdd<int>, 0);
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "PreOrderFold (BinaryTreeVec[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = PostOrderFold(btv, & FoldAdd<int>, 0);
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "PostOrderFold (BinaryTreeVec[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = InOrderFold(btv, & FoldAdd<int>, 0);
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "InOrderFold (BinaryTreeVec[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = BreadthFold(btv, & FoldAdd<int>, 0);
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "BreadthFold (BinaryTreeVec[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    btv.Clear();
    

    //BinaryTreeLnk
    std::cout << std::endl << "~~~ BinaryTreeLnk ~~~" << std::endl << std::endl;

    lasd::Vector<int> vector(4);
    vector[0] = 1;
    vector[1] = 2;
    vector[2] = 3;
    vector[3] = 4;
    lasd::BinaryTreeLnk<int> btl(vector);
    checked = btl.Empty();
    corretto = (checked == 0) ? "Correct!" : "Error!";
    std::cout << "Empty (BinaryTreeLnk[4]): " << checked << " - " << corretto << std::endl;

    lasd::BinaryTreeLnk<int> btlCopy = btl;
    checked = btl.operator==(btlCopy);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "BinaryTreeLnk == CopiaBinaryTreeLnk: " << checked << " - " << corretto << std::endl;

    std::cout<< "Map BinaryTreeLnk: ";
    Map(btl, & MapPrint<int>);
    std::cout << " - Correct!" << std::endl << "Map PreOrder BinaryTreeLnk: ";
    PreOrderMap(btl, & MapPrint<int>);
    std::cout << " - Correct!" << std::endl;

    numero = Fold(btl, & FoldAdd<int>, 0);
    corretto = (numero == 10) ? "Correct!" : "Error!";
    std::cout << "Fold (BinaryTreeLnk[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;
  
    numero = PreOrderFold(btl, & FoldAdd<int>, 0);
    corretto = (numero == 10) ? "Correct!" : "Error!";
    std::cout << "PreOrderFold (BinaryTreeLnk[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = PostOrderFold(btl, & FoldAdd<int>, 0);
    corretto = (numero == 10) ? "Correct!" : "Error!";
    std::cout << "PostOrderFold (BinaryTreeLnk[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = InOrderFold(btl, & FoldAdd<int>, 0);
    corretto = (numero == 10) ? "Correct!" : "Error!";
    std::cout << "InOrderFold (BinaryTreeLnk[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = BreadthFold(btl, & FoldAdd<int>, 0);
    corretto = (numero == 10) ? "Correct!" : "Error!";
    std::cout << "BreadthFold (BinaryTreeLnk[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    btl.Clear();
    checked = btl.Empty();
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Empty (BinaryTreeLnk[0]): " << checked << " - " << corretto << std::endl;

    std::cout<< "Map BinaryTreeLnk: ";
    Map(btl, & MapPrint<int>);
    std::cout << " - Correct!" << std::endl << "Map PreOrder BinaryTreeLnk: ";
    PreOrderMap(btl, & MapPrint<int>);
    std::cout << " - Correct!" << std::endl;

    numero = Fold(btl, & FoldAdd<int>, 0);
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "Fold (BinaryTreeLnk[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;
  
    numero = PreOrderFold(btl, & FoldAdd<int>, 0);
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "PreOrderFold (BinaryTreeLnk[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = PostOrderFold(btl, & FoldAdd<int>, 0);
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "PostOrderFold (BinaryTreeLnk[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = InOrderFold(btl, & FoldAdd<int>, 0);
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "InOrderFold (BinaryTreeLnk[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    numero = BreadthFold(btl, & FoldAdd<int>, 0);
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "BreadthFold (BinaryTreeLnk[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    btl.Clear();

    //BinarySearchTree
    std::cout << std::endl << "~~~ BinarySearchTree ~~~" << std::endl << std::endl;

    lasd::BST<int> bst;

    checked = bst.Empty();
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Empty (BinarySearchTree[0]): " << checked << " - " << corretto << std::endl;

    numero = bst.Size();
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "Size (BinarySearchTree[0]): " << numero << " - " << corretto << std::endl;

    numero = InOrderFold(bst, & FoldAdd<int>, 0);
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "InOrderFold (BinaryTreeLnk[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    bst.Insert(4);
    bst.Insert(3);
    bst.Insert(1);
    bst.Insert(2);
    checked = bst.Insert(5);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Inserimento (BinarySearchTree[5]): " << checked << " - " << corretto << std::endl;

    numero = InOrderFold(bst, & FoldAdd<int>, 0);
    corretto = (numero == 15) ? "Correct!" : "Error!";
    std::cout << "InOrderFold (BinaryTreeLnk[4] {1, 2, 3, 4}): " << numero << " - " << corretto << std::endl;

    lasd::BST<int> bst1(bst);
    checked = (bst==bst1);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Confronto con un costruttore specifico della sua copia: " << checked << " - " << corretto << std::endl;

    bst1=bst;
    checked = (bst==bst1);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Confronto con una sua copia: " << checked << " - " << corretto << std::endl;

    numero = bst.MinNRemove();
    corretto = (numero == 1) ? "Correct!" : "Error!";
    std::cout << "MinNRemove (BinarySearchTree[4]): " << numero << " - " << corretto << std::endl;

    numero = bst.MaxNRemove();
    corretto = (numero == 5) ? "Correct!" : "Error!";
    std::cout << "MaxNRemove (BinarySearchTree[3]): " << numero << " - " << corretto << std::endl;

    checked = bst.Empty();
    corretto = (checked == 0) ? "Correct!" : "Error!";
    std::cout << "Empty (BinarySearchTree[3]): " << checked << " - " << corretto << std::endl;

    numero = bst.Size();
    corretto = (numero == 3) ? "Correct!" : "Error!";
    std::cout << "Size (BinarySearchTree[3]): " << numero << " - " << corretto << std::endl;

    std::cout<< "Map InOrder BinarySearchTree: ";
    InOrderMap(bst, & MapPrint<int>);
    std::cout << " - Correct!" << std::endl;

    checked = bst.Exists(3);
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Exist(3) (BinarySearchTree[3] {2, 3, 4}): " << checked << " - " << corretto << std::endl;

    checked = bst.Exists(5);
    corretto = (checked == 0) ? "Correct!" : "Error!";
    std::cout << "Exist(5) (BinarySearchTree[3] {2, 3, 4}): " << checked << " - " << corretto << std::endl;

    numero = bst.PredecessorNRemove(4);
    corretto = (numero == 3) ? "Correct!" : "Error!";
    std::cout << "PredecessorNRemove(4) (BinarySearchTree[2]): " << numero << " - " << corretto << std::endl;

    numero = bst.SuccessorNRemove(0);
    corretto = (numero == 2) ? "Correct!" : "Error!";
    std::cout << "SuccessorNRemove(0) (BinarySearchTree[1]): " << numero << " - " << corretto << std::endl;

    numero = bst.Size();
    corretto = (numero == 1) ? "Correct!" : "Error!";
    std::cout << "Size (BinarySearchTree[1]): " << numero << " - " << corretto << std::endl;

    checked = bst.Empty();
    corretto = (checked == 0) ? "Correct!" : "Error!";
    std::cout << "Empty (BinarySearchTree[1]): " << checked << " - " << corretto << std::endl;

    bst.Clear();
    bst1.Clear();

    numero = bst.Size();
    corretto = (numero == 0) ? "Correct!" : "Error!";
    std::cout << "Size (BinarySearchTree[0]): " << numero << " - " << corretto << std::endl;

    checked = bst.Empty();
    corretto = (checked == 1) ? "Correct!" : "Error!";
    std::cout << "Empty (BinarySearchTree[0]): " << checked << " - " << corretto << std::endl;
    






    std::cout << std::endl << "Fine Personal LASD Test" << std::endl;
}

