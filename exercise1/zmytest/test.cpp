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



    std::cout << std::endl << "Fine Personal LASD Test" << std::endl;
}

