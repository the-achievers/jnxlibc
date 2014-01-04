#!/bin/bash +x

./configure
make setup
pushd test
./run_tests
result=$?
if [ ! $result -eq 0 ]; then
	echo "Error during testing: Aborting installation"
	popd
	make teardown
	exit 1
fi
popd
make teardown
if [ $1 = "RELEASE" ]; then
	echo "Building release library"
	make release
else
	echo "Building debug library"
	make
fi
sudo make install
echo "Installed succesfully"

which doxygen
HAS_DOXYGEN=$?

which doxy2man
HAS_DOXY2MAN=$?

MANPATH=/usr/share/man/man3

if [[ $HAS_DOXYGEN -eq 0 && $HAS_DOXY2MAN -eq 0 ]]; then
	rm -rf man
	mkdir -p docs/man/man3
	doxygen
	for f in docs/xml/*_8h.xml; do
		doxy2man -o docs/man/man3 $f
	done
	rm -rf docs/xml
	sudo rm $MANPATH/jnx*
	sudo cp docs/man/man3/* $MANPATH/
	echo "Created man pages for jnxlibc header files, functions, and structures."
else
	if [ -d docs/man/man3 ]; then
		sudo rm $MANPATH/jnx*
		sudo cp docs/man/man3/* $MANPATH/
		echo "Copied man pages from github repo. If you want to regenerate them you need to install doxygen and doxy2man."
	else
		echo "No man pages found in the repository. If you want to generate them you need to install doxygen and doxy2man, and run this script again."
	fi
fi
