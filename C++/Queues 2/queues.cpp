#include <fstream>
#include <iostream>

using namespace std;

class MyQueue
{
    static const size_t MAX_SIZE = 1e3;
    size_t _size;
    size_t _front, _back;
    int _queue[MAX_SIZE];

   public:
    MyQueue() : _size(0), _front(0), _back(0) {}

    void push(int value)
    {
        if (_size < MAX_SIZE)
        {
            _queue[_back] = value;
            _back = (_back + 1) % MAX_SIZE;
            _size++;
        }
    }

    int pop()
    {
        if (_size > 0)
        {
            int value = _queue[_front];
            _front = (_front + 1) % MAX_SIZE;
            _size--;
            return value;
        }
        return -1;
    }

    void print(ostream &out)
    {
        if (_size == 0)
        {
            out << "queue is empty!" << endl;
            return;
        }
        size_t i = _front;
        do
        {
            out << _queue[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != _back);
        out << endl;
    }
};

int main()
{
    ifstream in("queuesin.txt");
    ofstream out("queuesout.txt");

    MyQueue queue;
    int n;
    in >> n;
    while (n != -2)
    {
        if (n == -1)
        {
            queue.pop();
        }
        else
        {
            queue.push(n);
        }
        queue.print(out);
        in >> n;
    }

    return 0;
}