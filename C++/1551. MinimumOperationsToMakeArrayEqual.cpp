/*
PROBLEM - 1551. Minimum Operations to Make Array Equal

DESCRIPTION -

You have an array arr of length n where arr[i] = (2 * i) + 1 for all valid values
of i (i.e. 0 <= i < n).
In one operation, you can select two indices x and y where 0 <= x, y < n and
subtract 1 from arr[x] and add 1 to arr[y] (i.e. perform arr[x] -=1 and arr[y] += 1).
The goal is to make all the elements of the array equal. It is guaranteed that
all the elements of the array can be made equal using some operations.

Given an integer n, the length of the array. Return the minimum number of
operations needed to make all the elements of arr equal.

CONSTRAINTS-

1 <= n <= 10^4

APPROACH-

-- We can notice that the given array is the array with first n odd numbers.
-- So, there is a pattern. To make the array equal we should try to concentrate on
   the mid point so that we can increase the lesser numbers and decrease the greater
   ones.
-- Seeing some examples you will notice that as we move away from the midpoint we
   require operations as series of even numbers.
-- When n is odd, there is only one midpoint. So, the min operations required is
   sum of first n/2 even numbers i.e. (n/2)*((n/2)+1).
-- Now if n is even, the midpoint will be the avg of two middle elements. So,
   considering this midpoint you will notice that the series of operations required
   by each element is a series of odd numbers.
-- So, the min operations in this case is sum of first n/2 odd numbers i.e (n/2)*(n/2).

TIME COMPLEXITY-

TC of solution O(1).

*/

class Solution {
public:
	int minOperations(int n) {
		if (n & 1) return (int)(n / 2) * ((n / 2) + 1); // When n is odd.
		else return (int)(n / 2) * (n / 2);  // When n is even.
	}
};