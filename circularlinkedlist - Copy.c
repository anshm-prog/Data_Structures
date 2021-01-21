#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void add_beg();
void add_after();
void del();

struct node
{
	int data;
	struct node *next;
} *last;

int main()
{
	int ch,n,i;
	//clrscr();
	last=NULL;
	while(1)
	{
		printf("\n press 1:To create list:");
		printf("\n press 2:To display:");
		printf("\n press 3:To insert at begining:");
		printf("\n press 4:To add after:");
		printf("\n press 5:To delete:");
		printf("\n press 6:To exit:");
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
				exit(0);
			default:
				printf("\n wrong choice:");
		}
   }
}
	
	void create()
	{
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node)) ;
		printf("\n enter the number/item : ");
		scanf("%d",&temp->data);
		if(last==NULL)
		{
			last=temp;
			last->next=last;
			return;
		}
		temp->next=last->next;
		last->next=temp;
		last=temp;
	}
	
	void display()
	{
		int i=0,j;
		struct node *q;
		if(last==NULL)
		{
			printf("\n the list is empty");
			return;
		}
		q=last->next;
		printf("\n the list is:   \n");
		while(q!=last)
		{
			printf("%d-->",q->data);
			q=q->next;
			i++;
		}
		printf("%d<--Last\n^",last->data);
		j=5*i;
		for(i=0;i<=j;i++)
		
			printf("-");
			printf("|");
	}
		
	void add_beg()
	{
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		printf("\n enter a value:");
		scanf("%d",&temp->data);
		temp->next=last->next;
		last->next=temp;
	}
		
	void add_after()
	{
		int pos,i;
		struct node *temp,*q;
		printf("\n enter the position after which youn want to insert:");
		scanf("%d",&pos);
		q=last->next;
		for(i=0;i<pos-1;i++)
		{
			if(q==last)
			{
				printf("\n invalid position");
				return;
			}
			q=q->next;
		}
		temp=(struct node *)malloc(sizeof(struct node));
		printf("\n enter a value:");
		scanf("%d",&temp->data);
		if(q==last)
		{
			temp->next=q->next;
			q->next=temp;
			last=temp;
			return;
		}
		temp->next=q->next;
		q->next=temp;
	}
	
	void del()
	{
		int item;
		struct node *q,*temp;
		printf("\n enter a value to be deleted:");
		scanf("%d",&item);
		if(item==last->next->data)
		{
			temp=last->next;
			last->next=temp->next;
			free(temp);
			return;
		}
		q=last->next;
		while(q->next!=last)
		{
			if(item==q->next->data)
			{
				temp=q->next;
				q->next=temp->next;
				free(temp);
				return;
			}
			q=q->next;
		}
		if(q->next==last && item==last->data)
		{
			temp=last;
			q->next=last->next;
			last=q;
			free(temp);
			return;
		}
		printf("\n item not found");
	}


