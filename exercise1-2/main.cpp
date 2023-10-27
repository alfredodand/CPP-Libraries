
#include "zmytest/test.hpp"

#include "zlasdtest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  unsigned short index = 3;  
  
  while(index != 0){
    std::cout << std::endl << std::endl << "Inserire 0 per uscire, 1 per avviare il Simple Test, 2 per avviare il Personal Test"<< std::endl << std::endl <<
      "0) Esci" << std::endl << "1) Simple Test" << std::endl << "2) Personal Test" << std::endl;
    std::cout << "Numero da inserire: ";
    std::cin >> index;
    std::cout << std::endl << std::endl;

    while(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore();
      std::cout << "Input non valido. Inserisci un numero: ";
      std::cin >> index;
      std::cout << std::endl << std::endl;
    }

    switch (index){
      case 0:
        return 0;
      break;
      case 1:
        std::cout << "Lasd Libraries 2023" << std::endl;
        lasdtest(); // Call in the menu of your library test!
      break;
      case 2:
        std::cout << "Personal Lasd Libraries 2023" << std::endl;
        personalLasdTest();
      break;
      
      default:
        std::cout << "Inserire un numero valido";
      break;
    }
  }
}
