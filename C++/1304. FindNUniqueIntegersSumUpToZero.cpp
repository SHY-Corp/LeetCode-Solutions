/*
Finding N Unique Integers Sum Up To Zero-
Given an integer n, return any array containing n unique integers such that they add up to 0.

Problem link- https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

Approach-
Include integers from 1 to n/2 and -1 to -n/2 into the vector
If n is odd, include 0 into the vector as well.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> array(n,0);     //declaring a vector of integers of sie n, with each element initialised to 0
        int counter=0;              //counter variable will keep track of where the next element will be added
        
        for(int i=1;i<=n/2;i++)
        {
            array[counter]=i;
            counter++;
        }
        for(int i=-1;i>=-n/2;i--)
        {
            array[counter]=i;
            counter++;
        }
        
        return array;               //since all elements were originally initialised to zero, the last element will already be 0 if n is odd
    }
};