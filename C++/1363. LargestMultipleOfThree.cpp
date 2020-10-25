// Problem - 1363. Largest Multiple of Three

/*
Problem statement -
Given an integer array of digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order.

Since the answer may not fit in an integer data type, return the answer as a string.

If there is no answer return an empty string.
*/

/*
Constraints -
1. 1 <= digits.length <= 10^4
2. 0 <= digits[i] <= 9
3. The returning answer must not contain unnecessary leading zeros.
*/

/*
Example 1:
Input: digits = [8,1,9]
Output: "981"

Example 2:
Input: digits = [8,6,7,1,0]
Output: "8760"

Example 3:
Input: digits = [1]
Output: ""

Example 4:
Input: digits = [0,0,0,0,0,0]
Output: "0"
*/

//Solution
/*
Idea -
Obviously, trying combinations of numbers won't work as we can have up to 10,000 numbers. Luckily, there is a handy divisibility test:
*A number is divisible by 3 if the sum of all its digits is divisible by 3.
Observation 1: since the order does not matter, the largest number can be formed by adding digits from largest (9) to smallest (0), e.g. 9999966330000.
Therefore, we can just count the occurrences of each digit, and then generate the string.
Observation 2: we need to use all digits to form the maximum number. If we sum all digits, and the modulo of 3 is not zero, we need to remove 1 (preferably) or 2 sm
If modulo 3 of the sum is 1, for example, we will try to remove 1, 4, or 7, if exists, or two of 2, 5, or 8.
More examples:
9965341 % 3 == 1; we remove 1 to get the largest number.
9952000 % 3 == 1; now we need to remove two digits, 2 and 5, as there is no 1, 4, or 7.
These observations yield the following algorithm.
*/
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        string res = "";
        int m1[] = {1, 4, 7, 2, 5, 8}, m2[] = {2, 5, 8, 1, 4, 7};
        int sum = 0, ds[10] = {};
        for (auto d : digits) {
            ++ds[d];
            sum += d;
        }
        while (sum % 3 != 0) {
            for (auto i : sum % 3 == 1 ? m1 : m2) {
                if (ds[i]) {
                    --ds[i];
                    sum -= i;
                    break;
                }
            }
        }
        for (int i = 9; i >= 0; --i)
            res += string(ds[i], '0' + i);
        return res.size() && res[0] == '0' ? "0" : res;
    }
};
