#include "LinkList.h"

/*
Args:
* head:pointer of the head node.
Return:
* True or false.
Description:
* Create an empty linked list with a head node.
* The "next" field of the head node should point to NULL.
*/
_Bool CreateEmptyList(Node** head)
{
	*head = (Node*)malloc(sizeof(Node));
	if (*head == NULL) return false;
	(*head)->next = NULL;
	return true;
}


/*
Args:
* addr: pointer of an array.
* n: length of the array.
* head:pointer of the head node.
Return:
* True or false.
Description:
* Initialize a linked list with an array.
*/
_Bool CreateList(DataType *addr, unsigned int n, Node** head)
{
	Node* p = NULL, * tail = NULL;
	CreateEmptyList(head);
	for (unsigned int i = 0; i < n;++i)
	{
		p = (Node*)malloc(sizeof(Node));
		if (p == NULL) return false;
		p->data = addr[i];
		p->next = NULL;
		if ((*head)->next == NULL)
			(*head)->next = p;
		else
			tail->next = p;
		tail = p;
	}
	return true;
}


/*
Args:
* head: pointer of the head node.
Returns:
* True or false.
Description:
* Destroy the linked list.
* Release all allocated memory.
*/
_Bool DestroyList(Node *head)
{
	while (head)
	{
		Node* cur = head;
		head = head->next;
		free(cur);
	}
	return true;
}


/*
Args:
* head: pointer of the head node.
* index: index of the inserted data.
* data: the inserted data.
Returns:
* True or false.
Description:
*   If the linked list is "head->3->5->2",
* when you call (head, 0, 6), the linked
* list will be "head->6->3->5->2".
*/
_Bool ListInsert(Node *head, unsigned int index, DataType e)
{
	for (unsigned int i = 0; head && i < index; ++i)
		head = head->next;
	if (!head) return false;
	Node* p = (Node*)malloc(sizeof(Node));
	if (!p) return false;
	p->data = e;
	p->next = head->next;
	head->next = p;
	p = NULL;
	return true;
}


/*
Args:
* head: pointer of the head node.
* index: index of the deleted data.
* e:The deleted data.
Returns:
Description:
*   If the linked list is "head->3->5->2",
* when you call (head, 2), the linked
* list will be "head->3->5".
*/
_Bool ListDelete(Node *head, unsigned int index, DataType* e)
{
	for (unsigned int i = 0; head && i < index; ++i)
		head = head->next;
	if (!head) return false;
	Node* cur = head->next;
	*e = cur->data;
	head->next = cur->next;
	free(cur);
	cur = NULL;
	return true;
}
