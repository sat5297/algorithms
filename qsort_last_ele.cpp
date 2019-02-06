//This is a quicksort program in which the last element has been used as pivot.
//Trace the program for better understanding.
#include<iostream>
#include<stdlib.h>


using namespace std;

long int partition(long int [] ,long int ,long int );
void swap(long int*,long int *);

/*
This is a sorting methodology in which the array is sorted by dividing the array in 2-parts corresponding to the index of the
sorted element in the array.(sorted element is the pivot element with index pi)

The pi is index of the pivot, the elements which are atmost pivot are to the left of the pi and the elements greater than pivot 
are on the right of the pi.
*/

void swap(long int *a,long int *b)
{
long int t = *a;
*a = *b;
*b = t;
}


void quicksort(long int arr[],long int low,long int high)
 {
   if(low < high)
     { 
  		long int pi = partition(arr,low,high);
  		quicksort(arr,low,pi-1);   // Part1 from index starting index and the pi-1 index.
  		quicksort(arr,pi+1,high);  // Part2 from pi + 1 index to the last index.
    }
 }


/*
The partition function gives the value of index about which the partition needs to be performed(the pi value), 
pivot element is at correct position whereas the elements to the  left and right of the index pi needs to be sorted using the
same mechanism.
*/


long int partition(long int arr[],long int low,long int high)
 {
   long int pivot = arr[high];
   long int i = low - 1;

  for(long int j = low; j <= high -1; j++)  // the loop needs to iterate to 1 less than high index as arr[high]=pivot
   {
      if( arr[j] <= pivot)            // Comparing the elements inorder to perform required operation.
        { 
          i ++;
          swap(&arr[j],&arr[i]);
        }
   }
    swap(&arr[i+1],&arr[high]);
    return(i+1);
 }
 
 
 int main()
 {
 int n,i;
 //accepting the size of the array and creating it. 
 
 cout << " Enter the number of elements in the array:"<< endl;
 cin >> n;
 long int a[n];
 cout << " Enter "<<  n << " elements:" << endl;
 for(i = 0;i < n;i++)
     cin >> a[i];
 quicksort(a,0,n);

 cout << "The sorted array: " << endl;

 for(i = 0;i < n;i++)
     cout << a[i] << " \t";
 return 0;
 }
 

