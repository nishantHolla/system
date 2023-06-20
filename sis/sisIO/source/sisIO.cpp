
#include "sisIO.hpp"

SisIO::SisIO(std::string _logFilePath) :
	logFilePath (_logFilePath),
	logLevel (messageTypeNone),
	colorMessages (true),
	tagMessages (true),
	colorReset ("\u001b[0m")
{

	messageTypeToColor[messageTypePrompt] = colorBlue;
	messageTypeToColor[messageTypeNone] = colorWhite;
	messageTypeToColor[messageTypeOkay] = colorGreen;
	messageTypeToColor[messageTypeInfo] = colorCyan;
	messageTypeToColor[messageTypeWarn] = colorYellow;
	messageTypeToColor[messageTypeError] = colorRed;

	messageTypeToTag[messageTypePrompt] = " [INPT] ";
	messageTypeToTag[messageTypeNone] = "  ";
	messageTypeToTag[messageTypeOkay] = " [OKAY] ";
	messageTypeToTag[messageTypeInfo] = " [INFO] ";
	messageTypeToTag[messageTypeWarn] = " [WARN] ";
	messageTypeToTag[messageTypeError] = " [ERRR] ";

	colorToAnsiCode[colorBlue] = "\u001b[34;1m";
	colorToAnsiCode[colorWhite] = "\u001b[37;1m";
	colorToAnsiCode[colorGreen] = "\u001b[32;1m";
	colorToAnsiCode[colorCyan] = "\u001b[36;1m";
	colorToAnsiCode[colorYellow] = "\u001b[33;1m";
	colorToAnsiCode[colorRed] = "\u001b[31;1m";

}

int SisIO::output(messageType _messageType, const std::string& _message, bool _endline) {

	if (colorMessages)
		std::cout << colorToAnsiCode[messageTypeToColor[_messageType]];

	if (tagMessages)
		std::cout << messageTypeToTag[_messageType];

	std::cout << _message;

	if (colorMessages)
		std::cout << colorReset;

	if (_endline)
		std::cout << std::endl;

	return 0;
}

SisIO::~SisIO() {};