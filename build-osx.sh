#!/bin/sh

[ -f ./configure ] || autoreconf -f -i

installPrefix="/game"

if [ ! -f src/Makefile ]
then
        pathToCompiler="/Developer/GCC/6.2/PowerPC/32bit" # ="/usr"

        LDFLAGS="-L/opt/xerces-c-3.2.0/lib -L/opt/ogg-vorbis/lib -L/opt/libpng-1.6.32/lib -L/opt/zlib-1.2.8/lib -L${pathToCompiler}/lib" \
        CPPFLAGS="-I/opt/xerces-c-3.2.0/include" \
        CC="${pathToCompiler}/bin/gcc" CXX="${pathToCompiler}/bin/g++ -std=c++03" \
        ./configure --prefix=${installPrefix}
fi

installPath=`pwd`/headoverheelsroot
rm -rf "${installPath}"

make CFLAGS=-Werror CXXFLAGS=-Werror && make install DESTDIR="${installPath}"

headoverheelsbin="${installPath}${installPrefix}"/bin/headoverheels
if [ -f "${headoverheelsbin}" ]
then
        install_name_tool -change liballeg.4.4.dylib /opt/allegro-4.4.2/lib/liballeg.4.4.dylib "${headoverheelsbin}"
        otool -L "${headoverheelsbin}"

        games="/Applications/Games"
        rm -r -f "${games}"/Head\ over\ Heels.app
        cp -r extras/Head\ over\ Heels.app "${games}"/
        mkdir -p "${games}"/Head\ over\ Heels.app/Contents/MacOS/
        mkdir -p "${games}"/Head\ over\ Heels.app/Contents/Resources/
        cp headoverheelsroot/game/bin/headoverheels "${games}"/Head\ over\ Heels.app/Contents/MacOS/
        cp -r headoverheelsroot/game/share/headoverheels/* "${games}"/Head\ over\ Heels.app/Contents/Resources/
fi
