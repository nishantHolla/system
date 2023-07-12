#include "iostream"
#include "string"
#include "vector"

#include "sisCall.hpp"

std::string popArgs(int* argc, char** argv[]);

int main (int argc, char *argv[]) {
	if (argc < 3)
		std::exit(1);

	std::string program = popArgs(&argc, &argv);
	std::string domain = popArgs(&argc, &argv);
	std::string action = popArgs(&argc, &argv);

	std::vector<std::string> args = {};
	for (int i=0; i<argc; i++)
		args.push_back(argv[i]);
	argc = 0;

	SisCall::query(domain, action, args);

	return 0;
}

std::string popArgs(int* argc, char** argv[]) {
	(*argc)--;
	std::string arg = (*argv)[0];
	(*argv)++;
	return arg;
}
