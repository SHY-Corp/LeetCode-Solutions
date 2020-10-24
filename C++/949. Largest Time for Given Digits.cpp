// 949 | Largest Time for Given Digits | C++
// Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.
// 24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59.
// The earliest 24-hour time is 00:00, and the latest is 23:59.
// Return the latest 24-hour time in "HH:MM" format.  If no valid time can be made, return an empty string.

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
       int max_time = -1;
        // prepare for the generation of permutations next.
        std::sort(A.begin(), A.end());

        do {
            int hour = A[0] * 10 + A[1];
            int minute = A[2] * 10 + A[3];

            if (hour < 24 && minute < 60) {
                int new_time = hour * 60 + minute;
                max_time = new_time > max_time ? new_time : max_time;
            }
        } while(next_permutation(A.begin(), A.end()));

        if (max_time == -1) {
            return "";
        } else {
            string time="";
            int hr = max_time/60;
            int min = max_time%60;
            time.append(to_string(hr/10));
            time.append(to_string(hr%10));
            time.append(":");
            time.append(to_string(min/10));
            time.append(to_string(min%10));
            return time;
        }
    }
};