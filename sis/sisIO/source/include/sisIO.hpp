
#ifndef SIS_IO_H_
#define SIS_IO_H_

#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>


class SisIO {

public:

	SisIO(std::string _logFilePath);

	enum messageType {
		messageTypePrompt,
		messageTypeNone,
		messageTypeOkay,
		messageTypeInfo,
		messageTypeWarn,
		messageTypeError
	};

	enum color {
		colorWhite,
		colorGreen,
		colorCyan,
		colorYellow,
		colorRed,
		colorBlue
	};

	std::string logFilePath;
	messageType logLevel;
	bool colorMessages;
	bool tagMessages;

	int output(messageType _messageType, const std::string& _message, bool _endline=true);
	std::string inputLine(const std::string& _message);
	int log(messageType _messageType, const std::string& _message, const std::string _sender);

	template<typename T>
		T input(const std::string& _message) {
			output(messageTypePrompt, _message, false);
			T result;
			std::cin >> result;
			return result;
		}


	~SisIO();

private:

	std::unordered_map<messageType, color> messageTypeToColor;
	std::unordered_map<messageType, std::string> messageTypeToTag;
	std::unordered_map<color, std::string> colorToAnsiCode;

	const std::string colorReset;

};


#endif // !SIS_IO_H_
