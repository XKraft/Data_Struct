#include "BiTree.h"

/*
Args:
* s:the string of preorder traversal sequence.

for example:
if you want to obtain an element of s,you can write the code:
DataType data = *((*s));
if you want to obtain the second element of s,you can write the code:
(*s)++;
DataType data = *((*s));

Return:
* Pointer of the bitree node.
Description:
* Create a bitree from preorder traversal sequence.
*/
BinaryTree CreateBinaryTreeFromPreOrderSequence(DataType **s)
{
	BinaryTree T = NULL;
	if (*(*s) != '*')
	{
		T = (BinaryTree)malloc(sizeof(BinaryNode));
		if (!T)
			exit(-1);
		T->data = *(*s);
		(*s)++;
		T->left = CreateBinaryTreeFromPreOrderSequence(s);
		(*s)++;
		T->right = CreateBinaryTreeFromPreOrderSequence(s);
		return T;
	}
	else
		return T;
}

/*
Args:
* t:the pointer of the bitree.
* s:the string of preorder traversal sequence you returned.
Return:
* None.
Description:
* return preorder traversal sequence of the bitree.
*/
void PreOrderTraversal(BinaryTree t, DataType **s)
{
	if (t)
	{
		*(*s) = t->data;
		(*s)++;
		PreOrderTraversal(t->left, s);
		(*s)++;
		PreOrderTraversal(t->right, s);
	}
	else
	{
		*(*s) = '*';
	}
}

/*
Args:
* t:the pointer of the bitree.
* s:the string of ineorder traversal sequence you returned.
Return:
* None.
Description:
* return inorder traversal sequence of the bitree.
*/
void InOrderTraversal(BinaryTree t, DataType **s)
{
	if (t)
	{
		InOrderTraversal(t->left, s);
		*(*s) = t->data;
		(*s)++;
		InOrderTraversal(t->right, s);
	}
	else
	{
		*(*s) = '*';
		(*s)++;
	}
}

/*
Args:
* t:the pointer of the bitree.
* s:the string of postorder traversal sequence you returned.
Return:
* None.
Description:
* return postorder traversal sequence of the bitree.
*/
void PostOrderTraversal(BinaryTree t, DataType **s)
{
	if (t)
	{
		PostOrderTraversal(t->left, s);
		PostOrderTraversal(t->right, s);
		*(*s) = t->data;
		(*s)++;
	}
	else
	{
		*(*s) = '*';
		(*s)++;
	}
}

/*
Args:
* head: pointer of the bitree.
Returns:
* None
Description:
* Destroy the bitree.
* Release all allocated memory.
*/
BinaryTree DestroyTree(BinaryTree *T)
{
	if (*T)
	{
		BinaryTree lchild = (*T)->left;
		BinaryTree rchild = (*T)->right;
		free(*T);
		(*T) = NULL;
		DestroyTree(&lchild);
		DestroyTree(&rchild);
	}
	return *T;
}