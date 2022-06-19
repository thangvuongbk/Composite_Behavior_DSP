#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "../IComponent.h"

#include <list>

class Composite : public IComponent
{
    public:
        Composite();
        virtual ~Composite();

        /* Specific implementation for this class*/
        virtual void AddComp(IComponent *comp) override;
        virtual void RemoveComp(IComponent *comp) override;
        virtual bool IsComposite() const override;
        virtual std::string Operation() override;

        /* No override impl */

    protected:

    private:
        std::list<IComponent*> m_children;
        static int m_brach_spec;
        int m_numer;
};

#endif // COMPOSITE_H
