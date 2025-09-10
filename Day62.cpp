// Day 62 : Linked List Group Reverse.
// You are given the head of a Singly linked list. You have to reverse every k node in the linked list and return the head of the modified list.
// Note: If the number of nodes is not a multiple of k then the left-out nodes at the end, should be considered as a group and must be reversed.

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

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newhead = reverse(head->next);

    Node *front = head->next;
    front->next = head;
    head->next = nullptr;

    return newhead;
}

Node *getkth(Node *temp, int k)
{
    k -= 1;
    while (temp->next != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

Node *reverseKGroup(Node *head, int k)
{
    if (k <= 1 || head == NULL)
        return head;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        Node *kth = getkth(temp, k);
        Node *front = kth->next;
        kth->next = nullptr;
        Node *newhead = reverse(temp);
        if (prev == NULL)
        {
            head = newhead;
        }
        else
        {
            prev->next = newhead;
        }

        prev = temp;
        temp = front;
    }

    return head;
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

    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);

    Node* res = reverseKGroup(head1,2);
    printList(res);

}