#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

long long int removeZeros(long long int number){
  if(number%10 != 0){
    return number;
  }else{
    return removeZeros(number/10);
  }
}

int firstNumber(long long int number){
  return number % 10;
}

long long int removeFrontNumbers(long long int number){
  return number % 100000000000LL;
}

int main (){

  int number, instance = 1, allInputsAnswers[1000001];

  long long int fatorial;

  long long int result = 1;
  
  for(int i = 1; i<=1000000; i++){
    result *= i;
    result = removeZeros(result); 
    result = removeFrontNumbers(result);
    allInputsAnswers[i] = firstNumber(result);
  }

  while (cin >> number){
    cout << "Instancia "<< instance << endl << allInputsAnswers[number] << endl << endl;
    instance++;
  }

  return 0;
}