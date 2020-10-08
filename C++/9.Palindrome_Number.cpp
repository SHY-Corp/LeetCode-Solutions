class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> arr;
        int n = 0;
        if(0<=x && x<=9){
            return true;
        }
        if(x<0){
            return false;
        }
        
        int y = x;
        while(y){
            int num = y%10;
            y = y/10;
            arr.push_back(num);
            // cout<<num<<"\n";
            n++;
        }
        
        int i,j;
        i=0;
        j=n-1;
        
        while(i<j){
            // cout<<arr[i]<<" "<<arr[j]<<"\n";
            if(arr[i]!=arr[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
