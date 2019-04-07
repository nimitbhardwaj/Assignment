There are 2 main files which forms this whole library, filedesc.cpp which implements FileDesc class, which holds whole data about the file whose path is given into the constructor, and FileDescList which is actually a container of FileDesc objects.

FileDesc class implements methods to get the data fetchec for each file, the constructor fetches the data actually from the file and saves in internal structures. The some of getter methods are provided in the class. There are also the operators of =, ==, <= and < are overloaded which were required for the sorting the FileDescList. It also contains to_string method which converts the Class object to the string object.

FileDescList is the container as described above, it holds the linked list with a single next pointer of the FileDesc objects, the necessary methods for this class are printing, sorting and inserting node, the node is interested simply in the linear fashion, as done push_back operation, the printing of linked list is just converting each node data value to the string and printing them one by one. At last the important operation for this assignment was the sorting operation, sorting is done by using standard merge sort procedure, as would done for linked lists to obtain O(nlogn) time complexity.

The make file creates the shared and static libraries, the make rules illustrate the working.
make clean: it clears the ./bin folder
make: compiles the given source files to the shared and static libraries, libfiledescription.a is static library and libfiledescription.so is shared object library

make staticCompile: creates the driverStatic output program file, illustrating the static linking, which is a test driver file which can be executed by ./driverStatic

make sharedCompile: creates the driverShared output program file, illustrating the dynamic linking, which is a test driver file can be executed by ./driverShared
For shared compile, `export LD_LIBRARY_PATH=./bin/` is necessary as we are dealing with shared libraries here

The sample output for the program is also added in the images

Note make clean first if any error encountered
