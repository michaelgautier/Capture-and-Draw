BUILDING THE PROGRAM:

The program can be built on Linux using the inclued Makefile along with GnuMake. You would simply type make and press enter but the make file assumes certain dependencies placed in a particular directory structure. This README is designed to familiarize you with the dependency requirements in order to run the make file.

After you read this document all you will need to do is change the LIB_LOCAL_DIR variable in the Makefile. That variable identifies the root folder where you placed the dependencies. This will allow make to find the dependencies described here.

DEPENDENCIES:

The program depends on the following dependencies: JSONCpp and SFML. A compressed file in the dependencies folder contains a copy of the dependencies that was used build the program. This compressed file also will deflate to a directory structure understood by the Makefile that is listed alongside this README document. The following describes these dependencies.

JSONCpp is a set of C++ source code files maintained by Baptiste Lepilleur. You can find the code on GitHub. You will want to get the README.md file that describes how to create a merged code file you can include in your project. That procedure is in a section titled, Generating amalgamated source and header.

Simple and Fast Media Library in a project led by Laurent Gomila. The main set of C++ source code for SFML is available at www.sfml-dev.org at this time. The tutorial section of their website explains how to build the SFML code into binary form.

The make file mentioned in the beginning references the binary output of the JSONCpp and SFML code. Those binaries are expected to be in a particular directory. The directory hierarchy was created as a way consolidate dependencies from new source code. You will need the dependencies in the prescribed directory hierarchy.

The approach allows you to try out different dependency configurations without polluting the overall system configuration. It also helps with sustaining run time certainty during development. Alternatively, you can edit the Makefile to have the process refer to dependencies installed in a system-wide configuration. That can prove useful if you are settled on installing the dependencies from the distribution repository or running the default, formal install process available for the dependencies.

MAKE LIBRARY DIRECTORIES:

The fastest way to make the directory layout is to deflate the compressed file in the dependencies directory. It is recommended you deflate the file to a directory at least one level up from the program's src directory. If you decide to make the directory hierarchy yourself, please see the directory layout in the next section.

THIRD-PARTY LIBRARY AND INCLUDE DIRECTORY HIERARCHY:

The directory hierarchy is designed for building the program and not as a run time directory. This README file is associated with a dependencies folder that contains a compressed file named liblocal.tar.gz. That file expands to a minimally viable directory hierarchy with contents similar to the one below. 

The contents were built and tested with g++ version 4.8.2 and clang++ 3.4 on Ubuntu 14.04 LTS. If you decide to use newer versions of these tools, this document should still be relevant. Any dependencies you build, if you decide to use the included Makefile, it is advised you use this directory hierarchy at a point outside the source tree.

Top directory					<- Could be a home directory or other location.
	liblocal

		JSONCpp/json:			<- Header files for JSONCpp.
			json-forwards.h
			json.h

		JSONCpp/mk_build:		<- A Makefile for JSONCpp code defined for the program.
			Makefile

		JSONCpp/src:			<- Amalgamated/merged JSONCpp code.
			jsoncpp.cpp

		libjson_gcc:
			jsoncpp.o		<- Object file of JSONCpp code to be included in the program.

		libsfml_gcc:
			libsfml-graphics.so  libsfml-system.so  libsfml-window.so ... etc

		SFML:
			Audio
			Graphics
			Network
			System
			Window
			Audio.hpp  Graphics.hpp  Network.hpp  System.hpp  Window.hpp ... etc

	Capture and Draw Source Code		<- The program.
		mk_build			<- You are here.
		mk_docs
		src				<- Source tree.
	... etc
	
MAKEFILE:

The default Makefile was created with a default target. It will initiate the build of the program. The primary outputs are as follows:

	c_and_d				<- This is the name of the program.
	lib				<- Copies of the SFML binary files.
		libsfml-graphics.so
		libsfml-system.so
		libsfml-window.so

You can run the Makefile in a few ways:

	make clean			<- Removes any build outputs from a previous run of make in this directory.
	make CXX=clang++		<- Example of switching to another compiler. The program is then built with that compiler.
	make				<- Builds the program using the code in the src directory and dependent libraries.

RUNNING THE PROGRAM:

The program will run from any working directory in which the lib folder with the SFML binaries exist relative to the program's working directory. See the section, MAKEFILE, for details on the output file names.
