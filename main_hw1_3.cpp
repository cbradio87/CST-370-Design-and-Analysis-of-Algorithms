/*
 * Title: main_hw1_3.cpp
 * Abstract: This program collects the number of vertices
 * It then collects the numnber of edges to be traversed
 * it then collects from what vertice to what other vertice
 * is traversed. Then it outputs what other vertices are 
 * traveled to from the list of vertices in sequential
 * order.
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
    int vertices = 1;
    cin >> vertices;
    int edges = 0;
    cin >> edges;
    vector<int> inputs1={0};
    vector<int> inputs2={0};
    inputs1.clear();
    inputs2.clear();
    int vert1, vert2;
    for (int i = 0; i < edges; i++){
      cin >> vert1 >> vert2;
      inputs1.push_back (vert1);
      inputs2.push_back (vert2);
    }
    for (int i = 0; i < vertices; i++)
    {
      cout << i;
      vector<int> outputs1 = {0};
      outputs1.clear();
      for (int k = 0; k < edges; k++){
        if (inputs1[k] == i){
          outputs1.push_back (inputs2[k]);
        }
      }
      sort(outputs1.begin(), outputs1.end());
      for (int m = 0; m < edges; m++){
        if(outputs1[m+1]==0 && m+1 == 0){
          cout << "->" << outputs1[m+1];
        }
        if(m < outputs1.size()){
          cout << "->" << outputs1[m];
        }
      }
      cout << endl;
      outputs1.clear();
    }
    return 0;
}
