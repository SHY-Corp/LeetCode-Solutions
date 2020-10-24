import sys 
  
# Function to return the sum of a 
# triplet which is closest to x 
def solution(arr, x): 
  
    # To store the closets sum 
    closestSum = sys.maxsize 
  
    # Run three nested loops each loop  
    # for each element of triplet 
    for i in range (len(arr)) : 
        for j in range(i + 1, len(arr)): 
            for k in range(j + 1, len( arr)): 
              
                # Update the closestSum 
                if(abs(x - closestSum) >  
                abs(x - (arr[i] +
                arr[j] + arr[k]))): 
                    closestSum = (arr[i] +
                                    arr[j] + arr[k]) 
              
    # Return the closest sum found 
    return closestSum 
  
# Driver code 
if __name__ == "__main__": 
      
    arr = []
    arr=list(map(int,input().split()))
    x = int(input())
      
    print(solution(arr, x)) 
