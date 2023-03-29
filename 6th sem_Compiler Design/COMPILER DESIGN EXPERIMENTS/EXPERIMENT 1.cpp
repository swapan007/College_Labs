/*
experiment-1
Write a C program to identify whether a given line is a comment or not.


LOGIC: Read the input string. Check whether the string is starting with „/" and check next character is „/" or"*". If condition satisfies print comment. Else not a comment
*/

#include<stdio.h>
#include<conio.h>
int main() {
char com[30];
int i=2,a=0;
//clrscr();
printf("\n Enter comment:");
gets(com);
if(com[0]=='/') {
if(com[1]=='/')
printf("\n It is a comment");
else if(com[1]=='*') {
for(i=2;i<=30;i++)
{
if(com[i]=='*'&&com[i+1]=='/')
{
printf("\n It is a comment");
a=1;
break; }
else
continue; }
if(a==0)
printf("\n It is not a comment");
}
else
printf("\n It is not a comment");
}
else
printf("\n It is not a comment");
getch();
return 0;

 }
