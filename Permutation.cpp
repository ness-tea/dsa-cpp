#include <iostream>
using namespace std;

bool IsPermutation(string input1, string input2)
{
    if (input1.length() != input2.length())
    {
        return false;
    }

    int strLength = input1.length();
    int j = strLength - 1;
    for (int i = 0; i < strLength / 2; i++)
    {
        if (input1[i] != input2[j])
        {
            cout << input1[i] << " is not equal to " << input2[j] << endl;
            return false;
        } 
        
        j--;
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