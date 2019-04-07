#include "filedesc.hpp"
#include "filelist.hpp"
#include <string>

int main() {
	FileDesc f(std::string("./driver.cpp"));
	// printf("%s\n", f.to_string().c_str());
	FileDescList list;
	puts("Test for FileDesc(MimeType, size, username): ");
	printf("%s %ld %s\n", f.getMimeType().c_str(), f.getSize(), f.getUser().c_str());
	list.insertNode(FileDesc("./driver.cpp"));
	list.insertNode(FileDesc("./Makefile"));
	list.insertNode(FileDesc("./README.md"));
	list.insertNode(FileDesc("./driver.cpp"));
	puts("Unsorted");
	list.printList();
	list.sort();
	puts("Sorted");
	list.printList();
}
