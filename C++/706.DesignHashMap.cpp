/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

/*
class MyHashMap {
public:
    vector<list<pair<int, int>>> v;
    int len;

    int hash_func(int key)
    {
        return key%len;
    }
    MyHashMap() {
        len = 1000001;
        v.resize(len);
    }

    void put(int key, int value) {
        int i = hash_func(key);
        for(auto it=v[i].begin();it!=v[i].end();it++)
        {
            if(it->first==key)
            {
                it->second=value;
                return;
            }
        }
        v[i].push_back({key,value});
    }

    int get(int key) {
        int i = hash_func(key);
        for(auto it=v[i].begin();it!=v[i].end();it++)
        {
            if(it->first==key)
            {
                return it->second;

            }
        }
        return -1;
    }

    void remove(int key) {
        int i = hash_func(key);
        for(auto it=v[i].begin();it!=v[i].end();it++)
        {
            if(it->first==key)
            {
               v[i].erase(it);
                return;
            }
        }
    }
};
*/

class MyHashMap {
public:
    //initializing an array with the value from the given constraints
    int data[1000001];
    MyHashMap() {
        //filling the array with -1
        fill(data, data + 1000000, -1);
    }

    void put(int key, int value) {
        //storing a value into the key index of data array
        data[key] = value;
    }

    int get(int key) {
        return data[key];
    }

    void remove(int key) {
        //initializing the value as -1 indicating that the value has been removed
        data[key]= -1;
    }
};

/*
   TC: O(1)
   SC: O(n)
*/
