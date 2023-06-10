            #include <iostream>
            #include <vector>
            #include <map>
            #include <string>
            #include <cmath>
             
            using namespace std;
             
            bool definePerfect(int number){
                int n, newNumber = number;
                for(int i = 1; i<to_string(number).size(); i++){
                    n = newNumber % 10;
                    if( n != 0) return false;
                    newNumber /= 10;
                }
                return true;
            }
             
            int arredondamento_UP(int number){
                int n = number, count = 0;
                if(n > 0){
                    while (n >= 10) {
                        n /= 10;
                        count ++;
                    }
                    n++;
                } else {
                    while (n <= -10) {
                        n /= 10;
                        count ++;
                    }
                    n--;
                }
                n = n * pow(10, count); 
                return n;
            }
            
            int arredondamento_DOWN(int number){
                int n = number, count = 0;
                if(n > 0){
                    while (n >= 10) {
                        n /= 10;
                        count ++;
                    }
                } else {
                    while (n <= -10) {
                        n /= 10;
                        count ++;
                    }
                }
                n = n * pow(10, count); 
                return n;
            }
             
            void printEquation(int perfect, int nonPerfect, int arredondado){
                if(arredondado > 0)cout << arredondado << " x " << perfect << " - " << arredondado - nonPerfect << " x " << perfect << endl;
                else cout << arredondado << " x " << perfect << " + " << nonPerfect - arredondado << " x " << perfect << endl;
            }
            
            void printEquation_(int perfect, int nonPerfect, int arredondado){
                if(arredondado > 0)cout << arredondado << " x " << perfect << " - " << nonPerfect - arredondado << " x " << perfect << endl;
                else cout << arredondado << " x " << perfect << " - " << arredondado - nonPerfect << " x " << perfect << endl;
            }
             
            int main(){
             
                int input, numberOne, numberTwo, perfect, nonPerfect;
                cin >> input;
                for(int i = 0; i < input; i++){
                    cin >> numberOne >> numberTwo;
                    if(definePerfect(numberOne)){
                        perfect = numberOne;
                        nonPerfect = numberTwo;
                    } else{
                        perfect = numberTwo;
                        nonPerfect = numberOne;
                    }
                    int arredondado = arredondamento_UP(nonPerfect);
                    if(definePerfect(arredondado - nonPerfect)){
                        printEquation(perfect, nonPerfect, arredondado);
                    } else {
                        arredondado = arredondamento_DOWN(nonPerfect);
                        printEquation_(perfect, nonPerfect, arredondado);
                    }
                }
                
                return 0;
            }