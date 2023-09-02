
#!/bin/bash

SHUTDOWN_OPTION="shutdown\0icon\x1fGI_powerShutdownWhite\n"
RESTART_OPTION="restart\0icon\x1fGI_powerRestartWhite\n"
SLEEP_OPTION="sleep\0icon\x1fGI_powerSleepWhite\n"
LOCK_OPTION="lock\0icon\x1fGI_powerLockWhite\n"
LOGOUT_OPTION="logout\0icon\x1fGI_powerLogoutWhite\n"

OPTIONS="$SHUTDOWN_OPTION$RESTART_OPTION$LOCK_OPTION$SLEEP_OPTION$LOGOUT_OPTION"

SELECTED=`echo -en "$OPTIONS" | rofi -dmenu -i -p "Powermenu: " -icon-theme GI`

if [[ -z "$SELECTED" ]] ; then
	exit 1
fi

$XDG_CONFIG_HOME/rofi/scripts/confirm.sh
if [[ "$?" == "1" ]] ; then
	exit 2
fi

case "$SELECTED" in

	"shutdown") awesome-client "AwesomeWM.functions.shutdown()";;
	"restart") reboot;;
	"logout") kill -9 -1;;
	"sleep") systemctl suspend && betterlockscreen -l;;
	"lock") betterlockscreen -l;;
	*) exit 3;

esac
