#ifndef TREE_H
#define TREE_H

#include "shared_functions.hpp"

template <class Key, class T = int, class Compare = ft::less<Key> >
struct tree_node {
	public:
		const bool		UNIQUE_KEY;
		tree_node		*left;
		tree_node		*right; 
		tree_node		*parent;
		ft::pair<const Key, T>	key_val;
		bool			is_last;
		tree_node(bool keyIsUnique = true)
		: UNIQUE_KEY(keyIsUnique), left(nullptr), right(nullptr), parent(nullptr),
		key_val( ft::pair<Key, T>(Key(), T() )), is_last(false) {}

		tree_node(const Key &p_key, const T &p_value, bool keyIsUnique = true)
		: UNIQUE_KEY(keyIsUnique), left(nullptr), right(nullptr), parent(nullptr),
		key_val(ft::pair<Key, T>(p_key, p_value)), is_last(false) {}
		
		static tree_node	*create_last_elem(bool keyIsUnique)
		{
			tree_node	*last_node = new tree_node(keyIsUnique);
			last_node->is_last = true;
			return (last_node);
		}
		static tree_node	*get_root_node(tree_node *node)
		{
			while (node->parent)
				node = node->parent;
			return (node);
		}
		static tree_node	*insert(tree_node *root, tree_node *new_el)
		{
			Compare	comp;
			if (root && root->UNIQUE_KEY && new_el->key_val.first == root->key_val.first)
				return (root);
			if (root && root->is_last)
			{
				if (root->parent)
					root->parent->right = new_el;
				new_el->parent = root->parent;
				new_el->right = root;
				root->parent = new_el;
				return (new_el);
			}
			if (root && new_el->is_last) {
				root->right = new_el;
				new_el->parent = root;
				return (new_el); // xd
			}
			if (root && comp(new_el->key_val.first, root->key_val.first))
			{
				if (root->left)
					return (insert(root->left, new_el));
				root->left = new_el;
			}
			else if (root)
			{
				if (root->right)
					return (insert(root->right, new_el));
				root->right = new_el;
			}
			new_el->parent = root;
			return (new_el);
		}
		static tree_node	*deep_copy(tree_node *root, tree_node *root_parent = nullptr) {
			if (!root)
				return (nullptr);
			tree_node*	new_node = new tree_node(root->key_val.first, root->key_val.second, root->UNIQUE_KEY);
			new_node->parent = root_parent;
			new_node->is_last = root->is_last;
			new_node->left = deep_copy(root->left, root);
			new_node->right = deep_copy(root->right, root);
			return (new_node);
		}
		// search the node at the left of root that is the most on the right
		static tree_node	*get_prev(tree_node *root)
		{
			if (root->left)
				return (find_rightmost_node(root->left));
			return (first_left_parent(root));
		}
		static tree_node	*first_left_parent(tree_node *root)
		{
			tree_node	*parent_node = root->parent;
			if (!parent_node || parent_node->right == root)
				return (parent_node);
			return (first_left_parent(parent_node));
		}
		// search the node at the right of root that is the most on the left
		static tree_node	*get_next(tree_node *root)
		{
			if (root->right)
				return (find_leftmost_node(root->right));
			return (first_right_parent(root));
		}
		static tree_node	*first_right_parent(tree_node *root)
		{
			tree_node	*parent_node = root->parent;
			if (!parent_node || parent_node->left == root)
				return (parent_node);
			return (first_right_parent(parent_node));
		}
		static void			free_tree(tree_node *root)
		{
			if (!root)
				return ;
			free_tree(root->left);
			free_tree(root->right);
			delete root;
		}
		static tree_node	*find_leftmost_node(tree_node *root)
		{
			if (root && root->left)
				return (find_leftmost_node(root->left));
			return (root);
		}
		static tree_node	*find_rightmost_node(tree_node *root)
		{
			if (root && root->right)
				return (find_rightmost_node(root->right));
			return (root);
		}
		static tree_node	*find(tree_node *root, const Key& key)
		{
			Compare	comp;
			if (!root || root->is_last)
				return (nullptr);
			if (root->key_val.first == key)
				return (root);
			if (comp(key, root->key_val.first))
				return (find(root->left, key));
			else
				return (find(root->right, key));
		}
		static tree_node	*remove(tree_node *root, int *deletedCount)
		{
			return (remove(root, root->key_val.first, deletedCount));
		}
		static tree_node	*remove(tree_node *root, const Key& key, int *deletedCount)
		{
			if (!root || root->is_last)
				return (nullptr);
			if (root->key_val.first == key)
			{
				*deletedCount += 1;
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
						return (get_root_node(node_parent));
					}
					node_parent->right = remove_bindings(node_parent, node_left, node_right);
					return (get_root_node(node_parent));
				}
				return (get_root_node(remove_bindings(node_parent, node_left, node_right)));
			}
			Compare comp;
			if (comp(key, root->key_val.first)) {
				if (root->left)
					return (remove(root->left, key, deletedCount));
				return (get_root_node(root));
			} else {
				if (root->right)
					return (remove(root->right, key, deletedCount));
				return (get_root_node(root));
			}
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
};

#endif