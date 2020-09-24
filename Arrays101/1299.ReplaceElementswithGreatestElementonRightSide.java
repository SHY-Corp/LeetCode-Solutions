class Solution {
    public int findGreatest(int[] arr, int key){
        int len=arr.length;
        int max=arr[len-1];
        for(int i=len-1;i>key;i--){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        return max;   
    }
    
    public int[] replaceElements(int[] arr) {
        int len=arr.length;
    
        
        for(int i=0;i<len-1;i++){
            arr[i]=findGreatest(arr, i);
        }
        arr[len-1]=-1;
        
        return arr;
    }
}
