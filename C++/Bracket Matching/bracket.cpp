#include <iostream>
#include <map>
#include <stack>

using namespace std;

int N;
stack<char> brackets;
map<char, char> pairs = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

int main()
{
    cin >> N;
    bool ans = true;
    for (int i = 0; i < N; i++)
    {
        char ch;
        cin >> ch;
        if (ch == '(' || ch == '[' || ch == '{')
        {
            brackets.push(ch);
        }
        else
        {
            if (!brackets.empty() && ch == pairs[brackets.top()])
            {
                brackets.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    if (ans && brackets.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}