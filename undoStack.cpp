template<class T>
class UndoStack {
private:
	const int capacity = 100;
	int top, no_Of_Elements;
	T* box;
public:
	UndoStack() {
		// empty stack
		top = end = -1;
		box = new T [capacity];
		
	}
	bool Empty() {
		return no_Of_Elements == 0;
	}
	int next(int i) {
		return ((i + 1) % capacity);
	}
	int previous(int i) {
		return ((i + (capacity - 1)) % capacity);
	}
	void push(const T & data) {
		top = next(top);
		box[top] = data;
		no_Of_Elements++;
	}
	void pop() {
		top = previous(top);
		no_Of_Elements--;
	}
	void Print()
	{
		if (this->Empty()) {
			cout << "Empty queue";
			return;
		}

		else
			for (int i = 0; i < no_Of_Elements; i++)
				cout << box[i] << " ";
		cout << endl;
	}
	const T& peek() {
		if (this->Empty())
			return NULL;
		return box[top];
	}

};
