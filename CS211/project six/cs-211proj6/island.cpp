#include "island.h"



  Island::Island() // Island Constructor...
  {
    visited = false;
  }

  MyList Island::getList() // get the list for an Island...
  {
    return List;
  }

  void Island::setList(MyList leest) // set the current list with an updated list...
  {
    List = leest;
  }
  
  bool Island::getVisited() // return the visited status of the current island...
  {
    return visited;
  }

  void Island::setVisited(bool h) // set the visited status of the current island...
  {
    visited = h;
  }


  MyList::MyList() // constructor for list...
  {
    head = NULL;
  }

  void MyList::insert(int v) // insert a node into the list...
  {
    MyNode* tmp = new MyNode(v);
    tmp->setNext(head);
    head = tmp;
  }

  void MyList::remove (int v1) // remove a node from the list...
  {
    MyNode* tmp = head;
    MyNode* prev = NULL;
    while((tmp != NULL))
    {
      if (tmp->getElem() == v1) break;
      prev = tmp;
      
      tmp = tmp->getNext();
    }
    if (tmp == NULL) // we could not find v1 in the list
      return;
      
    if(prev == NULL)
    {
      delete tmp;
      head = NULL;
    }
    else
    {
      prev->setNext(tmp->getNext());
      delete tmp;
    }
    
  }

  void MyList::show() // show the current list, used in displaying all the information regarding each island...
  {
    MyNode* tmp = head;
    while(tmp != NULL)
    {
      printf("Has a ferry to: %d\n",tmp->getElem());
      tmp = tmp->getNext();
    }
  }

  int MyList::Size() // return the current size of the list...
  {
    MyNode* tmp = head;
    int counter = 0;
    while(tmp != NULL)
    {
      counter++;
      tmp = tmp->getNext();
    }
    return counter;
  }


  MyNode* MyList::getHead() // get the head of the list...
  {
    return head;
  }



  MyNode::MyNode(int v1) // constructor for nodes that will go into the list...
  {
    elem = v1;
    Next = NULL;
  }

  MyNode::MyNode(int v1, MyNode* n) // a copy constructor...
  {
    elem = v1;
    Next = n;
  }

  void MyNode::setElem(int v) // set the element of the node...
  {
    elem = v;
  }

  int MyNode::getElem() // get the element of the node...
  {
    return elem;
  }

  void MyNode::setNext(MyNode* n) // set the next pointer for the node...
  {
    Next = n;
  }

  MyNode* MyNode::getNext() // return the next node pointer for the node..
  {
    return Next;
  }