/* Q5. Ladder-gram (Word Ladder) problem */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// void printQueue(vector<string> q);

main()
{
    string sourceWord = "toolbox";
    string endWord = "topcoat";

    // Input the dictionary
    vector<string> dict;
    ifstream inputFile("dictionary.txt");
    if (inputFile.fail())
    {
        cout << "[!] COULD NOT READ FILE" << endl;
    }
    else
    {
        string s;
        while (getline(inputFile, s))
        {
            dict.insert(dict.end(), s);
        }
        inputFile.close();
    }

    vector<string> wordList; // All words from dict that are equal length to source/end word

    // Check source and end words are same length
    if (sourceWord.length() != endWord.length())
    {
        cout << "[!] Source and end word must have same length." << endl;
        return -1;
    }

    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    bool endWordExists = false; // Checking the end word exists

    // Filter for words of correct size
    int wordLength = sourceWord.length();
    for (int i = 0; i < dict.size(); i++)
    {
        if (dict[i].length() == wordLength)
        {
            // Make sure the endWord actually exists
            if (dict[i] == endWord)
            {
                endWordExists = true;
            }
            wordList.insert(wordList.end(), dict[i]);
        }
    }
    // End if there's no end word
    if (!endWordExists)
    {
        cout << "[!] End word `" << endWord << "` does not exist." << endl;
        return -1;
    }
    vector<string> queue = {sourceWord};
    int steps = 0; // Number of word changes between each word
    int toExploreCurrent = 1;
    int toExploreNext = 0;
    while (queue.size() != 0)
    {
        // Pop the head of the queue
        string word = queue[0];
        queue.erase(queue.begin());
        for (int i = 0; i < word.length(); i++)
        {
            for (int j = 0; j < 26; j++)
            {
                // Skip the letter already in the word
                if (letters[j] == word[i])
                {
                    continue;
                }
                // Create new word with this letter change
                string newWord = word;
                newWord[i] = letters[j];

                // Are there any matching words in the word list?
                for (int k = 0; k < wordList.size(); k++)
                {
                    // If we have a match
                    if (newWord == wordList[k])
                    {
                        // If the word is our end word
                        if (newWord == endWord)
                        {
                            // Return the amount of steps taken to get to thes word
                            cout << "End word found in " << steps + 1 << " steps." << endl;
                            return steps + 1;
                        }
                        // Otherwise add the new word to the queue
                        else
                        {
                            // Increment how many words we need to process on the next level
                            toExploreNext += 1;
                            queue.insert(queue.end(), newWord);
                            // Remove the new word from the word list
                            wordList.erase(wordList.begin() + k);
                        }
                    }
                }
            }
        }
        // Word has been processed
        toExploreCurrent -= 1;
        // If we've processed all the words on this level
        if (toExploreCurrent == 0)
        {
            // We're onto words a step forward
            steps += 1;
            // Update the current to explore with the found next to explore
            toExploreCurrent = toExploreNext;
            // Reset the to explore next
            toExploreNext = 0;
        }
    }
    cout << "Cannot reach end word." << endl;
    return -1;
}

// void printQueue(vector<string> q)
// {
//     cout << "QUEUE: " << endl;
//     for (int i = 0; i < q.size(); i++)
//     {
//         cout << "[" << i << "]: " << q[i] << endl;
//     }
//     cout << endl;
// }