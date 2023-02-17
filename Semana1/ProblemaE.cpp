
#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

int main() {
    string op;
    int numero;
    string op1 = "+";
    string op2 = "-";
    cin >> numero;
    int array[numero];
    stack<int> pilha;

    int num1,num2;
    
    for(int i = 0; i <= numero; i++){
        std::string expression;
        std::getline(std::cin, expression);
       

        std::istringstream ss(expression);
        while(ss >> op){
            
            if(op.compare(op1) == 0 || op.compare(op2) == 0){
                num1 = pilha.top();
                pilha.pop();
                num2 = pilha.top();
                pilha.pop();
                int conta;
            if(op.compare(op1) == 0){
                conta = num2 + num1;
            }else{
                conta = num2 - num1;
            }
            
            pilha.push(conta);
        }else{
           
            pilha.push(stoi(op));
            }
        }
        while(!pilha.empty()){
            cout << pilha.top() <<endl;
            pilha.pop();
        }

       
       
    }   
 
}


