#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void findSequence(vector<string>);

int main()
{
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

    // Sorting the words into lists of their associated lengths
    // NOTE: Using a 2D array would have been much cleaner, but I was having some issues
    //       getting it working that I didn't have enough time to resolve.
    vector<string> wordsLengthFour;
    vector<string> wordsLengthFive;
    vector<string> wordsLengthSix;
    vector<string> wordsLengthSeven;
    vector<string> wordsLengthEight;
    vector<string> wordsLengthNine;
    vector<string> wordsLengthTen;
    vector<string> wordsLengthEleven;
    vector<string> wordsLengthTwelve;
    vector<string> wordsLengthThirteen;
    vector<string> wordsLengthFourteen;
    vector<string> wordsLengthFifteen;

    for (int i = 0; i < dict.size(); i++)
    {
        switch (dict[i].length())
        {
        case 4:
            wordsLengthFour.insert(wordsLengthFour.end(), dict[i]);
            break;
        case 5:
            wordsLengthFive.insert(wordsLengthFive.end(), dict[i]);
            break;
        case 6:
            wordsLengthSix.insert(wordsLengthSix.end(), dict[i]);
            break;
        case 7:
            wordsLengthSeven.insert(wordsLengthSeven.end(), dict[i]);
            break;
        case 8:
            wordsLengthEight.insert(wordsLengthEight.end(), dict[i]);
            break;
        case 9:
            wordsLengthNine.insert(wordsLengthNine.end(), dict[i]);
            break;
        case 10:
            wordsLengthTen.insert(wordsLengthTen.end(), dict[i]);
            break;
        case 11:
            wordsLengthEleven.insert(wordsLengthEleven.end(), dict[i]);
            break;
        case 12:
            wordsLengthTwelve.insert(wordsLengthTwelve.end(), dict[i]);
            break;
        case 13:
            wordsLengthThirteen.insert(wordsLengthThirteen.end(), dict[i]);
            break;
        case 14:
            wordsLengthFourteen.insert(wordsLengthFourteen.end(), dict[i]);
            break;
        case 15:
            wordsLengthFifteen.insert(wordsLengthFifteen.end(), dict[i]);
            break;
        }
    }
    // Displaying amount of sequences
    cout << "[Word Length 4]: ";
    findSequence(wordsLengthFour);
    cout << "[Word Length 5]: ";
    findSequence(wordsLengthFive);
    cout << "[Word Length 6]: ";
    findSequence(wordsLengthSix);
    cout << "[Word Length 7]: ";
    findSequence(wordsLengthSeven);
    cout << "[Word Length 8]: ";
    findSequence(wordsLengthEight);
    cout << "[Word Length 9]: ";
    findSequence(wordsLengthNine);
    cout << "[Word Length 10]: ";
    findSequence(wordsLengthTen);
    cout << "[Word Length 11]: ";
    findSequence(wordsLengthEleven);
    cout << "[Word Length 12]: ";
    findSequence(wordsLengthTwelve);
    cout << "[Word Length 13]: ";
    findSequence(wordsLengthThirteen);
    cout << "[Word Length 14]: ";
    findSequence(wordsLengthFourteen);
    cout << "[Word Length 15]: ";
    findSequence(wordsLengthFifteen);
}

void findSequence(vector<string> wordsLength)
{
    // Sequence Queue initialised with the first word in the list
    vector<string> sequenceQueue = {wordsLength[0]};
    // Remove first word from the list
    wordsLength.erase(wordsLength.begin());
    int sequenceCount = 0;
    // While we have words...
    while (1)
    {
        // Look at the current word in the sequence
        string parentWord = sequenceQueue[sequenceCount];
        int nextSequenceFound = false;

        // For each word...
        for (int i = 0; i < wordsLength.size(); i++)
        {
            // Check if it's 2nd and 3rd letter equal the parent word's 3rd last and 2nd last letters
            if (wordsLength[i][1] == parentWord[parentWord.length() - 3] && wordsLength[i][2] == parentWord[parentWord.length() - 2])
            {
                // Increase the number of sequences
                sequenceCount += 1;
                // Add the word to the sequence
                sequenceQueue.insert(sequenceQueue.end(), wordsLength[i]);
                // Remove that word from the list so we don't search it again
                wordsLength.erase(wordsLength.begin() + i);
                // Mark that a sequence was found
                nextSequenceFound = true;
                break;
            }
        }
        if (!nextSequenceFound)
        {
            cout << sequenceCount + 1 << " sequences" << endl;
            break;
        }
    }
}