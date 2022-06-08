/*
 * Title: main_hw3_1.cpp
 * Abstract: This program put a set of 
 * numbers in prder and abbreviates any 
 * numbers that are in sequence.
 * Author: Christopher Bray
 * ID: 8280
 * Date: 3/22/2022
 */

#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int main()
{  
  int collected;
  cin >> collected;
  vector<int> thisArray;
  int inpInt;
  for (int i = 0; i < collected; i++){
    cin >> inpInt;
    thisArray.push_back(inpInt);
  }
  sort (thisArray.begin(), thisArray.end());
  thisArray.erase( unique( thisArray.begin(), thisArray.end() ), thisArray.end() );
  for (int i = 0; i < thisArray.size(); i++){
    if (i == 0){
      cout << thisArray[i];
      i++;
    }
    if(thisArray[i-1] != thisArray[i]-1){
      cout << " "<< thisArray[i];
    }
    if (thisArray[i-1] == thisArray[i]-1 && thisArray[i]+1 != thisArray[i+1]){
      cout << "-" << thisArray[i];
    }
  }
  cout << endl;

  return 0;
}

