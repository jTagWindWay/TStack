#pragma once

template <class T>
class TStack {

private:

	int Size;
	int MaxSize;
	T *mas;

public:

	TStack(_MaxSize = 100) {
		MaxSize = _MaxSize;
		Size = 0;
		mas = new T[MaxSize];
	}

	TStack(const TSctack&ts) {
		MaxSize = ts.MaxSize;
		Size = ts.Size;
		mas = new T[ts.MaxSize];
		for (int i = 0; i < Size; i++) {
			mas[i] = ts.mas[i];
		}
	}

	~TStack() {
		delete[]mas;
	}

	bool isEmpty() {
		return Size==0;
	}

	bool isFull() {
		return Size=MaxSize;
	}

	void Push(T a) {
		if (isEmpty())
			throw - 1;
		mas[Size] = a;
		Size++;
	}
	
	T Top()cons{
		if (isEmpty())
		    throw - 1;
		Size--;
		return mas[Size];
	}

	T Pop(){
		if (isEmpty())
			throw - 1;
		Size--;
		return mas[Size];
	}

	void Clear(){
		Size = 0;
	}
};