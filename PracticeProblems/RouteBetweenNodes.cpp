#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Node
{
public:
    int value;
    vector<Node*> children;

    Node(int value)
    {
        this->value = value;
    }

    void AddChild(Node* node)
    {
        children.push_back(node);
    }
};

class Graph
{
public:
    vector<Node*>* nodes;

    Graph()
    {
        this->nodes = new vector<Node*>();
    };

    ~Graph()
    {
        delete this->nodes;
    }

    void AddNode(Node* node)
    {
        nodes->push_back(node);
    }

    // BFS Solution
    bool hasRoute(Node* A, Node* B)
    {
        queue<Node*> queue; 
        map<Node*, bool> visited; // Stores node and whether it was already visted.

        queue.push(A);

        while (!queue.empty())
        {
            Node* temp = queue.front();

            for(auto childNode : temp->children)
            {   
                // Node hasn't been visited.
                if (visited.find(childNode) == visited.end())
                {
                    if (childNode == B)
                    {
                        return true;
                    }
                    else
                    {
                        visited[childNode] = true;
                        queue.push(childNode);
                    }
                }
            }

            queue.pop();
        }

        return false;
    }
};

int main()
{
    Node a(1), b(2), c(3), d(4), e(5);
    a.AddChild(&c);
    a.AddChild(&d);
    b.AddChild(&d);
    b.AddChild(&a);
    c.AddChild(&b);
    d.AddChild(&e);

    Graph graph;
    graph.AddNode(&a);
    graph.AddNode(&b);
    graph.AddNode(&c);
    graph.AddNode(&d);
    graph.AddNode(&e);

    cout << graph.hasRoute(&a, &e) << endl;
    cout << graph.hasRoute(&e, &b) << endl;
    cout << graph.hasRoute(&c, &a) << endl;
    cout << graph.hasRoute(&d, &a) << endl;
    cout << graph.hasRoute(&d, &b) << endl;
}