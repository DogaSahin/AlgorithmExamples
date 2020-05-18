#include <iostream>

struct node {
	int info;
	struct node* next;
	struct node* prev;
}*start, *rear;   // start stores first node and rear stores the last node

class queue {
public:
	void enqueue(int value);  // functions for adding - deleting from the list
	void dequeue();
    void pop();

	void makePalindrom();  // fuctions for palindrome calculations
    bool isPalindrome();

	void display();
	int GetLenght();

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
		temp->prev = NULL;
		start = temp;      
		rear = temp;
	}
	else {
		s = rear;
		s->next = temp;
		rear = temp;
	}
}

void queue::dequeue() {
	struct node* tmp = start;
	if (tmp == NULL) {
		std::cout << "List is empty" << std::endl;
		return;
	}
	start = start->next;
	start->prev = NULL;
	free(tmp);
	return;
}

void queue::pop() {
	if (start == NULL) {
		std::cout << "list is empty" << std::endl;
	}
	struct node* dlt, *temp;
	dlt = start;
	temp = start;
	while (dlt->next != NULL) {
		temp = dlt;
		dlt = dlt->next;
	}
	if (dlt == start) {  // If list has only 1 node
		start = NULL;
	}
	else {
		temp->next = NULL; // Disconnect link of second last node with last node
	}
	free(dlt); // delete the last node
	rear = temp;
	return;
}

void queue::display() {
	struct node* s;
	if (start == NULL) {
		std::cout << "its palindrome" << std::endl;
		return;
	}
	s = start;
	std::cout << "Linked List is :" << std::endl;
	while (s != NULL) {
		std::cout << s->info;
		s = s->next;
	}
}

int queue::GetLenght() {
	struct node* s = start;
	int count=0;
	while (s != NULL) {
		count++;
		s = s->next;
	}
	return count;
}

bool queue::isPalindrome() {
	struct node* x, * y;
	while (GetLenght() > 0) {
		x = start;
		y = start;
		if (start->next == NULL) {  // is list has one element we accept it as a palindrome
			std::cout << "list has only one element so its palindrom" << std::endl;
			break;
		}
		else {
			while (y->next != NULL) {  // set y to the end of the list
				y = y->next;
			}
			if (x->info == y->info) {  // if the last and the first elements are same
				dequeue();   // we delete first and the last node from the list
                display();
				pop();
				std::cout << std::endl;
				display();
				std::cout << std::endl;
			}
			else {
				std::cout << "not palindrome" << std::endl;
				return false;
				break;
			}
		}
	}
}

void queue::makePalindrom() {
	struct node* tmp1, * tmp2;
	int temp;
	while (isPalindrome() == false) {   // firstly we look if our list is palindrom or not
		while (GetLenght() > 0) {
			tmp1 = start;
			tmp2 = start;
			while (tmp2->next != NULL) {
				tmp2 = tmp2->next;
			}
			if (tmp1->info != tmp2->info) {  // if the first and last elements arent the same
				temp = tmp2->info;           // we store the last nodes info into temp
				tmp1->info = temp;           // we change the first nodes info
				isPalindrome(); 
			}
			else {
				isPalindrome();
				break;
			}
		}
		break;
	}
}


int main () {
	int choice, element;
	queue q;
	while (1) {
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << "Is Palindrome ?" << std::endl;
		std::cout << "1) Create a node" << std::endl;
		std::cout << "2) Display" << std::endl;
		std::cout << "3) Check if its palindrom" << std::endl;
		std::cout << "4) make it palindrom" << std::endl;
		std::cout << "Enter your choice" << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1:
			std::cout << "Enter the element: ";
			std::cin >> element;
			q.enqueue(element);
			std::cout << std::endl;
			break;
		case 2:
			q.display();
			std::cout << std::endl;
			break;
		case 3:
			q.isPalindrome();
			break;
		case 4:
			q.makePalindrom();
			break;
		default:
			return 0;
		}
	}
}