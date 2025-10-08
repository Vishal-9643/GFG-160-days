// Day 77 : Get Min from Stack.
/*
Implement a class SpecialStack that supports following operations:

push(x) – Insert an integer x into the stack.
pop() – Remove the top element from the stack.
peek() – Return the top element from the stack. If the stack is empty, return -1.
getMin() – Retrieve the minimum element from the stack in O(1) time. If the stack is empty, return -1.
isEmpty() –  Return true if stack is empty, else false
*/

#include <bits/stdc++.h>
using namespace std;

class SpecialStack
{
public:
    stack<pair<int, int>> st;
    SpecialStack()
    {
        // Define Stack
    }

    void push(int x)
    {
        // Add an element to the top of Stack
        if (st.empty())
        {
            st.push({x, x});
        }
        else
        {
            st.push({x, min(x, st.top().second)});
        }
    }

    void pop()
    {
        // Remove the top element from the Stack
        st.pop();
    }

    int peek()
    {
        // Returns top element of the Stack
        if (st.empty())
            return -1;
        return st.top().first;
    }

    bool isEmpty()
    {
        // Check if stack is empty
        return st.empty();
    }

    int getMin()
    {
        // Finds minimum element of Stack
        if (st.empty())
            return -1;
        return st.top().second;
    }
};

int main()
{
    SpecialStack st;

    st.push(18);
    st.push(19);
    st.push(29);
    st.push(15);
    st.push(16);

    cout << st.getMin() << endl;

    return 0;
}