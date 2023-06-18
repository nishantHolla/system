
#include "sisAuth.hpp"
#include <cstdio>
#include <string>

String SisAuth::hash(const String &_password, const int& _length) {
	String command ("echo \"" + _password + "\" | argon2 saltItWithSalt -l " + std::to_string(_length) + " -r");
	FILE* process = popen(command.c_str(), "r");

	if (process == nullptr)
		return "";

	String hash;
	for (int i=0; i < _length * 2; i++)
		hash += getc(process);

	pclose(process);
	return hash;
}

bool SisAuth::check(const String& _password, const String& _hash, const int& _length) {
	String passwordHash (SisAuth::hash(_password, _length));
	return (passwordHash == _hash);
}
