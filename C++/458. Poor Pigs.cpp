// problem - 458. Poor Pigs

/*
There are buckets buckets of liquid, where exactly one of the buckets is poisonous. 
To figure out which one is poisonous, you feed some number of (poor) pigs the 
liquid to see whether they will die or not. Unfortunately, 
you only have minutesToTest minutes to determine which bucket is poisonous.

You can feed the pigs according to these steps:
    1. Choose some live pigs to feed.
    2. For each pig, choose which buckets to feed it. 
       The pig will consume all the chosen buckets simultaneously and will take no time.
    3. Wait for minutesToDie minutes. You may not feed any other pigs during this time.
    4. After minutesToDie minutes have passed, 
       any pigs that have been fed the poisonous bucket will die, and all others will survive.
    5. Repeat this process until you run out of time.

Given buckets, minutesToDie, and minutesToTest, return the minimum number of pigs needed to 
figure out which bucket is poisonous within the allotted time.
*/

class Solution {
public:
    int poorPigs(int buckets, int die, int test) {
        int base = (test/die) + 1;
        int pigs = 0;
        // finding the log (buckets, base)
        while(pow(base, pigs) < buckets) pigs++;
        return pigs;
    }
};

// Time Complexity = O(n) [where n is number of pigs needed (log(buckets, base))]
// Space CComplexity = O(1)