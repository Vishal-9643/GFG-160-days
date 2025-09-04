// Day 58 : Reverse a linked list.
// You are given the head of a singly linked list. You have to reverse the linked list and return the head of the reversed list.

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *reverseList(Node *head)
{

    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

void printList(Node *node)
{
    while (node != nullptr)
    {
        cout << node->data;
        if (node->next)
            cout << " -> ";
        node = node->next;
    }
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = reverseList(head);

    printList(head);

    return 0;
}