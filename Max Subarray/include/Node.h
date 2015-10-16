#ifndef NODE_H
#define NODE_H


class Node<E>
{
    public:
        Node();
        virtual ~Node();
        Node next;
        Node previous;
        E element;
    protected:
    private:
};

#endif // NODE_H
