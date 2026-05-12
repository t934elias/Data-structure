/*
write a main program that creates a queue of integers filled randomly
between a and b entered by the user. The number of elements to be 
generated is also a user input
write a function that returns the min element in the queue

*/
#include "Queue.h"
#include<ctime>
int findMin(ArrayQueue<int>& q) {
	int sz = q.size();
	//int min = q.dequeue(); //remove first element and consider it min	
	//q.enqueue(min);
	int min = q.front();
	int head;
	for (int i = 1; i <= sz; i++) {
		head = q.dequeue();
		if (head < min)
			min = head;
		q.enqueue(head);
	}
	return min;
}
void print(Queue<int>& q) {
	if (q.empty())
		cout << "Queue is empty\n";
	else {
		cout << "Queue elements:";
		while (!q.empty()) {
			cout << q.dequeue() << " ";
		}
		cout << endl;
	}
}
int main() {
	srand(time(0));
	int nb, a, b, n;
	cout << "Enter the number of elements to be generated, followed by min and max range:";
	cin >> nb >> a >> b;
	//check if b < a --> swap
	if (a > b) {
		n = a;
		a = b;
		b = n;
	}
	//create array queue
	ArrayQueue<int> q(nb);
	b = b - a + 1;
	while (nb > 0) {
		q.enqueue(a + rand() % b);
		nb--;
	}	
	cout << "Min element in the queue is:" << findMin(q) << endl;
	print(q);
	return 0;
}
