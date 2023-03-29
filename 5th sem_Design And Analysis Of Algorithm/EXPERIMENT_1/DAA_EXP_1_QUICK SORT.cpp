/*

AIM:
WAP to implement Quick sort algorithm for sorting a list of integers in ascending order

THEORY – 

Quicksort is a well-known sorting algorithm developed by C. A. R. Hoare that, on 
average, makes O(nlogn) (big O notation) comparisons to sort n items. However, in the worst 
case, it makes O(n2) comparisons. Typically, quicksort is significantly faster in practice than 
other O(nlogn) algorithms, because its inner loop can be efficiently implemented on most 
architectures, and in most real-world data it is possible to make design choices which minimize 
the probability of requiring quadratic time.

Quicksort is a comparison sort and, in efficient implementations, is not a stable sort.

Quicksort sorts by employing a divide and conquer strategy to divide a list into two sub-lists.
The steps are:
• Pick an element, called a pivot, from the list. 
• Reorder the list so that all elements which are less than the pivot come before the pivot 
and so that all elements greater than the pivot come after it (equal values can go either 
way). After this partitioning, the pivot is in its final position. This is called the partition 
operation. 
• Recursively sort the list of lesser elements and the list of greater elements in sequence. 
The base cases of the recursion are lists of size zero or one, which are always sorted.

*/
// PROGRAM – 

#include <iostream>
using namespace std;
void quick_sort(int[],int,int);
int partition(int[],int,int);
int main()
{
 int a[50],n,i;
 cout<<"How many elements?";
 cin>>n;
 cout<<"\nEnter array elements:";
 
 for(i=0;i<n;i++)
 cin>>a[i];
 
 quick_sort(a,0,n-1);
 cout<<"\nArray after sorting:";
 
 for(i=0;i<n;i++)
 cout<<a[i]<<" ";
 
 return 0; 
}
void quick_sort(int a[],int l,int u)
{
 int j;
 if(l<u)
 {
 j=partition(a,l,u);
 quick_sort(a,l,j-1);
 quick_sort(a,j+1,u);
 }
}
int partition(int a[],int l,int u)
{
 int v,i,j,temp;
 v=a[l];
 i=l;
 j=u+1;
 
 do
 {
 do
 i++;
 
 while(a[i]<v&&i<=u);
 
 do
 j--;
 while(v<a[j]);
 
 if(i<j)
 {
 
 temp=a[i];
 a[i]=a[j];
 a[j]=temp;
 }
 }while(i<j);
 
 a[l]=a[j];
 a[j]=v;
 
 return(j);
}

