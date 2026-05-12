#include<vector> //dynamic array
template<typename T>
class Heap {
private:
	vector<T> list;
	int pos;
public:
	Heap(const int& max = 20) {
		list(max); //initial allocation but can grow more than max
		pos = 0;
	}
	void percolateUp(int p) {
		int parent = 1;
		T tmp;
		while (parent > 0) {
			parent = (p - 1) / 2;
			//swap elements at parent and p positions.
			if (list[parent] > list[p]) {
				tmp = list[p];
				list[p] = list[parent];
				list[parent] = tmp;
			}
			p = parent;//move to next parent			
		}
	}
	void insert(const T& val) {
		list.push_back(val);
		pos++;
		percolateUp(pos);
	}
	void percolateDown(int p) {
		int lc, rc,minPos,tmp=p*2;
		T tmp2;
		while (tmp < pos) {
			//compare between parent and both children
			//swap with the smallest
			lc = tmp + 1;
			rc = tmp + 2;
			//check if right child exists
			if (rc >= pos)
				minPos = lc;
			else {
				minPos = lc;
				if (list[rc] < list[lc])
					minPos = rc;
			}
			//check with parent and then swap
			if (list[minPos] < list[p]) {
				tmp2 = list[p];
				list[p] = list[minPos];
				list[minPos] = tmp2;
			}
			//move to next position
			p = minPos;
			tmp = p * 2;
		}
	}
	const T& deleteMin() {
		//swap element at pos 0 with last element 
		//percolateDown
		int val = list[pos];
		list[0] = list[--pos];
		list.pop_back();
		percolateDown(0);
		return val;
	}
	void buildHeap(vector<T>& v) {//O(n)
		//check every parent and place at correct position
		int lastParent = v.size() / 2;
		int pos = v.size();
		list = v;
		while (lastParent >= 0) {
			percolateDown(lastParent);
			lastParent--;
		}
	}
};