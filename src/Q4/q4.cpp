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
    // Initialise lookup with -1s
    fill_n(lookup, N, -1);

public:
    /* Constructor */
    myStructure(vector<int> inputList)
    {
        // Set the list to the input list
        list = inputList;
        // Initialise the lookup map
        for (int i = 0; i < list.size(); i++)
        {
            lookup[list[i]] = i;
        }
    }
    /* Clear method */
    void clear()
    {
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
        cout << "list: {  ";
        for (int i = 0; i < list.size(); i++)
        {
            cout << list[i] << "  ";
        }
        cout << "}" << endl;
        // Map printing
        cout << "map: {  ";
        for (int i = 0; i < N; i++)
        {
            cout << lookup[i] << "  ";
        }
        cout << "}" << endl;
    }
};

int main()
{
    vector<int> valueList{1, 4, 2};
    myStructure obj1({1, 4, 2});

    // vector<int> valueList{1, 4, 2}; // valueList with values between 0->N with no duplicates
    int lookup[N]; // Maps between valueList items and its accosciated index

    // Initialise lookup with -1s
    fill_n(lookup, N, -1);

    // Load valueList into our lookup map
    for (int i = 0; i < valueList.size(); i++)
    {
        lookup[valueList[i]] = i;
    }
    printList(valueList, lookup);
    clear(valueList, lookup);
    printList(valueList, lookup);

    // clear(valueList, lookup);
}