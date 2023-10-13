#include <iostream>

using namespace std;

class node
{

public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *newNode = new node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;

    return;
}

void insertAtTail(node *&head, int val)
{

    node *newNode = new node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return;
}

void deleteNode(node * &head, int key)
{

    node *temp = head;

    while (temp != NULL)
    {

        if (temp->data == key)
        {

            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }

            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
                if(temp == head){
                    head = head->next;
                }
            }

            return;
        }
        temp = temp->next;
    }

    cout << "node not found";
    return;
}

void display(node *head)
{

    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return;
}

int main()
{

    node *head = NULL;

    insertAtTail(head, 2);
    insertAtTail(head, 4);
    insertAtTail(head, 1);
    insertAtTail(head, 7);
    insertAtTail(head, 3);
    insertAtTail(head, 8);

    insertAtHead(head, 1);
    insertAtHead(head, 6);

    deleteNode(head, 6);
    deleteNode(head, 8);
    
    display(head);
}