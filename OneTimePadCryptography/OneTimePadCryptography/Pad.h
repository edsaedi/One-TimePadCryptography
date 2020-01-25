#pragma once
#include <iostream>
#include <string>
class Pad
{
public:
	std::string alphabet = "abcdefghijklmnopqrstuvwxxyz";
	std::string Encrypt(std::string plaintext, std::string key);
	std::string Decrypt(std::string ciphertext, std::string key);
};

