
#include <stdexcept>
#include <iostream>

#include "sisCall.hpp"
#include "sisAuth.hpp"

void SisCall::query(
		const std::string& _domain,
		const std::string& _action,
		const std::vector<std::string>& _args
) {

	if (_domain == "auth") {
		SisAuth auth;

		if (_action == "hash") {
			if (_args.size() != 1)
				throw std::invalid_argument("Usage: sis auth hash <string: password>");

			std::cout << auth.generateHash(_args[0]);

		}

		if (_action == "check") {
			if (_args.size() != 2)
				throw std::invalid_argument("Usage: sis auth check <string: password> <string: hash>");

			if (auth.checkHash(_args[0], _args[1]))
				std::cout << 1;
			else
				std::cout << 0;
		}

	}

}
