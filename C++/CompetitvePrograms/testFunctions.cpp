#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
void show(int arr[],int n)
{
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<"\n";
}
int main()
{
	int arr[10]={10,12,3,3,5,78,2,1,0,43};
	int arr2[10];
	show(arr,10);
	sort(arr,arr+10);
//	cout<<binary_search(arr,arr+10,33)<<" \n";
    show(arr,10);
    reverse(arr,arr+10);
    show(arr,10);
    cout<<*max_element(arr,arr+10)<<"\n";
    cout<<*min_element(arr,arr+10)<<"\n";
    cout<<accumulate(arr,arr+10,0)<<"\n";
    cout<<count(arr,arr+10,3)<<"\n";
    cout<<find(arr,arr+10,3)-arr<<"\n";
    //copy_n(arr,10,arr2);
    copy_n(arr, 6, arr2);
    show(arr2,10);
}
