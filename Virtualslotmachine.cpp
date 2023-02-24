#include <iostream>
#include <cstdlib>
#include "Virtualslotmachine.hpp"

using namespace std;

Virtualslotmachine::Virtualslotmachine()
{
  s1 = new spin();
  s2 = new spin();
  s3 = new spin();
  //Data Added
  s1->insert("A");
  s1->insert("B");
  s1->insert("C");
  s1->insert("7");
  s1->insert("A");
  s1->insert("B");
  s1->insert("C");
  s1->insert("A");
  s1->insert("B");
  s1->insert("A");
  s2->insert("A");
  s2->insert("B");
  s2->insert("C");
  s2->insert("7");
  s2->insert("A");
  s2->insert("B");
  s2->insert("C");
  s2->insert("A");
  s2->insert("B");
  s2->insert("A");
  s3->insert("A");
  s3->insert("B");
  s3->insert("C");
  s3->insert("7");
  s3->insert("A");
  s3->insert("B");
  s3->insert("C");
  s3->insert("A");
  s3->insert("B");
  s3->insert("C");
}

//Setting up the RNG
void Virtualslotmachine::reel()
{
  int random = rand()%100;
  
  //Random Number for s1
  for(int i = 0; i < random; i++)
    {
      s1->head = s1->head->next;
    }
  random = rand()%100;
  for(int i = 0; i < random; i++)
    {
      s2->head = s2->head->next;
    }
  random = rand()%100;
  for(int i = 0; i < random; i++)
    {
      s3->head = s3->head->next;
    }
}

int Virtualslotmachine::pay()
{
  string v1 = s1->head->data;
  string v2 = s2->head->data;
  string v3 = s3->head->data;
  
  //Check for win. If win is detected then payout.
  
  if(v1 == v2 && v2 == v3)
    {
      if(v1 == "A")
        {
          return 6;
        }
      else if(v2 == "B")
        {
          return 15;
        }
      else if(v3 == "C")
        {
          return 50;
        }
      else
        {
          return 500;
        }
    }
  else
    {
      return 0;
    }
}

string Virtualslotmachine::getS1prev()
  {
    return s1->head->prev->data;
  }
  
  string Virtualslotmachine::gets1()
  {
    return s1->head->data;
  }
  
  string Virtualslotmachine::gets1next()
  {
    return s1->head->next->data;
  }
  
  string Virtualslotmachine::gets2prev()
  {
    return s2->head->prev->data;
  }

  string Virtualslotmachine::gets2()
  {
    return s2->head->data;
  }
  string Virtualslotmachine::gets2next()
  {
    return s2->head->next->data;
  }
  
  string Virtualslotmachine::gets3prev()
  {
    return s3->head->prev->data;
  }

  string Virtualslotmachine::gets3()
  {
    return s3->head->data;
  }
  
  string Virtualslotmachine::gets3next()
  {
    return s3->head->next->data;
  }