/* Q4. Data structure for storing unordered lists */

#include <iostream>
#include <vector>
using namespace std;

// class Map //O(1)
// {
//     const

//     // private:
//     //     int data[]; // N + 1 size

//     //     int hash(int key)
//     //     {
//     //         int index = 0;
//     //         return index;
//     //     }

//     // Can store integers in the range 0 - > N (n is the upper bound)
//     // Duplicate integers not allowed
//     // Add, delete, test being in the list, iterating through the list
//     // Clearing the list
// };

// struct map
// {
//     int value;
//     int index;
// };

int main()
{
    const int N = 10;
    // Our list of values
    vector<int> arr{1, 4, 2};

    // Load the values into a hash table
    int lookup[N];
    // Fill the lookup with -1 values
    fill_n(lookup, N, -1);

    // Loading the array into our map
    for (int i = 0; i < arr.size(); i++)
    {
        lookup[arr[i]] = i;
    }

    for (int i = 0; i < N; i++)
    {
        if (lookup[i] != -1)
        {
            cout << i << " : " << lookup[i] << endl;
        }
    }
}