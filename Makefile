default:
	#compile files
	g++ -fPIC -I./include/ ./src/filedesc.cpp -c -o ./bin/filedesc.o
	g++ -fPIC -I./include/ ./src/filelist.cpp -c -o ./bin/filelist.o
	# static library
	ar rcs ./bin/libfiledescription.a ./bin/filedesc.o ./bin/filelist.o
	# dynamic library
	g++  -shared ./bin/* -o ./bin/libfiledescription.so

clean:
	rm ./bin/*

staticCompile:
	g++ driver.cpp -I./include ./bin/libfiledescription.a -o driverStatic

sharedCompile:
	g++ driver.cpp -I./include -L./bin -lfiledescription  -o driverShared
	export LD_LIBRARY_PATH=./bin
