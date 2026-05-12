template <typename T>
class Node
{
private:
    T value;
    Node<T>* next;

public:
    // constructor, by default next is null if not assigned
    Node(const T& val, Node<T>* n = nullptr)
    {
        value = val;
        next = n;
    }
    // getter and setter for value
    const T& getValue()
    {
        return value;
    }
    void setValue(const T& val)
    {
        value = val;
    }
    // getter and setter for next
    Node<T>* getNext()
    {
        return next;
    }
    void setNext(Node<T>* n)
    {
        next = n;
    }
};