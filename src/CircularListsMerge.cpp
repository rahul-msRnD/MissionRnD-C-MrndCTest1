/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

int lengthofCLL(struct node* temp)
{
	int count = 1;
	struct node* temp1 = temp;
	do
	{
		temp = temp->next;
		count++;
	} while (temp1 != temp);
	return count-1;
}

struct node* findLastNodeOfCLL(struct node* head)
{
	int count = 1;
			struct node* p1 = head;
			struct node* p2 = head;
			do
			{
				p1 = p1->next->next;
				p2 = p2->next;
				count++;
			} while (p1->next != p2);
			
		return p2;
}

struct node* sortedMerge(struct node* a, struct node* b)
{
	struct node* result = NULL;
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;
	else if (a->data >= b->data)
	{
		result = b;
		result->next = sortedMerge(a, b->next);
	}
	else
	{
		result = a;
		result->next = sortedMerge(a->next, b);
	}
	return result;
}

int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	if (*head1==NULL && *head2==NULL)
		return -1;
	if (*head1 == NULL)
		return lengthofCLL(*head2);
	if (*head2 == NULL)
		return lengthofCLL(*head1);
	int a = lengthofCLL(*head1);
	int b = lengthofCLL(*head2);
	struct node* p1 = findLastNodeOfCLL(*head1);
	struct node* p2 = findLastNodeOfCLL(*head2);
	p1->next = NULL;
	p2->next = NULL;
	*head1 = sortedMerge(*head1, *head2);
	struct node* temp = *head1;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *head1;
	return a+b;


}