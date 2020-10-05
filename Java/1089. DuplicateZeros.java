class Solution {
    
    void dupli(int arr[], int index, int len){
        for(int i=len-1; i>index;i--){
            arr[i]=arr[i-1];
        }
        arr[index]=0;
    }
    
    public void duplicateZeros(int[] arr) {
        
        int len=arr.length;
        
        for(int i=0;i<arr.length;i++){
            if(arr[i]==0){
                dupli(arr, i, len);
                i++;
            }
        }
    }
}
