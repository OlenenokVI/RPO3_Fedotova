#define NOMINMAX
#include <iostream>
#include <windows.h>
#include <string>
#include <limits>

/*
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
*/


int main(){
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8); //1251 CP_UTF8
	srand(time(NULL));

	// откладка
	/*
	std::string name = "Text";
	std::string* ptr = nullptr;
	ptr = new std::string[5];
	delete[] ptr;
	std::string arr[2]{ "hello", "hi" };
	arr[1][2]; - во втором слове вторая буква

	name.erase(3);
	std::cout << name;

	auto lol = std::find(arr->begin(), arr->end(), "hi");

	std::string test = "Виктория";
	for (int i = 0; i < test.size(); i++)
	{
		std::cout << test[i] ;
	}
	*/
	/*
	std::string one;
	int num = 0;

	while (true)
	{
		system("cls");

		std::getline(std::cin, one); // откуда, куда положить
		std::cout << one << std::endl;

		std::getline(std::cin, one, 'r'); // считывает до символа r
		std::cout << one << std::endl;

		std::cin >> num;
		std::cout << num << std::endl;

		// std::cin.ignore(32767, '\n'); не самый лучший способ. (очистка сина, чтоб гетлайн снова работал после него)

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // лучший способ

		system("pause");
	}
	*/

	while (true)
	{
		system("cls");
		std::cout << "\t Регистрация\n\n";
		std::cout << "Придумайте и введите логин: ";
		std::string login;
		std::getline(std::cin, login);
		if (login.size() < 5 || login.size() > 15)
		{
			std::cout << "Неподходящий логин! \n";
			Sleep(1000);
			continue;
		}
		std::cout << "\nПридумайте и введите пароль: ";
		std::string password;
		while (true)
		{
			system("cls");
			std::cout << "\t Регистрация\n\n";
			std::cout << "Ваш логин: " << login;
			std::cout << "\nПридумайте и введите пароль: ";
			std::getline(std::cin, password);
			if (password.size() < 5 || password.size() > 15)
			{
				std::cout << "Неподходящий пароль! \n";
				Sleep(1000);
			}
			else
			{
				break;
			}
		}

		system("pause");

		while (true)
		{
			system("cls");

			std::cout << "\t Авторизация\n\n";
			std::cout << "Введите свой логин: ";
			std::string login_new;
			std::getline(std::cin, login_new);
			if (login_new != login)
			{
				std::cout << "Неверный логин! \n";
				Sleep(1000);
				continue;
			}
			std::cout << "\nВведите свой пароль: ";
			std::string password_new;
			while (true)
			{
				system("cls");
				std::cout << "\t Авторизация\n\n";
				std::cout << "Ваш логин: " << login_new;
				std::cout << "\nВведите свой пароль: ";
				std::getline(std::cin, password_new);
				if (password_new != password)
				{
					std::cout << "Неверный пароль! \n";
					Sleep(1000);
				}
				else
				{
					break;
				}
			}
			std::cout << "\n\nПоздравляем с успешным входом! :)\n\n";

			system("pause");
		}
	}
	








	/*
	int size = 5;
	int* ptr = nullptr;

	Memory(ptr, size);
	Fill(ptr, size);
	Print(ptr, size);
	Delete(ptr);
	*/
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
