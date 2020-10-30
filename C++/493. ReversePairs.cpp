/*
	493. Reverse Pairs LeetCode Problem.
	
	The problem states that we are given an array A. We need to find the number of all the pairs which satisfy the following conditions:
		1. i<j, where i and j are indexes.
		2. A[i]>2*A[j]
		
	
	Approach to the solution:
	
	1. Naive solution:
		A naive solution will be to traverse over the array twice. The first traversal will be for each individual
		elements and the second traversal will be comparing that element with each of the other remaining elements
		to check whether above conditions satisfy or not. 
		If it satisfies then increase the count. 
		
		The total time complexity for the problem will be O(N^2) and the space complexity will be O(1).
		
	2. Merge sort approach (or Divide and Conquer approach):
		If we observe carefully, we can use the merge function in merge sort to our benefit.
		
		In Merge sort, we split the array in two halves from the middle. And then repeat the process until we are left with no element.
		
		Let's say we have an array A={8,4,3,2,1}
		
					8,4,3,2,1
					/	\
				8,4          3,2,1
				/  \  	     /	  \
				8   4	    3	  2,1
						/	\
						2	1			
									
		As we can see in the above representation, we divided the array from the middle until we are left with no element.
		
		Now, while merging the array in a sorted manner, we will compare the left and right branch as to whether they comply with the above conditions or not:
		
		Example: if we consider 8 and 4
			So, 8 <= 2*4, thus, it is definitely not form a pair. So we simply sort it and change their places. We get [4,8,3,2,1].
			
			next we compare 2 and 1
			So, 2<=2*1, thus, it is definitely not form a pair. So we simply sort it and change their places. We get [4,8,3,1,2].
			
			next we compare 3 and (1,2).
			So, 3>2*1, thus we have a pair {(3,1)} but 3<=2*2, so it doesn't form a pair. Finally we sort them and get [4,8,1,2,3].
			
			finally we compare (4,8) and (1,2,3).
			So, for element 4, 4>2*1 but 4<=2*2 and 4<=2*3, thus we get pairs {(3,1),(4,1)}.
			and, for element 8, 8>2*1, 8>2*2 and 8>2*3 but 8<=2*4, thus we get pairs {(3,1),(4,1),(8,1),(8,2),(8,3)}. After sorting we get [1,2,3,4,8].
			
		From above, we get {(3,1),(4,1),(8,1),(8,2),(8,3)}. Thus the total count is 5.
*/

class Solution {
    
private:
    int merge(vector<int>& arr, int low, int mid, int high){
        int inv=0;
        int i=low, j=mid, k=low;
        for(;i<mid; i++){
            while((j<=high) && (arr[i]>2LL*arr[j])){
                j++;
            }
            inv+=(j-mid);
        }
        
        vector<int> temp;
        i=low, j=mid;
        while((i<mid) && (j<=high)){
            if(arr[i]<=arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }
        while(i<mid)
            temp.push_back(arr[i++]);
        while(j<=high)
            temp.push_back(arr[j++]);
        
        for(int i:temp){
            arr[k++]=i;
        }
        
        return inv;
    }
    
    int mergeSort(vector<int>& arr, int low, int high){
        int inv=0;
        if(high>low){
            int mid=low+(high-low)/2;
            inv+=mergeSort(arr, low, mid);
            inv+=mergeSort(arr, mid+1, high);
            inv+=merge(arr, low, mid+1, high);
        }
        return inv;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
