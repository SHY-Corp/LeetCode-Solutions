/*Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. */

#include <cctype>
#include <limits>
class Solution {
public:
    int myAtoi(string str) {

        // Skip leading whitespace
        size_t index = str.find_first_not_of(' ');

        if(index == string::npos) return 0;

        long result = 0;

        bool negative = false;

        // Check optional signs
        if(str[index] == '-') {

            negative = true;
            index++;
         }

        else if(str[index] == '+') {

            index++;

        }

        // Build result
        for(int i=index; i<str.size(); i++) {

            if(isdigit(str[i])) {

                result = result * 10 + (str[i]-'0');
                if(negative && -result <= INT_MIN) return INT_MIN;
                if(!negative && result >= INT_MAX) return INT_MAX;

            }

            else {

                break;

            }

        }

        // Account for negative if the case
        if(negative) result = -result;

        return int(result);

    }
};
