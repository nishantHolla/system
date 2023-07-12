
#ifndef SIS_CALL_H_
#define SIS_CALL_H_

#include <string>
#include <vector>

class SisCall {
public:

private:

// ---

public:

	static void query(
			const std::string& _domain,
			const std::string& _action,
			const std::vector<std::string>& _args
	);


private:
};

#endif // !SIS_CALL_H_
