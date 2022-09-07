
#include <unordered_map>
#include <cstdlib>
#include <iostream>
using namespace std;

// Where input1 is one insert away from being input2
bool IsOneInsertAway(string input1, string input2)
{
    int index1 = 0;
    int index2 = 0;
    int insertCount = 0;;

    for (int i = 0; i < input1.length(); i++)
    {
        if (input1[index1] != input2[index2])
        {
            insertCount += 1;

            if (insertCount > 1)
            {
                return false;
            }

            index2 += 1;
        }
        else
        {
            index1 += 1;
            index2 += 1;   
        }
    }

    return true;
}

bool IsOneEditAway(string input1, string input2)
{
    int editCount = 0;

    for (int i = 0; i < input1.length(); i++)
    {
        if (input1[i] != input2[i])
        {
            editCount += 1;

            if (editCount > 1)
            {
                return false;
            }
        }
    }

    return true;
}

bool IsOneAway(string input1, string input2)
{
    bool result = false;
    int input1Len = input1.length(), input2Len = input2.length();
    int lenDiff = abs(input1Len - input2Len);

    if (lenDiff > 1)
    {
        result = false;
    }

    if (input1Len > input2Len)
    {
        result = IsOneInsertAway(input2, input1);
    }
    else if (input2Len > input1Len)
    {
        result = IsOneInsertAway(input1, input2);
    }
    else
    {
        result = IsOneEditAway(input1, input2);
    }

    return result;
}

int main()
{
    string input1, input2;
    cout << "Enter string 1: ";
    cin >> input1;

    cout << "Enter string 2: ";
    cin >> input2;

    cout << "Is string 2 one or zero edits away from string 1? --- " << IsOneAway(input1, input2) << endl;
    return 0;
}