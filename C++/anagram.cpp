#include <iostream>
using namespace std;

int main()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    if(s1.length()!=s2.length()){
        cout<<"not anagram";
        return 0;
    }
    int array[26];
    for(int i=0;i<26;i++){
        array[i]=0;
    }
    for(int i=0;i<s1.length();i++){
        array[s1[i]-'a']++;
        array[s2[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(array[i]!=0){
            cout<<"not anagram";
            return 0;
        }
    }
    cout<<"anagram";

    return 0;
}
