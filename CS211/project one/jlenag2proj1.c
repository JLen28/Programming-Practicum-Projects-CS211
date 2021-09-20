/////////////////////////////////////////////////
//////////////////Project One
//// Joseph Lenaghan
//// University of Illinois at Chicago
//// CS 211
//// UIN: 676805596 | netID: jlenag2 | 9/11/2019
///////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
/////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

// copy function below, accepts array that needs copying, and array
// that will hold the copy, as well as the current size...
void arrayCopy(int fromArray[], int toArray[], int size) {
  int i = 0;
    for ( i = 0; i < size; i++) {
        toArray[i] = fromArray[i];
    }
}// end copy function...

// sort function accepts any array and the current size and sorts it // ascending order... 
void sort(int sortedArr[], int size) {
    int j = 0;
    int temp = 0;
    int i;
    int k;

    for ( i = 0; i < size - 1; i++) {

        j = i;
        //if the if is satisfied then it is properly sorted,
        // so the for loop continues...
        for ( k = i + 1; k < size; k++) {
            if (sortedArr[k] < sortedArr[i] && sortedArr[k] < sortedArr[j]) {
                j = k;
            }
        }
        //j does not equal i they are not proper, so properly arrange them...
        if (j != i) {
            temp = sortedArr[i];
            sortedArr[i] = sortedArr[j];
            sortedArr[j] = temp;
        }


    }


}// end sort function...

// Two sum search function follows the logic presented in
// class, the low and high pointer respond to the addition
// of their data values by one or the other shifting based on the results of the addition...
int* sumSearch(int A[], int arr_size, 
                           int sum) 
{ 
    int l = 0; 
    int r = 0; // tail and head initialized...


    l = 0; // head...
    r = arr_size - 1; // tail...
    while (l < r) { 
        if (A[l] + A[r] == sum){
            int static temp[3];
            temp[0] = 1;
            temp[1] = l;
            temp[2] = r;
            return temp;
        }
        else if (A[l] + A[r] < sum){ // move the head...
            l = l + 1;
        }
        else{ // A[i] + A[j] > sum move the tail...
            r = r - 1;
        } 
    }
    // unsuccessful search...
    int temp[1];
    temp[0] = -1;  
    return temp; 
}// end Two sum search....

int main (int argc, char** argv)
{
 int val; // target value...
 int *arr1; // initial array that will hold first couple values...
 int *arr2; // copy array...
 int allocated = 10; // initial array size....
 arr1 =(int*)malloc(allocated*sizeof(int)); // array intiialized..
 int counter = 0; // counter to access the individual positions of the array...

 /* prompt the user for input */
 printf ("Enter in a list of numbers ito be stored in a dynamic array.\n");
 printf ("End the list with the terminal value of -999\n");
 
 /* loop until the user enters -999 */
 scanf ("%d", &val);
 while (val != -999)
   {
     arr1[counter] = val; // given counter position is set to red value...
     if(counter == allocated){ // full?
       int *temp = arr1; // temp holds arrays info...
       //new array initialized with double the space...
       arr1 = (int*)malloc(allocated*2*sizeof(int));
       int i =  0; // counter
       for(i = 0; i < allocated; i++){
         arr1[i] = temp[i]; // fill new array with old info...
       }
       free (temp); // old memory is recovered, now get
       // rid of temp...
       allocated = allocated * 2; /* corresponding size
       integer is doubled...*/
           
     }
     counter++; // counter accounts for each position of array
    /* get next value */
    scanf("%d", &val);
   }// end while...

 /* call function to make a copy of the array of values */
 // copy array initialized so it can hold first arrays data...
 arr2 = (int*)malloc(allocated*sizeof(int)); 
 arrayCopy(arr1,arr2,allocated);

 /* call function to sort one of the arrays */
 sort(arr1,allocated);

 /* loop until the user enters -999 */
 printf ("Enter in a list of numbers to use for searching.  \n");
 printf ("End the list with a terminal value of -999\n");
 scanf ("%d", &val);
 // array is defined to hold the return result of the sum
 // function
 int* result;
 while (val != -999)
   {

    /* call function to perform target sum operation */
    result = sumSearch(arr1,allocated,val);



    /* print out info about the target sum results  */
    //successful!...
    if(result[0] == 1){
    // print statement block that relays return information
    printf("Success! \n");
    printf("The target value was: %d\n", val);
    printf("Index position one: %d\n",result[1]);
    printf("Index position two: %d\n",result[2]);
    }// end if...
    //unsuccessful!...
    else if(result[0]==-1){
      printf("Sum search unsuccesful, Try again!\n");
      result[0] = 0;
    }// end else if....

   

    /* get next value */
    scanf("%d", &val);
   }// end while...


 //printf ("Good bye\n"); // all done!
 return 0;
}// end main...
