// ArrayList implementation

#include <iostream>
using namespace std;

#define MAX_SIZE_DEFAULT 2

class ArrayList
{
private:
    int m_length = MAX_SIZE_DEFAULT;
    int curIndex = 0;
    int* m_pArray = nullptr;

    void Resize()
    {
        m_length *= 2;
        int* oldArray = m_pArray;
        int* newArray = new int[m_length];

        for (int i = 0; i < m_length; i++)
        {
            newArray[i] = oldArray[i];
        }

        delete oldArray;
        m_pArray = newArray;

        cout << "Resized array to size " << m_length << endl;
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
        if (curIndex == m_length)
        {
            Resize();
        }

        m_pArray[curIndex] = entry;
        curIndex++;
    }
};

int main()
{
    ArrayList arrayList = ArrayList();

    for (int i = 0; i < 50; i++)
    {
        arrayList.Add(i);
        cout << i << endl;
    }

    return 0;
}