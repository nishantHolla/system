
#ifndef SIS_IO_H_
#define SIS_IO_H_

#include <string>
#include <iostream>
#include <unordered_map>

using String = std::string;

class SisIO {
public:

	enum mType {
		mTypeNone,
		mTypeOkay,
		mTypeInfo,
		mTypeWarn,
		mTypeError
	};

	SisIO(const String& _logPath);
	~SisIO();


	const String ansiWhite;
	const String ansiGreen;
	const String ansiCyan;
	const String ansiYellow;
	const String ansiRed;
	const String ansiReset;

	String logPath;
	mType logLevel;

	String tagNone;
	String tagOkay;
	String tagInfo;
	String tagWarn;
	String tagError;

	void output(mType _mType, const String& _message, bool _color, bool _tag);

private:

	String colorNone;
	String colorOkay;
	String colorInfo;
	String colorWarn;
	String colorError;

	std::unordered_map<mType, String*> colorMap;
	std::unordered_map<mType, String*> tagMap;

};

#endif // !SIS_IO_H_
