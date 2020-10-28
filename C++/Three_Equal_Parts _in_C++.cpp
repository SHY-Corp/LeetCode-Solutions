#include <bits/stdc++.h>
using namespace std;
void print_vector(vector<auto> v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << v[i] << ", ";
   }
   cout << "]"<<endl;
}
class Solution {
   public:
   vector<int> threeEqualParts(vector<int>& A){
      vector<int> ret(2, -1);
      int num = 0;
      int n = A.size();
      for (int i = 0; i < n; i++) {
         num += (A[i] == 1);
      }
      if (num % 3 != 0)
         return ret;
      if (num == 0) {
         return { 0, 2 };
      }
      int req = num / 3;
      int idx = n - 1;
      for (int temp = 0; idx >= 0 && temp < req; idx--) {
         temp += A[idx] == 1;
      }
      idx++;
      int firstEnd = getIdx(A, 0, idx);
      if (firstEnd < 0)
         return ret;
      int secondEnd = getIdx(A, firstEnd + 1, idx);
      if (secondEnd < 0)
         return ret;
      return { firstEnd, secondEnd + 1 };
   }
   int getIdx(vector<int>& a, int left, int right){
      while (left < right && a[left] == 0)
      left++;
      while (right < (int)a.size()) {
         if (a[left] != a[right])
            return -1;
         left++;
         right++;
      }
      return left - 1;
   }
};
main(){
   Solution ob;
   vector<int> v = {0,1,0,1,1};
   print_vector(ob.threeEqualParts(v));
}