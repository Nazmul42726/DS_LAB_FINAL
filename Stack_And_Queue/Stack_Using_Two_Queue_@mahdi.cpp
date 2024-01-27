#include <iostream>
using namespace std;

class queue
{
private:
    int arr[1000];

public:
    int first, last;
    queue()
    {
        first = -1;
        last = -1;
    }

    void push(int x)
    {
        if (first == -1)
        {
            first = 0;
        }
        arr[++last] = x;
    }

    void pop()
    {
        if (first == -1 || first > last)
        {
            cout << "Error: Queue is empty" << endl;
            return;
        }
        first++;
        if (first > last)
        {
            first = -1;
            last = -1;
        }
    }

    int front()
    {
        if (empty())
        {
            cout << "Error: Queue is empty" << endl;
            return -1;
        }
        return arr[first];
    }

    int back()
    {
        if (empty())
        {
            cout << "Error: Queue is empty" << endl;
            return -1;
        }
        return arr[last];
    }

    bool empty()
    {
        return (first == -1 || first > last);
    }

    int size() {
        if (empty()) {
            return 0;
        } else {
            return last - first + 1;
        }
    }
};

class stack
{
private:
    queue q1, q2;

public:
    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        if (q1.empty())
            return -1; // Stack underflow

        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int element = q1.front();
        q1.pop();
        swap(q1, q2);
        return element;
    }

    // // By making push() operation costly:
    // void push(int x)
    // {
    //     q2.push(x);
    //     while (!q1.empty())
    //     {
    //         q2.push(q1.front());
    //         q1.pop();
    //     }
    //     queue q = q1;
    //     q1 = q2;
    //     q2 = q;
    // }

    // void pop()
    // {
    //     if (q1.empty())
    //         return;
    //     q1.pop();
    // }

    int top()
    {
        if (q1.empty())
            return -1; // Stack underflow

        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int element = q1.front();
        q2.push(element);
        q1.pop();
        swap(q1, q2);
        return element;
    }

    bool empty()
    {
        return q1.empty();
    }
    int size()
    {
        return q1.size();
    }
};

int main()
{
    stack stack;
    stack.push(5);
    stack.push(10);
    stack.pop();
    stack.push(12);
    cout<<stack.size()<<endl;
    cout << "Top element is: " << stack.top() << endl;
    return 0;
}