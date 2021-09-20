#include <cstdio>
#include <cstring>
#include <cstdlib>


// this class is used to hold information for each position of the  list in MyList...
class MyNode{
  private:
  int elem;
  MyNode* Next;

  public:
  MyNode(int v1);


  MyNode(int v1, MyNode* n);


  void setElem(int v);

  int getElem();


  void setNext(MyNode* n);


  MyNode* getNext();


};
// this class utilizes the aforementioned MyNode to store information in an easy to accesss list...
class MyList{
  private:
  MyNode* head;

  public:

  MyList();


  void insert(int v);


  void remove (int v1);


  void show();


  int Size();
	
  MyNode* getHead();

};

// this class utilizes the aforementioned MyList as its adjaceny list to keep track of its ferry rides to other islands...
class Island{
  private:
  MyList List;
  bool visited;

  public:

  Island();

  MyList getList();

  void setList(MyList leest);
  
  bool getVisited();

  void setVisited(bool h);

};