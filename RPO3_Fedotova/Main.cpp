#define NOMINMAX
#include "Test.hpp"
#include <windows.h>
#include <string>
#include <limits>
#include <io.h>		// _setmode, _fileno
#include <fcntl.h>	// _O_U16TEXT

void PushArray(int*& arr, int& size)
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

void GetIn(int*& arr, int& size, int index)
{
	if (index < 0 || index > size) {
		return;
	}
	int newSize = size + 1;
	int* temp = new int[newSize] {};
	int j = 0;
	for (int i = 0; i < newSize; i++)
	{
		if (i == index)
		{
			temp[i] = 24;
		}
		else {
			temp[i] = arr[j++];
		}
	}
	delete[] arr;
	arr = temp;
	size = newSize;
}

void GetOff(int*& arr, int& size, int index)
{
	if (index < 0 || index >= size) {
		return;
	}
	int newSize = size - 1;
	int* temp = new int[newSize] {};
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			continue;
		}
		else {
			temp[j++] = arr[i];
		}
	}
	delete[] arr;
	arr = temp;
	size = newSize;
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
	std::wcout << L"Рандомный массив: ";
	for (int i = 0; i < size; i++)
	{
		std::wcout << arr[i] << L" ";
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



int main() {
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	// изменения из-за сетмод
	/*
	std::string			std::wstring		широкая строка
	char				wchar_t
	std::cout			std::wcout
	std::cin			std::wcin
	"text"				L"text"
	'f'					L'f'


	std::wstring one, two;
	std::wcout << L"Введите текст: ";
	std::getline(std::wcin, one, L'\n');
	std::wcout << L"Введите текст: ";
	std::getline(std::wcin, two, L'\n');
	std::wcout << one << L'\n' << two << std::endl;

	*/
	/*
	std::wstring name = L"Hello world\n";
	std::wcout << name;

	// найти слово в строке (индекс первой буквы)
	size_t position = name.find(L"world");
	std::wcout << position << L"\n\n";
	if (position != std::wstring::npos)
	{
		std::wcout << L"слово найдено юхуууу" << L"\n";
	}

	// возврат какого-то участка строки (с какого индекса, сколько символа читатать)
	std::wcout << name.substr(4, 5) << L"\n\n";

	// вырезка
	name.erase(4, 5);
	std::wcout << name << L'\n';

	// вставка
	name.insert(3, L"   Привет Мир   ");
	std::wcout << name << L'\n';

	// замена (с какого индекса начать, сколько слов вырезать, что вставить
	name.replace(5, 4, L"Толя ");
	std::wcout << name << L"\n\n";

	name.clear();
	if (name.empty())
	{
		std::wcout << L"Строка пустая(\n\n";
	}
	*/


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


	//регистрация и вход
	/*
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
	*/



	int size = 5;
	int* ptr = nullptr;

	Memory(ptr, size);
	Fill(ptr, size);
	Print(ptr, size);
	Delete(ptr);

	int* name = new int[size] {3, 1, 2, 6, 9};
	std::wcout << L"\n\n";
	std::wcout << L"До добавления: ";

	for (int i = 0; i < size; i++)
	{
		std::wcout << name[i] << L" ";
	}
	std::wcout << L"\n";
	PushArray(name, size);

	std::wcout << L"После добавления в конец: ";
	for (int i = 0; i < size; i++)
	{
		std::wcout << name[i] << L" ";
	}

	int index_GetIn = 3;
	GetIn(name, size, index_GetIn);
	std::wcout << L"\nПосле добавления по индексу: ";
	for (int i = 0; i < size; i++)
	{
		std::wcout << name[i] << L" ";
	}

	int index_GetOff = 5;
	GetOff(name, size, index_GetOff);
	std::wcout << L"\nПосле удаления по индексу: ";
	for (int i = 0; i < size; i++)
	{
		std::wcout << name[i] << L" ";
	}

	std::wcout << L"\n\n";
	Delete(name);
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
