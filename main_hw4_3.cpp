/*
 * Title: main_hw4_3.cpp
 * Abstract: This program county how many connections each
 * vertex has and then starts with the one closest to 0 that
 * is the lowest number and then returns them in ascending 
 * order.
 * Author: Christopher Bray
 * ID: 8280
 * Date: 4/5/2022
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int verts, paths;
  cin >> verts >> paths;
  int e[paths][2];
  int d[verts][2];
  for(int i = 0; i < verts; i++){
    d[i][0] = i;
    d[i][1] = 0;
  }
  for(int i = 0; i < paths; i++){
    cin >> e[i][0] >> e[i][1];
    d[e[i][1]][1]++;
  }
  vector<pair<int,int>> p;
  for(int i = 0; i < verts; i++){
    p.push_back(make_pair(d[i][1], d[i][0]));
  }
  sort(p.begin(),p.end());
  for(int i = 0; i < verts; i++) {
    cout << "In-degree[" << i << "]:" << d[i][1] << "\n";
  }
  int diff = 0;
  for (int i = 0; i < verts-1; i++){
    if(p[i].first != p[i + 1].first){
      diff = 1;
      break;
    }
  }
  if (diff) {
    cout << "Order:";
    cout << p[0].second;
    for(int i = 1; i < verts; i++)
      cout << "->" << p[i].second;
  }
  else
    cout << "No Order:";
  cout << endl;
    return 0;
}

