// Day 65 : Find the first node of loop in linked list.
// You are given the head of a singly linked list. If a loop is present in the linked list then return the first node of the loop else return -1.

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

int cycleStart(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow->data;
        }
    }
    return -1;
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    head->next->next->next->next->next = head->next->next;

    int loopNode = cycleStart(head);

    if (loopNode != -1)
        cout << loopNode;
    else
        cout << -1;
}