#include <unordered_map>
#include <iostream>
using namespace std;

bool useBitVector = true;

bool IsPermutatedPalindrome2(string input)
{
    int charBits = 0;
    int strLength = input.length();

    for (int i = 0; i < strLength; i++)
    {
        int charValue = int(input[i]) - int('a');

        charBits ^= 1 << charValue;
    }

    int oddCharCount = 0;

    for (int i = 0; i < (sizeof(int) * 8); i++)
    {
        if ((charBits & (1 << i)) >= 1)
        {
            oddCharCount += 1;

            if (oddCharCount > 1)
            {
                return false;
            }
        }
    }

    return true;
}

bool IsPermutatedPalindrome(string input)
{
    unordered_map<char, int> charCount;
    int strLength = input.length();

    for (int i = 0; i < strLength; i++)
    {
        if (charCount.find(input[i]) == charCount.end())
        {
            charCount.insert({input[i], 1});
        }
        else
        {
            charCount[input[i]] += 1;
        }
    }

    int oddCharCount = 0;
    for (auto it = charCount.begin(); it != charCount.end(); it++)
    {
        if (it->second % 2 == 1)
        {   
            oddCharCount += 1;

            if (oddCharCount > 1)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;
    
    bool isPermutatedPalindrome = useBitVector ? IsPermutatedPalindrome2(input) : IsPermutatedPalindrome(input);
    cout << "Is " << input << " a permutated palindrome? --- " << isPermutatedPalindrome << endl;

    return 0;
}