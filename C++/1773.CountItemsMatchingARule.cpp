/**
 * @file 1773. Count Items Matching a Rule.cpp
 * @author Vipul Kumar Singh (https://github.com/vipul-2003)
 * @brief
 * @version 0.1
 * @date 2021-11-09
 * @link https://leetcode.com/problems/count-items-matching-a-rule/
 * @copyright Copyright (c) 2021
 *
 */

/*
Problems-

You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.

The ith item is said to match the rule if one of the following is true:

ruleKey == "type" and ruleValue == typei.
ruleKey == "color" and ruleValue == colori.
ruleKey == "name" and ruleValue == namei.
Return the number of items that match the given rule.

Example 1:
Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
Output: 1
Explanation: There is only one item matching the given rule, which is ["computer","silver","lenovo"].

Example 2:

Input: items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
Output: 2
Explanation: There are only two items matching the given rule, which are ["phone","blue","pixel"] and ["phone","gold","iphone"]. Note that the item ["computer","silver","phone"] does not match.


Constraints:

1 <= items.length <= 104
1 <= typei.length, colori.length, namei.length, ruleValue.length <= 10
ruleKey is equal to either "type", "color", or "name".
All strings consist only of lowercase letters.

*/

// Source Code

//Simple nested  if else is used here ...

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {

        int count = 0; // to count the number matching the criteria 

        for (int i = 0; i < items.size(); i++) // simply for loop for traversing 
        {
            if (ruleKey == "type") // if the value "ruleKey" is equal to "type" then code inside if else is executed 
            {
                items[i][0] == ruleValue ? ++count : count; // ternuary operator used
            }

            else if (ruleKey == "color") // if the value "ruleKey" is equal to "color" then code inside if else is executed 
            {
                items[i][1] == ruleValue ? ++count : count;
            }

            else // both of the above doesn't fulfill the criteria then else will executed at last 
            {
                items[i][2] == ruleValue ? ++count : count;
            }
        }

        return count; //  return the value as "count" as function is of int type 
    }
};
