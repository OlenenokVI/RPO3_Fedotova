#include "Test.hpp"

int a = 0;

void PrintHello()
{
	std::wcout << L"Hi\n";
}

int aloy(int a)
{
	static int g = 10; // но тут переменная наоборот живет :|
	return 0;
}

bool islol()
{
	return false;
}
