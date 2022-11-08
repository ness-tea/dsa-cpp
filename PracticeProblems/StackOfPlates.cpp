#include "../Stack.hpp"
#include "../ArrayList.hpp"
#include <iostream>

using namespace std;

class SetOfStacks
{
public:
    ArrayList<Stack<int>> stacks;
    int stackCapacity = 0;

    SetOfStacks(int stackCapacity)
    {
        this->stackCapacity = stackCapacity;
        stacks = ArrayList<Stack<int>>();
    };

    void Push(int data)
    {

    }

    Node<int>* Pop()
    {
        return nullptr;
    }

    Node<int>* PopAt(int stackIndex)
    {
        return nullptr;
    }
};

int main()
{
    return 0;
}
