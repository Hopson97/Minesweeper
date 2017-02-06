#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

enum class Type
{
    Normal,
    Bomb
};

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
