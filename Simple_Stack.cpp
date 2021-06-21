template <typename T>
class Stack
{
	int no_Of_Elements, top, capacity;
	T* box;

public:
	//Constrcutor
	//Default Constructor
	Stack(int isize = 0){
		if (isize > 0)
		{
			capacity = isize;
			no_Of_Elements = 0;
			top = -1;
			box = new T[capacity];
		}
		else
		{
			no_Of_Elements = capacity = 0;
			box = nullptr;
			top = -1;
		}
	}
	//Member Functions
	void Push(const T& obj){
		if (no_Of_Elements < capacity)
		{
			box[++top] = obj;
			no_Of_Elements++;
		}
		else if (capacity == 0)
		{
			box = new T[1];
			box[++top] = obj;
			no_Of_Elements = capacity = 1;
		}
		else
		{
			capacity *= 2;
			//Growing
			T* temp = new T[capacity];
			//copying values
			for (int i = 0; i < no_Of_Elements; i++)
				temp[i] = box[i];
			temp[++top] = obj;
			no_Of_Elements++;

			delete[] box;
			box = temp;
		}
	}
	//Pop
	void Pop(){
		if (this->Empty())
			return;
		else if (this->no_Of_Elements > capacity / 2)
		{
			no_Of_Elements--;
			top--;
		}
		else
		{
			//Shrinking
			capacity /= 2;
			T* temp = new T[capacity];
			//Copying Values
			for (int i = 0; i < no_Of_Elements; i++)
				temp[i] = box[i];
			
			no_Of_Elements--;
			top--;
			delete[] box;
			box = temp;
		}
	}
	//Empty
	bool Empty(){
		return no_Of_Elements == 0;
	}
	//Full
	bool Full(){
		return no_Of_Elements == capacity;
	}
	//Peek
	T Peek(){
		if (this->Empty())
			return NULL;
		return this->box[top];
	}


	//Print
	void Print()
	{
		if (this->Empty()) {
			cout << " Stack is Empty " << endl;
			return;
		}
			
		for (int i = 0; i < no_Of_Elements; i++)
			cout << box[i] << " ";
		cout << endl;
	}

	Stack<T> operator =(const Stack<T>& obj)
	{
		//checking if caller function already
		//has some allocated memory
		if (this)
			delete[] this->box;

		//Copying (Assigning)
		this->no_Of_Elements = obj.no_Of_Elements;
		this->capacity = obj.capacity;
		this->top = obj.top;
		//Initialize Values
		box = new T[this-> no_Of_Elements];
		//copying stack
		for (int i = 0; i < this->no_Of_Elements; i++)
			this->box[i] = obj.box[i];

		return *this;
	}
	
	void reverseStack() {
		if (this->Empty())
			return;
		int x = peak();
		pop();
		reverseStack();
		push(x);
	}
};
