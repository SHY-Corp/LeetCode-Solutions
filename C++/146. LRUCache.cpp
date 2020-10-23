/*

Problem : Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:
    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key

Approach : (Why I have used list and map)

When a value is used via the put function or the get function we need to place the entry at front of the lru cache, I have used list representation for lru where the first entry is the most recently used and last entry is least recently used

Since if we know the exact pointer position of the element in list we can delete in O(1) in cpp because list is doubly linked list so I use a map positions to store the locations of the elements so that they can be deleted when required.

Rest of the steps are commented with the code

*/

class LRUCache {
public:
    int size;
    unordered_map<int, int> values; // stores the values of the keys in map
	list<int> lru; // list where first element is most recently used and last is least recently used
	unordered_map<int, list<int>::iterator> positions; // map to store position of keys in lru list

    void updateLRU(int key) {
		if(positions.find(key) != positions.end()) { // if key is already present we have to erase the earlier instance and bring it to front of list as it is now most recently used
			lru.erase(positions[key]);
			lru.push_front(key);
			positions[key] = lru.begin(); // update the position map
		}
		else {
			if(lru.size() < size) { // if key not present and size is less than max just add the key to lru and return
				lru.push_front(key);
				positions[key] = lru.begin();
			}
			else { // else remove the least recently used key and add new key to front 
				values.erase(lru.back());
				positions.erase(lru.back());
				lru.pop_back();
				lru.push_front(key);
				positions[key] = lru.begin();
			}
		}
	}

    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(values.find(key) == values.end()) return -1; // if key not present in list return -1
		else {
			updateLRU(key); // else we update the lru list and the position of the key in lru using update function
		}
		return values[key]; // return value of key
    }
    
    void put(int key, int value) {
        updateLRU(key); // we update the lru list and position of key in lru using update function
		values[key] = value; // update the value of key if present or store if not present
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
