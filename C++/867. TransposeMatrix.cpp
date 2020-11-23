// Problem - 867. Transpose Matrix
// This code will help you in Transposing any Square Matrix(n*n).

class Solution {
    public:
    int n;                      // Taking input as a number for the size of matix.
    cin>>n;
    
    int a[n][n];
    for(int i=0 ;i<n; i++){     
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    for(int i=0 ;i<n; i++){     // It will show you the Original matrix that you have inserted.
        for(int j=0; j<n; j++){
            cout<<" "<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0 ;i<n; i++){     // This is the Main Logic behind for Transposing Matrix.
        for(int j=i; j<n; j++){
            // swap
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    for(int i=0 ;i<n; i++){     // It will give the final output Transposed Matrix.
        for(int j=0; j<n; j++){
            cout<<" "<<a[i][j];
        }
        cout<<"\n";
    }

    return 0;
};