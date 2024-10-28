#include <fstream>
#include <iostream>

using namespace std;

class MyStack
{
    static const size_t MAX_DEPTH = 1e3;
    size_t _depth;
    int _stack[MAX_DEPTH];

   public:
    MyStack() : _depth(0) {}

    void push(int value)
    {
        if (_depth < MAX_DEPTH)
        {
            _stack[_depth++] = value;
        }
    }

    int pop()
    {
        if (_depth > 0)
        {
            return _stack[--_depth];
        }
        return -1;
    }

    int top()
    {
        if (_depth > 0)
        {
            return _stack[_depth - 1];
        }
        return -1;
    }

    bool empty() { return _depth == 0; }

    size_t size() { return _depth; }

    void print(ostream &out)
    {
        if (empty())
        {
            out << "stack is empty!" << endl;
            return;
        }
        for (size_t i = 0; i < _depth; i++)
        {
            out << _stack[i] << " ";
        }
        out << endl;
    }
};

int main()
{
    ifstream in("stacksin.txt");
    ofstream out("stacksout.txt");
    MyStack st;
    int n;
    in >> n;
    while (n != -2)
    {
        if (n == -1)
        {
            st.pop();
        }
        else
        {
            st.push(n);
        }
        st.print(out);
        in >> n;
    }
    return 0;
}