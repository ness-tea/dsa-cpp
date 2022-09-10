#include <iostream>
#include <string>
using namespace std;

string CompressString(string& input)
{
    string comprString;
    int counter = 1;

    int i = 1;
    while (i <= input.size())
    {
        if ((i < input.size() && input[i] != input[i - 1]) || i >= input.size()) 
        {
            comprString.push_back(input[i-1]);
            comprString.push_back('0' + counter);

            counter = 1;
        }
        else
        {
            counter++;
        }

        i++;
    }

    if (comprString.size() >= input.size())
    {
        return input;
    }

    return comprString;
}

int main()
{
    string input;
    cout << "Enter string to compress: ";
    cin >> input;

    cout << "Compressed string is = " << CompressString(input) << endl;

    return 0;
}