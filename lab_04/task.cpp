#include <iostream>

using namespace std;

class Node
{
public:
    int coefficient;
    int power;
    Node *next;
};

void add_node(int x, int y, Node **tmp)
{
    Node *first, *second;
    second = *tmp;

    if (second == NULL)
    {
        first = new Node;
        first->coefficient = x;
        first->power = y;
        *tmp = first;
        first->next = new Node;
        first = first->next;
        first->next = NULL;
    }
    else
    {
        first->coefficient = x;
        first->power = y;
        first->next = new Node;
        first = first->next;
        first->next = NULL;
    }
}

void sum(Node *p1, Node *p2, Node *p3)
{
    while (p1->next && p2->next)
    {
        if (p1->power > p2->power)
        {
            p3->power = p1->power;
            p3->coefficient = p1->coefficient;
            p1 = p1->next;
        }
        else if (p1->power < p2->power)
        {
            p3->power = p2->power;
            p3->coefficient = p2->coefficient;
            p2 = p2->next;
        }
        else
        {
            p3->power = p1->power;
            p3->coefficient = p1->coefficient + p2->coefficient;
            p1 = p1->next;
            p2 = p2->next;
        }
        p3->next = new Node;
        p3 = p3->next;
        p3->next = NULL;
    }

    while (p1->next || p2->next)
    {
        if (p1->next)
        {
            p3->power = p1->power;
            p3->coefficient = p1->coefficient;
            p1 = p1->next;
        }
        if (p2->next)
        {
            p3->power = p2->power;
            p3->coefficient = p2->coefficient;
            p2 = p2->next;
        }
        p3->next = new Node;
        p3 = p3->next;
        p3->next = NULL;
    }
}

void display(Node *node)
{
    while (node->next != NULL)
    {
        cout << node->coefficient << "x^" << node->power;
        node = node->next;
        if (node->next != NULL)
        {
            cout << " + ";
        }
        else 
        {
            cout << endl;
        }
    }
}
int main()
{
    Node *p1 = NULL, *p2 = NULL, *p3 = NULL;

    add_node(5, 12, &p1);
    add_node(2, 9, &p1);
    add_node(4, 7, &p1);
    add_node(6, 6, &p1);
    add_node(1, 3, &p1);

    cout << "Polynomial 1: " << endl;
    display(p1);

    add_node(7, 8, &p2);
    add_node(2, 7, &p2);
    add_node(8, 6, &p2);
    add_node(6, 4, &p2);
    add_node(2, 2, &p2);
    add_node(3, 1, &p2);
    add_node(40, 0, &p2);

    cout << "\n\nPolynomial 2: " << endl;
    display(p2);

    p3 = new Node;
    sum(p1, p2, p3);

    cout << "\n\nSum of Polynomials 1 and 2: " << endl;
    display(p3);

    return 0;
}