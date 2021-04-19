/* Q1. Sweep Line Algorithm */
// PROBLEM: Orthogonal Line Intersection Search
// Brute force is O(N^2) but we must design O(nlogn)
// We have N lines, they are only vertical or horizontal.
// Derive the efficency of our algorithm.
#include <iostream>
using namespace std;
#define LINE_COUNT 8

struct point
{
    int x, y;
};
struct line
{
    point p1, p2;
};

class binarySearchTree
{
private:
    struct node
    {
        line data;
        node *left;
        node *right;
    };
    node *rootPointer; // Our root node

    /* Check if the tree is empty */
    bool treeIsEmpty()
    {
        // Tree will be empty if the root node is NULL
        if (rootPointer == NULL)
        {
            return true;
        }
        return false;
    }

    /* Check if a node is not null */
    bool nodeExists(node *nodePointer)
    {
        // The node exists if it dosen't equal NULL
        if (nodePointer != NULL)
        {
            return true;
        }
        return false;
    }

    /* Create a new node */
    node *createNewNode(line data)
    {
        // Allocate memory for a new node
        node *newNode = new node();
        // Set it's data to the input data
        newNode->data = data;
        // Set it's left and right child as null
        newNode->left = NULL;
        newNode->right = NULL;
        // Return a pointer to the new node
        return newNode;
    }

    void insertWithRecursion(line data, node *nodePointer)
    {
        // If the tree is empty
        if (treeIsEmpty())
        {
            // Set the passed value as root
            rootPointer = createNewNode(data);
            return;
        }
        // If the value should be on the LEFT of the node
        // we're looking at:
        else if (data.p1.y < nodePointer->data.p1.y)
        {
            // If there's something already connected to
            // the left of the node:
            if (nodeExists(nodePointer->left))
            {
                // Recursively go to the pointer's left child
                // and use that as the node we're comparing against
                insertWithRecursion(data, nodePointer->left);
            }
            // If the left of the node is free:
            else
            {
                // Create the new node for this spot
                nodePointer->left = createNewNode(data);
            }
        }
        // If the value should be on the RIGHT of the node
        // we're looking at:
        else if (data.p1.y > nodePointer->data.p1.y)
        {
            // If there's something already connected to
            // the right of the node:
            if (nodeExists(nodePointer))
            {
                // Recursively go to the pointer's right child
                // and use that as the node we're comparing against
                insertWithRecursion(data, nodePointer->right);
            }
            // If the right of the node is free:
            else
            {
                // Create the new node for this spot
                nodePointer->right = createNewNode(data);
            }
        }
        // If the values are equal:
        else
        {
            cout << "[!] DUPLICATE VALUE: Not accepting lines that have equal Y axis values." << endl;
        }
    }
    void printTreeWithRecursion(node *nodePointer)
    {
        // If the tree is not empty
        if (!treeIsEmpty())
        {
            // If it's possible to go LEFT:
            if (nodeExists(nodePointer->left))
            {
                // Print the left node's children (recursively)
                printTreeWithRecursion(nodePointer->left);
            }
            // Output the value
            cout << nodePointer->data.p1.y << " ";
            // If it's possible to go RIGHT:
            if (nodeExists(nodePointer->right))
            {
                // Print the right node's children (recursively)
                printTreeWithRecursion(nodePointer->right);
            }
        }
        // Otherwise, if the tree is empty:
        else
        {
            cout << "Tree is empty." << endl;
        }
    }

    node *findNodeWithRecursion(line data, node *nodePointer)
    {
        // If our node pointer is pointing to something:
        if (nodeExists(nodePointer))
        {
            // If the values are equal:
            if (nodePointer->data.p1.y == data.p1.y)
            {
                // Return this as our node
                return nodePointer;
            }
            // Otherwise, recursively look for it...
            else
            {
                // In the LEFT (if the value is less than)
                if (data.p1.y < nodePointer->data.p1.y)
                {
                    return findNodeWithRecursion(data, nodePointer->left);
                }
                // In the RIGHT (if the value is greater than)
                else
                {
                    return findNodeWithRecursion(data, nodePointer->right);
                }
            }
        }
        // If our node pointer isn't pointing to anything -> NULL
        else
        {
            return NULL;
        }
    }

    /* Locates a node in the tree */
    void findNode(line data)
    {
        // Finds a node in the tree using a recursive method:
        findNodeWithRecursion(data, rootPointer);
    }

    void removeWithRecursion(line data, node *nodePointer)
    {
        if (!treeIsEmpty())
        {
            // If the root node matches what we want to remove:
            if (data.p1.y == rootPointer->data.p1.y)
            {
                // REMOVE ROOT
            }
            else
            {
                // If the value should be to the left:
                if (data.p1.y < nodePointer->data.p1.y)
                {
                    // And a left node exists
                    if (nodeExists(nodePointer->left))
                    {
                        // If we've found a match:
                        if (data.p1.y == nodePointer->left->data.p1.y)
                        {
                            // REMOVE MATCH (nodePointer, nodePointer->left, true)
                        }
                        // Otherwise, go and check the node's left children:
                        else
                        {
                            removeWithRecursion(data, nodePointer->left);
                        }
                    }
                }
                // If the value should be to the right
                else if (data.p1.y > nodePointer->data.p1.y)
                {
                    // And a right node exists
                    if (nodeExists(nodePointer->right))
                    {
                        // If we've found a match:
                        if (data.p1.y == nodePointer->right->data.p1.y)
                        {
                            // REMOVE MATCH (nodePointer, nodePointer->right, false)
                        }
                        // Otherwise, go and check the node's right children:
                        else
                        {
                            removeWithRecursion(data, nodePointer->right);
                        }
                    }
                }
                // Otherwise, if we couldn't find the value:
                else
                {
                    cout << "[!] VALUE TO REMOVE NOT FOUND: Could not find " << data.p1.y << " in the tree." << endl;
                }
            }
        }
        // Otherwise, if the tree is empty:
        else
        {
            cout << "Tree is empty." << endl;
        }
    }

    void chooseSmallestNode()
    {
        chooseSmallestNodeWithRecursion(rootPointer);
    }

    line chooseSmallestNodeWithRecursion(node *nodePointer)
    {
        if (treeIsEmpty())
        {
            cout << "Tree is empty." << endl;
            return (line){};
        }
        else
        {
            if (nodeExists(nodePointer->left))
            {
                return chooseSmallestNodeWithRecursion(nodePointer->left);
            }
            else
            {
                return nodePointer->data;
            }
        }
    }

    void removeFoundRoot()
    {
        if (!treeIsEmpty())
        {
            node *rootPointerReference = rootPointer;
            line rootPointerData = rootPointer->data;
            line smallestInRightSubTree;

            // If the root node has no children:
            if (!nodeExists(rootPointer->left) && !nodeExists(rootPointer->right))
            {
                // Set the root node to null
                rootPointer = NULL;
                // Deallocate the pointer reference
                delete rootPointerReference;
            }
            // If the root node has 1 child:
            // -> And it's on the right
            else if (!nodeExists(rootPointer->left) && nodeExists(rootPointer->right))
            {
                // Set the root node to it's right child
                rootPointer = rootPointer->right;
                // Remove the right child node
                rootPointerReference->right = NULL;
                // Deallocate the pointer reference
                delete rootPointerReference;
            }
            // -> And it's on the left
            else if (nodeExists(rootPointer->left) && !nodeExists(rootPointer->right))
            {
                // Set the root node to it's right child
                rootPointer = rootPointer->left;
                // Remove the right child node
                rootPointerReference->left = NULL;
                // Deallocate the pointer reference
                delete rootPointerReference;
            }
            // If the root has 2 children
            else
            {
            }
        }
        else
        {
            cout << "[!] ROOT CANNOT BE REMOVED: Tree is empty." << endl;
        }

    public:
        binarySearchTree()
        {
            // Initialise tree as empty
            rootPointer = NULL;
        }

        /* Insert a node into the tree */
        void insert(line data)
        {
            // Inserting the node using a recursive method:
            insertWithRecursion(data, rootPointer);
        }

        /* Remove a node from the tree */
        void remove(line data)
        {
            // Removing the node using a recursive method:
            removeWithRecursion(data, rootPointer);
        }

        /* Printing the tree (in acending order) */
        void printTree()
        {
            // Printing the tree using a recursive method:
            printTreeWithRecursion(rootPointer);
        }
    };

    int compare(const void *, const void *);
    bool lineIsVerticle(line);
    void displayLines(line[]);

    main()
    {
        // Initialise lines
        line lines[LINE_COUNT];
        // L1
        lines[0].p1.x = 1;
        lines[0].p1.y = 1;
        lines[0].p2.x = 7;
        lines[0].p2.y = 1;
        // L2
        lines[1].p1.x = 2;
        lines[1].p1.y = 3;
        lines[1].p2.x = 4;
        lines[1].p2.y = 3;
        // L3
        lines[2].p1.x = 3;
        lines[2].p1.y = 4;
        lines[2].p2.x = 8;
        lines[2].p2.y = 4;
        // L4
        lines[3].p1.x = 5;
        lines[3].p1.y = 6;
        lines[3].p2.x = 5;
        lines[3].p2.y = 3;
        // L5
        lines[4].p1.x = 6;
        lines[4].p1.y = 2;
        lines[4].p2.x = 6;
        lines[4].p2.y = 0;
        // L6
        lines[5].p1.x = 7;
        lines[5].p1.y = 5;
        lines[5].p2.x = 7;
        lines[5].p2.y = 3;
        // L7
        lines[6].p1.x = 10;
        lines[6].p1.y = 6;
        lines[6].p2.x = 10;
        lines[6].p2.y = 1;
        // L8
        lines[7].p1.x = 11;
        lines[7].p1.y = 3;
        lines[7].p2.x = 12;
        lines[7].p2.y = 3;

        // 1. Sort the lines based on the X-coordinate
        // N log N (apparently)
        displayLines(lines);
        qsort(lines, LINE_COUNT, sizeof(line), compare);
        cout << "* QUICK SORT *" << endl;
        displayLines(lines);

        // 2. Binary search tree
        binarySearchTree bst;
        bst.printTree();

        for (int i = 0; i < LINE_COUNT; i++)
        {
            bst.insert(lines[i]);
            if (lineIsVerticle(lines[i]))
            {
                cout << "Verticle" << endl;
            }
            else
            {
                cout << "Horizontal" << endl;
            }
        }
        bst.printTree();
    }

    int compare(const void *a, const void *b)
    {
        const line *line1 = (line *)a;
        const line *line2 = (line *)b;

        if (line1->p1.x > line2->p1.x)
        {
            return 1;
        }
        else if (line1->p1.x < line2->p1.x)
        {
            return -1;
        }
        return 0;
    };

    bool lineIsVerticle(line a)
    /* Tell us if the line his Horizontal or Verticle */
    {
        // If the line has same X-axis -> Verticle
        if (a.p1.x == a.p2.x)
        {
            return true;
        }
        // Otherwise -> Horizontal
        return false;
    }

    void displayLines(line arr[])
    {
        for (int i = 0; i < LINE_COUNT; i++)
        {
            cout << "Line #" << i << ":";
            cout << "(" << arr[i].p1.x << ", " << arr[i].p1.y << ")" << endl;
        }
    }