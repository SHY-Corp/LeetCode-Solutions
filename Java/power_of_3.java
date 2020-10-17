// calculates if a number is power of three 
// clean code in java

public class Power_3 { 
  
    // Returns true if n is power of 3, else false 
    static boolean check(int n) 
    { 
        /* The maximum power of 3 value that  
           integer can hold is 1162261467 ( 3^19 ) .*/
        return 1162261467 % n == 0; 
    } 
  
    // Driver code 
    
     public static void main(String args[]) 
    { 
        int n = 9; 
        if (check(n)) 
            System.out.println("Yes"); 
        else
            System.out.println("No"); 
    } 
} 
