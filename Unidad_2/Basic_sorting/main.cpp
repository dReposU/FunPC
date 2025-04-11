#include "continuousSorting.hpp"
#include <string>
#include <vector>
#include "Persona.hpp"
using namespace std;
// change sorting algorithms to generalized continious containers and boolean
// comparsion pa
//lexicolographical order

int main() {
  srand(time(NULL));
  cout<<"hola"<<endl;
  vector<int> vecSmall(10);
  auto ascending = [](auto a, auto b) -> bool { return a > b; };
  auto descending = [](auto a, auto b) -> bool { return a < b; };
  //auto isEven = [](auto num) -> bool { return num % 2 == 0; };
  //auto imprimir = [](auto num) -> void { cout << num << " "; };
  //auto imprimirInd = [](auto num, auto ind) -> void {
  //  cout << ind << ": " << num << " ";
  //};
  //auto indexEven = [](auto num, auto ind) -> bool { return ind % 2 == 0; };
  // auto descending = [](auto a, auto b) -> bool {
  //   return a > b;
  // };
  cout<<"Eaasaadf "<<endl;
  /*Llenar las estructuras pequeñas (1E2)*/
  ascendinly_fill_container(vecSmall, vecSmall.size(), -999, 999, true);
  
  //recorrer(vecSmall, vecSmall.size(), imprimir, isEven);
  //cout << endl;
  //printCon(vecSmall, vecSmall.size(), isEven);
  //cout << endl;
  //print(vecSmall, vecSmall.size());
  //cout << endl;
  //recorrerInd(vecSmall, vecSmall.size(), imprimirInd);
  //cout << endl;
  //printIndCon(vecSmall, vecSmall.size(), indexEven);
  cout<<"Elementos en orden ascendente: "<<endl;
  print(vecSmall, vecSmall.size());
  cout<<endl;
  cout<<"Permutado: "<<endl;
  permutate(vecSmall, vecSmall.size());
  print(vecSmall, vecSmall.size());
  
  cout << "\n\n--------=============== Ordenamiento básico (1E2) ===============----------"<<endl<<endl;
  cout << "-------- Continuous ----------"<<endl;
  testSortAlg(exchangeSort, vecSmall, vecSmall.size(), ascending);
  testSortAlg(exchangeSort2, vecSmall, vecSmall.size(), ascending);
  testSortAlg(exchangeSort3, vecSmall, vecSmall.size(), ascending);
  testSortAlg(exchangeSort4, vecSmall, vecSmall.size(), ascending);
  testSortAlg(bubbleSort, vecSmall, vecSmall.size(), ascending);
  testSortAlg(bubbleSort2, vecSmall, vecSmall.size(), ascending);
  testSortAlg(bubbleSort_flagged, vecSmall, vecSmall.size(), ascending);
  testSortAlg(selectionSort, vecSmall, vecSmall.size(), ascending);
  testSortAlg(insertionSort, vecSmall, vecSmall.size(), ascending);  
  testSortAlg(shellSort, vecSmall, vecSmall.size(), ascending);
  cin.get();

  //--------------------------------------------------------------
  cout << "\n\n--------=============== Ordenamiento avanzado (1E6) ===============---------- " << endl;
  vector<int> largeVec(1000000);

  /* ascendinly_fill_container(largeVec, largeVec.size(), -1000000, 1000000, false);
  permutate(largeVec, largeVec.size()); */

  
  
  cout << "Continuo: ";
  //printRange(largeVec, largeVec.size(), 0, 10); cout<<endl;
  mergeSort(largeVec, 0, largeVec.size(), [](auto a, auto b) -> bool { return a <= b; });
  //printRange(largeVec, largeVec.size(), 0, 10); cout<<endl;
  cout << isOrdered(largeVec, largeVec.size(), ascending) << " ";
  heapSort(largeVec, largeVec.size(), descending);
  //printRange(largeVec, largeVec.size(), 0, 10); cout<<endl;
  cout << isOrdered(largeVec, largeVec.size(), descending) << " "<<endl; 
  cout << "Singly: "<<endl;
  auto compareDinero = [](Persona *a, Persona *b) -> bool {
    return a->getDinero() <= b->getDinero();
  };
  auto compareDineroAscending = [](Persona *a, Persona *b) -> bool {
    return a->getDinero() > b->getDinero();
  };

  
  auto compareCreditos = [](Persona *a, Persona *b) -> bool {
      return a->getCreditos() >= b->getCreditos();
  };

  auto compareCreditosDescending = [](Persona *a, Persona *b) -> bool {
      return a->getCreditos() < b->getCreditos();
  };

  /* auto compareMonedas = [](Persona *a, Persona *b) -> bool {
      return a->getMonedas() > b->getMonedas();
  }; */

  auto compareMonedasAscending = [](Persona *a, Persona *b) -> bool {
      return a->getMonedas() > b->getMonedas();
  };

  
  auto compareBilletes = [](Persona *a, Persona *b) -> bool {
      return a->getBilletes() < b->getBilletes();
  };

  auto compareBilletesDescending = [](Persona *a, Persona *b) -> bool {
      return a->getBilletes() < b->getBilletes();
  };

  
  /* auto comparePapeles = [](Persona *a, Persona *b) -> bool {
      return a->getPapeles() <= b->getPapeles();
  };

  auto comparePapelesAscending = [](Persona *a, Persona *b) -> bool {
      return a->getPapeles() > b->getPapeles();
  }; 
 */
  
  /* auto printPersonaAttributes = [](Nodo<Persona*> * person, size_t i) -> void
  { cout <<i<< ": " << person->valor->getNombre() << "  " <<
  person->valor->getDinero() << endl;
  };
 */
  /*
  std::list<int> miLista = {1, 2, 3, 4, 5};

  // Obtener un puntero al primer elemento (cabeza)
  int* ptrCabeza = &miLista.front();

  // Obtener un puntero al último elemento (cola)
  int* ptrCola = &miLista.back();
  */
  /*
  int size = rand() % 4 + 20;
  int *arr = genIncreasingV(size, true);
  vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print(vec, vec.size());
  cout << "\n";
  cout << "Arreglo original: ";
  print(arr, size);
  cout << "\n";
  permutate(arr, size);
  cout << "Arreglo permutado: ";
  print(arr, size);
  cout << "\n \n";

  // sorting algorithms
  exchangeSort(arr, size, true);
  cout << "exchangeSort: ";
  print(arr, size);
  cout << "\t" << isOrdered(arr, size, true) << "\n \n";

  // can i reduce this code? with some function parameter (not lambdas)
  permutate(arr, size);
  print(arr, size);
  cout<<"\n";
  exchangeSort2(arr, size, true);
  cout << "exchangeSort2: ";
  print(arr, size);
  cout << "\t" << isOrdered(arr, size, true) << "\n \n";

  permutate(arr, size);
  print(arr, size);
  cout<<"\n";
  exchangeSort3(arr, size, true);
  cout << "exchangeSort3: ";
  print(arr, size);
  cout << "\t" << isOrdered(arr, size, true) << "\n \n";

  permutate(arr, size);
  print(arr, size);
  cout<<"\n";
  exchangeSort4(arr, size, true);
  cout << "exchangeSort4: ";
  print(arr, size);
  cout << "\t" << isOrdered(arr, size, true) << "\n \n";

  permutate(arr, size);
  print(arr, size);
  cout<<"\n";
  bubbleSort(arr, size, true);
  cout << "bubbleSort: ";
  print(arr, size);
  cout << "\t" << isOrdered(arr, size, true) << "\n \n";
  */

  return 0;
}