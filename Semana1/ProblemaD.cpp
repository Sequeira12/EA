#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {

    std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  list<int> l;
  l.push_back(0);
  list<int>::iterator it = l.begin();
  string op,op2;
  int x;
  int contador = 0;
  int ver = 0;
 
  while (std::cin >> op ) {
    if(std::cin.eof()){
        break;
    }
    if (op == "MOVE"){
       
        cin >> op;
        if(op == "LEFT"){
            if (it != l.begin()) {
                it--;
            }
        }else if(op == "RIGHT"){
            if (it != l.end()) {
                it++;
            }
        }
    
    }else if (op == "INSERT"){
        cin >> op2 >> x;
        if(op2 == "LEFT"){
            l.insert(it, x);
        }
        else if(op2 == "RIGHT"){
        
            it = l.insert(++it, x);
            it--;
    }
    }
  }
 
  for (const int& elem : l) {
    cout << elem << endl;
  }
  return 0;
}