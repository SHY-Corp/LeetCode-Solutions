class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size();

        //changed long double -> double!
        double sum=0.0;

        //sorting the salary array in increasing order
        sort(begin(salary), end(salary));

        //iterating from 2nd element till 2nd last element to store their sum
        for(int i=1; i<=n-2; i++)
        {
           sum = sum + salary[i];
        }

        //dividing the sum by (n-2) to find the average because we did not include the min(1st) and the
        //max(last) element in the salary array, so total employees = n-2
        double avg = sum/(n-2);

        return avg;
    }
};
