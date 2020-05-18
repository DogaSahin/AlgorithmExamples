#include <iostream>

class Stack {
public:
	struct node {
		int x;
		struct node* next;
	}*top, *last;

	void push(int x);
	void RecSelectionSort(struct node* temp);
	void SelectionSort();
	void swap(struct node* a, struct node* b);
	void display();

	Stack() {
		top = NULL;
		last = NULL;
	}
};

void Stack::push(int x) {
	struct node* temp1, * temp2;
	temp1 = new (struct node);   // we allocate a memory for the node
	temp1->x = x;
	temp1->next = NULL;
	if (top == NULL) {    // if  list is empty
		top = temp1;
		last = temp1;
	}
	else {    // if list is not empty
		temp2 = last;
		temp2->next = temp1;
		last = temp1;
	}
}

void Stack::display() {
	struct node* tmp = top;
	if (top == NULL) {
		std::cout << "List is empty" << std::endl;
		return;
	}
	while (tmp) {
		std::cout << " " <<tmp->x;
		tmp = tmp->next;
	}
}

void Stack::swap(struct node* a, struct node* b) {
	int temp = a->x;
	a->x = b->x;
	b->x = temp;
}

void Stack::SelectionSort() {
	struct node *tmp = top;
	struct node* min, *s;
	while (tmp != NULL) {
		min = tmp;
		s = tmp->next;
		while ( s != NULL) {
			if (min->x > s->x) {
				min = s;
			}
			s = s->next;
		}
		swap(min, tmp);
		tmp = tmp->next;
	}
}

void Stack::RecSelectionSort(struct node* temp) {

	if (temp == NULL)
		return;

	struct node* min , *s;
	min = temp;
	s = temp->next;
	while (s != NULL) {
		if (min->x > s->x) {
			min = s;
		}
		s = s->next;
    }
	swap(min,temp);
	RecSelectionSort(temp->next);
}

int main(void) {
	int choice, element;
	Stack stck;
	while (true) {
		std::cout << std::endl;
		std::cout << "For entering an element please type '1' " << std::endl;
		std::cout << "To use Recursive selection sort please type '2' " << std::endl;
		std::cout << "To use normal selection sort please type '3' " << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1:
			std::cout << "Please Enter the element: ";
			std::cin >> element;
			stck.push(element);
			break;
		case 2:
			std::cout << "before sorting :";
			stck.display();
			std::cout << std::endl;
			stck.RecSelectionSort(stck.top);
			std::cout << "after sorting :";
			stck.display();
			std::cout << std::endl;
			break;
		case 3:
			std::cout << "before sorting :";
			stck.display();
			std::cout << std::endl;
			stck.SelectionSort();
			std::cout << "after sorting :";
			stck.display();
			break;
		}
	}
}
