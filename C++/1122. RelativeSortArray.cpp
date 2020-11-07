/**
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
 * Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order. 
 * 
 * 
 * Approach : 
 * 
 * We iterate over the reference array, and maintain leading and trailing indices on the main array.
 * 
 * According to the element from reference array, we iterate over the main array to find the reference array element and keep putting it in the place of trailing index while
 * continually increasing the leading index.
 */

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int j = 0;
        for (auto x : arr2)
        {
            for (int i = j; i < arr1.size(); i++)
            {
                if (arr1[i] == x)
                {
                    int temp = arr1[j];
                    arr1[j++] = arr1[i];
                    arr1[i] = temp;
                }
            }
        }

        sort(arr1.begin() + j, arr1.end());

        return arr1;
    }
};