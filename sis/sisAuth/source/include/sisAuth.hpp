
#ifndef SIS_AUTH_H_
#define SIS_AUTH_H_

#include <string>

using String = std::string;

class SisAuth {
public:

	String hash(const String& _password, const int& _length);
	bool check(const String& _password, const String& _hash, const int& _length);

private:

};

#endif // !SIS_AUTH_H_
