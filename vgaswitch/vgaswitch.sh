#!/bin/sh
# vgaswitcheroo - use involves 

if [ $UID -ne 0 ]; then
	echo "You must be the root user in order to run this."
	exit 1
fi

switchloc=/sys/kernel/debug/vgaswitcheroo/switch
function display_help(){
	tb=$'\t'
	nwl=$'\n'
	echo "VGASwitch - Version 0.1"
	echo "Usage: $0 [ARG1] [ARG2]..."
	echo " VGASwitch is a utility for aiding in the simplicity in switching graphics"
	echo " cards, often on a laptop, in which there is the presence of both an"
	echo " Integrated Graphics Card and a Discrete Graphics Card. The IGC is"
	echo " often the one connected to the CPU (hence \"integrated\") while the DGC"
	echo " often exists independent of it. This configuration is made for power "
	echo " saving: when the laptop switches to a power-saving mode, it uses the"
	echo " (less-powerful) IGC, but transitioning out of this mode (into performance"
	echo " mode) makes the laptop use the (more-powerful) DGC, although this does"
	echo " consume more energy. This short script enables you to switch between the"
	echo " two without having to write something to"
	echo -e '\e[0;32m'
	echo "  $switchloc" 
	echo -e '\e[0m'
	echo " via the Terminal, and to simplify this to an optionally automatic process."
	echo $nwl
	echo "============================= Using VGASwitch ============================="
	echo "                         Some arguments for use...                         "
	echo " ON   - This option turns on the currently inactive GPU, but does not switch"
	echo "        chips yet."
	echo " IGD  - This option switches to the Integrated Graphics Card, sets it as the"
	echo "        default, but does not connect it with the outputs (video). Graphics "
	echo "        calls are not redirected to this GPU without a restart of the X "
	echo "        Server, which usually involves logging out and back in again."
	echo " DIS  - This option switches to the Discrete Graphics Card, sets it as the"
	echo "        default, but does not connect it with the outputs (video). This "
	echo "        functions exactly as IGD, where graphics calls will not be made to "
	echo "        this GPU without a restart of the X server."
	echo " OFF  - This option turns off the currently non-default GPU, but does not"
	echo "        switch chips yet. Please note, after switching to either IGD or DIS,"
	echo "        turning off the inactive GPU will result in a blank screen, as the "
	echo "        \"inactive\" GPU will be the one still connected to outputs."
	echo " DIGD - This option queues a switch to the Integrated Graphics Card"
	echo "        automatically upon restart of the X Server, but it along does not"
	echo "        turn off the inactive GPU afterwards, which may consume more power"
	echo "        with both GPUs running."
	echo " DDIS - This option behaves exactly like DIGD, except for switching to the"
	echo "        Discrete Graphics Card instead. Does not take effect without a"
	echo "        restart of the X Server."
	echo " Examples:"
	echo " > $0 ON IGD"
	echo "      Turns on the inactive GPU (in this case, the IGC) and switches to it."
	echo " > $0 DDIS"
	echo "      Queues an automatic switch to the DGC upon restart of the X Server."
	echo " > $0 OFF"
	echo "      In this case, if the user switched successfully to the new card, he or"
	echo "      she might wish to turn off the inactive card to avoid unnecessary"
	echo "      power consumption."
	echo " > $0 ON DIS OFF"
	echo "      WARNING: This is a BAD example. Doing this will result in a blank"
	echo "      display. Be sure to turn off the GPU that is no longer the default"
	echo "      AFTER it is disconnected with the video outputs (once a restart has "
	echo "      occurred)."
	echo "============================== Miscellaneous ==============================="
	echo " --help       - Display this text."
	echo " --status     - List all GPUs on system and their power states."
	echo " --switchloc  - Display the location of VGASwitcheroo."
	if [ $BASH_SOURCE == "/usr/bin/vgaswitch" ]; then
		echo " --uninstall  - Remove this program from /usr/bin/."
	else
		echo " --install    - Install this script to /usr/bin/vgaswitch for easy command-"
		echo "                line access."
		echo " --uninstall  - Remove and undo any changes made by --install."
	fi
}

if [ -e $switchloc ]; then
	if [[ $# == 0 ]]; then display_help; exit 0; fi
	for p in $*; do
		ecval=false
		case $p in
			"--help") 
				display_help
				ecval=true
			;;
			"--switchloc")
				echo $switchloc
				ecval=true
			;;
			"--status")
				cat $switchloc
				ecval=true
			;;
			"--install")
				if [ $BASH_SOURCE == "/usr/bin/vgaswitch" ]; then
					echo "Error: Cannot install when already installed."
					exit 1
				fi
				cp -f $BASH_SOURCE "/usr/bin/vgaswitch"
				chmod a+x "/usr/bin/vgaswitch"
				echo "Installed to /usr/bin/vgaswitch."
				ecval=true
			;;
			"--uninstall")
				rm -f "/usr/bin/vgaswitch"
				echo "Removed /usr/bin/vgaswitch."
				ecval=true
			;;
		esac
		if [ $ecval == false ]; then
			echo $p > $switchloc
		fi
	done
else 
	echo "Apparently, the VGASwitcheroo capability is nonexistent due to either an unsupported card or otherwise missing functionality."
	exit 0
fi
