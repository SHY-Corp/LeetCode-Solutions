#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
PROBLEM - 694. Number of Distinct Islands

DESCRIPTION -

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical). You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island has the same shape as another island (and not rotated or reflected).

Input: 
  [
    [1,1,0,0,1],
    [1,0,0,0,0],
    [1,1,0,0,1],
    [0,1,0,1,1]
  ]
Output: 3
Explanation:
  11   1    1
  1        11   
  11
   1

APPROACH-

-- In this solution, we have implemented BFS algorithm
-- Created two 2d vectors: dir->stores direction and dirS->represents whether we took 
left or right or up or down direction to move to the neighbor 
-- 'b' is stored in the path string when we backtrack from cell

TIME COMPLEXITY-

TC of solution O(n^2) 
SC of solution O(1)

*/

class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    vector<char> dirS={'d','u','r','l'};
    string s="";
    int countIslands(vector<vector<int>> &graph,int i,int j){
        graph[i][j]=0;
        int cnt=1;
        for(int d=0;d<dir.size();d++){
            int x=i+dir[d][0];
            int y=j+dir[d][1];
            if(x>=0&& y>=0 && x<graph.size() && y<graph[0].size() && graph[x][y]==1){           
                s+=dirS[d];
                cnt+=countIslands(graph,x,y);
                s=s+'b';
            }
        }
        return cnt;
    }
    int numberofDistinctIslands(vector<vector<int>> &graph) {
        // write your code here
        unordered_set<string> shape;
        for(int i=0;i<graph.size();i++)
            for(int j=0;j<graph[0].size();j++)
                if(graph[i][j]==1){
                    s="";
                    countIslands(graph,i,j);
                    shape.insert(s);
                }
        return shape.size();
    }
};