class Solution {
  //In this program we are using dynamic programming
  // We are using this approach because we need to remember the outputs for lower cases also.
    public boolean winnerSquareGame(int n) {
      //Checking for the base cases
        if(n<=4){
            if(n==1||n==3||n==4){
            return true;
            }else{
                return false;
            }
        }
        //Check if the given number has a perfect square root
        if(Math.sqrt(n)-(int)Math.sqrt(n)==0){
            return true;
        }
        //Array to store values obtained for different cases
        //Performing dynamic programming
        boolean[] arr=new boolean[n];
        arr[0]=true;
        arr[1]=false;
        arr[2]=true;
        arr[3]=true;
        for(int i=4;i<n;i++){
            if(Math.sqrt(i+1)-(int)Math.sqrt(i+1)==0){
                arr[i]=true;
                continue;
            }
            for(int j=1;j*j<=i+1;j++){
                if(arr[i-j*j]==false){
                    arr[i]=true;
                    break;
                }
            }
        }
        return arr[n-1];
    }
}
