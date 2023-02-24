#include "Spin.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

spin::spin()
{
  head = nullptr;
}

// Not working
//spin::~spin()
//{
//  node* itr = head;
//  while (itr != nullptr)
//    {
//      head = head->next;
//      delete itr;
//      itr = head;
//    }
//}

void spin::insert(string Nwnode)
{
  //Check if the head is the nullptr
  if(head == nullptr)
    {
      //If head isn't null ptr then set new node as the head
      head = new node(Nwnode);
    }
  else
    {
      node* n = new node(Nwnode);
      //making the links to the nodes in the circular linked list
      n->next = head;
      n->prev = head -> prev;
      head->prev->next = n;
      head->prev = n;
      head = n;
    }
}