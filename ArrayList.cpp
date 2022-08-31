// ArrayList implementation

#include <iostream>
using namespace std;

#define MAX_SIZE_DEFAULT 2

class ArrayList
{
private:
    int m_length = MAX_SIZE_DEFAULT;
    int* m_pArray = nullptr;

    void Resize()
    {
        int* oldArray = m_pArray;
        int* newArray = new int[m_length * 2];

        for (int i = 0; i < m_length; i++)
        {
            newArray[i] = oldArray[i];
        }

        delete oldArray;
        m_pArray = newArray;
    }

public:
    ArrayList()
    {
        m_pArray = new int[MAX_SIZE_DEFAULT];
    };

    ArrayList(int size) : m_length(size)
    {
        m_pArray = new int[size];
    }

    ~ArrayList(){};

    void Add(int entry)
    {
        if ()
    }
};

int main()
{
    ArrayList arrayList = ArrayList();



    return 0;
}