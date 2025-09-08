// Day 61 : Merge two sorted linked lists.
// Given the head of two sorted linked lists consisting of nodes respectively. Merge both lists and return the head of the sorted merged list.

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

Node *sortedMerge(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *dummy = new Node(0);
    Node *temp = dummy;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }
        else if (temp1->data > temp2->data)
        {
            temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
        else
        {
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
            temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        temp->next = temp1;
        temp = temp->next;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        temp->next = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }

    return dummy->next;
}

void printList(Node *curr)
{
    while (curr != nullptr)
    {
        cout << curr->data;
        if (curr->next != nullptr)
            cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}
int main()
{

    Node *head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);
    head1->next->next->next = new Node(40);

    Node *head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    Node *res = sortedMerge(head1, head2);

    printList(res);
}