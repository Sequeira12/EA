#include <iostream>
#include <vector>
#include <algorithm>

int main() {
 
  std::vector<int> vec;
  int num;
  while (std::cin >> num) {
   vec.push_back(num);
   if (std::cin.eof()) {
      break;
    }
  }
  std::sort(vec.begin(),vec.end());

  for(int numero : vec){
    std::cout << numero <<std::endl;
  }

  return 0;
}


