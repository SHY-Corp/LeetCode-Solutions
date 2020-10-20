/*
Aim : Complete the given functions (insert(), remove(), getRandom()),acc to mentioned conditions 
      all in O(1) time i.e. , in constant average time.

Soln : We can use a map to store the indexes of inserted element. 
    
       insert() :
                 after inserting a element we store the value(vector size - 1) into the map at map[val].
       remove() :
                 1. we will swap the no to be removed with last no in the vector, so as the keep the position of index in order preserved.
                 2. then remove the last element
                 3. change the index in the map of th swapped element
                 4. remove the deleted element from the map
                 
      getRandom() :
                 return the array at index rand()%size of array.
                 here rand is a inbuilt function that when moded with size returns a random in the range of size of array 
*/
class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> mp;
public:
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) != mp.end())
            return false;
        
        nums.push_back(val);
        mp[val] = nums.size()-1;
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) == mp.end())
            return false;
        
        swap(nums[mp[val]], nums[(nums.size()-1)]);
        nums.pop_back();
        
        mp[nums[mp[val]]] = mp[val];
        mp.erase(val);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
       // srand(NULL);
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
