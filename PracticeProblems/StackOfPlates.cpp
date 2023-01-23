#include "../Stack.hpp"
#include "../ArrayList.hpp"
#include <iostream>

using namespace std;

class SetOfStacks
{
public:
    ArrayList<Stack<int>> stacks;
    int stackCapacity = 0;
    int numStacks = 1;
    int stackNodeCounter = 0;

    SetOfStacks(int stackCapacity)
    {
        this->stackCapacity = stackCapacity;
        stacks = ArrayList<Stack<int>>();
    };

    Stack<int> GetLastStack()
    {
        return stacks.GetEntry(numStacks - 1);
    }

    void Push(int data)
    {
        Stack<int> curStack = GetLastStack();

        if (stackNodeCounter < stackCapacity)
        {   
            curStack.Push(data);
            stackNodeCounter++;
        }
        else
        {
            Stack<int> newStack = Stack<int>(data);
            stacks.Add(newStack);
            stackNodeCounter = 0;
            numStacks++;
        }
    }

    Node<int>* Pop()
    {
        Stack<int> curStack = GetLastStack();
        Node<int>* node = curStack.Pop();

        if (curStack.IsEmpty())
        {
            stacks.Remove();
            numStacks--;
        }

        return node;
    }

    Node<int>* PopAt(int stackIndex)
    {
        return nullptr;
    }
};

int main()
{
    SetOfStacks stack = SetOfStacks(5);

    cout << "current stack size: " << stack.numStacks << endl;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    //stack.Push(6);

    cout << "current stack size: " << stack.numStacks << endl;
}
