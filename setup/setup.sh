
#!/bin/bash

SETUP_DIR=`pwd`

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

cd ../config/
link alacritty "$CONFIG_DIR/alacritty"
link clangd "$CONFIG_DIR/clangd"
link contour "$CONFIG_DIR/contour"
link git "$CONFIG_DIR/git"
link lf "$CONFIG_DIR/lf"
link picom "$CONFIG_DIR/picom"
link rofi "$CONFIG_DIR/rofi"
link starship "$CONFIG_DIR/starship"
link xprofile/xprofile "$HOME/.xprofile"
link zathura "$CONFIG_DIR/zathura"
link zsh "$CONFIG_DIR/zsh"

pull git@github.com:nishantHolla/awesomeConfig.git "$CONFIG_DIR/awesome"
pull git@github.com:nishantHolla/neovimConfig.git "$CONFIG_DIR/nvim"
cd $SETUP_DIR

cd $HOME
pull git@github.com:nishantHolla/icons.git "$HOME/Icons"
mkdir -p $HOME/.local/share/icons
link Icons "$HOME/.local/share/icons/GI"

pull git@github.com:nishantHolla/fonts.git "$HOME/Fonts"
link Fonts "$HOME/.local/share/fonts"

pull git@github.com:nishantHolla/wallpapers.git "$HOME/Wallpapers"
