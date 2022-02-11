#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> s;
    // currently stack is empty, true (1)
    printf("%d\n", s.empty());
    printf("-----------\n");

    s.push('a');
    s.push('b');
    s.push('c');
    // stack is LIFO, thus the current elements of stack is like this:
    // c <- top
    // b
    // a
    printf("%c\n", s.top()); // output 'c'
    // pop topmost
    s.pop();
    printf("%c\n", s.top()); // 'b'
    printf("%d\n", s.empty()); // 0
    printf("----------------\n");

    queue<char> q;
    printf("%d\n", q.empty()); // 1

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    q.push('z');
    printf("%c\n", q.front());
    printf("%c\n", q.back());
    printf("------------\n");

    // b, a, z
    while (!q.empty()) {
        printf("%c\n", q.front());
        q.pop();
    }
    printf("--------------\n");

    deque<char> d;
    d.push_back('a');
    d.push_back('b');
    d.push_back('c');

    printf("%c - %c\n", d.front(), d.back());
    d.push_front('d');
    printf("%c - %c\n", d.front(), d.back());
    printf("%c %c %c %c\n", d[0], d[1], d[2], d[3]); // only in c++ 'd a b c'

    d.pop_back();
    printf("%c - %c\n", d.front(), d.back());
    d.pop_front();
    printf("%c - %c\n", d.front(), d.back());

    return 0;
}
