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
		# populate src
		if [ ! -e src/com ]; then mkdir src/com; fi
		if [ ! -e src/manifest.txt ]; then touch src/manifest.txt; fi
		;;
	"--help" | "-h") # default
		display_help
		;;
	*)
		printf "Unknown option. Pass --help or -h for more information.\n"
		exit 1
		;;
	esac
done

if [ $# -eq 0 ]; then display_help; fi
