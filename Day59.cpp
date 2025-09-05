// Day 59 : Rotate a Linked List.
// You are given the head of a singly linked list, you have to left rotate the linked list k times. Return the head of the modified linked list.

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

Node *rotate(Node *head, int k)
{
    Node *temp = head;
    int cnt = 1;
    while (temp->next != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    int r = k % cnt;
    while (r--)
    {
        temp->next = head;
        temp = temp->next;
        head = head->next;
    }

    temp->next = nullptr;

    return head;
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

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head = rotate(head, 6);
    printList(head);
}
