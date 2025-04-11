#pragma once
#include <functional>
#include <iostream>
#include <list>

using namespace std;
/*
foo(function sortAlg, T &container){
  getsize(container); // overloads
  sortAlt; //calling
}
*/
// Utility -----------------------------------------------------
template <class T, class K> void recorrer(T container, size_t size, K acción);
template <class T, class K, class M>
void recorrer(T container, size_t size, K acción, M condición);
template <class T> void print(T container, size_t size);
template <class T, class K>
void printCon(T container, size_t size, K condición);
// print only odd index with its index
template <class T, class K>
void recorrerInd(T container, size_t size, K acción);
template <class T, class K, class M>
void recorrerInd(T container, size_t size, K acción, M condición);
template <class T> void printInd(T container, size_t size);
template <class T, class K>
void printIndCon(T container, size_t size, K condición);
template <class T>
void printRange(T container, size_t size, size_t min, size_t max);
template <class T> void swapT(T &a, T &b);
template <class T>
void permutate(T &container, size_t size); // Fisher-Yates shuffle
template <class T> void invert(T &container, size_t size);
template <class T, class K> bool isOrdered(T container, size_t size, K compare);
//Binary Search
template <typename T, typename K>
int binarySearch(T &container, K toSearch, int max, int min);
template <typename T, typename K>
int binarySearch(T &container, K toSearch);

template <typename T, typename K>
std::list<int> findAllOccurrences(T &container, K toSearch);
//----------
template <class T, class K>
void ascendinly_fill_container(T &container, size_t size, K absoluteMin,
                               K absoluteMax, bool not_duplicated_values);
// Sorting -----------------------------------------------------
template <class T, class K>
void exchangeSort(T &container, size_t size, K compare);
template <class T, class K>
void exchangeSort2(T &container, size_t size, K compare);
template <class T, class K>
void exchangeSort3(T &container, size_t size, K compare);
template <class T, class K>
void exchangeSort4(T &container, size_t size, K compare);
template <class T, class K>
void bubbleSort(T &container, size_t size, K compare);
template <class T, class K>
void bubbleSort2(T &container, size_t size, K compare);
template <class T, class K>
void bubbleSort_flagged(T &container, size_t size, K compare);
template <class T, class K>
void selectionSort(T &container, size_t size, K compare);
template <class T, class K>
void insertionSort(T &container, size_t size, K compare);
template <class T, class K>
void shellSort(T &container, size_t size, K compare);
template<class T, class K>
void testSortAlg(void(*sortAlg)(T &container, size_t size, K compare), T& container, size_t size, K compare);
//advance sorting
/* template <class T, class M>
void heapify(T &container, size_t size, size_t i, M compare);
template <class T, class M>
void heapSort(T &container, size_t size, M compare); */
//---------------------------------------------------------------------------

    template <class T, class K>
    void recorrer(T container, size_t size, K acción) {
  for (size_t i = 0; i < size; i++)
    acción(container[i]);
}
template <class T, class K, class M>
void recorrer(T container, size_t size, K acción, M condición) {
  for (size_t i = 0; i < size; i++)
    if (condición(container[i]))
      acción(container[i]);
}
template <class T> void print(T container, size_t size) {
  auto imprimir = [](auto num) -> void { cout << num << " "; };
  recorrer(container, size, imprimir);
}

template <class T, class K>
void printCon(T container, size_t size, K condición) {
  auto imprimir = [](auto num) -> void { cout << num << " "; };
  recorrer(container, size, imprimir, condición);
}
template <class T> void swapT(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}
template <class T, class K>
void recorrerInd(T container, size_t size, K acción) {
  for (size_t i = 0; i < size; i++)
    acción(container[i], i);
}

template <class T, class K, class M>
void recorrerInd(T container, size_t size, K acción, M condición) {
  for (size_t i = 0; i < size; i++)
    if (condición(container[i], i))
      acción(container[i], i);
}

template <class T> void printInd(T container, size_t size) {
  auto imprimir = [](auto num, size_t i) -> void {
    cout << i << ": " << num << " ";
  };
  recorrerInd(container, size, imprimir);
}

template <class T, class K>
void printIndCon(T container, size_t size, K condición) {
  auto imprimir = [](auto num, size_t i) -> void {
    cout << i << ": " << num << " ";
  };
  recorrerInd(container, size, imprimir, condición);
}

template <class T>
void printRange(T container, size_t size, size_t min, size_t max){
  if(min>max)return;
  if(max>=size)return;
  if(min<0)return;
  if(min == 0 && max == size-1)
    return print(container, size);
  //faltan otras guard clauses

  size_t i = 0;
  while(i<min)
    i++;
      
  for(; i <= max; i++){
    cout<<container[i]<<" ";
  }
}
template <class T> void permutate(T &container, size_t size) {
  size_t randIndex;
  for (size_t i = size - 1; i > 0; i--) {
    randIndex = rand() % i; //[0; i) there is a change always. If u want [0; i]
                            // use rand() % (i + 1).
    swapT(container[i], container[randIndex]);
  }
}
template <class T> void invert(T &container, size_t size) {
  size_t aux = size / 2;
  for (size_t i = 0; i < aux; i++)
    swapT(container[i], container[size - i - 1]);
}
template <class T, class K>
bool isOrdered(T container, size_t size, K compare) {
  if (size < 2)
    return true;

  for (size_t i = 0; i < size - 1; i++) {
    if (compare(container[i], container[i + 1]))
      return false;
  }
  return true;
}

template <typename T, typename K>
int binarySearch(T &container, K toSearch, int max, int min) {
    if (max >= min) {
        int mid = min + (max - min) / 2;
        if (container[mid] == toSearch)
            return mid;
        if (container[mid] < toSearch)
            return binarySearch(container, toSearch, max, mid + 1);
        return binarySearch(container, toSearch, mid - 1, min);
    }
    return -1;
}

template <typename T, typename K>
int binarySearch(T &container, K toSearch) {
    return binarySearch(container, toSearch, container.size() - 1, 0);
}

template <typename T, typename K>
std::list<int> findAllOccurrences(T &container, K toSearch) {
    std::list<int> indices;
    int initialIndex = binarySearch(container, toSearch);

    if (initialIndex == -1) {
        return indices; // No se encontró el elemento
    }

    // Buscar hacia la izquierda
    int leftIndex = initialIndex;
    while (leftIndex >= 0 && container[leftIndex] == toSearch) {
        indices.push_front(leftIndex);
        leftIndex--;
    }

    // Buscar hacia la derecha
    int rightIndex = initialIndex + 1;
    while (rightIndex < container.size() && container[rightIndex] == toSearch) {
        indices.push_back(rightIndex);
        rightIndex++;
    }

    return indices;
}

// fill with only intiger numbers
// there is imposible to have absoluteMax duplicated values
template <class T, class K>
void ascendinly_fill_container(T &container, size_t size, K absoluteMin,
                               K absoluteMax, bool not_duplicated_values) {
  K elem, local_interval_min = absoluteMin, module = absoluteMax - absoluteMin;
  long double intervalDivision, local_interval_max;

  if (absoluteMin > absoluteMax)
    return;

  if (absoluteMin == absoluteMax && not_duplicated_values)
    return;

  if (absoluteMin == absoluteMax &&
      !not_duplicated_values) // same as vector<T> container(size, value)
  {
    for (size_t i = 0; i < size; i++)
      container[i] = absoluteMin;
  }

  if (module < size && not_duplicated_values)
    return;

  if (not_duplicated_values)
    intervalDivision = static_cast<long double>(module) / size;
  else
    intervalDivision = static_cast<long double>(module) / (rand() % size + 1);

  local_interval_max = absoluteMin + intervalDivision;

  for (size_t i = 0; i < size; i++) {
    if (local_interval_min > absoluteMax)
      local_interval_min = absoluteMax;

    if (local_interval_max > absoluteMax)
      local_interval_max = absoluteMax;

    elem =
        rand() % static_cast<K>(local_interval_max - local_interval_min + 1) +
        local_interval_min;

    // std::cout << i + 1 << "\tRange: " << local_interval_min << " - (int)"
    //           << local_interval_max << "\telem = " << elem << "\n"; // Range
    //           //of number for each iteration
    container[i] = local_interval_min = elem; // element == new local minimun
    local_interval_max += intervalDivision;

    if (not_duplicated_values)
      local_interval_min++;
  }
  // std::cout << intervalDivision << "\n";
}

// interval, size, intervalDivision
/*
0-10, 3, (10-0)/3 == 3.3333.....
-10-0, 3, (0 - (-10))/3 == 3.3333....
1-11, (11-1)/3 == 3.3333.....
-9-1, 3, (1 - (-9))/3 == 3.333....
-5-5, 3, (5 - (-5))/3 == 3.3333....
-20-(-10), 3, ((-10) - (-20))/3 == 3.3333.....

if(absoluteMin>absoluteMax)return; (should throw an error)
*/

// Sorting algorithms definition ----------------------------------------------
template <class T, class K>
void exchangeSort(T &container, size_t size, K compare) {
  for (size_t i = 0; i < size - 1; i++) {
    for (size_t j = i + 1; j < size; j++) {
      if (compare(container[i], container[j]))
        swapT(container[i], container[j]);
    }
  }
}

template <class T, class K>
void exchangeSort2(T &container, size_t size, K compare) {
  for (int i = size - 1; i > 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      if (compare(container[j], container[i]))
        swapT(container[i], container[j]);
    }
  }
}

template <class T, class K>
void exchangeSort3(T &container, size_t size, K compare) {
  for (size_t i = 0; i < size - 1; i++) {
    for (size_t j = size - 1; j > i; j--) {
      if (compare(container[i], container[j]))
        swapT(container[i], container[j]);
    }
  }
}

template <class T, class K>
void exchangeSort4(T &container, size_t size, K compare) {
  for (size_t i = size - 1; i > 0; i--) {
    for (size_t j = 0; j < i; j++) {
      if (compare(container[j], container[i]))
        swapT(container[i], container[j]);
    }
  }
}
template <class T, class K>
void bubbleSort(T &container, size_t size, K compare) {
  for (size_t i = 0; i < size - 1; i++) {
    for (size_t j = 1; j < size - i; j++) {
      if (compare(container[j - 1], container[j]))
        swapT(container[j - 1], container[j]);
    }
  }
}
template <class T, class K>
void bubbleSort2(T &container, size_t size, K compare) {
  for (size_t i = 1; i < size; i++) {
    for (size_t j = size - 1; j >= i; j--) {
      if (compare(container[j - 1], container[j]))
        swapT(container[j - 1], container[j]);
    }
  }
}

template <class T, class K>
void bubbleSort_flagged(T &container, size_t size, K compare) {
  bool ordenado;
  for (size_t i = 0; i < size - 1; i++) {
    ordenado = true;
    for (size_t j = 0; j < size - (i + 1); j++) {
      if (compare(container[j], container[j + 1])) {
        swapT(container[j], container[j + 1]);
        ordenado = false;
      }
    }
    if (ordenado)
      break;
  }
}

template <class T, class K>
void selectionSort(T &container, size_t size, K compare) {
  size_t auxInd;
  auto aux = container[0];
  for (size_t i = 0; i < size - 1; i++) {
    auxInd = i;
    aux = container[i]; // less operations in compare
    for (size_t j = i + 1; j < size; j++) {
      if (compare(aux, container[j])) {
        auxInd = j;
        aux = container[j];
      }
    }
    container[auxInd] = container[i];
    container[i] = aux;
  }
}
template <class T, class K>
void insertionSort(T &container, size_t size, K compare) {
  long long int i;
  auto key = container[0];
  for (size_t j = 1; j < size; j++) {
    key = container[j];
    i = j - 1;
    while (i >= 0 && compare(container[i], key)) {
      container[i + 1] = container[i];
      i--;
    }
    container[i + 1] = key;
  }
}

template <class T, class K>
void shellSort(T &container, size_t size, K compare) {
  auto tmp = container[0];
  for (size_t gap = size / 2; gap > 0; gap /= 2) {
    for (size_t i = gap; i < size; i++) {
      tmp = container[i];
      size_t j = i;
      for (; j >= gap && compare(container[j - gap], tmp);
           j -= gap){
             container[j] = container[j - gap];
           }
      container[j] = tmp;
    }
  }
}

template<class T, class K>
void testSortAlg(void(*sortAlg)(T &container, size_t size, K compare), T& container, size_t size, K compare){
  permutate(container, size);
  sortAlg(container, size, compare);
  cout << isOrdered(container, size, compare) << " ";
}
//comparisons must be done with <= and >=
//only works for vector rn
//declaration problems
template <class T, class M>
void merge(T &A, size_t min, size_t mid, size_t max, M compare)
{
    size_t i = 0, j = 0, k = min;

    T L(A.begin() + min, A.begin() + mid);
    T R(A.begin() + mid, A.begin() + max);
    //size_t Lsize = mid - min, Rsize = max - mid;
    while (i < L.size() && j < R.size())
    {
        if (compare(L[i], R[j]))
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < L.size())
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < R.size())
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
template <class T, class M>
void mergeSort(T &A, size_t min = 0, size_t max = 0, M compare = [](auto a, auto b) -> bool { return a <= b; })
{
    if (max == 0)
        max = A.size();
    if (max - min > 1)
    {
        size_t mid = (min + max) / 2;
        mergeSort(A, min, mid, compare);
        mergeSort(A, mid, max, compare);
        merge(A, min, mid, max, compare);
    }
}

template <class T, class M>
void heapify(T &container, size_t size, size_t i, M compare)
{
    size_t max = i;
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;
    if (l < size && compare(container[l], container[max]))
        max = l;
    if (r < size && compare(container[r], container[max]))
        max = r;
    if (max != i)
    {
        swapT(container[i], container[max]);
        heapify(container, size, max, compare);
    }
}
template <class T, class M>
void heapSort(T &container, size_t size = 0, M compare = [](auto a, auto b) -> bool
              { return a > b; })
{
    long long int i = (size / 2) - 1;
    for (; i >= 0; i--)
    {
        heapify(container, size, i, compare);
    }

    for (size_t i = 0; i < size - 1; i++)
    {
        swapT(container[0], container[size - i - 1]);
        heapify(container, size - i - 1, 0, compare);
    }
}