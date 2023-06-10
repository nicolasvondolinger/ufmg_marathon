#include <iostream>

using namespace std;

int fatorial(int number){
  if(number == 1 || number == 0){
    return 1;
  } else{
    return number * fatorial(number - 1);
  }
}

int main(){

  int number;

  cin >> number;

  cout << fatorial(number) << endl;

  return 0;
}