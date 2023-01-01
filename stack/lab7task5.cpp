#include <iostream>
#include <fstream>
#include <iomanip>
 
using namespace std;
 
 
template <class Type>
class stackADT {
public:
    virtual void initializeStack() = 0;
    virtual bool isEmptyStack() const = 0;
    virtual bool isFullStack() const = 0;
    virtual void push(const Type& newItem) = 0;
    virtual Type top() const = 0;
    virtual void pop() = 0;
};
 
template<class Type>
class stackType : public stackADT<Type> {
public:
    const stackType<Type>& operator = (const stackType<Type>&);
    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;
    void push(const Type& newItem);
    Type top() const;
    void pop();
    stackType(int stackSize = 100);
    stackType(const stackType<Type>& otherStack);
private:
    int maxStackSize;
    int stackTop;
    Type* list;
    void copyStack(const stackType<Type>& otherStack);
};
 
template<class Type>
void stackType<Type>::initializeStack() {
    stackTop = 0;
}
 
template<class Type>
bool stackType<Type>::isEmptyStack() const {
    return stackTop == 0;
}
 
template<class Type>
bool stackType<Type>::isFullStack() const {
    return stackTop == maxStackSize;
}
 
template<class Type>
void stackType<Type>::push(const Type& newItem) {
    if (!isFullStack()) {
        list[stackTop] = newItem;
        stackTop++;
    }
    else {
        cout << "Cannot add to a full stack." << endl;
    }
}
 
template<class Type>
Type stackType<Type>::top() const {
    if (stackTop != 0)
        return list[stackTop - 1];
    else
        throw "stackTop is 0";
}
 
template<class Type>
void stackType<Type>::pop() {
    if (!isEmptyStack()) {
        stackTop--;
    }
    else {
        cout << "Cannot remove from an empty stack." << endl;
    }
}
 
template<class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack) {
    delete[] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    list = new Type[maxStackSize];
    for (int j = 0; j < stackTop; j++) {
        list[j] = otherStack.list[j];
    }
}
 
template<class Type>
stackType<Type>::stackType(int stackSize) {
    if (stackSize <= 0) {
        cout << "Size of the array to hold the stack must be positive." << endl;
        cout << "Creating an array of size 100." << endl;
        maxStackSize = 100;
    }
    else {
        maxStackSize = stackSize;
    }
    stackTop = 0;
    list = new Type[maxStackSize];
}
 
template<class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack) {
    list = NULL;
    copyStack(otherStack);
}
 
template<class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& otherStack) {
    if (this != &otherStack) {
        copyStack(otherStack);
    }
    return *this;
}
 
void evaluateOpr(ofstream& out, stackType<double>& stack,
    char& ch, bool& isExpOk)
{
    double op1, op2;
    if (stack.isEmptyStack())
    {
        out << " (Not enough operands)";
        isExpOk = false;
    }
    else
    {
        op2 = stack.top();
        stack.pop();
        if (stack.isEmptyStack())
        {
            out << " (Not enough operands)";
            isExpOk = false;
        }
        else
        {
            op1 = stack.top();
            stack.pop();
            switch (ch)
            {
            case '+':
                stack.push(op1 + op2);
                break;
            case '-':
                stack.push(op1 - op2);
                break;
            case '*':
                stack.push(op1 * op2);
                break;
            case '/':
                if (op2 != 0)
                    stack.push(op1 / op2);
                else
                {
                    out << " (Division by 0)";
                    isExpOk = false;
                }
                break;
            default:
                out << " (Illegal operator)";
                isExpOk = false;
            }
        }
    }
}
 
void discardExp(ifstream& in, ofstream& out, char& ch)
{
    while (ch != '=')
    {
        in.get(ch);
        out << ch;
    }
}
 
void evaluateExpression(ifstream& inpF, ofstream& outF, stackType<double>& stack, char& ch, bool& isExpOk)
{
    double num;
    outF << ch;
    while (ch != '=')
    {
        switch (ch)
        {
        case '#':
            inpF >> num;
            outF << num << " ";
            if (!stack.isFullStack())
                stack.push(num);
            else
            {
                cout << "Stack overflow. "
                    << "Program terminates!" << endl;
                exit(0);
            }
            break;
        default:
            evaluateOpr(outF, stack, ch, isExpOk);
        }
        if (isExpOk)
        {
            inpF >> ch;
            outF << ch;
            if (ch != '#')
                outF << " ";
        }
        else
            discardExp(inpF, outF, ch);
    }
}
 
 
 
 
 
void printResult(ofstream& outF, stackType<double>& stack,
    bool isExpOk)
{
    double result;
    if (isExpOk)
    {
        if (!stack.isEmptyStack())
        {
            result = stack.top();
            stack.pop();
            if (stack.isEmptyStack())
                outF << result << endl;
            else
                outF << " (Error: Too many operands)" << endl;
        }
        else
            outF << " (Error in the expression)" << endl;
    }
    else
        outF << " (Error in the expression)" << endl;
    outF << "_________________________________"
        << endl << endl;
}
 
 
 
int main() {
    bool expressionOk;
    char ch;
    stackType<double> stack(100);
    ifstream infile;
    ofstream outfile;
    infile.open("RpnData.txt");
    if (!infile)
    {
        cout << "Cannot open the input file. "
            << "Program terminates!" << endl;
        return 1;
    }
    outfile.open("RpnOutput.txt");
    outfile << fixed << showpoint;
    outfile << setprecision(2);
    infile >> ch;
    while (infile)
    {
        stack.initializeStack();
        expressionOk = true;
        outfile << ch;
            evaluateExpression(infile, outfile, stack, ch,
                expressionOk);
        printResult(outfile, stack, expressionOk);
        infile >> ch;
    }
    infile.close();
    outfile.close();
   
    return 0;
}
