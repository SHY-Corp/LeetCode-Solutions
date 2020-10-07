// C++ program to find longest common prefix  
// of given array of words. 
#include<iostream> 
#include<algorithm> 
  
using namespace std; 
  
string commonPrefixUtil(string str1, string str2) 
{ 
    string result; 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Compare str1 and str2 
    for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++) 
    { 
        if (str1[i] != str2[j]) 
            break; 
        result.push_back(str1[i]); 
    } 
  
    return (result); 
} 
  
// A Function that returns the longest common prefix 
// from the array of strings 
string commonPrefix (string arr[], int n) 
{ 
    string prefix =  arr[0]; 
  
    for (int i=1; i<=n-1; i++) 
        prefix = commonPrefixUtil(prefix, arr[i]); 
  
    return (prefix); 
} 

int main() 
{ 
    int n;
    cout<<"Input no. of words : ";
    cin>>n;
    int i;
    string ar[n];
    cout<<"Input the words: \n";
    for(i=0;i<n;i++){
    	cin>>ar[i];
    } 
    cout << "The longest common prefix is: "
         << commonPrefix(ar, n)
         << "\n"; 
    return 0; 
} 
