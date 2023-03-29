/*
AIM:
Write a program to implement Knapsack Problem.
In Fractional Knapsack, we can break items for maximizing the total value of knapsack. This 
problem in which we can break an item is also called the fractional knapsack problem.
Input : 
 Same as above
Output :
 Maximum possible value = 240
 By taking full items of 10 kg, 20 kg and 
 2/3rd of last item of 30 kg
An efficient solution is to use Greedy approach. The basic idea of the greedy approach is to 
calculate the ratio value/weight for each item and sort the item on basis of this ratio. Then take 
the item with the highest ratio and add them until we can’t add the next item as a whole and 
at the end add the next item as much as we can. Which will always be the optimal solution to 
this problem.
A simple code with our own comparison function can be written as follows, please see sort 
function more closely, the third argument to sort function is our comparison function which 
sorts the item according to value/weight ratio in non-decreasing order.
After sorting we need to loop over these items and add them in our knapsack satisfying abovementioned criteria.
As main time taking step is sorting, the whole problem can be solved in O(n log n) only.
*/
//PROGRAM

// C++ program to solve fractional Knapsack Problem
#include <bits/stdc++.h>
using namespace std;
// Structure for an item which stores weight and corresponding
// value of Item
struct Item
{
 int value, weight;
 // Constructor
 Item(int value, int weight) : value(value), weight(weight)
 {}
};
// Comparison function to sort Item according to val/weight ratio
bool cmp(struct Item a, struct Item b)
{
 double r1 = (double)a.value / a.weight;
 double r2 = (double)b.value / b.weight;
 return r1 > r2;
}
double fractionalKnapsack(int W, struct Item arr[], int n)
{
 sort(arr, arr + n, cmp);
 // Uncomment to see new order of Items with their ratio /*
 for (int i = 0; i < n; i++)
 {
 cout << arr[i].value << " " << arr[i].weight << " : "
 << ((double)arr[i].value / arr[i].weight) << endl;
 }
// */
 int curWeight = 0; // Current weight in knapsack
 double finalvalue = 0.0; // Result (value in Knapsack)
 for (int i = 0; i < n; i++)
 {
 if (curWeight + arr[i].weight <= W)
 {
 curWeight += arr[i].weight;
 finalvalue += arr[i].value;
 }
 // If we can't add current Item, add fractional part of it
 else
 {
 int remain = W - curWeight;
 finalvalue += arr[i].value * ((double) remain / arr[i].weight);
 break;
 } 
 }
 return finalvalue;
}
// driver program to test above function
int main()
{
 int W = 50; // Weight of knapsack
 Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
 int n = sizeof(arr) / sizeof(arr[0]);
 cout << "Maximum value we can obtain = "
 << fractionalKnapsack(W, arr, n);
 return 0;
}

