
#!/bin/bash

link() {
	if [[ (-d $2) || (-f $2) ]] ; then
		echo "Collision detected. $2 already exists. Skipping ..."
		return
	fi

	CURRENT_DIR=`pwd`
	TARGET="$CURRENT_DIR/$1"
	echo "Linking $TARGET to $2 ..."
	ln -sf "$TARGET" $2
}

pull() {
	if [[ (-d $2) || (-f $2) ]] ; then
		echo "Collision detected. $2 already exists. Skipping ..."
		return
	fi

	echo "Pulling down $1 to $2 ..."
	git clone -q $1 $2
}


if [ -z "$XDG_CONFIG_HOME" ] ; then
	CONFIG_DIR="$HOME/.config"
else
	CONFIG_DIR="$XDG_CONFIG_HOME"
fi

link contour "$CONFIG_DIR/contour"
link lf "$CONFIG_DIR/lf"
link pcmanfm "$CONFIG_DIR/pcmanfm"
link picom "$CONFIG_DIR/picom"
link rofi "$CONFIG_DIR/rofi"
link starship "$CONFIG_DIR/starship"
link xprofile/xprofile "$HOME/.xprofile"
link zathura "$CONFIG_DIR/zathura"
link zsh "$CONFIG_DIR/zsh"

pull git@github.com:nishantHolla/awesomeConfig.git "$CONFIG_DIR/awesome"
pull git@github.com:nishantHolla/neovimConfig.git "$CONFIG_DIR/nvim"
