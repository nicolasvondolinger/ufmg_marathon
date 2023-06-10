#include <iostream>
#include <vector>

using namespace std;

int main(){

  int m, n;

  cin >> m >> n;

  vector<vector <int>> matrix(m, vector<int>(n));

  for(int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      cin >> matrix[i][j]; 
    } 
  }

  vector<int> total;
  int soma = 0;

  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      soma += matrix[i][j];
    }
    total.push_back(soma);
    soma = 0;
  }


  for (int j = 0; j < n; j++){
    for (int i = 0; i < m; i++){
      soma += matrix[i][j];
    }
    total.push_back(soma);
    soma = 0;
  }

  int bigger = total[0];

  for(int i = 1; i < total.size(); i++){
    if(bigger < total[i]){
      bigger = total[i];
    }
  }

  cout << bigger;
  

  return 0;
}