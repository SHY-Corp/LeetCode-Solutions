//C++ code to find the median of two sorted arrays,which works for different sized arrays also
#include <iostream>
#include <vector>
using namespace std;

double get_median(vector<int> &arr1, vector<int> &arr2, int x, int y)
{
    int low = 0, high = x;
    while (low <= high)//using binary search reduces complexity to O(Log(min(x,y)),x and y are the sizes of arrays
    {
        int partition_x = (low + high) / 2;
        // partitioning of the second array
        int partition_y = (x + y + 1) / 2 - partition_x;

        // getting max_left_x and min_right_x values
        int max_left_x, min_right_x;
        max_left_x = (partition_x > 0) ? arr1[partition_x - 1] : INT_MIN;
        min_right_x = (partition_x == x) ? INT_MAX : arr1[partition_x];

        // getting max_left_y and min_right_y values
        int max_left_y, min_right_y;
        max_left_y = (partition_y > 0) ? arr2[partition_y - 1] : INT_MIN;
        min_right_y = (partition_y == y) ? INT_MAX : arr2[partition_y];

        if (max_left_x <= min_right_y && min_right_x >= max_left_y)
        {
            if ((x + y) % 2 == 0) //if the sum of sizes of 2 arrays is even we take the average of middle_most elements
                return ((double)max(max_left_x, max_left_y) + (double)min(min_right_x, min_right_y)) / 2.0;
            else
                return max(max_left_x, max_left_y);
        }
        // else we move the partition region accordingly
        else if (max_left_x > min_right_y)
            high = partition_x - 1;
        else
            low = partition_x + 1;
    }
    return 0;
}
int main()
{
	int m,n;
	cin>>m>>n;
	vector<int> a(m),b(n);
	int i;
	for(i=0;i<=m-1;i++)cin>>a[i];
	for(i=0;i<=n-1;i++)cin>>b[i];
	if(a.size()>b.size())
	{
		swap(a,b); //to ensure that first array is always smaller or equal in size than the second one
		swap(m,n);
	}
	double median=get_median(a,b,m,n);
	cout<<median;
}
