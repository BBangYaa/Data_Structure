#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

class Node
{
    public:
        Node();
        void push(double val);
        double pop();
        void print();
        bool isEmpty();
    private:
        double data;
        Node *top;
        Node *ptr;
};

Node::Node()
{
    top = NULL;
    ptr = NULL;
}

void Node::push(double val)
{
    Node *next = new Node;
    next->data = val;
    next->ptr = top;
    top = next;
}

double Node::pop()
{
    if (isEmpty())
    {
        cout << "Error: Too many operators" << endl;
    }
    else
    {
        Node *next = top->ptr;
        double ret = top->data;
        delete top;
        top = next;
        return ret;
    }
}

void Node::print()
{
    cout << top->data << endl;
}

bool Node::isEmpty()
{
    return top == 0;
}

bool isOperator(const string &input)
{
    string ops[] = {"+", "-", "*", "/"};

    for (int i = 0; i < 4; i++)
    {
        if (input == ops[i])
        {
            return true;
        }
    }

    return false;
}

void performOp(const string &input, Node &stack)
{
    double fVal, sVal;
    int errCheck = 0;

    sVal = stack.pop();
    fVal = stack.pop();

    if (input == "+")
    {
        stack.push(fVal + sVal);
    }
    else if (input == "-")
    {
        stack.push(fVal - sVal);
    }
    else if (input == "*")
    {
        stack.push(fVal * sVal);
    }
    else if (input == "/" && sVal != 0)
    {
        stack.push(fVal / sVal);
    }

    if (input == "/" && sVal == 0)
    {
        cout << "Error: Division by zero" << endl;
        errCheck = 1;
    }

    if (errCheck == 0)
    {
        stack.print();
    }
}

int main()
{
    string input;
    Node stack;
    double num;

    cout << "RPN Calculator" << endl;
    cout << "Please enter your calculation or 0 to quit" << endl;

    while (true)
    {
        cin >> input;

        if (istringstream(input) >> num)
        {
            stack.push(num);
        }
        else if (isOperator(input))
        {
            performOp(input, stack);
        }
        else if (input == "q")
        {
            return 0;
        }
    }
}