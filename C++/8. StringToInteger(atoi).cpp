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
