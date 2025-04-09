#include <iostream>
using namespace std;

void print(int n) {
  if (n > 0) {
    print(n - 1);
    cout << n;
  }
}

void triag(int n) {
  if (n > 0) {
    triag(n - 1);
    print(n);
    cout << '\n';
  }
}

int main() 
{
  int n;
  for(;;) {
    cin >> n;
    if (n == 0) break;
    triag(n);
    cout << "--------------\n";
  }
  return 0;
}