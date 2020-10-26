#include <vector>

#include <algorithm>

#include <functional>

#include <iostream>

using namespace std;

 

int main()

{

    vector <int> vec1, vec2;

    vector <int>::iterator Iter1, Iter2;

    int i;

    for(i = 0; i <= 10; i++)

        vec1.push_back(i);

    cout<<"Operation: random_shuffle(vec1.begin(), vec1.end()).\n";

    random_shuffle(vec1.begin(), vec1.end());

    cout<<"Vector vec1 is data:\n";

    for(Iter1 = vec1.begin(); Iter1 != vec1.end(); Iter1++)

        cout<<*Iter1<<" ";

    cout<<endl;

    // make vec1 a heap with default less than ordering

    cout<<"\nOperation: make_heap(vec1.begin(), vec1.end()).\n";

    make_heap(vec1.begin(), vec1.end());

    cout<<"The heaped version of vector vec1 data:\n";

    for(Iter1 = vec1.begin(); Iter1 != vec1.end(); Iter1++)

        cout<<*Iter1<<" ";

    cout<<endl;

    // make vec1 a heap with greater than ordering

    cout<<"\nOperation: make_heap(vec1.begin(), vec1.end(), greater<int>()).\n";

    make_heap(vec1.begin(), vec1.end(), greater<int>());


 
    cout<<"The greater-than heaped version of vec1 data:\n";


 
    for(Iter1 = vec1.begin(); Iter1 != vec1.end(); Iter1++)

        cout<<*Iter1<<" ";

    cout<<endl;

    return 0;

}

 
