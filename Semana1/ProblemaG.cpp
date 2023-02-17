
#include <iostream>
#include <list>
#include <string>
#include <set>


using namespace std;


int main() {
    string op;
   
    multiset<int> shoes;

    int tempoC, tempoN;
    int ContadorT = 0;
  
    int valor;
    while(cin >> op >> valor){
       
        if(op == "ADD"){
            shoes.insert(valor);
        }else if(op == "REQUEST"){
            
             auto it = shoes.lower_bound(valor);
            if (it == shoes.end()) {
                cout << "impossible" << endl;
            } else {
                cout << *it << endl;
                shoes.erase(it);
            }
            
        }   
    
    }
    
    
  
   
 
}


