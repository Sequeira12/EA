#include <iostream>
#include <unordered_set>


using namespace std;

unordered_set<int> P;
int chessGame(int x,int y, int m);
int main(){
    int valorFinal = 0;
    int n_cavalos;
    cin >> n_cavalos;
    
    for(int i = 0; i < n_cavalos; i++){
        int pos1,pos2,move;
        cin >> pos1 >> pos2 >> move;
        pos1+=200;
        pos2+=200;
        valorFinal += chessGame(pos1,pos2,move);
    }
    cout << valorFinal << endl;
    return 0;
}


int chessGame(int x,int y, int m){
    
    int z = (x + y)*(x + y + 1)/2 + y;
    //cout << z << endl;
    if(m == 0){
        if(P.count(z)>0){
            return 0;
        }else{
            P.insert(z);
            return 1;
        }
    }else{
        int v = 0;
        if(P.count(z)==0){
         
            P.insert(z);
            v = 1;
        }
            return (v + chessGame(x+2,y+1,m-1) + 
        chessGame(x+2,y-1,m-1) + chessGame(x-2,y+1,m-1) + chessGame(x-2,y-1,m-1)+
        chessGame(x-1,y+2,m-1) + chessGame(x-1,y-2,m-1) +chessGame(x+1,y+2,m-1)+chessGame(x+1,y-2,m-1) );
        
    }
}