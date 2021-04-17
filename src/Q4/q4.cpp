/* Q4. Data structure for storing unordered lists */

#include <iostream>
#include <vector>
using namespace std;
#define N 10 // Maximum integer

void printList(vector<int>, int[N]);
void clear(vector<int>, int[N]);

class myStructure
{
private:
    int const NN = 10;
    int lookup[N];
    vector<int> list;

public:
    /* Constructor */
    myStructure(vector<int> inputList)
    {
        // Set the list to the input list
        list = inputList;
        // Initialise lookup map with -1s
        fill_n(lookup, N, -1);
        // Initialise the lookup map
        for (int i = 0; i < list.size(); i++)
        {
            lookup[list[i]] = i;
        }
    }
    /* Clear method */
    void clear()
    {
        cout << "-- CLEAR LIST --" << endl;
        // Set the list values in our map to -1
        // O(K) where K is size of list
        for (int i = 0; i < list.size(); i++)
        {
            lookup[list[i]] = -1;
        }
        // O(K) where k is size of the list
        list.clear();
    }
    /* Printing out the list and lookup map*/
    void print()
    {
        // List printing
        cout << "list: {";
        for (int i = 0; i < list.size(); i++)
        {
            if (i == list.size() - 1)
            {
                cout << list[i];
            }
            else
            {
                cout << list[i] << ", ";
            }
        }
        cout << "}" << endl;
        // Lookup map printing
        cout << "lookup: {";
        for (int i = 0; i < N; i++)
        {
            if (i == N - 1)
            {
                cout << lookup[i];
            }
            else
            {
                cout << lookup[i] << ", ";
            }
        }
        cout << "}" << endl;
    }
};

int main()
{
    myStructure obj1({1, 4, 2});
    obj1.print();
    obj1.clear();
    obj1.print();
    return 0;
}