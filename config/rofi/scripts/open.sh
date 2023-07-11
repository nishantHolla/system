
#!/bin/bash

APPLICATIONS_OPTIONS="applications\0icon\x1fGI_fileAppWhite\n"
IMAGE_OPTION="images\0icon\x1fGI_fileImageWhite\n"
VIDEO_OPTION="videos\0icon\x1fGI_fileVideoWhite\n"
TEXT_OPTION="texts\0icon\x1fGI_fileTextWhite\n"
PDF_OPTION="pdfs\0icon\x1fGI_filePdfWhite\n"
DIRECTORIES_OPTION="directories\0icon\x1fGI_fileDirectoryWhite\n"

OPTIONS="$APPLICATIONS_OPTIONS$IMAGE_OPTION$VIDEO_OPTION$TEXT_OPTION$PDF_OPTION$DIRECTORIES_OPTION"

SELECTED=`echo -en "$OPTIONS" | rofi -dmenu -i -p "Open: " -icon-theme GI`

if [[ -z "$SELECTED" ]] ; then
	exit 1
fi

openImage() {
	COLLECTED_FILES=`fd -H -e jpg -e jpeg -e png -e webp . $HOME | sort | sed 's/$/\\\0icon\\\x1fGI_fileImageWhite/'`
	SELECTED_FILE=`echo -en  "$COLLECTED_FILES" | rofi -dmenu -i -p "Open image: " -icon-theme GI`
	if [[ -f "$SELECTED_FILE" ]]; then
		$IMAGE_VIEWER $SELECTED_FILE
	else
		exit 2
	fi

}

openVideo() {
	COLLECTED_FILES=`fd -H -e mp4 . $HOME | sort | sed 's/$/\\\0icon\\\x1fGI_fileVideoWhite/'`
	SELECTED_FILE=`echo -en "$COLLECTED_FILES" | rofi -dmenu -i -p "Open video: " -icon-theme GI`
	if [[ -f "$SELECTED_FILE" ]]; then
		$VIDEO_VIEWER $SELECTED_FILE
	else
		exit 2
	fi
}

openText() {
	COLLECTED_FILES=`fd -H -e txt -e md -e sh . $HOME | sort | sed 's/$/\\\0icon\\\x1fGI_fileTextWhite/'`
	SELECTED_FILE=`echo -en "$COLLECTED_FILES" | rofi -dmenu -i -p "Open text file: " -icon-theme GI`
	if [[ -f "$SELECTED_FILE" ]]; then
		$TERMINAL $EDITOR $SELECTED_FILE
	else
		exit 2
	fi
}

openDirectory() {
	COLLECTED_FILES=`fd -H -t d . $HOME | sort | sed 's/$/\\\0icon\\\x1fGI_fileDirectoryWhite/'`
	SELECTED_FILE=`echo -en "$COLLECTED_FILES" | rofi -dmenu -i -p "Open directory: " -icon-theme GI`
	if [[ -d "$SELECTED_FILE" ]]; then
		$FILE_MANAGER $SELECTED_FILE
	else
		exit 2
	fi
}

openPdf() {
	COLLECTED_FILES=`fd -H -e pdf . $HOME | sort |  sed 's/$/\\\0icon\\\x1fGI_filePdfWhite/'`
	SELECTED_FILE=`echo -en "$COLLECTED_FILES" | rofi -dmenu -i -p "Open PDF: " -icon-theme GI`
	if [[ -f "$SELECTED_FILE" ]]; then
		$PDF_VIEWER $SELECTED_FILE
	else
		exit 2
	fi
}

sleep 0.3
case "$SELECTED" in

	"applications")
		rofi -show drun;;

	"images")
		openImage;;

	"videos")
		openVideo;;

	"texts")
		openText;;

	"pdfs")
		openPdf;;

	"directories")
		openDirectory;;

	*) exit 3;;
esac
