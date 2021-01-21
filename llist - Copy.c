#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void add_beg();
void add_after();
void del();
void rev();
void print_rev();
struct node
{
int data;
struct node *next;
} *start;
int main()
{
int ch,n,i;
//clrscr();
start=NULL;
while(1)
{
	printf("\n press 1:To create list:");
	printf("\n press 2:To display:");
	printf("\n press 3:To insert at begining:");
	printf("\n press 4:To add after:");
	printf("\n press 5:To delete:");
	printf("\n press 6:To reverse the list:");
	printf("\n press 7:To print reversely:");
	printf("\n press 8:To exit:");
	printf("\n enter your choice:");
	scanf("%d",&ch);
switch(ch)
{
	case 1:
	printf("\n how many no you want to store:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	create();
	}
	break;
	case 2:
		display();
		break;
	case 3:
		add_beg();
		break;
	case 4:
		add_after();
		break;
	case 5:
		del();
		break;
	case 6:
		rev();
		break;
	case 7:
		print_rev();
		break;
	case 8:
		exit(0);
	default:
		printf("\n wrong choice:");
		}
		   }
		       }
	void create()
	{
	struct node *temp,*q;
	temp=(struct node *)malloc(sizeof(struct node)) ;
	printf("\n enter the numbers:");
	scanf("%d",&temp->data);
	if(start==NULL)
	{
	temp->next=NULL;
	start=temp;
	return;
	}
	q=start;
	while(q->next!=NULL)
	{
	q=q->next;
	}
	temp->next=q->next;
	q->next=temp;
	}
		void display()
	{
	struct node *temp,*q;
	if(start==NULL)
	{
	printf("\n the list is not created");
	return;
	}
	printf("\n the list is:   \n Start-->");
	q=start;
	while(q!=NULL)
	{
	printf("%d-->",q->data);
	q=q->next;
	}
	//printf("NULL");
	printf("\b\b\b   ");
	}
		void add_beg()
	{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\n enter a value:");
	scanf("%d",&temp->data);
	temp->next=start;
	start=temp;
	}
		void add_after()
	{
	int pos,i;
	struct node *temp,*q;
	printf("\n enter the position after which youn want to insert:");
	scanf("%d",&pos);
	q=start;
	for(i=0;i<pos-1;i++)
	{
	if(q->next==NULL)
	{
	printf("\n invalid position");
	return;
	}
	q=q->next;
	}
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\n enter a value:");
	scanf("%d",&temp->data);
	temp->next=q->next;
	q->next=temp;
	}
		void del()
	{
	int item;
	struct node *q,*temp;
	printf("\n enter a value to be deleted:");
	scanf("%d",&item);
	if(item==start->data)
	{
	temp=start;
	start=start->next;
	free(temp);
	return;
	}
	q=start;
	while(q->next->next!=NULL)
	{
	if(q->next->data==item)
	{
	temp=q->next;
	q->next=temp->next;
	free(temp);
	}
	q=q->next;
	}
	if(q->next->data==item)
	{
	temp=q->next;
	q->next=temp->next;
	free(temp);
	}
	printf("\n item not found");
	}
	
	
	void rev()
	{
		struct node *p1,*p2,*p3;
		p1=start;
		p2=p1->next;
		p3=p2->next;
		p1->next=NULL;
		while(p3!=NULL)
		{
			p2->next=p1;
			p1=p2;
			p2=p3;
			p3=p2->next;
		}
		p2->next=p1;
		start=p2;
	}
	
	
	void print_rev()
	{
		struct node *p,*q;
		p=NULL;
		while(start!=p)
		{
			q=start;
			while(q->next!=p)
			{
				q=q->next;
			}
			printf("%d <-- ",q->data);
			p=q;
		}
		printf(" start");
	}

