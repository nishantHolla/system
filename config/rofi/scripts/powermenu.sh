
#!/bin/bash

SHUTDOWN_OPTION="shutdown\0icon\x1fGI_powerShutdownWhite\n"
RESTART_OPTION="restart\0icon\x1fGI_powerRestartWhite\n"
SLEEP_OPTION="sleep\0icon\x1fGI_powerSleepWhite\n"
LOCK_OPTION="lock\0icon\x1fGI_powerLockWhite\n"

OPTIONS="$SHUTDOWN_OPTION$RESTART_OPTION$SLEEP_OPTION$LOCK_OPTION"

SELECTED=`echo -en "$OPTIONS" | rofi -dmenu -p "Powermenu: " -icon-theme GI`

if [[ -z "$SELECTED" ]] ; then
	exit 1
fi

$XDG_CONFIG_HOME/rofi/scripts/confirm.sh
if [[ "$?" == "1" ]] ; then
	exit 1
fi

if [[ $SELECTED == "shutdown" ]] ; then
	shutdown now
elif [[ $SELECTED == "restart" ]] ; then
	reboot
elif [[ $SELECTED == "sleep" ]] ; then
	systemctl suspend
elif [[ $SELECTED == "lock" ]] ; then
	betterlockscreen -l
fi
