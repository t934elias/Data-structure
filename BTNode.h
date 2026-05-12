template <typename T>
class BTNode {
private:
	T data;
	BTNode<T>* left, * right;
public:
	BTNode(const T& d, BTNode<T>* left = nullptr, BTNode<T>* right = nullptr) {
		data = d;
		this->left = left;
		this->right = right;
	}
	//getter and setter for the data
	const T& getData() {
		return data;
	}
	void setData(const T& d) {
		data = d;
	}
	//getter and setter for the left
	BTNode<T>* getLeft() {
		return left;
	}
	void setLeft(BTNode<T>* l) {
		left = l;
	}
	//getter and setter for the right
	BTNode<T>* getRight() {
		return right;
	}
	void setRight(BTNode<T>* r) {
		right = r;
	}
}; 
