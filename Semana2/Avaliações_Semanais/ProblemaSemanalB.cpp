#include <iostream>
using namespace std;
int main(){
    int n_cavalos;
    cin >> n_cavalos;
    cout << n_cavalos << endl;
    for(int i = 0; i < n_cavalos; i++){
        int pos1,pos2,move;
        cin >> pos1 >> pos2 >> move;
        cout << pos1 << " "<< pos2 << " "<< move << endl;
    }
    return 0;
}