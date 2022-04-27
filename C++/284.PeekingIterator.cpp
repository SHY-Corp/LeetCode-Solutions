/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    //for storing the "next value" for use in "peek" function
    int next_val;
    //for storing the "has next value"
    bool has_next;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.

        //store current has_next value
        has_next = Iterator::hasNext();
        if(has_next)
            //store the "next_val" for "future" use in "peek" function
            next_val = Iterator::next();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        //return current next_val
        return next_val;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        //store the current next for returning
	    int x = next_val;

        //update the has_next variable
        has_next = Iterator::hasNext();

        if(has_next)
            //update the next_val and move the iterator to next position
            next_val = Iterator::next();

        //return the previously stored current next
        return x;
	}

	bool hasNext() const {
        //return current has_next value
	    return has_next;
	}
};

/*
   TC:  peek() = O(1); next() = O(1); hasNext() = O(1);
   SC:  O(1)
*/
