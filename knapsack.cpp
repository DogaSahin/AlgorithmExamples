#include <iostream>
#include <string>

class KSP {
public:
	int x;
	std::string values;

	struct item_attributes {
		int weight, price;
		std::string name;
		struct item_attributes* next;
	}*start, * last;

	KSP() {
		start = NULL;
		last = NULL;
	}

	void Get_item_Attributes();
	void ksp(struct item_attributes* temp, int space, int total, std::string s);
};

void KSP::Get_item_Attributes() {
	int weight, price;
	std::string name;
	struct item_attributes* s, * temp;
	temp = new(struct item_attributes);
	temp->next = NULL;

	std::cout << "Enter the name of the item: ";
	std::cin >> name;
	std::cout << std::endl;
	std::cout << "Enter the price of the item: ";
	std::cin >> price;
	std::cout << std::endl;
	std::cout << "Enter the weight of the item: ";
	std::cin >> weight;
	std::cout << std::endl;

	temp->price = price;
	temp->weight = weight;
	temp->name = name;

	if (start == NULL) {   // if linked list is empty
		start = temp;
		last = temp;
	}
	else {
		s = last;
		s->next = temp;
		last = temp;
	}
}

void KSP::ksp(struct item_attributes *temp , int space, int total, std::string s) {
	if (temp->next == NULL || space <= temp->weight) {
		if (space >= temp->weight) {
			s.append(temp->name, 1);
			total += temp->weight;
		}
		if (x < total) {
			x = total;
			values = s;
		}
		return;
	}
	ksp(temp->next, space, total, s);
	s.append(temp->name, 1);
	ksp(temp->next, space - temp->weight, total + temp->price, s);
}

int main() {
	KSP p;
	std::string s = " ";
	int space, x;
	std::cout << "How many item you want to enter ? ";
	std::cin >> x;
	for (int i = 0; i < x; i++) {
		p.Get_item_Attributes();
		std::cout << i + 1 << ".item has added" << std::endl;
		std::cout << std::endl;
	}
	std::cout << "Please enter the space of the bag: ";
	std::cin >> space;
	p.ksp(p.start , space , 0 , s);
	std::cout << p.values;
	return 0;
}