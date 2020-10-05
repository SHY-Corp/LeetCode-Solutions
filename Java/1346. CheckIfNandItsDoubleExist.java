import java.util.*;
class Solution {
    public boolean checkIfExist(int[] arr) {
        int len=arr.length;
        boolean result=false;
        Hashtable <Integer,Integer> keys= new Hashtable<>();
        for(int i=0;i<len;i++){
            keys.put(i,arr[i]);
        }
        
        for(int i=0;i<len;i++){
            keys.remove(i);
            if(keys.contains(arr[i]*2)){
                result=true;
                break;
            }else if (arr[i]%2==0 && keys.contains(arr[i]/2)){
                result=true;
                break;
            }
            keys.put(i,arr[i]);
        }
            return result;

        }
    }
