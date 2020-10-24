#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    
    
    
   //-> get the diagonal of each column for the first row
   //-> sort the diagonal and put back into the matrix diagonal
   //-> get the diagonal of each row for the first column
   //-> sort the diagonal and put back into the matrix diagonal
   
    for(int i = 0; i < n; i++) {
        int ci = i, cj = 0;
        vector<int> v;
        while(ci < n && cj < m) {
            v.push_back(mat[ci++][cj++]);
        }
        sort(v.begin(), v.end());
        int k = 0; ci = i, cj = 0;
        while(ci < n && cj < m) {
            mat[ci++][cj++] = v[k++];
        }
    }

    for(int j = 0; j < m; j++) {
        int ci = 0, cj = j;
        vector<int> v;
        while(ci < n && cj < m) {
            v.push_back(mat[ci++][cj++]);
        }
        sort(v.begin(), v.end());
        int k = 0; ci = 0, cj = j;
        while(ci < n && cj < m) {
            mat[ci++][cj++] = v[k++];
        }
    }
    return mat;
}

int main()
{

    cout<<"Enter the size of matrix  row colomn :";
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix( n , vector<int> (m, 0)); 

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin>>matrix[i][j];

    cout<<endl;

    matrix = diagonalSort(matrix);

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
