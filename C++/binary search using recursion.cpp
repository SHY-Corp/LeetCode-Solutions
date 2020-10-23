// input - input array
// size - length of input array
// element - value to be searched
int binary(int input[],int si,int end,int x)
{
    if(si>end)
        return -1;
    int mid=(si+end)/2;
    if(input[mid]==x)
        return mid;
    else if(input[mid]>x)
        binary(input,si,mid-1,x);
    else
        binary(input,mid+1,end,x);
}

int binarySearch(int input[], int size, int element) {
    // Write your code here
    int start=0;
    int end=size-1;
    int t=binary(input,start,end,element);
    return t;
}

