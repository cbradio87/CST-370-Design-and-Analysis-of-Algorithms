/*
 * Title: main_hw1_2.cpp
 * Abstract: This program collect an index of
 * how many number are to be entered, then takes
 * the numbers entered by the user. It then returns
 * The numbers of highest frequency and what that 
 * frequency is.
 * Author: Christopher Bray
 * ID: 8280
 * Date: 3/8/2022
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int totNum;
    cin >> totNum;
    int thisArray[totNum];
    for(int i = 0; i < totNum; i++)
    {
        cin >> thisArray[i];
    }
    sort(thisArray, thisArray + totNum, greater<int>());
    int freq = 1;
    vector<int> output={0};
    output.clear();
    int talley = 1;
    for(int i = 0; i < totNum; i++){
      if(thisArray[i]==thisArray[i+1]){
        talley++;
      }
      if((thisArray[i] != thisArray[i+1]) && (freq < talley)){
        freq = talley;
        output.clear();
        output.push_back (thisArray[i]);
      }
      if((thisArray[i] != thisArray[i+1]) && freq == talley ){
      output.push_back (thisArray[i]);
      }
      if(thisArray[i] != thisArray[i+1]){
      talley = 1;
      }
    }
    
    cout << "Frequency:"<< freq << endl;
    cout << "Number:";
    for(int i = 1; i < output.size(); i++){
      cout << output[i];
      if (i == output.size()-1){
        cout << endl;
      }
      else
        cout << " ";
      }
    return 0;
}
