#include "BST.h"

/*
Args:
* root: The root pointer of the BST
   arr: The pointer to a integer array
   len: The length of the data, which needs to be stored in BST

Description:
* Create an BST with arr whose length is len
*/

//返回值为与data相等的结点的根，如果不存在则返回null
BST_P SearchBSTF(BST_P *root, DataType data)
{
	if (((*root) == NULL) || (((*root)->data == data))) { return NULL; }
	else if (((*root)->lchild == NULL) && ((*root)->rchild == NULL)) { return NULL; }
	else if ((*root)->lchild == NULL)
	{
		if (((*root)->rchild->data) == data) { return (*root); }
		else { return SearchBSTF(&((*root)->rchild), data); }
	}
	else if ((*root)->rchild == NULL)
	{
		if (((*root)->lchild->data) == data) { return (*root); }
		else { return SearchBSTF(&((*root)->lchild), data); }
	}
	else if ((((*root)->lchild->data) == data)|| (((*root)->rchild->data) == data)) { return (*root); }
	else if (((*root)->lchild->data) > data) { return SearchBSTF(&((*root)->lchild), data); }
	else if (((*root)->rchild->data) < data) { return SearchBSTF(&((*root)->rchild), data); }
	else
	{
		if (SearchBSTF(&((*root)->lchild), data) == NULL) { return SearchBSTF(&((*root)->rchild), data); }
		else { return SearchBSTF(&((*root)->lchild), data); }
	}
}


void CreateBST(BST_P *root, int *arr, int len)
{
	if (*root)
		return;
	*root = (BST_P)malloc(sizeof(BST_T));
	if (!(*root)) exit(-1);
	(*root)->data = *arr;
	(*root)->lchild = NULL;
	(*root)->rchild = NULL;
	for (int i = 1; i < len; ++i)
	{
		BST_P cur = *root, prev = *root;
		while (cur)
		{
			if (cur->data >= arr[i])
			{
				prev = cur;
				cur = cur->lchild;
			}
			else
			{
				prev = cur;
				cur = cur->rchild;
			}
		}
		BST_P p = (BST_P)malloc(sizeof(BST_T));
		if (!p) exit(-1);
		p->data = arr[i];
		p->lchild = p->rchild = NULL;
		if (prev->data >= arr[i])
			prev->lchild = p;
		else
			prev->rchild = p;
	}
}



/*
Args:
* root: The root pointer of the BST

Description:
* Destroy root BST, free all the memory of root BST
*/
void DestoryBST(BST_P *root)
{
	if (*root)
	{
		BST_P p1 = (*root)->lchild;
		BST_P p2 = (*root)->rchild;
		free(*root);
		*root = NULL;
		DestoryBST(&p1);
		DestoryBST(&p2);
	}
}


/*
Args:
* root: The root pointer of the BST
  data: The data you want to insert into BST

Description:
* Insert data into the root BST,return true.
* ATTENTION: If data already exist in BST, DO NOTIHNG and return false.
*/
bool InsertBSTNode(BST_P *root, DataType data)
{
	BST_P cur = *root, prev = *root;
	while (cur)
	{
		if (cur->data == data)
			return false;
		if (cur->data > data)
		{
			prev = cur;
			cur = cur->lchild;
		}
		else
		{
			prev = cur;
			cur = cur->rchild;
		}
	}
	BST_P p = (BST_P)malloc(sizeof(BST_T));
	if (!p) exit(-1);
	p->data = data;
	p->lchild = p->rchild = NULL;
	if (prev->data > data)
		prev->lchild = p;
	else
		prev->rchild = p;
	return true;
}


/*
Args:
* root: The root pointer of the BST
  data: The data you want to delete from BST

Description:
* Delete data from the root BST, and free the memory
* ATTENTION: If data doesn't exist in BST, DO NOTIHNG and return false.
*/
bool DeleteBSTNode(BST_P *root, DataType data)
{
	BST_P p = SearchBSTF(root, data);
	if (!p)
		return false;
	BST_P *s = NULL;
	if (p->lchild && p->lchild->data == data)
		s = &(p->lchild);
	else
		s = &(p->rchild);
	if ((*s)->lchild == NULL && (*s)->rchild == NULL)
	{
		free(*s);
		*s = NULL;
	}
	else if ((*s)->lchild == NULL)
	{
		BST_P temp = *s;
		*s = (*s)->rchild;
		free(temp);
		temp = NULL;
	}
	else if((*s)->rchild == NULL)
	{
		BST_P temp = *s;
		*s = (*s)->lchild;
		free(temp);
		temp = NULL;
	}
	else
	{
		BST_P temp = (*s)->lchild;
		BST_P prev = temp;
		while (temp->rchild)
		{
			prev = temp;
			temp = temp->rchild;
		}
		(*s)->data = temp->data;
		if (prev != (*s))
			prev->rchild = temp->lchild;
		else
			prev->lchild = temp->lchild;
		free(temp);
		temp = NULL;
	}
	return true;
}

/*
Args:
* root: The root pointer of the BST
  data: The data you want to search

Description:
* Search data within the root BST, and return its BST pointer
* ATTENTION: If data doesn't exist in BST, return NULL.
*/
BST_P SearchBST(BST_P *root, DataType data)
{
	if (!(*root))
		return NULL;
	if ((*root)->data > data)
		SearchBST(&((*root)->lchild), data);
	else if ((*root)->data < data)
		SearchBST(&((*root)->rchild), data);
	else
		return *root;
}



/*
Args:
* root: The root pointer of the BST

Description:
* visualize the MidOrderTraverse of root BST
*/
void MidOrderTraverse(BST_P root)
{
	if (root!=NULL)
	{
		MidOrderTraverse(root->lchild);
		printf("%d, ", root->data);
		MidOrderTraverse(root->rchild); 
	}
}

