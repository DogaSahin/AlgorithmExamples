#include <iostream>

class List{
public:
	struct node {
		int x;
		struct node* next;
	}*first, *last;

	void add(int x);
	void FindDividers();
	void RecLinearSearch(struct node* tmp, int key);

	List() {
		first = NULL;
		last = NULL;
	}
};

void List::add(int x) {
	struct node* temp1, * temp2;
	temp1 = new (struct node);   // we allocate a memory for the node
	temp1->x = x;
	temp1->next = NULL;
	if (first== NULL) {    // if  list is empty
		first = temp1;
		last = temp1;
	}
	else {    // if list is not empty
		temp2 = last;
		temp2->next = temp1;
		last = temp1;
	}
}

void List::FindDividers() {
	struct node* tmp = first;
	while (tmp) {
		std::cout << tmp->x << " Dividers are : ";
		for (int i = 1; i <= tmp->x; i++) {
			if (tmp->x % i == 0) {
				std::cout << " " << i;
			}
		}
		tmp = tmp->next;
		std::cout << std::endl;
	}
}

void List::RecLinearSearch(struct node* tmp, int key) {
	if (tmp == NULL) {
		std::cout << "element you search does not exist" << std::endl;
		return;
	}

	if (tmp->x == key) {
		FindDividers();
		return;
	}
	return RecLinearSearch(tmp->next, key);
}

int main() {
	List s;
	int element, max , search;
	std::cout << "how many element there will be in the list ?" << std::endl;
	std::cin >> max;
	for (int i = 0; i < max; i++) {
		std::cout << "please enter the element: ";
		std::cin >> element;
		s.add(element);
	}
	std::cout << "enter the element you want to search: ";
	std::cin >> search;
	s.RecLinearSearch(s.first, search);
	return 0;
}





