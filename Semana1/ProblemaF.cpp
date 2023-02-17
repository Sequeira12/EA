
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <sstream>

using namespace std;
struct tasks{
    int chegada;
    int tempo;
};

int main() {
    string op;
    int numero;
    string op1 = "+";
    string op2 = "-";
    cin >> numero;
   
    queue<tasks> pilha;
    int tempoC, tempoN;
    int ContadorT = 0;
    for(int i = 0; i < numero; i++){
        cin >> tempoC >> tempoN;
     
        if(ContadorT < tempoC){
            ContadorT = ContadorT + tempoC - ContadorT;
        }
        ContadorT += tempoN;
        
    }
    cout << ContadorT << endl;
    
    
   
 
}


