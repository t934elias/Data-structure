/*
write a main program that allows the user to
1- create a list of integers
2- allow the user to fill the list in the same order the elements come in (0 value to stop)
3- print the list
4- delete an element
5- push front the tail value
6- insert the head value at a given position
7- add a search function that returns the position of the element in case found.
*/

#include "List.h"
//the search ass a template function
//int searchInt(List<int> list, int n)

template<typename T>
int search(List<T>& list, const T& n) {
	if (list.empty())
		return -1;
	Node<T>* cur = list.begin();
	int pos = 0;
	while (cur != nullptr) {
		if (cur->getValue() == n)
			return pos;
		cur = cur->getNext();
		pos++;
	}
	return -2;
}
int main() {
	//1- create a list of integers
	List<int> mylist; //call the constructor --> initializing to nullptr (empty list)
	//List<int> mylist2(nullptr);
	//2 - allow the user to fill the list in the same order the elements come in(0 value to stop)
	int n;
	cout << "Enter an integer (0 to stop):";
	cin >> n;
	while(n!=0){		
		mylist.push_back(n);
		cin >> n;
	} 
//	3 - print the list
	mylist.print();

//4 - delete an element
	cout << "Enter an element to delete:";
	cin >> n;
	mylist.remove(n);
	mylist.print();
//		5 - push front the tail value
	if (mylist.empty())
		cout << "List is empty cannot push element\n";
	else mylist.push_front(mylist.back());
	//mylist.push_front(mylist.end()->getValue());
	
//6 - insert the head value at a given position
	cout << "Enter a position:";
	cin >> n;
	mylist.insert(mylist.front(), n);
	//mylist.insert(mylist.begin()->getValue(), n);

//7 - add a search function that returns the position of the element in case found.
	cout << "Enter an element to search for:";
	cin >> n;
	int  pos = search(mylist, n);
	if (pos == -1)
		cout << "List is empty\n";
	else if (pos == -2)
		cout << n << " was not found\n";
	else cout << n << " was found at " << pos << endl;
	return 0;
}
