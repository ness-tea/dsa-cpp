#include <iostream>
using namespace std;

// Is s1 a substring of s2
bool IsSubstring(string s1, string s2)
{
    if (s2.find(s1) != string::npos)
    {
        return true;
    }

    return false;
}

bool IsStringRotation(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }

    s1.append(s1);

    return IsSubstring(s2, s1);
}

int main()
{
    string s1, s2;
    cout << "Enter substring: ";
    cin >> s1;
    cout << "Enter string to check substring for: ";
    cin >> s2;
    cout << "Is " << s1 << " a substring of " << s2 << "? " << IsStringRotation(s1, s2) << endl;

    return 0;
}