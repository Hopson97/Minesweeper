#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

struct Node
{
    enum class Type
    {
        Normal,
        Bomb
    };

    Node(Type t);

    Type type;
    bool isDug      = false;
    bool hasFlag    = false;
};

#endif // NODE_H_INCLUDED
