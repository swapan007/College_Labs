/*
AIM:
Write a program that implements Prim’s algorithm to generate 
minimum cost spanning tree.
PROGRAM LOGIC:
1) Create a set S that keeps track of vertices already included in MST.
2) Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE.
Assign key value as 0 for the first vertex so that it is picked first.
3) While S doesn’t include all vertices.
a) Pick a vertex u which is not there in Sand has minimum key value.
b) Include u to S.
c) Update key value of all adjacent vertices of u.
To update the key values, iterate through all adjacent vertices. For every adjacent vertex v, if
weight of edge u-v is less than the previous key value of v, update the key value as weight of 
u-v
The idea of using key values is to pick the minimum weight edge from cut. The key values are 
used
only for vertices which are not yet included in MST, the key value for these vertices indicate 
the
minimum weight edges connecting them to the set of vertices included in MST.
*/

#include<stdio.h>
int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10];
int main()
{
printf("\n Enter the number ofnodes:"); scanf("%d",&n);
printf("\n Enter the adjacency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++){
scanf("%d",&cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=999;
}
visited[1]=1;
printf("\n");
while(ne<n)
{
for(i=1,min=999;i<=n;i++)
for(j=1;j<=n;j++)
if(cost[i][j]<min)
if(visited[i]!=0)
{
min=cost[i][j];
a=u=i;
b=v=j;
}
if(visited[u]==0 || visited[v]==0)
{
printf("\n Edge %d:(%d %d");
printf("cost:%d",ne++,a,b,min); 
mincost+=min;
visited[b]=1;
}
cost[a][b]=cost[b][a]=999;
}
printf("\n Minimun cost=%d",mincost);
//return 0;
}
