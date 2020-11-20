// problem - 621. Task Scheduler

/*
    Given a characters array tasks, representing the tasks a CPU needs to do, 
    where each letter represents a different task. Tasks could be done in any order. 
    Each task is done in one unit of time. For each unit of time, 
    the CPU could complete either one task or just be idle.

    However, there is a non-negative integer n that represents the cooldown period between 
    two same tasks (the same letter in the array), that is that there must be 
    at least n units of time between any two same tasks.

    Return the least number of units of times that the CPU will take to finish 
    all the given tasks.
*/

#include <unordered_map>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // to track the frequency of tasks
        unordered_map<char, int> freq;
        // highest(max) frequency
        int high_freq = 0;
        for(char task: tasks) {
            freq[task]++;
            high_freq = max(high_freq, freq[task]);
        }
        
        // number of tasks with the highest frequency 
        int num_high_freq = 0;
        for(pair<char, int> x: freq) {
            if(x.second == high_freq) num_high_freq++;   
        }
        
        int len = tasks.size();
        // if the size of tasks is less then formula else length of tasks
        return max(len, ((high_freq - 1) * (n + 1)) + num_high_freq);
    }
};

// Time Complexity = O(N) 
// Space Complexity = O(N) [where N is length of tasks]