// size_capacity.cpp
// Vector size versus capacity

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size() 
         << " capacity: " << vec.capacity() << endl;

    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size() 
             << " capacity: " << vec.capacity() << endl;
    }

    return 0;
}

/*2.1  The size of the vector is defined as the number of elements currently in the vector where the 
capacity of the vector is the amount of space the vector is currently using in memory, the size of the vector 
is always equal to or smaller than the capacity of the vector because the vector doubles the capacity 
every time more space is required to store more elements this is why vectors are said to be able to resize dynamically.
*/