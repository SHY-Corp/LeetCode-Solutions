#include <bits/stdc++.h>
class RecentCounter {
public:
    RecentCounter() {
        arr = {};
    }
    int ping(int t) {
        arr.push_back(t);
        auto left = std::lower_bound(arr.begin(), arr.end(), t - 3000);
        auto right = std::lower_bound(arr.begin(), arr.end(), t + 1);
        return right - left;
    }
    std::vector<int> arr;
};