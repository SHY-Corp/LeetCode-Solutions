// Problem - 867. Transpose Matrix

class Solution {
    public:
    int n;
    cin>>n;
    
    int a[n][n];
    for(int i=0 ;i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    for(int i=0 ;i<n; i++){
        for(int j=0; j<n; j++){
            cout<<" "<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0 ;i<n; i++){
        for(int j=i; j<n; j++){
            // swap
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    for(int i=0 ;i<n; i++){
        for(int j=0; j<n; j++){
            cout<<" "<<a[i][j];
        }
        cout<<"\n";
    }

    return 0;
};