// Day 63 : Clone List with Next and Random.
// You are given a special linked list with n nodes where each node has two pointers a next pointer that points to the next node of the singly linked list, and a random pointer that points to the random node of the linked list.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};

Node *cloneLinkedList(Node *head)
{
    if (!head)
        return NULL;

    unordered_map<Node *, Node *> nmap;

    Node *temp = head;
    while (temp)
    {
        nmap[temp] = new Node(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp)
    {
        nmap[temp]->next = temp->next ? nmap[temp->next] : nullptr;
        nmap[temp]->random = temp->random ? nmap[temp->random] : nullptr;
        temp = temp->next;
    }

    return nmap[head];
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "(";
        if (head->random)
            cout << head->random->data << ")";
        else
            cout << "null" << ")";

        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{

    // Creating a linked list with random pointer
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    // Print the original list
    cout << "Original linked list:\n";
    printList(head);

    Node *clonedList = cloneLinkedList(head);

    cout << "Cloned linked list:\n";
    printList(clonedList);

    return 0;
}