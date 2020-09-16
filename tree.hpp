#ifndef TREE_H
#define TREE_H

#include <iostream>

namespace ft
{
	template<typename Tp>
	struct less {
		bool operator()(const Tp& x, const Tp& y) const
		{
			return (x < y);
		}
	};
}

template <class Key, class T = int, class Compare = ft::less<Key> >
struct tree_node {
	tree_node		*left;
	tree_node		*right; 
	tree_node		*parent;
	Key				key;
	T				value;
	tree_node(): left(nullptr), right(nullptr), parent(nullptr), key(Key()), value(T()) {}
	tree_node(const Key &p_key, const T &p_value = T())
	: left(nullptr), right(nullptr), parent(nullptr), key(p_key), value(p_value) {}
	
	static tree_node	*insert(tree_node *root, tree_node *new_el)
	{
		recur_insert(root, new_el);
		root = new_el;
		while (root->parent)
			root = root->parent;
		return (root);
	}
	static void			free_tree(tree_node *root)
	{
		if (!root)
			return;
		free_tree(root->left);
		free_tree(root->right);
		delete root;
	}
	static tree_node	*find(tree_node *root, const Key& key)
	{
		if (!root)
			return (nullptr);
		if (root->key == key)
			return (root);
		if (root->key > key)
			return (find(root->left, key));
		else
			return (find(root->right, key));
	}
	static tree_node	*remove(tree_node *root)
	{
		return (remove(root, root->key));
	}
	static tree_node	*remove(tree_node *root, const Key& key)
	{
		if (!root)
			return (nullptr);
		if (root->key == key)
		{
			tree_node	*node_parent = root->parent;
			tree_node	*node_left = root->left;
			tree_node	*node_right = root->right;
			bool		was_left_child = (node_parent && root == node_parent->left);
			delete root;
			if (node_parent)
			{
				if (was_left_child)
				{
					node_parent->left = remove_bindings(node_parent, node_left, node_right);
					return (node_parent->left);
				}
				node_parent->right = remove_bindings(node_parent, node_left, node_right);
				return (node_parent->right);
			}
			return (remove_bindings(node_parent, node_left, node_right));
		}
		if (root->key > key)
			return (remove(root->left, key));
		else
			return (remove(root->right, key));
	}
	private:
	static tree_node	*remove_bindings(tree_node *node_parent, tree_node *node_left, tree_node *node_right)
	{
		if (!node_left)
		{
			if (!node_right)
				return (nullptr);
			node_right->parent = node_parent;
			return (node_right);
		}
		node_left->parent = node_parent;
		if (node_right)
			insert(node_left, node_right);
		return (node_left);
	}
	static void			recur_insert(tree_node *root, tree_node *new_el)
	{
		Compare	comp;
		if (root != nullptr && comp(new_el->key, root->key))
		{
			if (root->left != nullptr)
			{
				recur_insert(root->left, new_el);
				return ;
			}
			root->left = new_el;
		}
		else if (root != nullptr)
		{
			if (root->right != nullptr)
			{
				recur_insert(root->right, new_el);
				return ;
			}
			root->right = new_el;
		}
		new_el->parent = root;
	}
};

#endif