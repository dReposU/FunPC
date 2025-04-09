#include <iostream>
using namespace std;

void readarr(int* A, int N) {
  if (N > 0) {
    cin >> *A;
    readarr(++A, N - 1);
  }
}

void print(int* A, int N) {
  if (N > 0) {
    cout << *A << ' ';
    print(++A, N - 1);
  }
}

int main() 
{
  int T, N;
  int A[100];
  cin >> T;
  for(int k = 0; k < T; ++k) {
    cin >> N;
    readarr(A, N);
    cout << "Case " << k << ":\n";
    print(A, N);
    cout << '\n';
  }
  return 0;
}

/*
2
5
8 6 3 3 4
10
10 20 30 40 50 60 70 80 90 100
*/