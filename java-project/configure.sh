# configures an example Java project folder

function display_help() {
	printf "This is a general configure script. See options below:
--help, -h
\tDisplays this output.
--initial, -i
\tSets up the initial directory hierarchy.\n"
}

for arg in "$@"; do
	case $arg in
	"--initial" | "-i") # set up initial hierarchy
		ds=(src bin build)
		for fld in ${ds[@]}; do
			if [ ! -e $fld ]; then mkdir $fld; fi
		done
		;;
	"--help" | "-h" | "*") # default
		display_help
		;;
	esac
done

if [ $# -eq 0 ]; then display_help; fi
