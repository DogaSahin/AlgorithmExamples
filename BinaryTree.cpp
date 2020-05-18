#include <iostream>

struct node {
	int data;
	struct node* left;
	struct node* right;
}*root;

class Btree {
public:
	void Add(int value);
	void Postorder(node *ptr);
	void Postorder_trav();

	Btree (){
		root = NULL;
	}
};

void Btree::Add(int value) {
	struct node* temp ,*parent;
	temp = new (struct node);
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	parent = NULL;
	if (root == NULL) {
		root = temp;
	}
	else {
		node* ptr;
		ptr = root;
		while (ptr != NULL) {
			parent = ptr;

			if (value > ptr->data)
				ptr = ptr->right;
			else
				ptr = ptr->left;
		}

		if (value < parent->data)
			parent->left = temp;
		else
			parent->right = temp;		
	}
}

void Btree::Postorder_trav() {
	Postorder(root);
}

void Btree::Postorder(node *ptr) {
	if (ptr != NULL) {
		Postorder(ptr->left);
		Postorder(ptr->right);
		std::cout << "  " << ptr->data << "     ";
	}
}

int main() {
	Btree t;
	int item;
	while (1) {
		std::cout << "Enter an item" << std::endl;
		std::cin >> item;
		if (item != 0) {
			t.Add(item);
		}
		else
			break;
	}
	t.Postorder_trav();
}