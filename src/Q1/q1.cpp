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
    float x, y;
};
struct line
{
    point p1, p2;
};
int compare(const void *, const void *);
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
    displayLines(lines);
    qsort(lines, LINE_COUNT, sizeof(line), compare);
    cout << "* QUICK SORT *" << endl;
    displayLines(lines);
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

void displayLines(line arr[])
{
    for (int i = 0; i < LINE_COUNT; i++)
    {
        cout << "Line #" << i << ":";
        cout << "(" << arr[i].p1.x << ", " << arr[i].p1.y << ")" << endl;
    }
}