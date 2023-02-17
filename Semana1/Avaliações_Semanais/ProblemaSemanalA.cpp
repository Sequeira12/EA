#include <iostream>
#include <set>
using namespace std;

#include <algorithm>
int main() {
    int numeroConv;
   
    while(cin >> numeroConv){
        set<int> negativos;
        set<int> positivos;
        int array[numeroConv];
        int nConvi;
        int n = sizeof(array) / sizeof(array[0]);
        int contaF = 0;
        for(int i = 0; i < numeroConv; i++){
            cin >> nConvi;
            if(nConvi > 0){
                positivos.insert(nConvi);
            }else{
                negativos.insert(nConvi);
            }
            array[i] = nConvi;
        }

        cin >> nConvi;
      
        int contador = 0;
        for(int i = 0; i < numeroConv; i++){
            for(int j = i+1; j < numeroConv;j++){

                if(array[i]>0 && array[j] > 0){
                    int valor = array[i] + array[j];
                    int valorIn = -valor;
                    int ret = 0;
                    ret = negativos.count(valorIn);
                      if(ret>0){
                        contador++;
                        break;
                    }
                }

                  if(array[i]<0 && array[j] < 0){
                    int valor = array[i] + array[j];
                   
                    int valorIn = -valor;
                    int ret = 0;
                    ret = positivos.count(valorIn);
                    if(ret>0){
                        contador++;
                        break;
                    }
                }
                

            }
            if(contador != 0){
                break;
            }
        }
        if(contador != 0){
            cout << "Fair" << endl;
        }else{
            cout << "Rigged" << endl;
        }

        
        
        
       
    
       
    }
    return 0;
}