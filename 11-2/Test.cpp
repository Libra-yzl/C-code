#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>

//void main()
//{
//
//    stack<char> S;
//
//    char x, y;
//
//    x = 'n'; y = 'g';
//
//    S.push(x); S.push('i'); S.push(y);
//
//    S.pop(); S.push('r'); S.push('t'); S.push(x);
//
//    S.pop(); S.push('s');
//
//    while (!S.empty())
//
//    {
//
//        x = S.top();
//
//        S.pop();
//
//        cout << x;
//
//    };
//
//    cout << y;
//
//}
// 

//int main()
//
//{
//
//    queue<char> Q;
//
//    char x, y;
//
//    x = 'n'; y = 'g';
//
//    Q.push(x); Q.push('i'); Q.push(y);
//
//    Q.pop(); Q.push('r'); Q.push('t'); Q.push(x);
//
//    Q.pop(); Q.push('s');
//
//    while (!Q.empty())
//
//    {
//
//        x = Q.front();
//
//        Q.pop();
//
//        cout << x;
//
//    };
//
//    cout << y;
//    return 0;
//}


//int main()
//
//{
//
//    priority_queue<int> a;
//
//    priority_queue<int, vector<int>, greater<int> > c;
//
//    priority_queue<string> b;
//
//    for (int i = 0; i < 5; i++)
//
//    {
//
//        a.push(i);
//
//        c.push(i);
//
//    }
//
//    while (!a.empty())
//
//    {
//
//        cout << a.top() << ' ';
//
//        a.pop();
//
//    }
//
//    cout << endl;
//
//    while (!c.empty())
//
//    {
//
//        cout << c.top() << ' ';
//
//        c.pop();
//
//    }
//
//    cout << endl;
//
//    b.push("abc");
//
//    b.push("abcd");
//
//    b.push("cbd");
//
//    while (!b.empty())
//
//    {
//
//        cout << b.top() << ' ';
//
//        b.pop();
//
//    }
//
//    cout << endl;
//
//    return 0;
//
//}


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& str : tokens) {
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                int ret = 0;
                switch (str[0]) {
                case '+':
                    st.push(left + right);
                    break;
                case '-':
                    st.push(left - right);
                    break;
                case '*':
                    st.push(left * right);
                    break;
                case '/':
                    st.push(left / right);
                    break;
                }
            }
            else st.push(stoi(str));
        }
        return st.top();
    }
};