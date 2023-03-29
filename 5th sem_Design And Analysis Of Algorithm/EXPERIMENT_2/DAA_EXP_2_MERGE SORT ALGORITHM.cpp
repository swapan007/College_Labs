/*
AIM:
Write a program to implement Merge sort algorithm for sorting a list 
of integers in ascending order.

Theory:-

 Like QuickSort, Merge Sort is a Divide and Conquer algorithm. It divides input 
array in two halves, calls itself for the two halves and then merges the two sorted 
halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is 
key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two 
sorted sub-arrays into one. See following C implementation for details.
MergeSort(arr[], l, r)
If r > l
 1. Find the middle point to divide the array into two halves: 
 middle m = (l+r)/2
 2. Call mergeSort for first half: 
 Call mergeSort(arr, l, m)
 3. Call mergeSort for second half:
 Call mergeSort(arr, m+1, r)
 4. Merge the two halves sorted in step 2 and 3:
 Call merge(arr, l, m, r)
Time Complexity: Sorting arrays on different machines. Merge Sort is a recursive 
algorithm and time complexity can be expressed as following recurrence relation.
T(n) = 2T(n/2) + 
The above recurrence can be solved either using Recurrence Tree method or Master 
method. It falls in case II of Master Method and solution of the recurrence is .
Time complexity of Merge Sort is in all 3 cases (worst, average and best) as merge 
sort always divides the array in two halves and take linear time to merge two halves.
Auxiliary Space: O(n)
Algorithmic Paradigm: Divide and Conquer
Sorting In Place: No in a typical implementation
Stable: Yes
*/
// Program:-

#include <iostream>
using namespace std;
// A function to merge the two half into a sorted data.
void Merge(int *a, int low, int high, int mid)
{
// We have low to mid and mid+1 to high already sorted.
int i, j, k, temp[high-low+1];
i = low;
k = 0;
j = mid + 1;
// Merge the two parts into temp[].
while (i <= mid && j <= high)
{
if (a[i] < a[j])
{
temp[k] = a[i];
k++;
i++;
}
else
{
temp[k] = a[j];
k++;
j++;
}
}
// Insert all the remaining values from i to mid into temp[].
while (i <= mid)
{
temp[k] = a[i];
k++;
i++;
}
// Insert all the remaining values from j to high into temp[].
while (j <= high)
{
temp[k] = a[j];
k++;
j++;
}
// Assign sorted data stored in temp[] to a[].
for (i = low; i <= high; i++)
{
a[i] = temp[i-low];
}
}
// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
int mid;
if (low < high)
{
mid=(low+high)/2;
// Split the data into two half.
MergeSort(a, low, mid);
MergeSort(a, mid+1, high);
// Merge them to get sorted output.
Merge(a, low, high, mid);
}
}
int main()
{
int n, i;
cout<<"\nEnter the number of data element to be sorted: ";
cin>>n;
int arr[n];
for(i = 0; i < n; i++)
{
cout<<"Enter element "<<i+1<<": ";
cin>>arr[i];
}
MergeSort(arr, 0, n-1);
// Printing the sorted data.
cout<<"\nSorted Data ";
for (i = 0; i < n; i++)
 cout<<"->"<<arr[i];
return 0;
}

