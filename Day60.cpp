// Day 60 : Add Number Linked Lists.
// You are given the head of two singly linked lists head1 and head2 representing two non-negative integers. You have to return the head of the linked list representing the sum of these two numbers.

// Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

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
{ // reversing list.
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newhead = reverseList(head->next);

    Node *front = head->next;
    front->next = head;
    head->next = NULL;

    return newhead;
}

Node *Remove(Node *head)
{ // removing leading zero.
    while (head && head->data == 0 && head->next != NULL)
    {
        head = head->next;
    }

    return head;
}
Node *addTwoLists(Node *head1, Node *head2)
{
    Node *first = reverseList(head1);
    Node *second = reverseList(head2);

    Node *dummy = new Node(0);
    Node *temp = dummy;
    int carry = 0;

    while (first || second || carry)
    {
        int sum = carry;

        if (first)
        {
            sum += first->data;
            first = first->next;
        }

        if (second)
        {
            sum += second->data;
            second = second->next;
        }

        carry = sum / 10;
        temp->next = new Node(sum % 10);
        temp = temp->next;
    }

    Node *result = reverseList(dummy->next);
    result = Remove(result);

    return result;
}

void printList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data;
        if (curr->next != NULL)
        {
            cout << " -> ";
        }
        curr = curr->next;
    }
    cout << "\n";
}

int main()
{

    Node *num1 = new Node(1);
    num1->next = new Node(2);
    num1->next->next = new Node(3);

    Node *num2 = new Node(9);
    num2->next = new Node(9);
    num2->next->next = new Node(9);

    Node *sum = addTwoLists(num1, num2);
    printList(sum);

}