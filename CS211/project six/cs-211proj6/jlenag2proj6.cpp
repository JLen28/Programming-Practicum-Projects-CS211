#include "island.h"


// this class stores all the filenames in a Linked list that can be used to check if a filename is already open...
class fileList{
  private:
  char* filename;
  fileList* Next;

  public:

  fileList() // initializer...
  {
    Next = NULL;
  }
  fileList(char* f) // initializer...
  {
   filename = f;
   Next = NULL; 
  }

  fileList(char* f, fileList* n) // copy constructor...
  {
    filename = f;
    Next = n;
  }

  void addFileName(char* f) // add a file to the LL
  {
    filename = f;
  }

  char* getFileName() // return the stored filename for the node...
  {
    return filename;
  }

  void setNext(fileList* f) // set the Nodes Next...
  {
    Next = f;
  }

  fileList* getNext() // return the next of the node...
  {
    return Next;
  }
  int Size(fileList* head) // return the size of the LL...
  {
    fileList* tmp = head;
    int counter = 0;
    while(tmp != NULL)
    {
      counter++;
      tmp = tmp->getNext();
    }
    return counter;
  }

  bool alreadyOpen(fileList* head,char* f) // is the file already open? ( is it in the linked list?)...
  {
    fileList* tmp = head;
    while(tmp != NULL)
    {
      if(tmp->getFileName() == f)
      {
        return true;
      }
      tmp = tmp->getNext();
    }
    return false;
  }
  void remove (fileList* head,char* v1) // remove a file from the list when we are all finished with it...
  {
    fileList* tmp = head;
    fileList* prev = NULL;
    while((tmp != NULL))
    {
      if (tmp->getFileName() == v1) break;
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
};

// provided ArchipelagoExpedition class is now modified to utilize Island, MyNode, and MyList class...
class ArchipelagoExpedition
{
 private:
    Island* aList;
    int NIslands;
    fileList* head; 
  
 public:
  
 // Use a constructor to initialize the Data Members for your expedition
 ArchipelagoExpedition() // initialize...
 {
    NIslands = 10;
    aList = new Island[NIslands];
    head = new fileList();
 }
  
  
 // The main loop for reading in input
 void processCommandLoop (FILE* inFile) 
 {
  char  buffer[300];
  char* input;

  input = fgets ( buffer, 300, inFile );   // get a line of input
    
  // loop until all lines are read from the input
  while (input != NULL)
  {
    // process each line of input using the strtok functions 
    char* command;
    command = strtok (input , " \n\t");

    printf ("*%s*\n", command);
    
    if ( command == NULL )
      printf ("Blank Line\n");
 
    else if ( strcmp (command, "q") == 0) 
      exit(1);
     
    else if ( strcmp (command, "?") == 0) 
      showCommands();
     
    else if ( strcmp (command, "t") == 0) 
      doTravel();
     
    else if ( strcmp (command, "r") == 0)
      doResize();
    

    else if ( strcmp (command, "i") == 0) 
      doInsert();

    else if ( strcmp (command, "d") == 0) 
      doDelete();

    else if ( strcmp (command, "l") == 0) 
      doList();

    else if ( strcmp (command, "f") == 0) 
      doFile();

    else if ( strcmp (command, "#") == 0) 
      ;
     
    else
      printf ("Command is not known: %s\n", command);
     
    input = fgets ( buffer, 300, inFile );   // get the next line of input

  }
 }
 
 void showCommands()
 {
   printf ("The commands for this project are:\n");
   printf ("  q \n");
   printf ("  ? \n");
   printf ("  # \n");
   printf ("  t <int1> <int2> \n");
   printf ("  r <int> \n");
   printf ("  i <int1> <int2> \n");
   printf ("  d <int1> <int2> \n");
   printf ("  l \n");
   printf ("  f <filename> \n");
 }
 // helper function to figure out where there is a ferry and where there isnt...
 void depthFirstSearchHelper(int x, int y)
 {
   for(int i = 0; i < NIslands; i++)
   {
     aList[i].setVisited(false);
   }
   if(dfs(x,y) == true)
   {
     printf("You can get from island %d", x);
     printf(" to island ");
     printf("%d in one or more ferry rides \n", y);
   }
   else
   {
     printf("You can NOT get from island %d", x);
     printf(" to island ");
     printf("%d in one or more ferry rides \n", y); 
   }
 }
// this dfs function is called by the above helper and is utilized to find one or more ferries between islands if they exist.
 bool dfs(int a, int b)
 {
   int index = a;
   MyList p = aList[index].getList();
   int Size = p.Size();
   MyNode* tmp = p.getHead();
   for(int i = 0; i < Size; i++)
   {
     int result = tmp->getElem();
     if(result == b)
     {
       return true;
     }
     if(aList[index].getVisited() == false)
     {
       aList[index].setVisited(true);
       if(dfs(result,b) == true)
       {
         return true;
       }
     }
   }
  return false;
 }
 
 void doTravel()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   //printf("%s\n", next);
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");

   //printf("%s\n", next);
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   if((val2 > NIslands) || (val1 > NIslands) || (val2 < 0) || (val1 < 0))
   {
     printf("One or more integers out of range\n");
     return;
   }
   
   
   printf ("Performing the Travel Command from %d to %d\n", 
            val1, val2);

  depthFirstSearchHelper(val1, val2);
   
 }
 
 void doResize()
 {
    int val1 = 0;
    char* next = strtok (NULL, " \n\t");
    //printf("%s\n", next);
    if ( next == NULL )
    {
      printf ("Integer value expected\n");
      return;
    }
    val1 = atoi ( next );
    if ( val1 == 0 && strcmp (next, "0") != 0)
    {
      printf ("Integer value expected\n");
      return;
    }
    printf ("Performing the Resize Command with %d\n", val1 );
    Island* tmp = aList;
    NIslands = val1;
    aList = new Island[val1];
    delete tmp;
 }
 
 void doInsert()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   //printf("%s\n", next);
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");

   //printf("%s\n", next);
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   if((val2 > NIslands) || (val1 > NIslands) || (val2 < 0) || (val1 < 0))
   {
     printf("One or more integers out of range\n");
     return;
   }
   aList[val1].setVisited(true);
   aList[val2].setVisited(true);
   MyList leest = aList[val1].getList();
   leest.insert(val2);
   aList[val1].setList(leest);
 }
 
 void doDelete()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   //printf("%s\n", next);
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");

   //printf("%s\n", next);
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   if((val2 > NIslands) || (val1 > NIslands) || (val2 < 0) || (val1 < 0))
   {
     printf("One or more integers out of range\n");
     return;
   }
   aList[val1].setVisited(false);
   aList[val2].setVisited(false);
   MyList leest = aList[val1].getList();
   leest.remove(val2);
   aList[val1].setList(leest);
 }
 
 void doList()
 {
   for(int i = 0; i < NIslands; i++)
   {
     printf("For Island: %d\n", i);
     if(aList[i].getList().Size() == 0)
     {
       printf("No current ferries \n");
     }
     else
     {
        aList[i].getList().show();
     }

   }
 }
 
 void doFile()
 {
   char* fName = strtok (NULL, "\n\t");
   if( fName == NULL)
   {
     printf("Filename expected\n");
     return;
   }

   printf("Perfoming the File command with file: %s\n", fName);
   if(head->alreadyOpen(head,fName) == true)
   {
     printf("Error! file is already open, try a different file...\n");
     return;
   }
   head->addFileName(fName);
   FILE* pFile;
   pFile = fopen(fName, "r");

   if(!pFile){
     printf("No matching text file found in directory...Exiting\n");
     return;
   }

   this->processCommandLoop(pFile);

   head->remove(head,fName);

   fclose(pFile);

 }
};


int main (int argc, char** argv)
{
  // set up the variable inFile to read from standard input
  FILE* inFile = stdin;



  // set up the data needed for the island adjcency list
  ArchipelagoExpedition islandData;
   
  // call the method that reads and parses the input
  islandData.showCommands();
  printf ("\nEnter commands at blank line\n");
  printf ("    (No prompts are given because of f command)\n");
  islandData.processCommandLoop (inFile);
   
  printf ("Goodbye\n");
  return 1;
 }