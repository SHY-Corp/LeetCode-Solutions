// Problem - 855. Exam Room

/*
Problem statement -
In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.
When a student enters the room, they must sit in the seat that maximizes the distance to the closest person. 
If there are multiple such seats, they sit in the seat with the lowest number.
(Also, if no one is in the room, then the student sits at seat number 0.)
Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() returning an int representing what seat the student sat in,
and ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.
It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.
*/

/*
Constraints - 
1. 1 <= N <= 10^9
2. ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times across all test cases.
3. Calls to ExamRoom.leave(p) are guaranteed to have a student currently sitting in seat number p.
*/

/*
Example -
Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
Output: [null,0,9,4,2,null,5]
Explanation:
ExamRoom(10) -> null
seat() -> 0, no one is in the room, then the student sits at seat number 0.
seat() -> 9, the student sits at the last seat number 9.
seat() -> 4, the student sits at the last seat number 4.
seat() -> 2, the student sits at the last seat number 2.
leave(4) -> null
seat() -> 5, the student sits at the last seat number 5.
*/

//Solution
/*
Idea -
Use a list L to record the index of seats where people sit.

seat():
1. find the biggest distance at the start, at the end and in the middle.
2. insert index of seat
3. return index

leave(p): pop out p

Time Complexity:
O(N) for seat() and leave()
*/

class ExamRoom {
public:
    int n;
    vector<int> L;
    ExamRoom(int N) {
        n = N;
    }
    
    int seat() {
        if (L.size() == 0) {
            L.push_back(0);
            return 0;
        }
        int d = max(L[0], n - 1 - L[L.size() - 1]);
        for (int i = 0; i < L.size() - 1; ++i) d = max(d, (L[i + 1] - L[i]) / 2);
        if (L[0] == d) {
            L.insert(L.begin(), 0);
            return 0;
        }
        for (int i = 0; i < L.size() - 1; ++i)
            if ((L[i + 1] - L[i]) / 2 == d) {
                L.insert(L.begin() + i + 1, (L[i + 1] + L[i]) / 2);
                return L[i + 1];
            }
        L.push_back(n - 1);
        return n - 1;
    }
    
    void leave(int p) {
        for (int i = 0; i < L.size(); ++i) if (L[i] == p) L.erase(L.begin() + i);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */