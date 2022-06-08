/*
 * Title: main_hw6_2.cpp
 * Abstract: This program implements Floyd's algorithm it takes the      * user input of the number of vertices and then the program creates     * and outputs a matrix accordingly.
 * Author: Christopher Bray
 * ID: 8280
 * Date: 4/19/2022
 */

#include<iostream>

using namespace std;

const int MAX=25;
int graphThis[MAX][MAX];
int dis[MAX][MAX];

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n; i++){
        for(int j = 0;j < n; j++){
            cin >> graphThis[i][j];
            if(graphThis[i][j]==-1)
                dis[i][j] = 1e9;
            else
                dis[i][j] = graphThis[i][j];
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0;i < n; i++){
            for(int j=0;j < n; j++){
                if((dis[i][j]>dis[i][k]+dis[k][j])&&(dis[i][k]!=1e9)&&(dis[k][j]!=1e9)){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << dis[i][j];
            if( j < n-1){
              cout <<" ";
            }
        }
        cout<<"\n";
    }
}
