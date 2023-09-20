#include <iostream>
#include <string>

class StackException
{
private:
    std::string message;

public:
    StackException(const std::string& msg) : message(msg) {}

    const std::string& GetMessage() const
    {
        return message;
    }
};

class Stack
{
    enum { EMPTY = -1, FULL = 9 };
    int data[FULL + 1];
    int topIndex;

public:
    Stack()
    {
        topIndex = EMPTY;
    }

    bool IsFull() const
    {
        return topIndex == FULL;
    }

    bool Push(int element)
    {
        if (IsFull())
        {
            throw StackException("Stack is full. Cannot push element.");
        }

        data[++topIndex] = element;
        return true;
    }

    bool IsEmpty() const
    {
        return topIndex == EMPTY;
    }

    int Pop()
    {
        if (IsEmpty())
        {
            throw StackException("Stack is empty. Cannot pop element.");
        }

        return data[topIndex--];
    }

    int Peek()
    {
        if (IsEmpty())
        {
            throw StackException("Stack is empty. Cannot peek element.");
        }

        return data[topIndex];
    }

    int GetCount() const
    {
        return topIndex + 1;
    }

    void Clear()
    {
        topIndex = EMPTY;
    }
};

int main()
{
    Stack st;
    try
    {
        st.Push(35);
        std::cout << "Count: " << st.GetCount() << std::endl;
        st.Push(11);
        st.Push(88);
        st.Push(55);
        st.Push(55);
        st.Push(55);
        st.Push(55);
        st.Push(55);
        st.Push(55);
        st.Push(99);
        st.Push(100);
        std::cout << "Count: " << st.GetCount() << std::endl;
        std::cout << "Element: " << st.Pop() << std::endl;
        std::cout << "Count: " << st.GetCount() << std::endl;

        while (!st.IsEmpty())
        {
            std::cout << "Element: " << st.Pop() << std::endl;
        }
        std::cout << "Count: " << st.GetCount() << std::endl;
    }
    catch (const StackException& ex)
    {
        std::cout << "Error: " << ex.GetMessage() << std::endl;
    }

    return 0;
}