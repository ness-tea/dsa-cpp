//  Linked List Implementation                                   

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

class LinkedList
{
private:
  Node* m_head;
  Node* m_tail;
public:
  LinkedList()
  {
    m_head = nullptr;
    m_tail = nullptr;
  }

  ~LinkedList()
  {
  }

  void CreateNode(int data)
  {
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;

    if (m_head != nullptr)
    {
      m_tail->next = temp;
      m_tail = temp;
    }
    else
    {
      m_head = temp;
      m_tail = temp;
      temp = nullptr;
    }
  }

  void Display()
  {
    Node* temp = new Node;
    temp = m_head;

    while (temp != nullptr)
    {
      cout << temp->data << "\t";
      temp = temp->next;
    }
  }

  void InsertNodeAtStart(int data)
  {
    Node* temp = new Node;
    temp->data = data;
    temp->next = m_head;
    m_head = temp;
  }

  void InsertNodeAtEnd(int data)
  {
    Node* temp = new Node;
    temp->data = data;
    m_tail->next = temp;
    m_tail = temp;
  }

  void InsertNodeAtPosition(int data, int position)
  {
    Node* temp = new Node;
    Node* cur = m_head;
    Node* pre = nullptr;

    for (int i = 0; i < position; i++)
    {
      pre = cur;
      cur = cur->next;
    }

    temp->data = data;
    pre->next = temp;
    temp->next = cur;
  }

  void DeleteNodeAtStart()
  {
    Node* temp = new Node;
    temp = m_head;
    m_head = m_head->next;
    delete temp;
  }

  void DeleteNodeAtEnd()
  {
    Node* cur = new Node;
    Node* prev = new Node;
    cur = m_head;

    while (cur->next != nullptr)
    {
      prev = cur;
      cur = cur->next;
    }

    prev->next = nullptr;
    m_tail = prev;
    delete cur;
  }

  void DeleteNodeAtPosition(int position)
  {
    Node* cur = new Node;
    Node* prev = new Node;

    for (int i = 0; i < position-1; i++)
    {
      prev = cur;
      cur = cur->next;
    }

    prev->next = cur->next;
    delete cur;
  }

  int main()
  {
    LinkedList chain = LinkedList();

    for (int i = 0; i < 10; i++)
    {
      CreateNode(i);
      cout << m_tail->data << endl;
    }

    return (0);
  }
};
