
#!/bin/bash

YES_OPTION="yes\0icon\x1fGI_confirmYesWhite\n"
NO_OPTION="no\0icon\x1fGI_confirmNoWhite\n"

OPTIONS="$YES_OPTION$NO_OPTION"


SELECTION=`echo -en $OPTIONS | rofi -dmenu -i -p "Are you sure? : " -icon-theme GI`

echo "$SELECTION"
if [[ $SELECTION == "yes" ]] ; then
	exit 0
fi
exit 1
