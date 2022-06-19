#include "Composite.h"


#include <iostream>
#include <string>

using namespace std;

int Composite::m_brach_spec = 0;

Composite::Composite() : m_numer(0)
{
    cout << "ctor: " << __func__ << endl;
    m_brach_spec++;
    m_numer = m_brach_spec;
}

Composite::~Composite()
{
    cout << "dtor: " << __func__ << endl;
}

void Composite::RemoveComp(IComponent* comp)
{
    cout << "Entering func: " << __func__ << endl;
    m_children.remove(comp);
    comp->SetParent(nullptr);
    cout << "Leaving func: " << __func__ << endl;
}

bool Composite::IsComposite() const
{
    return true;
}

void Composite::AddComp(IComponent* comp)
{
    cout << "Entering func: " << __func__ << endl;
    m_children.push_back(comp);
    comp->SetParent(this);
    cout << "Leaving func: " << __func__ << endl;
}


string Composite::Operation()
{
    std::string ret{};
    for (IComponent *comp : m_children) {
        if (comp == m_children.back()) {
            ret += comp->Operation();
        }
        else {
            //++m_brach_spec;
            //m_numer = m_brach_spec;
            ret += comp->Operation() + "+";
        }
    }

    return "BRANCH_" + std::to_string(m_numer) + "(" + ret + ")";
}


