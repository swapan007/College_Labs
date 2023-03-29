/*
AIM:
Write a program to implement Dijkstra’s algorithm for the Single 
source shortest path problem.
Dijkstra’s algorithm.
1) Create a set S that keeps track of vertices included in shortest path tree, i.e., whose minimum
distance from source is calculated and finalized. Initially, this set is empty.
2) Assign a distance value to all vertices in the input graph. Initialize all distance values as
INFINITE.Assign distance value as 0 for the source vertex so that it is picked first.
3) While S doesn’t include all vertices
a) Pick a vertex u which is not there in S and has minimum distance value.
b)Include u to S.
c) Update distance value of all adjacent vertices of u.
To update the distance values, iterate through all adjacent vertices. For every adjacent vertex 
v, if
sum of distance value of u (from source) and weight of edge u-v, is less than the distance value 
of v,
then update the distance value of v.
*/
//SOURCE CODE:
#include<stdio.h>
#define infinity 999
void dij(int n, int v,int cost[20][20], int dist[]){
int i,u,count,w,flag[20],min;
for(i=1;i<=n;i++)
flag[i]=0, dist[i]=cost[v][i];
count=2;
while(count<=n){
min=99;
for(w=1;w<=n;w++)
if(dist[w]<min && !flag[w]) {
min=dist[w];
u=w;
}
flag[u]=1;
count++;
for(w=1;w<=n;w++)
if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
dist[w]=dist[u]+cost[u][w];
}
}
int main(){
int n,v,i,j,cost[20][20],dist[20];
printf("enter the number of nodes:");
scanf("%d",&n);
printf("\n enter the cost matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++){
scanf("%d",&cost[i][j]);
if(cost[i][j] == 0)
cost[i][j]=infinity;
}
printf("\n enter the source matrix:");
scanf("%d",&v);
dij(n,v,cost,dist);
printf("\n shortest path : \n");
for(i=1;i<=n;i++)
if(i!=v)
printf("%d->%d,cost=%d\n",v,i,dist[i]);
}

