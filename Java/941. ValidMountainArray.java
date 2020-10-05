class Solution {
    
    public boolean checkASC(int[] A, int e){
        boolean result=false;
        int prev=A[0];
        for(int i=1;i<=e;i++){
            if(prev>=A[i]){
                result=false;
                break;
            }else{
                result=true;
            }
            prev=A[i];
        }
        return result;
    }
    
    public boolean checkDESC(int[] A, int s, int e){
        boolean result=false;
        int prev=A[s];
        if(e-s==1){
            result=true;
        }
        for(int i=s+1;i<e;i++){
            if(prev<=A[i]){
                result=false;
                break;
            }else{
                result=true;
            }
            prev=A[i];
        }
        return result;
    }
    
    
    public boolean validMountainArray(int[] A) {
        int peak=0, prev;
        int len=A.length;
        boolean isMountain=false;
        if(len>=3){
            prev=A[0];
            for(int i=1;i<len;i++){
            if(prev>A[i]){
                peak=i-1;
                break;
            }
            prev=A[i];        
        }
        
        isMountain=(checkASC(A,peak) && checkDESC(A,peak+1,len));
            
        }
             
        return isMountain;
    }
}
