#ifndef LEAF_H
#define LEAF_H

#include "../IComponent.h"

/**
*** The Leaf class represents the end of object of a composition. a Leaf can not have any children
***
**/
class Leaf : public IComponent
{
    public:
        Leaf();
        virtual ~Leaf();

        virtual std::string Operation() override;

    protected:

    private:
};

class SmallerLeaf : public Leaf
{
    public:
        SmallerLeaf();
        virtual ~SmallerLeaf();

        virtual std::string Operation() override;

    protected:

    private:
};

#endif // LEAF_H
