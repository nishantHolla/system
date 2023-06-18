
#ifndef SIS_IO_H_
#define SIS_IO_H_

#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

#define MAX_INPUT 100
#define MAX_LOG 1000

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
	const String ansiBlue;
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
	String tagInput;

	void output(mType _mType, const String& _message, bool _color, bool _tag);

	template<typename T>
		T input(const String& _message, bool _color, bool _tag) {
			if (_color)
				std::cout << colorInput;

			if (_tag)
				std::cout << tagInput;

			std::cout << _message;

			if (_color)
				std::cout << ansiReset;

			T inp;
			std::getline(std::cin, inp);
			return inp;
		}

	int log(mType _mType, const String& _message, const String& _sender);

private:

	String colorNone;
	String colorOkay;
	String colorInfo;
	String colorWarn;
	String colorError;
	String colorInput;

	std::unordered_map<mType, String*> colorMap;
	std::unordered_map<mType, String*> tagMap;

};

#endif // !SIS_IO_H_
