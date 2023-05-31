/*
	Guy Halfon 322206624
	Shlomi Barsheshet 208132993
*/
#include <iostream>
#include <time.h>

using namespace std;

struct object {
	int key;
	object* next;
	object* prev;
};

int countingfun(object* p, int* time) {
	int temp = p->key;
	int i = 1;
	int j = 1;
	int t = 0;
	int x = 0;
	int flag = 0;
	if (temp == 1) {
		while (true) {
			x++;
			if (flag == 0) {
				p = p->next;
				p->key = 1 - p->key;
			}
			else if (flag == 1) {
				p = p->prev;
			}
			i--;
			if (i == 0) {
				flag = 1 - flag;
				if (flag == 0) {
					if (p->key == 0) {
						*time = x;
						i = j + t;
						return i;
					}
					t++;
				}
				i = j + t;

			}
		}
	}
	else if (temp == 0) {
		while (true) {
			x++;
			if (flag == 0) {
				p = p->next;
				p->key = 1 - p->key;
			}
			else if (flag == 1) {
				p = p->prev;
			}
			i--;
			if (i == 0) {
				flag = 1 - flag;
				if (flag == 0) {
					if (p->key == 1) {
						*time = x;
						i = j + t;
						return i;
					}
					t++;
				}
				i = j + t;

			}
		}
	}
};


int main() {
	srand(time(0));
	int x = 0;
	int k = rand() % 2;
	object* first = new object;
	first->key =  k;
	k = rand() % 2;
	object* second = new object;
	first->next = second;
	second->prev = first;
	second->key = k;

	while (x != 1) {
		k = rand() % 2;
		x = rand() % 100 + 1;
		object* temp = new object;
		temp->key = k;
		second->next = temp;
		temp->prev = second;
		second = temp;
	}
	first->prev = second;
	second->next = first;
	second = nullptr;
	int time = 0;
	int res = countingfun(first, &time);
	cout << "number of cross: " << res << endl;
	cout << "Time O(n^2): " << time;
	return 0;
}