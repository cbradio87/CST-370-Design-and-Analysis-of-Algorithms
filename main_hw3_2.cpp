/*
 * Title: main_hw3_2.cpp
 * Abstract: This program finds the route 
 * with lowest cost to visit all vertices 
 * it then prints the total cost and the route.
 * Author: Christopher Bray
 * ID: 8280
 * Date: 3/22/2022
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{  
  int numVert;
  int numEdg;
  cin >> numVert;
  cin >> numEdg;
  int vert1[numEdg];
  int vert2[numEdg];
  int val[numEdg];
  vector<int> theRoute;
  vector<int> theCost;
  for(int i = 0; i < numEdg; i++){
    cin >> vert1[i] >> vert2[i] >> val[i];
  }
  int startVert = 0;
  cin >> startVert;
  theRoute.push_back (startVert);
  
  int lowestNum = 5000;
  for(int i = 0; i < numEdg; i++){
    if(vert1[i] == startVert && val[i] < lowestNum){
      theRoute.push_back(vert2[i]);
    }
  }
  lowestNum = 5000;
  for(int i = 0; i < numEdg; i++){
    if(vert1[i] == theRoute.back() && val[i] < lowestNum){
      theRoute.push_back(vert2[i]);
    }
  }
  theRoute.push_back(startVert);
  cout << "Path:";
  for(int i = 0; i < numVert + 1; i++){
    cout << theRoute[i];
    if (i < theRoute.size()-2){
      cout << "->";
    }
  }
  cout << endl << "Cost:";
  int cost = 0;
  for(int j = 0; j < numEdg; j++){
    for(int i = 0; i < theRoute.size()-1; i++){
      if(theRoute[i] == vert1[j] && theRoute[i+1]==vert2[j]){
        theCost.push_back(val[j]);
      }
    }
  }
  for (int i = 0; i < theCost.size(); i++){
    cost += theCost[i];
  }
  cout << cost;
  cout << endl;
  return 0;
}

