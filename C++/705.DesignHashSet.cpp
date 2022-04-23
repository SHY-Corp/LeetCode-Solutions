class MyHashSet {
public:
    //creating a vector for storing all the possible hash values
    vector<bool> hash;
    MyHashSet() {
        //resizing this vector to a value given in the constraints
        hash.resize(1e6+1, false);
    }

    void add(int key) {
        //marking the key as true to indicate that it has been inserted
        hash[key] = true;
    }

    void remove(int key) {
        //marking the key as false to indicate it's not in the hash set
        hash[key] = false;
    }

    bool contains(int key) {
        //returning the value of this key. If the key exists, it will return true, else false
        return hash[key];
    }
};

/*
    TC: O(1)
    SC: O(n)
*/

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
