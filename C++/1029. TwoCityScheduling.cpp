/* 
Two City Scheduling- A company is planning to interview 2n people. Given the array costs where 
costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of
flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.*/

/* 
Approach- We will sort the array in the increasing order of differences(v[i][0]-v[i][1]) between the
first element and the second element of the row and then assign first n values(v[i][0]) of the sorted 
array to first city and latter n values(v[i][1]) to second city thus this will minimise the total cost.*/

class Solution {
public:
    
    static bool cmp(vector <int> &a,vector <int> &b){
        return (a[0]-a[1])<(b[0]-b[1]); // A comparator to sort according to the differences
    }  
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),cmp); //sorting the costs in increasing order of differences
        int sum=0;
        for(int i=0;i<costs.size()/2;i++){
            sum+=costs[i][0]; // Assigning first n to city A
        }
        for(int i=costs.size()/2;i<costs.size();i++){
            sum+=costs[i][1]; // Assigning latter n to city B
        }
        return sum; // minimum total cost
    }
};