
#include "sisIO.hpp"


SisIO::SisIO(const String& _logPath):
	ansiWhite ("\u001b[37;1m"),
	ansiGreen ("\u001b[32;1m"),
	ansiCyan ("\u001b[36;1m"),
	ansiYellow ("\u001b[33;1m"),
	ansiRed ("\u001b[31;1m"),
	ansiBlue ("\u001b[34;1m"),
	ansiReset ("\u001b[0m"),

	logPath (_logPath),
	logLevel (SisIO::mTypeNone),

	tagNone (" [MSSG] "),
	tagOkay (" [OKAY] "),
	tagInfo (" [INFO] "),
	tagWarn (" [WARN] "),
	tagError (" [ERRR] "),
	tagInput (" [INPT] "),

	colorNone (ansiWhite),
	colorOkay (ansiGreen),
	colorInfo (ansiCyan),
	colorWarn (ansiYellow),
	colorError (ansiRed),
	colorInput (ansiBlue)
{
	tagMap[mTypeNone] = &tagNone;
	tagMap[mTypeOkay] = &tagOkay;
	tagMap[mTypeInfo] = &tagInfo;
	tagMap[mTypeWarn] = &tagWarn;
	tagMap[mTypeError] = &tagError;

	colorMap[mTypeNone] = &colorNone;
	colorMap[mTypeOkay] = &colorOkay;
	colorMap[mTypeInfo] = &colorInfo;
	colorMap[mTypeWarn] = &colorWarn;
	colorMap[mTypeError] = &colorError;
}

void SisIO::output(mType _mType, const String& _message, bool _color, bool _tag) {

	if (_color)
		std::cout << *colorMap[_mType];

	if (_tag)
		std::cout << *tagMap[_mType];

	std::cout << _message;

	if (_color)
		std::cout << ansiReset;

	std::cout << "\n";

}

int SisIO::log(mType _mType, const String& _message, const String& _sender) {
	std::fstream logFile (logPath, std::ios::app);

	if (logFile.good() == false)
		return 1;

	const String logMessage = "\nFrom: " + _sender + "\nType: " + *tagMap[_mType] + "\nMessage: " + _message + "\n";

	if (logMessage.size() > MAX_LOG) {
		logFile.close();
		return 2;
	}

	logFile.write(logMessage.c_str(), logMessage.size());

	logFile.close();
	return 0;
}

SisIO::~SisIO() {}
