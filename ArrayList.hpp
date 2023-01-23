// ArrayList implementation

#include <iostream>
using namespace std;

#define MAX_SIZE_DEFAULT 2

template <typename T>
class ArrayList
{
private:
    int m_length = MAX_SIZE_DEFAULT;
    int curIndex = 0;
    T* m_pArray = nullptr;

    void Resize()
    {
        m_length *= 2;
        T* oldArray = m_pArray;
        T* newArray = new T[m_length];

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
        m_pArray = new T[MAX_SIZE_DEFAULT];
    };

    ArrayList(int size) : m_length(size)
    {
        m_pArray = new T[size];
    }

    ~ArrayList(){};

    int GetCurrentIndex()
    {
        return curIndex;
    }   

    T GetEntry(int index)
    {
        return m_pArray[index];
    }

    void Add(T entry)
    {
        if (curIndex == m_length)
        {
            Resize();
        }

        m_pArray[curIndex] = entry;
        curIndex++;
    }

    void Remove()
    {
        m_pArray[curIndex] = 0;
        curIndex--;
    }
};