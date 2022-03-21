#include<bits/stdc++.h>
using namespace std;

template<class T>
class Array{
public:
	Array(int capacity){
		this->capacity = capacity;
		this->size = 0;
		this->array = new T[capacity];
	}
	
	Array(const Array &arr){
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->array = new T[arr.capacity];
		for(int i=0;i<arr.size;i++){
			this->arr[i] = arr.arr[i];
		}
	}
	
	~Array(){
		if(this->array != NULL){
			delete[] this->array;
			this->array = NULL;
		}	
	}
	
	T* array;
	int capacity;
	int size;
	
	Array& operator=(const Array &arr){
		if(this->array != NULL){
			delete[] this->array;
			this->array = NULL;
		}
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->array = new T[arr.capacity];
		for(int i=0;i<arr.size;i++){
			this->arr[i] = arr.arr[i];
		}
		return *this;
	}
	
	T& operator[](const int index){
		return this->array[index];
	}
	
	void Push_Back(const T &value){
		if(this->size == this->capacity){
			cout<<"该数组已满"<<endl;
			return;
		}
		this->array[this->size] = value;
		this->size++;
	}
	
	void Pop_Back(){
		if(this->size == 0){
			cout<<"该数组已空"<<endl;
			return;
		}
		this->size--;
	}
	
};

int main(){
	Array<string> arr1(10);
	
	for(int i=0;i<10;i++){
		arr1[i] = "aaaa";
		cout<<arr1[i]<<endl;
	}
	return 0;
} 
