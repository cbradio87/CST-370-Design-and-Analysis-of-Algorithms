/*
 * Title: main_hw2_2.cpp
 * Abstract: This program displays all the 
 * possible combinations of however many entries 
 * you desire. They can be not displayed or 
 * displayed.
 * Author: Christopher Bray
 * ID: 8280
 * Date: 3/15/2022
 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void decToBin(int decNum, int bigNum[]){
    int i = 0;
    while(decNum > 0) {
      bigNum[i] = decNum % 2;
      i++;
      decNum = decNum / 2;
    }
}

int main(){
  int numby, numDecim, i, j, k, count, bigNum[10];
  string entered[10];
  cin >> numby;
  for(i = 0; i < numby; i++){
      cin >> entered[i];
  }
  numDecim = pow(2, numby);
  for(i = 0; i < numDecim; i++){
    cout << i << ":";
    for(j = 0; j < numby; j++){
      bigNum[j] = 0;
    }
    decToBin(i, bigNum);
    for(j = numby - 1; j >= 0; j--){
      cout << bigNum[j];
    }
    cout << ":";
    k = 0;
    count = 0;
    for(j = numby - 1; j >= 0; j--){
      if(bigNum[j] == 1){
        cout << entered[k];
        if(bigNum[j-1]==1){
          cout << " ";
        }
        else if(bigNum[j-2] == 1){
          cout << " ";
        }
        else if(bigNum[j-3] == 1){
          cout << " ";
        }
        count++;
      }
      
      k++;
    }
    if(count == 0){
      cout << "EMPTY";
    }
    cout << endl;
  }
  return 0;
}
