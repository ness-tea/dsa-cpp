#include <unordered_map>
#include <iostream>
using namespace std;

bool noDataStruct = true;

bool IsUnique(string input)
{
    if (!noDataStruct)
    {
        std::unordered_map<char, int> charCountMap;

        for (int i = 0; i < input.length(); i++)
        {
            if (charCountMap.find(input[i]) == charCountMap.end())
            {
                charCountMap.insert({input[i], 1});
            }       
            else
            {
                charCountMap[input[i]] += 1;
            }

            if (charCountMap[input[i]] > 1)
            {
                return false;
            }
        }
    }
    else
    {
        for (int i = 0; i < input.length(); i++)
        {
            for (int j = i + 1; j < input.length(); j++)
            {
                if (input[i] == input[j])
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}

int main()
{
    string input1 = "coffee", input2 = "Oinkle";

    cout << "Is " << input1 << " a unique string? " << IsUnique(input1) << endl;
    cout << "Is " << input2 << " a unique string: " << IsUnique(input2) << endl;

    return 0;
}