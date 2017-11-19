#!/bin/bash
# build_latest.sh
# Use this script to build a custom package.

ARCH=x86_64
curdir=$(pwd)
newdir=
pkg=$(basename $1 2>/dev/null)
clone_new_pkg=

if [ ! -e /bin/asp ]; then
    printf "Please install asp\n"
    exit 1
fi

if [ ! -e /bin/git ]; then
    printf "Please install git\n"
    exit 1
fi

if [ -z $1 ]; then
    printf "Usage: $0 pkg\n"
    exit 1
fi

if [ ! -d $pkg ]; then
    printf "No package '$pkg' in directory.\n"
    read -p "Would you like to clone it? [y/n]: " clone_new_pkg
    if [[ $clone_new_pkg == y ]]; then
        asp checkout $pkg
    fi
    if [ ! -d $pkg ]; then
        exit 1
    fi
fi

cd $pkg
asp update
git reset --hard
git pull

printf "Now edit the PKGBUILD again...\n"
pkgbuild_array=()
while IFS=  read -r -d $'\0'; do
    pkgbuild_array+=("$REPLY")
done < <(find . -path \*x86_64\*PKGBUILD -print0)

$EDITOR ${pkgbuild_array[0]}
newdir=$(dirname ${pkgbuild_array[0]})
cd $newdir && makepkg -Csri --asdeps --noconfirm && exit 0

printf "Failed to build/install package $pkg. Fix the errors and try again.\n"
exit 1
