#include <iostream>
#include <array>
int main() {
  int numero;
  std::cin >> numero;
  int array[numero];
  for(int i = 0; i < numero; i++){
    std::cin >> array[i];
  }
  for(int i = numero-1;i >= 0;i--){
    if(i!=0){
        std::cout << array[i] << " ";
    }else{
        std::cout << array[i];
    }    
  }
  std::cout << std::endl;
  return 0;


}