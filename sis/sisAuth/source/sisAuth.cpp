
#include "sisAuth.hpp"

SisAuth::SisAuth() {

	if (std::filesystem::exists("/usr/bin/argon2") == false) {
		std::cout << "Argon2 not found! SisAuth will not work.";
		hasArgon2 = false;
	}
	else {
		hasArgon2 = true;
	}

}


std::string SisAuth::generateHash(std::string _password, unsigned int _length) {

	if (hasArgon2 == false)
		return "";

	std::string command = "echo \"" + _password + "\" | argon2 saltItWithSalt -r -l " + std::to_string(_length);
	FILE* process = popen(command.c_str(), "r");
	if (process == nullptr)
		return "";

	std::string hash;
	char c;
	while ((c=fgetc(process)) != EOF)
		hash += c;

	pclose(process);

	return hash;
}


SisAuth::~SisAuth() {}
