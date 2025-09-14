//  Day 66 : Remove loop in Linked List.
// Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void removeLoop(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            break;
        }
    }
    if (slow == fast)
    {
        slow = head;

        if (slow == fast)
        {
            while (fast->next != slow)
                fast = fast->next;
        }
        else
        {
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = nullptr;
    }
}

void printList(Node *curr)
{
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{

    // Create a hard-coded linked list:
    // 1 -> 3 -> 4
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);

    // Create a loop
    head->next->next->next = head->next;

    removeLoop(head);
    printList(head);
}