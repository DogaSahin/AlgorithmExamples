#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector> 

class KMP {
public:
	void CreateArr();
	void computeLPSArray(std::vector <int> pattern, int M, int* lps);
	void kmp(std::vector <int> main, std::vector <int> pattern);
	void show();

	std::vector <int> v;
};

void KMP::CreateArr() {
	int random, x;
	std::cout << "please enter the size of the string: ";
	std::cin >> x;
	srand(time(NULL));
	for (int i = 0; i < x; i++) {
		int random = rand() % 2;
		v.insert(v.begin(), random);
	}
}

void KMP::show() {
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i];
}

void KMP::computeLPSArray(std::vector <int> pattern, int N, int* lps) {
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < N) {  // the loop calculates lps[i] for i = 1 to M-1 
		if (pattern[i] == pattern[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else { 
			if (len != 0) {
				len = lps[len - 1]; 
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMP::kmp(std::vector <int> main , std::vector <int> pattern) {
	int M = main.size();
	int N = pattern.size();
	int*p = new int[N];  // array same size as the pattern array
	computeLPSArray(pattern, N, p);
	int i = 0, j = 0;
	while (i < M) {
		if (pattern[j] == main[i]) {
			j++;
			i++;
		}
		if (j == N) {
			std::cout << std::endl;
			std::cout << "Found pattern at position:  " << i - j + 1;
			j = p[j - 1];
		}
		else if (i < M && pattern[j] != main[i]) {    // mismatch after j matches 
			if (j != 0)  // Do not match lps[0..lps[j-1]] characters they will match anyway
			 
				j = p[j - 1];
			else
				i = i + 1;
		}
	}
}

int main() {
	KMP main, pattern, p;
	std::cout << "-----------Initilazition for the main string-----------------" << std::endl;
	main.CreateArr();
	std::cout << "-----------Initilazition for the pattern string--------------" << std::endl;
	pattern.CreateArr();
	std::cout << std::endl;
	std::cout << "main string is: ";
	main.show();
	std::cout << std::endl;
	std::cout << "pattern is: ";
	pattern.show();
	p.kmp(main.v , pattern.v);
	return 0;
}