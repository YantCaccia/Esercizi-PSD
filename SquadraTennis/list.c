#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"


struct list {
	int size;
	struct node *head;
};

struct node {
	Item item;
	struct node *next;
};

List newList(){
	
	List list = malloc(sizeof(struct list));
	list->size = 0;
	list->head = NULL;
	
	return list;
}

int isEmpty(List list){
	return list->head == NULL;
}

void addHead(List list, Item item){
	struct node *x = malloc(sizeof(struct node));
	x->next = list->head;
	x->item = item;
	list->head = x;
	list->size++;
}

Item removeHead(List list){
	Item app;
	if(isEmpty(list)==1){
		fprintf(stderr,"Lista vuota");
		return NULL;
	}	
	struct node *temp = list->head;
	list->head = temp->next;
	app=temp->item;
	free(temp);
	list->size--;
	return app;
}

Item getHead(List list){
	if(isEmpty(list)==1){
		fprintf(stderr,"Lista vuota");
		return NULL;
	}
		
	return list->head->item;
}

int sizeList(List list){
	return list->size;
}

void printList(List list){
	struct node *p;
	for(p = list->head; p != NULL; p = p->next)
		outputItem(p->item);
} 

Item searchList(List list, Item it, int *pos){
	struct node *p;
	*pos=0;
	for(p=list->head;p;p=p->next){
		if(cmpItem(p->item,it)==0)
			return p->item;
		++*pos;
	}
	*pos=-1;
	return NULL;
}

Item removeItem(List list, Item it)
{
	struct node *p, *prev;
	Item o;
	if(isEmpty(list)==1){
		fprintf(stderr,"Lista vuota");
		return NULL;
	}
	for(p=list->head;p;prev = p, p=p->next)
	{
		if(cmpItem(p->item,it)==0)
			if (p == list -> head)
				return removeHead (list);
			else
			{
				o = p -> item;
				prev -> next = p -> next;
				free (p);
				list -> size --;
				return o;
			}
	}
	return NULL;
}

Item removePos(List list, int pos)
{
	struct node *p, *prev;
	Item o;
	int i;
	if(isEmpty(list)==1){
		fprintf(stderr,"Lista vuota");
		return NULL;
	}
	for(i = 0, p=list->head;p && i <= pos;i++, prev = p, p=p->next)
	{
		if(i == pos)
			if (p == list -> head)
				return removeHead (list);
			else
			{
				o = p -> item;
				prev -> next = p -> next;
				free (p);
				list -> size --;
				return o;
			}
	}
	return NULL;
}
int addItem(List list, Item item, int pos){
	if (pos == 0)
	{
		addHead(list, item);
		return 1;
	}
	if (pos > sizeList(list))
		return 0;
	struct node *p;
	int i;
	for (p = list -> head, i = 0; p; i++, p = p -> next)
	{
		if (i == pos-1)
		{
			struct node *new = malloc(sizeof(struct node));
			new -> next = p -> next;
			p -> next = new;
			new -> item = item;
			list -> size++;
			return 1;
		}
	}
	return 0;
} // 0 <= pos <= sizeList(list)

int addTail(List list, Item item)
{
	return addItem(list, item, sizeList(list));
}

void reverseList(List list)
{
	struct node *prev=NULL;
	struct node *p;
	struct node *temp;
	for(p=list->head;p;prev=p,p=temp)
	{
		temp= p->next;
		p->next=prev;
	}
	list->head=prev;
}

List cloneList(List list)
{
	List clone= newList();
	struct node *p;
	for (p = list -> head; p; p = p -> next)
	{
		Item item=cloneItem(p->item);
		addTail(clone,item);
	}
	return clone;
}



