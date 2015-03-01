# HapTechSeniorDesign

#### Install Json-cpp

Json-cpp is part of the posemachines repository. Browse into the extern/jsoncpp/ directory. After installing the scons package, run the following to build jsoncpp.

`scons platform=linux-gcc check`

For 64-bit linux.

#### Install gTest

gtest is also part of the repository. Browse into the extern/gtest-1.7.0/make directory and type make. 

make gtest.a

(for 64-bit linux)

#### Install OpenGL
$ sudo apt-get install freeglut3-dev

#### Install Aquilia
go to /extern/aquila-src and make aquila 
$ cmake ../aquila-src -DCMAKE_INSTALL_PREFIX="../aquila"

then run 
$ make
$ make install

#### Link libraries.
Generate symbolic links to the libraries using `sudo ln -s` for the libraries generated by VLFeat and JSON-CPP to a standard location such as in '/usr/local/lib'.

Use the following command to link JSON-CPP.

sudo ln -s <AbsolutePathToHapTechSeniorDesign>/extern/json-src-0.5.0/libs/linux-gcc-4.6/libjson_linux-gcc-4.6_libmt.so /usr/local/lib/

Note, you may need to also link to /usr/lib/ depending on your setup
