#!/bin/sh
# install script for Gradle

if [ $UID -ne 0 ]; then
	echo "You must be root to run this."
	return 1
fi


g_dir=/usr/lib64/gradle
libdir=$g_dir/lib
bindir=$g_dir/bin
gradle_ex=$bindir/gradle # executable location

function make_dirs() {
	if [ ! -d $g_dir ]; then mkdir $g_dir; fi
	if [ ! -d $libdir ]; then mkdir $libdir; fi
	if [ ! -d $bindir ]; then mkdir $bindir; fi
}

function copy_all() {
	cp -r bin $g_dir
	cp -r lib $g_dir
}

function make_links() {
	ln -s $gradle_ex /usr/bin/gradle
}

make_dirs
copy_all
make_links
