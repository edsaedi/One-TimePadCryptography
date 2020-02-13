#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
#include <cctype>
#include <vector>
#include <iterator>
#include <fstream>
#include <filesystem>
#include <array>
#include <unordered_set>
#include <tuple>

std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

void LowerCase(std::string& string)
{
	std::transform(string.begin(), string.end(), string.begin(),
		[](unsigned char c) { return std::tolower(c); });
}

std::string GenerateKey(int length)
{
	std::string result;
	for (size_t i = 0; i < length; i++)
	{
		int random = rand() % 26;
		result += alphabet[random];
	}
	return result;
}

//int Modulo(int a, int b)
//{
//	if (a >= 0)
//	{
//		return a % b;
//	}
//	a *= -1;
//	return a & b;
//}

std::tuple<std::string, std::string> Encrypt(std::string plaintext)
{
	std::string result = "";
	std::string key = GenerateKey(plaintext.size());
	for (size_t i = 0; i < key.size(); i++)
	{
		auto indexPlain = alphabet.find(plaintext[i]);
		if (indexPlain == std::string::npos)
		{
			result += plaintext[i];
		}
		else
		{
			auto indexKey = alphabet.find(key[i]);
			result += alphabet[(indexKey + indexPlain) % 26];
		}
	}

	std::tuple<std::string, std::string> returner = std::make_tuple(result, key);
	return returner;
}

std::string Decrypt(std::string encrypted, std::string key)
{
	std::string result = "";
	for (size_t i = 0; i < key.size(); i++)
	{
		auto indexEncr = alphabet.find(encrypted[i]);
		auto indexKey = alphabet.find(key[i]);
		result += alphabet[(indexEncr - indexKey + 26) % 26];
	}

	return result;
}

int main()
{
	srand(time(nullptr));

	std::cout << "Enter in a string to encrypt without spaces.\n";
	std::string plaintext;
	std::cin >> plaintext;
	LowerCase(plaintext);
	auto tup = Encrypt(plaintext);
	std::string encryption = std::get<0>(tup);
	std::cout << encryption << "\n";
	std::string key = std::get<1>(tup);
	std::cout << key << "\n";
	std::string decrypted = Decrypt(encryption, key);
	std::cout << decrypted;
}
