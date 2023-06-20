
#ifndef SIS_AUTH_H_
#define SIS_AUTH_H_

#include <iostream>
#include <filesystem>
#include <string>

class SisAuth {

public:

	SisAuth();

	std::string generateHash(std::string _password, unsigned int _length);

	~SisAuth();

private:
	bool hasArgon2;

};

#endif // !SIS_AUTH_H_
