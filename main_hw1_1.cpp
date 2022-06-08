/*
 * Title: main_hw1_1.cpp
 * Abstract: This program asks for the amount of numbers
 * to be entered. Then the program finds the minimum
 * distance between the numbers and displays all the
 * pairs with that distance.
 * Author: Christopher Bray
 * ID: 8280
 * Date: 3/8/2022
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int amount = 0;
    cin >> amount;
    int thisArray[amount];
    for (int i = 0; i < amount; i++) {
      cin >> thisArray[i];
    }
    sort(thisArray, thisArray + amount);
    int minDistance= thisArray[amount];
    vector<int> output1={0};
    vector<int> output2={0};
    output1.clear();
    output2.clear();
    
    for (int i = 0; i < amount-1; i++) {
      int thisDiff = abs(thisArray[i+1] - thisArray[i]);
      if (thisDiff < minDistance){
        minDistance = thisDiff;
        output1.clear();
        output2.clear();
        output1.push_back (thisArray[i]);
        output2.push_back (thisArray[i+1]);
      }
      if (thisDiff == minDistance){
      }
    }  
    
    for (int i = 0; i < amount; i++) {
      int thisDiff = thisArray[i+1] - thisArray[i];
      if(thisDiff == minDistance) {
        output1.push_back (thisArray[i]);
        output2.push_back (thisArray[i+1]);
      }
    }
    
    cout << "Min Distance:" << minDistance << endl;
    for (int i = 1; i < output1.size(); i++) {
      cout << "Pair:" << output1[i] <<" "<< output2[i] 
        << endl;
    } 
    return 0;
}
