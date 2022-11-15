#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: is a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 * Return: a pointer to the new node, or NULL on failure or if parent is NULL
**/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode, *temp;

	if (!parent)
		return (NULL);

	newnode = malloc(sizeof(binary_tree_t));
	if (!newnode)
		return (NULL);

	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL;
	newnode->right = NULL;

	if (!parent->left)
	{
		parent->left = newnode;
	}
	else
	{
		temp = parent->left;
		parent->left = newnode;
		temp->parent = newnode;
		newnode->left = temp;
	}

	return (newnode);
}
