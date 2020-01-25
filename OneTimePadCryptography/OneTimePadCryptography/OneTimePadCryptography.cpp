#include <iostream>
#include <string>
#include <time.h>

std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

std::string GenerateKey(int length)
{
	std::string result;
	srand(time(NULL));
	for (size_t i = 0; i < length; i++)
	{
		int random = rand() % 26;
		result += alphabet[random];
	}
	return result;
}

int main()
{
	std::cout << "Hello World!\n";
}
