#include <iostream>
#include <windows.h>
#include <cmath>

void PushArray(int *&arr, int &size) 
{
	size++;
	int* temp = new int[size] {};
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = arr[i];
	}
	temp[size - 1] = 100;
	delete[] arr;
	arr = temp;
}

void Memory(int*& arr, int& size) {
	if (arr != nullptr)
	{
		delete[] arr;
	} 
	arr = new int[size];
}
void Fill(int*& arr, int& size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}
void Print(int*& arr, int& size) {
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}
void Delete(int*& arr) {
	if (arr == nullptr)
	{
		return;
	}
	delete[] arr;
	arr = nullptr;
}


int main(){
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);


	int size = 5;
	int* ptr = nullptr;

	Memory(ptr, size);
	Fill(ptr, size);
	Print(ptr, size);
	Delete(ptr);


	return 0;
}

/*
int size = 0;
	std::cin >> size;
	int* ptr = new int[size];

	delete[] ptr;
	ptr = nullptr;

	int row = 3, col = 4;

	int* ad = &row;
	int** fds = &ad;

	int** vv = new int* [row];
	for (int i = 0; i < row; i++)
	{
		vv[i] = new int[col];
	}

	for (int i = 0; i < row; i++)
	{
		delete[] vv[i];
	}
	delete[] vv;

	// аудиетория
	int side = 2, row = 4, col1 = 4, col2 = 3;
	int*** arr = new int** [side];
	for (int i = 0; i < side; i++)
	{
		arr[i] = new int* [row];
	}
	for (int i = 0; i < row; i++)
	{
		arr[0][i] = new int[col1];

	}
	arr[1][0] = new int[2];
	for (int i = 1; i < row; i++)
	{
		arr[1][i] = new int[col2];
	}


	int size = 5;
	int* name = new int[size] {3, 1, 2, 6, 9};

	for (int i = 0; i < size; i++)
	{
		std::cout << name[i] << " ";
	}
	std::cout << "\n\n";
	PushArray(name,size);

	for (int i = 0; i < size; i++)
	{
		std::cout << name[i] << " ";
	}
*/
