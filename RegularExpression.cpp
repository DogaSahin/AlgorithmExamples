#include <iostream>

class Stack {
public:
	void push(char ch);
	void pop();

	void display();
	int GetLenght();

	struct node {
		char ch;
		struct node* next;
	}*top, * last;

	Stack() {
		top = NULL;
		last = NULL;
	}
};

void Stack::push(char ch) {
	struct node* temp1, * temp2;
	temp1 = new (struct node);   // we allocate a memory for the node
	temp1->ch = ch;
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

void Stack::pop() {
	if (top == NULL)
		return;
	struct node* temp, * dlt;
	dlt = top;
	temp = top;
	while (dlt->next != NULL) {
		temp = dlt;
		dlt = dlt->next;
	}
	if (dlt == top) {
		top = NULL;
	}
	else {
		temp->next = NULL;
	}
	free(dlt);
	last = temp;
	return;
}

void Stack::display() {
	struct node* s = top;
	if (top == NULL) {
		std::cout << "list is empty" << std::endl;
		return;
	}
	s = top;
	std::cout << "elements in the list :" << std::endl;
	while (s != NULL) {
		std::cout << s->ch;
		s = s->next;
	}
}

int Stack::GetLenght() {
	struct node* s = top;
	int count = 0;
	while (s != NULL) {
		count++;
		s = s->next;
	}
	return count;
}

int main(void) {
	Stack stck1, stck2;
	char ch;
	int a, b;
	std::cout << "enter the string " << std::endl;
	std::string s;
	std::cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a') {
			ch = 'a';
			stck1.push(ch);
		}
		else {
			ch = 'b';
			stck2.push(ch);
		}
	}
	
	std::cout << "please enter the coefficient of a " << std::endl;
	std::cin >> a;
	std::cout << "please enter the coefficient of b" << std::endl;
	std::cin >> b;

	while (stck1.GetLenght() -a >= 0 && stck2.GetLenght() - b >= 0 ) {
		for (int i = 0; i < a; i++) {
			stck1.pop();
		}
		for (int i = 0; i < b; i++) {
			stck2.pop();
		}
        std::cout << std::endl;
		stck1.display();
		if (stck1.GetLenght() == 0 && stck2.GetLenght() == 0) {
			std::cout << " Expression is regular " << std::endl;
			return 0;
		}
	}
	std::cout << std::endl;
	std::cout << "expression is irregular" << std::endl;
	return 0;
}