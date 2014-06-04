#!/bin/sh

if [ $UID -eq 0 ]; then
	echo "It is not recommended to run this as the root user."
	exit 1
fi

if [ -e /bin/dnf ]; then
	PROG=/bin/dnf
else
	PROG=/bin/yum
fi

echo "Installing essential build tools..."

DEPS="wget rpmdevtools rpm-build yum-utils"

$PROG -y install $DEPS

rpmdev-setuptree

cd $(rpm --eval %_sourcedir)

wget "http://leamas.fedorapeople.org/spotify/latest/spotify-client.spec"

spectool -g "spotify-client.spec" && sudo yum-builddep "spotify-client.spec"

env QA_RPATHS=$((0x10|0x08)) rpmbuild -bb "spotify-client.spec"

printf "Install the Spotify package? (y/n): "
read toInstall

if [ $toInstall == "y" ]; then
	$PROG -y install ~/rpmbuild/RPMS/`uname -m`/spotify-client*.rpm
fi

