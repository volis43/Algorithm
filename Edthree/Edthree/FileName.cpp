#include <iostream>
#include <algorithm>

typedef struct tree_element
{
	int value;
	struct tree_element* left;
	struct tree_element* right;
} tree_element;

// создание ветkи для древнего древо!
tree_element* create_tree_element(int i);

void insert_into_tree(tree_element* root, tree_element* elem);

void print_tree(tree_element* cur_elem);

tree_element* create_tree_element(int i)
{
	tree_element* elem = new tree_element;
	elem->value = i;
	elem->left = NULL;
	elem->right = NULL;
		return elem;
}

void insert_into_tree(tree_element* root, tree_element* elem)
{
	if (elem->value < root->value)
	{
		if (root->left == NULL)
		{
			root->left = elem;
		}
		else
		{
			insert_into_tree(root->left, elem);
		}
	}
	else
	{
		if (root->right == NULL)
		{
			root->right = elem;

		}
		else
		{
			insert_into_tree(root->right, elem);
		}
	}
}

void print_tree(tree_element* cur_elem)
{
	if (cur_elem->left != NULL)
	{
		print_tree(cur_elem->left);
	}
	std::cout << "Value = " << cur_elem->value << std::endl;
	if (cur_elem->right != NULL)
	{
		print_tree(cur_elem->right);
	}
	
}

int main()
{
	int n[8] = {50, 1, 51, 45, 10, -1, -4, 0};

	tree_element* root = create_tree_element(0);
	
	for (int i = 0; i < 8; i++)
	{
		tree_element* el = create_tree_element(n[i]);
		insert_into_tree(root, el);
	}

	std::cout << "EdTree: " << std::endl;
	print_tree(root);

	return 0;
}