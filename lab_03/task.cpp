#include <iostream>
#include <stdlib.h>
using namespace std;
// class of node
class node
{
public:
    int value;
    node *next;
};

class List
{
    node *head = NULL;

public:
    void insert_at_beginning(int new_value)
    {
        node *new_node = new node;
        new_node->value = new_value;
        new_node->next = head;
        head = new_node;
    }
    void insert_at_loc(int location, int new_value)
    {
        int i = 1;
        node *current = head;
        node *next_node = new node;
        node *insert = new node;
        insert->value = new_value;
        while (true)
        {
            next_node = current;
            current = current->next;
            if (i == location)
            {
                break;
            }
            else
            {
                i++;
            }
        }
        insert->next = current;
        next_node->next = insert;
    }
    void display()
    {
        node* display_pointer = new node;
        display_pointer = head;
        while (display_pointer != NULL){
            cout << display_pointer->value << " ";
            display_pointer = display_pointer->next;
        }
        cout << endl;
    }
    void del(int del_value)
    {
        node *current = head;
        node *next_node = new node;
        while (current != NULL)
        {
            next_node = current;
            current = current->next;
            if (current->value == del_value)
            {
                break;
            }
        }
        next_node->next = current->next;
        cout << current->value << endl;
        delete current;
    }
    void count()
    {
        node* current = head;
        node* x = new node;
        int num_of_nodes = 0;
        while (current != NULL){
            x = current;
            current = current->next;
            num_of_nodes++;
        }
        cout << "Total Nodes: " << num_of_nodes << endl;
    }
};

int main()
{
    List *list = new List;
    int x = 0;
    int value;
    int location;
    while (true)
    {
        cout << "Press 1 to insert a new node at the beginning" << endl;
        cout << "Press 2 to insert a new node at a specific location" << endl;
        cout << "Press 3 to delete a specific node " << endl;
        cout << "Press 4 to display list" << endl;
        cout << "Press 5 to find total nodes in list" << endl;
        cin >> x;
        //system("CLS");

        if (x == 1)
        {
            cout << "Enter value to place at beginning of list" << endl;
            cin >> value;
            list->insert_at_beginning(value);
        }
        else if (x == 2)
        {
            cout << "Enter value to place in list" << endl;
            cin >> value;
            cout << "Enter location at which to place value" << endl;
            cin >> location;
            list->insert_at_loc(location, value);
        }
        else if (x == 3)
        {
            cout << "Enter value to delete in list" << endl;
            cin >> value;

            list->del(value);
        }
        else if (x == 4)
        {
            list->display();
        }
        else if (x == 5)
        {
            list->count();
        }
        else
        {
            cout << "Incorrect input" << endl;
            break;
        };
        cout << endl;
    }
    return 0;
}