template <typename T>
class stack
{
private:

	int no_Of_Elements, top, end, capacity;
	T* box;
	bool inverted = false;
public:
	//Constrcutor
	//Default Constructor
	stack(int isize = 0)
	{
		if (isize > 0)
		{
			capacity = isize;
			no_Of_Elements = 0;
			top = end = -1;
			box = new T[capacity];
		}
		else
		{
			no_Of_Elements = capacity = 0;
			box = nullptr;
			top = end = -1;
		}
	}
	//Copy Constructor
	stack(const stack<T>& obj)
	{
		this->no_Of_Elements = obj.no_Of_Elements;
		this->capacity = obj.capacity;
		this->top = obj.top;
		this->end = obj.end;
		this->inverted = obj.inverted;

		//Initialize Values
		this->box = new T[this->no_Of_Elements];
		//copying stack
		for (int i = 0; i < this->no_Of_Elements; i++)
			this->box[i] = obj.box[i];
	}

	//Member Functions
	int next(int i) {
		return ((i + 1) % capacity);
	}
	int previous(int i) {
		return ((i + (capacity - 1)) % capacity);
	}
	// yet to code
	void reverseArray()
	{
		swap(top, end);
		if (inverted == false)
			inverted = true;
		else
			inverted = false;
	}
	//Push
	void Push(const T& obj)
	{
		if (no_Of_Elements < capacity){
			top = next(top);
			box[top] = obj;
			no_Of_Elements++;
		}
		else if (capacity == 0){
			box = new T[1];
			top = next(top);
			end = next(end);
			box[top] = obj;
			no_Of_Elements = capacity = 1;
			
		}
		else{
			if (inverted == false) {
				//Growing
				capacity *= 2;
				T* temp = new T[capacity];
				//copying values
				for (int i = 0; i < no_Of_Elements; i++) {
					temp[i] = box[i];
				}

				top = next(top);
				temp[top] = obj;

				no_Of_Elements++;

				delete[] box;
				box = temp;
			}
			else {
				capacity *= 2;
				T* temp = new T[capacity];
				//copying values
				for (int i = end, j = 0; i >= 0 && j <= (no_Of_Elements); i = previous(i), j++) {
					temp[j] = box[i];
				}
				end = 0;
				top = no_Of_Elements;
				temp[top] = obj;
				no_Of_Elements++;

				delete[] box;
				box = temp;

			}	
		}
		cout << "Pushed at : " << top << ", " << box[top] << "\t \t number of elements :" << no_Of_Elements << endl;
	}
	//Pop
	void Pop()
	{
		cout << "Pop is called" << endl;
		if (this->Empty())
			return;
		
		if (inverted == false) {
			if (no_Of_Elements > capacity / 2)
			{
				no_Of_Elements--;
				top = previous(top);
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
				top = previous(top);
				delete[] box;
				box = temp;
			}
		}
		else {
			if (no_Of_Elements > capacity / 2) {
				top = previous(top);
				no_Of_Elements--;
			}
			else if (no_Of_Elements <= capacity / 2) {
				capacity = capacity / 2;
				cout << "Shrinking started:= ;)" << endl;
				T* temp = new T[capacity];
				for (int i = end, j = 0;  j < capacity - 1 ;  j++) {
					cout << " i : " << i <<" : " <<  box[i] << " entered" << endl; 
					temp[j] = box[i];
					cout << "box[i] : " << box[i] << endl;
					cout <<"temp[" << j << "] : " <<  temp[j];
					i = previous(i);
				}
				cout << endl;
				no_Of_Elements--;
				top = no_Of_Elements - 1;
				end = 0;
				delete[] box;
				box = temp;
			}


		}
		cout << "Number of Elements: " << no_Of_Elements << "\t capacity : " << capacity << endl;
	}
	//Empty
	bool Empty()
	{
		return (no_Of_Elements == 0);
	}
	//Full
	bool Full()
	{
		return (no_Of_Elements == capacity);
	}
	//Peek
	const T& Peek()
	{
		if (this->Empty())
			return NULL;
		return this->box[top];
	}
	//Print
	void Print()
	{
		if (this->Empty()) {
			cout << "Empty queue";
			return;
		}
			
		else {
			cout << endl << endl << endl << "number of Elments : " << no_Of_Elements << "\t capacity : " << capacity;

			cout << endl << endl << "\t Content of Stack is : " << endl;
			
			for (int i = end, j = 0; j < capacity; j++) {
				cout << "\t box[" << j << "] : " << box[i] << endl;
				i = previous(i);
			}
		}
		
		cout << endl;
	}
	
	//Operator Overloading
	
	stack<T> operator =(const stack<T>& obj)
	{
		cout << "assignment operator() called" << endl;
		if (this)
			delete[] this->box;
		//Copying (Assigning)
		this->no_Of_Elements = obj.no_Of_Elements;
		this->capacity = obj.capacity;
		this->top = obj.top;
		//Initialize Values
		this->box = new T[this->no_Of_Elements];
		//copying stack
		for (int i = 0; i < this->no_Of_Elements; i++)
			this->box[i] = obj.box[i];

		return *this;
	}

};
