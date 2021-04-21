/* Q5. Ladder-gram (Word Ladder) problem */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

main()
{
    vector<string> dict = {"hot",
                           "dog",
                           "dot",
                           "lot",
                           "log",
                           "cog",
                           "dress",
                           "impress",
                           "me"}; // All our words
    vector<string> wordList;      // All words from dict that are equal length to source/end word

    string sourceWord = "hit"; // The word we're going from
    string endWord = "cog";    // The word we're going to

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
        exit(1);
    }

    for (int i = 0; i < wordList.size(); i++)
    {
        cout << wordList[i] << "  ";
    }
    vector<string> queue = {sourceWord};
    int steps = 0;        // Number of word changes between each word
    int wordsAtLevel = 0; // Amount of words at a given level

    steps += 1;
    wordsAtLevel += 1;

    while (queue.size() != 0)
    {
        // Pop the head of the queue
        string word = queue[queue.size() - 1];
        queue.pop_back();

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
                        cout << "[match found]: " << wordList[k] << endl;
                        // If the word is our end word
                        if (newWord == endWord)
                        {
                            // Return the amount of steps taken to get to thes word
                            return steps;
                        }
                        // Otherwise add the new word to the queue
                        else
                        {
                            cout << "-----------------" << endl;
                            queue.insert(queue.end(), newWord);

                            for (int i = 0; i < wordList.size(); i++)
                            {
                                cout << wordList[i] << "  ";
                            }
                            cout << endl;

                            cout << "Removing" << wordList[k] << endl;
                            // Remove the new word from the word list
                            wordList.erase(wordList.begin() + k);

                            for (int i = 0; i < wordList.size(); i++)
                            {
                                cout << wordList[i] << "  ";
                            }
                            cout << endl;
                            cout << "-----------------" << endl;
                        }
                    }
                }
            }
        }
    }

    // Using BFS
    // https://www.youtube.com/watch?v=ZVJ3asMoZ18
}