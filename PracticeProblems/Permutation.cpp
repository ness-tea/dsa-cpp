#include <unordered_map>
#include <iostream>
using namespace std;

bool IsPermutation(string input1, string input2)
{
    if (input1.length() != input2.length())
    {
        return false;
    }

    unordered_map<char, int> charCount;
    int strLength = input1.length();

    for (int i = 0; i < strLength; i++)
    {
        if (charCount.find(input1[i]) == charCount.end())
        {
            charCount.insert({input1[i], 1});
        }
        else
        {
            charCount[input1[i]] += 1;
        }
    }

    for (int i = 0; i < strLength; i++)
    {
        if (charCount.find(input2[i]) != charCount.end())
        {
            charCount[input2[i]] -= 1;
            if (charCount[input2[i]] < 0)
            {
                return false;
            }
        }
    }    

    return true;
}

int main()
{
    string input1, input2;

    cout << "Enter input1 value: "; 
    getline(cin, input1);

    cout << "Enter input1 value: ";
    getline(cin, input2);

    cout << "Is " << input2 << " a permutation of " << input1 << "? " << IsPermutation(input1, input2) << endl;
    return 0;
}