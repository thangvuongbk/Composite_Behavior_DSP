#ifndef ICOMPONENT_H_INCLUDED
#define ICOMPONENT_H_INCLUDED

#include <string>

class IComponent {
public:
    virtual ~IComponent() {
    }
    void SetParent(IComponent *comp) {
        m_parent = comp;
    }

    IComponent *GetParent() {
        return m_parent;
    }

  /**
   * In some cases, it would be beneficial to define the child-management
   * operations right in the base Component class. This way, you won't need to
   * expose any concrete component classes to the client code, even during the
   * object tree assembly. The downside is that these methods will be empty for
   * the leaf-level components.
   */
   virtual void AddComp(IComponent *comp) {};
   virtual void RemoveComp(IComponent *comp) {};

   /**
   * You can provide a method that let's client to figure out whether a component can bear a children
   */
   virtual bool IsComposite() const {
    return false;
   }

    /**
    *** The base component can implement some default behavior or leave it to concrete classes
    *** (by declaring the method containing the behavior as "abstract")
    */

    virtual std::string Operation() = 0;

protected:
    IComponent *m_parent;


};

#endif // ICOMPONENT_H_INCLUDED
