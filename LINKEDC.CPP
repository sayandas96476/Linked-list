#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int item;
	struct node *next;
};
struct node *create(struct node *head)
{
	int i=0,n;
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr=head;
	printf("\nHow many elements u want 2 enter=");
	scanf("%d",&n);
	printf("\nEnter 0 element=");
	scanf("%d",&ptr->item);
	ptr->next=NULL;
	while(i<n-1)
	{
		ptr->next=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter %d element=",i+1);
		scanf("%d",&ptr->next->item);
		ptr->next->next=NULL;
		ptr=ptr->next;
		i++;
	}
	return head;
}
struct node *insertb(struct node *head)
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter new element=");
	scanf("%d",&ptr->item);
	ptr->next=head;
	head=ptr;
	return head;
}
struct node *insertl(struct node *head)
{
	struct node *ptr,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	ptr=head;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	printf("\nEnter Element=");
	scanf("%d",&temp->item);
	temp->next=NULL;
	ptr->next=temp;
	return head;
}
void display(struct node *head)
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("\nThe List is empty");
	}
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			printf("\t->%d",ptr->item);
			ptr=ptr->next;
		}
	 }
}
struct node *insertany(struct node *head)
{
	struct node *ptr,*temp,*preptr;
	int loc,i=0;
	temp=(struct node*)malloc(sizeof(struct node));
	ptr=head;
	printf("\n Enter the location u want to insert=");
	scanf("%d",&loc);
	while(i<=loc)
	{
		preptr=ptr;
		ptr=ptr->next;
		i++;
	}
	printf("\n Enter the element=");
	scanf("%d",&temp->item);
	preptr->next=temp;
	temp->next=ptr;
	return head;
}
void main()
{
	struct node *head,*ptr;
	int i;
	clrscr();
	while(1)
	{
		printf("\n Press 1 to create a linklist");
		printf("\n Press 2 for displaying the linklist");
		printf("\n Press 3 for inserting at begining");
		printf("\n Press 4 for inserting at last");
		printf("\n Press 5 for inserting at any location");
		printf("\n Press 6 for exiting the linklist");
		printf("\n Enter your choice:");
		scanf("%d",&i);
		switch(i)
		{
			case 1: ptr=create(head);
				break;
			case 2: display(ptr);
				break;
			case 3: ptr=insertb(ptr);
				break;
			case 4: ptr=insertl(ptr);
				break;
			case 5: ptr=insertany(ptr);
				break;
			case 6: exit(1);
			default: printf("\n Wrong Input!!!!");
		}
	}

}
