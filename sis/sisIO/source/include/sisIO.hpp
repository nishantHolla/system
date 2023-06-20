
#ifndef SIS_IO_H_
#define SIS_IO_H_

#include <string>
#include <unordered_map>
#include <iostream>


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

	~SisIO();

private:

	std::unordered_map<messageType, color> messageTypeToColor;
	std::unordered_map<messageType, std::string> messageTypeToTag;
	std::unordered_map<color, std::string> colorToAnsiCode;

	const std::string colorReset;

};


#endif // !SIS_IO_H_
