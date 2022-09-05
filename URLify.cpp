#include <iostream>
using namespace std;

string URLify(string input, int trueLength)
{
    char* result;
    int spacesCount = 0, finalLength;

    for (int i = 0; i < trueLength; i++)
    {
        if (input[i] == ' ')
        {
            spacesCount++;
        }
    }

    finalLength = trueLength + spacesCount * 2;
    result = new char[finalLength + 1];
    result[finalLength] = '\0';

    for (int i = trueLength - 1; i >= 0; i--)
    {
        if (input[i] == ' ')
        {
            result[finalLength - 1] = '0';
            result[finalLength - 2] = '2';
            result[finalLength - 3] = '%';
            finalLength -= 3;
        }
        else
        {
            result[finalLength - 1] = input[i];
            finalLength -= 1;
        }
    }

    return result;
}

int main()
{
    string input;
    cout << "Enter string to URLify: ";
    getline(cin, input);

    cout << "URLifying " << input << " ...........> " << URLify(input, input.length()) << endl;

    return 0;
}