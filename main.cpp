#include <iostream>

#include <iostream>
#include "IComponent.h"
#include "Leaf.h"
#include "Composite.h"

using namespace std;

void simpleClientCode(IComponent* comp) {
    std::string ret = comp->Operation();
    cout << "RESULT: " << ret << endl;
}

void complexClientCode(IComponent *comp1, IComponent* comp2) {
    if(comp1->IsComposite()) comp1->AddComp(comp2);
    std::string ret =  comp1->Operation();
    cout << "RESULT: " << ret << endl;
}


int main()
{
    IComponent* simple = new Leaf();
    simpleClientCode(simple);

    cout << "\n\nWith Complex component\n";
    IComponent* root = new Composite();
    IComponent* branch1 = new Composite();
    IComponent* branch2 = new Composite();
    IComponent* branch3 = new Composite();

    IComponent* leaf1 = new Leaf();
    IComponent* leaf2 = new Leaf();
    IComponent* leaf3 = new Leaf();
    IComponent* smallleaf1 = new SmallerLeaf();

    branch1->AddComp(leaf1);
    branch1->AddComp(leaf1);
    branch1->AddComp(branch3);

    branch2->AddComp(leaf3);

    branch3->AddComp(smallleaf1);

    root->AddComp(branch1);
    root->AddComp(branch2);

    complexClientCode(root, simple);

    delete simple;
    delete root;
    delete branch1;
    delete branch2;
    delete branch3;
    delete leaf1;
    delete leaf2;
    delete leaf3;

    return 0;
}
