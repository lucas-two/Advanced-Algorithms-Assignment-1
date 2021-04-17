/* Q4. Data structure for storing unordered lists */

#include <iostream>
#include <vector>
using namespace std;

class myStructure
{
private:
    int N, listSize;
    vector<int> lookup, list;

public:
    /* Constructor */
    myStructure(vector<int> inputList, int inputN)
    {
        // Set the N value
        N = inputN;
        // Set lookup map to size N + 1
        lookup.resize(N + 1);
        // Set the list to the input list
        list = inputList;
        // Set the list size
        listSize = list.size();
        // Initialise lookup map with -1s
        for (int i = 0; i <= N; i++)
        {
            lookup[i] = -1;
        }
        // Initialise the lookup map with values from list
        for (int i = 0; i < listSize; i++)
        {
            lookup[list[i]] = i;
        }
    }
    /* Add method */
    void add(int value)
    {
        cout << "-- ADD (" << value << ") --" << endl;
        // Check if value is between 0 and N
        if (value < 0 || value > N)
        {
            cout << "[!] VALUE OUT OF BOUNDS: (" << value << ") is not between 0 and " << N << "." << endl;
            return;
        }
        //Check value is not already in the list
        if (lookup[value] != -1)
        {
            cout << "[!] DUPLICATE: (" << value << ") is already a member of the list." << endl;
            return;
        }
        // Add value to the end of the list
        // O(1)
        list.insert(list.end(), value);
        // Add value to the lookup map
        // O(1)
        lookup[list[listSize]] = listSize;
        // Increment the list size
        listSize = listSize + 1;
    }
    /* Delete method */
    void remove(int value)
    {
        cout << "-- DELETE (" << value << ") --" << endl;
        // Make sure the value exists
        if (exists(value))
        {
            // O(1)
            // Swap element to delete with last element of list (in lookup map)
            int valueSwappingTo = list[listSize - 1];
            // Set the element we're deleting to the last element in the list
            list[lookup[value]] = list[lookup[valueSwappingTo]];
            // Update the index of the value we swapped to
            lookup[valueSwappingTo] = lookup[value];
            // Remove the index of the value we deleted (set to -1)
            lookup[value] = -1;
            // Remove the head of the array
            list.pop_back();
            // Decrease the list size
            listSize = listSize - 1;
        }
    }
    /* Exists method */
    bool exists(int value)
    {
        // O(1)
        if (lookup[value] != -1)
        {
            cout << "Value (" << value << ") exists." << endl;
            return true;
        }
        cout << "Value (" << value << ") does not exist." << endl;
        return false;
    }
    /* Iterate method */
    void iterate()
    {
        cout << "-- ITERATE LIST --" << endl;
        // O(N)
        // NOTE: I'm unsure how to make iterating O(1)
        cout << "list: {";
        for (int i = 0; i < listSize; i++)
        {
            if (i == listSize - 1)
            {
                cout << list[i];
            }
            else
            {
                cout << list[i] << ", ";
            }
        }
        cout << "}" << endl;
    }

    /* Clear method */
    void clear()
    {
        cout << "-- CLEAR LIST --" << endl;
        // Set the list values in our map to -1
        // O(K) where K is size of list
        for (int i = 0; i < listSize; i++)
        {
            lookup[list[i]] = -1;
        }
        // O(K) where k is size of the list
        list.clear();
        listSize = 0;
    }
    /* Printing out the list and lookup map*/
    void print()
    {
        // List printing
        cout << "list: {";
        for (int i = 0; i < listSize; i++)
        {
            if (i == listSize - 1)
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
        for (int i = 0; i <= N; i++)
        {
            if (i == N)
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
    myStructure a({1, 4, 3, 9}, 10);
    a.print();

    a.add(5);
    a.print();
    a.add(11);
    a.add(-3);
    a.add(5);
    a.add(8);
    a.print();

    a.remove(8);
    a.print();
    a.remove(8);
    a.remove(4);
    a.print();

    a.exists(8);
    a.exists(5);

    a.iterate();

    a.clear();

    a.print();
    return 0;
}