/*
 * Title: main_hw3_3.cpp
 * Abstract: This program takes an input 
 * of a set of numbers The first line 
 * indicates that there how many vertices 
 * are in the graph. The first vertex starts 
 * from the number 0. The second line  
 * represents the number of edges, and 
 * following two lines are the edge information.   * The output reflects the path.
 * the input information.
 * Author: Christopher Bray
 * ID: 8280
 * Date: 3/22/2022
 */

#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<vector<int>> & D, vector<int>& mark, int q, int& count){
  int R = D.size();
  count += 1;
  mark[q] = count;
  for (int w = 0; w < R; w++){
    if (D[q][w]== 1) {
      if(mark[w] == 0)
        dfs(D, mark, w, count);
    }
  }
}

vector<int> DFS(const vector<vector<int>>& D, int orig){
  int R = D.size();
  vector<int> mark(R,0);
  for(int i = 0; i < R; i++) mark[i] = 0;
  int count = 0;
  dfs(D, mark, orig, count);
  return mark;
}
int main()
{
  int R, E;
  cin >> R;
  vector<vector<int>> D;
  for (int i = 0; i < R; i++){
    vector<int> row(R, 0);
    D.push_back(row);
  }
  cin >> E;
  for (int i = 0; i < E; i++){
    int u, q;
    cin >> u >> q;
    D[u][q] = 1;
  }
  int orig = 0;
  vector<int> Mark = DFS(D, orig);
  for (int i = 0; i < Mark.size(); i++)
    cout << "Mark[" << i << "]:" << Mark[i] << endl;
  return 0;
}
