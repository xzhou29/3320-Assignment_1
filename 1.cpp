//Program Code in C++

#include "tower.h"

tower::tower() {
	current = 1;
	n = 6;
	for (int j = 0; j < 12; j++) {
		toDest[j] = 1;
	}

	for (int i = 1; i <= n; i++) {
		toDest[i] = 0;
	}

	r = n;
	start(n, "Start", "Aux1", "Aux3", "Aux2", "Aux4", "Dest", current);
}

void tower::start(int numberOfDisks, string start, string source, string dest, string aux, string last, string last1, int current)
{
	move(1, start, source, current);
	current++;
	algorithm(n, "Start", "Aux1", "Aux3", "Aux2", "Aux4","Dest", current);
	move(1, dest, last, current);
	current++;
	move(1, last, last1, current);
	current++;
}

int tower::algorithm(int numberOfDisks, string start, string source, string dest, string aux, string last, string last1, int& current)
{
	if (numberOfDisks == 1) {
		move(numberOfDisks, source, aux, current);
		current++;
		move(numberOfDisks, aux, dest, current);
		current++;
	}
	
	else if (numberOfDisks >= 2) {
		current = algorithm(numberOfDisks - 1, start, source, dest, aux, last, last1, current);
		if (hasMoved[numberOfDisks] != 1) {
			move(numberOfDisks, start, source, current);
			current++;
			hasMoved[numberOfDisks] = 1;
		}

		move(numberOfDisks, source, aux, current);
		current++;
		current = algorithm(numberOfDisks - 1, start, dest, source, aux, last, last1, current);
		move(numberOfDisks, aux, dest, current);
		current++;

		if (toDest[numberOfDisks + 1] != 0) {	
			move(numberOfDisks, dest, last, current);
			current++;
			move(numberOfDisks, last, last1, current);
			current++;
			toDest[numberOfDisks] = 1;
		}
		if (numberOfDisks == r) 
			r--;
			current = algorithm(numberOfDisks - 1, start, source, dest, aux, last, last1, current);
	};
	return current;
}

void tower::move(int adisk, string source, string dest, int current)
{

	cout << "Move " << current << ": Move disk# " << adisk << " from " << source << " to " << dest << endl;
}


tower::~tower()
{
}

#pragma once
#include<iostream>
#include<string>
using namespace std;

class tower {
public:
	tower();
	~tower();

	void start(int numofdisk, string start, string source, string dest, string aux, string last, string last1, int current);
	int algorithm(int numofdisk, string start, string source, string dest, string aux, string last, string last1, int& current);
	void move(int adisk, string source, string dest, int current);

private:
	int n, current, r;
	int hasMoved[12], toDest[12];

};

#include<iostream>
#include<time.h>
#include "tower.h"
using namespace std;

int main() {
	clock_t begin = clock();
	tower to;
	clock_t end = clock();

	cout << "Time is: " << (end - begin) << " ms" << endl;

	system("pause");
	return 0;
}
