#include <bits/stdc++.h> 
using namespace std; 

int maxSubarrayProduct(int arr[], int n) 
{ 
	
	int max_ending_here = 1; 
	int min_ending_here = 1; 

	int max_so_far = 1; 
	int flag = 0; 
	
	for (int i = 0; i < n; i++) { 
		if (arr[i] > 0) { 
			max_ending_here = max_ending_here * arr[i]; 
			min_ending_here = min(min_ending_here * arr[i], 1); 
			flag = 1; 
		} 
		else if (arr[i] == 0) { 
			max_ending_here = 1; 
			min_ending_here = 1; 
		} 
		else { 
			int temp = max_ending_here; 
			max_ending_here = max(min_ending_here * arr[i], 1); 
			min_ending_here = temp * arr[i]; 
		} 

		if (max_so_far < max_ending_here) 
			max_so_far = max_ending_here; 
	} 
	if (flag == 0 && max_so_far == 1) 
		return 0; 
	return max_so_far; 
} 

int main() 
{ 
	int arr[] = { 1, -2, -3, 0, 7, -8, -2 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Maximum Sub array product is "
		<< maxSubarrayProduct(arr, n); 
	return 0; 
} 
