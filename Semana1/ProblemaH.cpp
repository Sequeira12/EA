
#include <iostream>
#include <list>
#include <string>
#include <map>


using namespace std;


int main() {
    string op;
   
    map<int,int> inventario;

    int valor;
    int quantidade,identi;
    while(cin >> op){
        if(op == "ADD"){
            cin >> quantidade >> identi;
          
            inventario[identi] += quantidade;
          
        }else if(op == "REM"){
            cin >> quantidade >> identi;
          
              if(inventario[identi] >= quantidade){
             
                inventario[identi]-=quantidade;
              
            }else{
                cout << "remove refused" << endl;
            }    
        }else if(op == "QUERY"){
            cin >> identi ;
         
            cout << inventario[identi]<< endl ;
          
          
        }
    }
   
}


