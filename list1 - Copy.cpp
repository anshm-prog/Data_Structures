#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
//Structure declaration for the node
struct node
{
int info;
struct node *link;
}*start;
//This function will create a new linked list
void Create_List(int data)
{
struct node *q,*tmp;
//Dynamic memory is been allocated for a node
tmp= (struct node*)malloc(sizeof(struct node));
tmp->info=data;
tmp->link=NULL;
if(start==NULL) /*If list is empty*/
start=tmp;
else
{ /*Element inserted at the end*/
q=start;
while(q->link!=NULL)
q=q->link;
q->link=tmp;
}
}/*End of create_list()*/

