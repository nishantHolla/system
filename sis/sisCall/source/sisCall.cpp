
#include <stdexcept>
#include <iostream>

#include "sisCall.hpp"
#include "sisAuth.hpp"
#include "sisPower.hpp"

void SisCall::query(
		const std::string& _domain,
		const std::string& _action,
		const std::vector<std::string>& _args
) {

	if (_domain == "auth") {
		SisAuth auth;

		if (_action == "hash") {
			if (_args.size() != 1)
				throw std::invalid_argument("Bad args\nUsage: sis auth hash <string: password>");

			std::cout << auth.generateHash(_args[0]);

		}

		else if (_action == "check") {
			if (_args.size() != 2)
				throw std::invalid_argument("Bad args\nUsage: sis auth check <string: password> <string: hash>");

			if (auth.checkHash(_args[0], _args[1]))
				std::cout << 1;
			else
				std::cout << 0;
		}

		else
			throw std::invalid_argument("Bad action\nUsage: sis auth <hash | check>");

	}

	else if (_domain == "power") {
		SisPower power;

		if (_action == "lock")
			power.lock();

		else if (_action == "shutdown")
			power.shutdown();

		else if (_action == "restart")
			power.restart();

		else if (_action == "logout")
			power.logout();

		else if (_action == "sleep")
			power.sleep();

		else
			throw std::invalid_argument("Bad action\nUsage: sis power <lock | shutdown | restart | logout | sleep>");

	}
}
