 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// stack defined...
typedef struct Stack{
  int* darr;
  int allocated;
  int inUse;
}stack; // end stack definition...

// stack initializer...
stack* init(int allocated){
  stack* cur = (stack*)malloc(sizeof(stack));
  cur->allocated = allocated;
  cur->inUse = -1;
  cur->darr = (int*)malloc(cur->allocated *sizeof(int));
  return cur;
} // end initializer...

//full function checks for full capacity of the stack...
int isFull(stack* cur){
  return cur->inUse == cur->allocated - 1;
}// end full...
// empty function checks if stack is empty...
int isEmpty(stack* cur){

  return cur->inUse == - 1;
}// end empty...

int increased(stack* cur,int debug){
  stack* temp = init(cur->allocated);

  int m;
  for(m = 0; m < cur->allocated; m++){
      temp->darr[m] = cur->darr[m];
  }

  cur->allocated = cur->allocated + 4;
  cur->darr = (int*)malloc(cur->allocated * sizeof(int));

  for(m = 0; m <= temp->allocated; m++){
    if(debug == 1){ 
      printf("elements from old list: ");
      printf("%c\n",temp->darr[m]);
      }
      cur->darr[m] = temp->darr[m];
  }
  free(temp);
  return 0;
}

// pushback function...
void push(stack* cur,int val,int debug){
  
  cur->inUse += 1;
  if(cur->inUse == cur->allocated -1){
    if( debug == 1){
     printf("Array Full! Incrementing...\n");
    }
    increased(cur,debug);
  }
   cur->darr[cur->inUse] = val;
} // end pushback...

// pop function...
int pop(stack* cur){
  if(isEmpty(cur)){
    return INT_MIN;
  }
  return cur->darr[cur->inUse--];
}// end pop...

// peek function, looks at the top of the stack...
int peek(stack* cur){
  if(isEmpty(cur)){
    return INT_MIN;
  }
  return cur->darr[cur->inUse];
} // end peek...

// clear function clears the stack...
void clear(stack* cur){
  int i = 0;
  while(i < cur->allocated){
    pop(cur);
    i++;

  }
} // end clear...
// function that accepts a string and trims it properly...
void removeExtraLetter(char *str[15]){
  char* q;
  char* output;
  for(q = str[0]; *q != '\0'; q++ ){
     if (*q == 'a'){
      printf("%c",*q);
    }
    else if(*q == 'b'){
      printf("%c",*q);
    }
    else if(*q == 'c'){
      printf("%c",*q);
    }
    else if(*q == 'd'){
      printf("%c",*q);
    }
}
} // end removeExtraLetter...


int main(int argc, char const *argv[])
{
	
	char input[300];
  int debugMode = 0; // debug begins in the off position..
	
	 /* set up an infinite loop */
 while (1)
 {
   /* get line of input from standard input */
   printf ("\nEnter input to check or q to quit\n");
   fgets(input, 300, stdin);

   /* remove the newline character from the input */
   int i = 0;
   while (input[i] != '\n' && input[i] != '\0')
   {
      i++;
   }
   input[i] = '\0';


   /* check if user enter q or Q to quit program */
   if ( (strcmp (input, "q") == 0) || (strcmp (input, "Q") == 0) )
     break;
   else if( (strcmp(input, "-e") == 0)){
     if(debugMode == 1){
       printf("Debug mode disabled...\n"); // disable debug
       debugMode = 0;
     }
     else{
     printf("Debug mode enabled...\n"); // enable debug
     debugMode = 1;
     }
   }
 
   
   /*Start tokenizing the input into words separated by space
    We use strtok() function from string.h*/
   /*The tokenized words are added to an array of words*/
   
   char delim[] = " ";
   char *ptr = strtok(input, delim);
   int j = 0 ; 
   char *wordList[15];
  

	while (ptr != NULL)
	{	
		wordList[j++] = ptr;
		ptr = strtok(NULL, delim);
	}
  char *c; // pointer to walk through wordList...
  stack* cur = init(4); // stack initialized...
  // decode algorithm begins below...
  for(c = wordList[0]; *c != '\0'; c++)
  {
    if (*c == 'a'){
      push(cur,*c,debugMode);
      if (debugMode == 1){
        printf("Push a!\n");
        printf("current stack size: ");
        printf("%d\n",cur->inUse);
      }
    }
    else if(*c == 'b'){
      push(cur,*c,debugMode);
      if (debugMode == 1){
        printf("Push b!\n");
          printf("current stack size: ");
        printf("%d\n",cur->inUse);
      }
    }
    else if(*c == 'c'){
      if (debugMode == 1){
        push(cur,*c,debugMode);
        printf("Push c!\n");
          printf("current stack size: ");
        printf("%d\n",cur->inUse);
      }
    }
    else if(*c == 'd'){
      push(cur,*c,debugMode);
      if (debugMode == 1){
        printf("Push d!\n");
        printf("current stack size: ");
        printf("%d\n",cur->inUse);
      }
    }
    else{
      if(*c == 'm'){
        char result = peek(cur);
        if(result == 'a'){
          if (debugMode == 1){
            printf("Pop a!\n");
              printf("current stack size: ");
        printf("%d\n",cur->inUse);
          }
          pop(cur);
        }
        else{continue;}
      }
      else if(*c == 'n'){
        char result = peek(cur);
        if(result == 'b'){
          if (debugMode == 1){
            printf("Pop b!\n");
              printf("current stack size: ");
        printf("%d\n",cur->inUse);
          }
          pop(cur);
        }
        else{continue;}
      }
      else if(*c == 'o'){
        char result = peek(cur);
        if(result == 'c'){
          if (debugMode == 1){
            printf("Pop c!\n");
              printf("current stack size: ");
        printf("%d\n",cur->inUse);
          }
          pop(cur);
        }
        else{continue;}
      }
      else if(*c == 'p'){
        char result = peek(cur);
        if(result == 'd'){
          if (debugMode == 1){
            printf("Pop d!\n");
              printf("current stack size: ");
        printf("%d\n",cur->inUse);
          }
          pop(cur);
        }
        else{continue;}
      }
     }
   } // end the decode algorithm...
   if(isEmpty(cur)){ // decode successful...
     char *n;
     removeExtraLetter(wordList);
   }
   else(printf("stack not empty\n")); // unsuccessful decode...



 }

 printf ("\nGoodbye\n");





	return 0;
}