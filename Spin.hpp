#ifndef Spin_hpp
#define Spin_hpp
#include <string>


class spin
{
private:
    typedef struct node
    {
        std::string data;
        node* next;
        node* prev;
        node(std::string Cnode)
        {
            data = Cnode;
            next = this;
            prev = this;
        }
        
    }* nodePtr;

public:

    node* head;
    spin(); // Constructs each spin
    void insert(std::string Nwnode);
    

};
#endif	




