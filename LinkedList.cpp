// Linked List implementation (int type) 

#include "LinkedList.hpp"

int main()
{
    LinkedList<int> linkedList = LinkedList<int>();
    int numNodes = 10, data1 = 11, data2 = 31, data3 = 22;;

    for (int i = 0; i < numNodes; i++)
    {
        linkedList.CreateNode(i);
    }

    // Test cases
    linkedList.DisplayNodes();

    linkedList.InsertNodeAtStart(data1);
    linkedList.DisplayNodes();

    linkedList.InsertNodeAtEnd(data2);
    linkedList.DisplayNodes();  

    linkedList.InsertNodeAtPosition(data3, 3);
    linkedList.DisplayNodes();

    linkedList.DeleteNodeAtPosition(11);
    linkedList.DisplayNodes();

    linkedList.DeleteNodeAtStart();
    linkedList.DisplayNodes();

    linkedList.DeleteNodeAtEnd();
    linkedList.DisplayNodes();

    linkedList.DeleteNodeAtPosition(2);
    linkedList.DisplayNodes();

    linkedList.~LinkedList();

    return 0;
}