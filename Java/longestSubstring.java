class Solution {
   
    
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int ans = 0 ;
        
        for(int i=0;i<n;i++)
        {
            boolean[]arr=new boolean [256];
            for(int j=i;j<n;j++)
            {
                if(arr[s.charAt(j)]==true)
                    break;
                else
                {    arr[s.charAt(j)]=true;
                    ans = Math.max(ans,j-i+1);
                }
                
            }
            arr[s.charAt(i)] = false; 
           
           
        }
        return ans;
        
    }
}
