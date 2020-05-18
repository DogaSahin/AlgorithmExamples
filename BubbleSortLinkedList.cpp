#include <iostream>

class queue {
public:
	struct node {
		int info;
		struct node* next;
	}*start, * rear;  // start stores first node and rear stores the last node

	void enqueue(int value);  // functions for adding - deleting from the list
	void BubbleSort();
	void RecBubbleSort(struct node* temp);
	void Swap(struct node* a, struct node* b);
	void display();

	queue() {
		start = NULL;     // we initially set start and rear to null
		rear = NULL;
	}
};

void queue::enqueue(int value) {
	struct node* s, * temp;
	temp = new(struct node);
	temp->info = value;
	temp->next = NULL;
	if (start == NULL) {   // if linked list is empty
		start = temp;
		rear = temp;
	}
	else {
		s = rear;
		s->next = temp;
		rear = temp;
	}
}

void queue::BubbleSort() {
	struct node* s = start;
	struct node* tmp = start;

	if (start == NULL)
		return;

	while (s != NULL) {
		while (tmp->next != NULL) {
			if (tmp->info > tmp->next->info) {
				Swap(tmp, tmp->next);
			}
			tmp = tmp->next;
		}
		s = s->next;
		tmp = start;
	}
}

void queue::RecBubbleSort(struct node *temp) {
	
	if (temp == NULL)
		return;

	struct node* tmp = start;
	while (tmp->next != NULL) {
		if (tmp->info > tmp->next->info) {
			Swap(tmp, tmp->next);
		}
		tmp = tmp->next;
	}
	RecBubbleSort(temp->next);
}

void queue::Swap(struct node* a, struct node* b) {
	int temp = a->info;
	a->info = b->info;
	b->info = temp;
}

void queue::display() {
	struct node* s;
	if (start == NULL) {
		return;
	}
	s = start;
	while (s != NULL) {
		std::cout << " " << s->info;
		s = s->next;
	}
}

int main(void) {
	int choice, element;
	queue q;
	while (true) {
		std::cout << std::endl;
		std::cout << "Type '1' for adding an item to the queue" << std::endl;
		std::cout << "type '2' for using bubble sort algortihm" << std::endl;
		std::cout << "Type '3' for using the recursive bubble sort algorithm" << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1:
			std::cout << "Please enter the element :";
			std::cin >> element;
			q.enqueue(element);
			break;
		case 2:
			std::cout << "Before Sorting :";
			q.display();
			std::cout << std::endl;
			std::cout << "After sorting :";
			q.BubbleSort();
			q.display();
			break;
		case 3:
			std::cout << "Before Sorting :";
			q.display();
			std::cout << std::endl;
			std::cout << "After sorting :";
			q.RecBubbleSort(q.start);
			q.display();
			break;
		default:
			break;
		}
	}
}