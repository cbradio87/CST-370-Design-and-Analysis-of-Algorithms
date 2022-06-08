/*
 * Title: main_hw2_3.cpp
 * Abstract: This program determines if the input 
 * is a palindrome and returns true if it is or 
 * false if it is not.
 * Author: Christopher Bray
 * ID: 8280
 * Date: 3/15/2022
 */

#include <iostream>
#include<string>
using namespace std;

class palinD{
  public:
    bool isPalinDRecur(string str, int start, int end){
      if (start == end){
        return true;
      }
      if (tolower(str[start]) != tolower(str[end])){
        return false;
      }
      if (start < end +1){
        return isPalinDRecur(str,start+1,end-1);
      }
      return true;
    }
    bool isPal(string str){
      int len = str.size();
      if(len==0){
        return false;
      }
      return isPalinDRecur(str, 0, len-1);
      
    }
      
};

int main()
{
  palinD p;
  string str;
  getline(cin, str);
  for (int i = 0; i < str.length(); i++){
  	str[i] = tolower(str[i]);
  }
  for ( int i = 0; i < str.size(); i++){
    if (!isalnum(str[i]) || str[i] == ' '){
      str.erase(i,1);
      i--;
    }
  }
  if(p.isPal(str)){
    cout<<"TRUE";
  }
  else{
    cout << "FALSE";
  }
  return 0;
}

