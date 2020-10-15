// Problem - 319. Bulb Switcher

// There are n bulbs that are initially off. 
// You first turn on all the bulbs.
// Then, you turn off every second bulb. 
// On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on).
// For the i-th round, you toggle every i bulb.
// For the n-th round, you only toggle the last bulb. 
// Find how many bulbs are on after n rounds.

class Solution {
public:
    int bulbSwitch(int n) {
        int count=0;
        for(int i=1; i*i<=n; i++) {             // only bulbs at perfect squares position will remain turned on
            count++;
        }
        return count;
    }
};