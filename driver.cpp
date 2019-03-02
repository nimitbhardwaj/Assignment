#include "filedesc.hpp"
#include "filelist.hpp"
#include <string>

int main() {
	FileDesc f(std::string("./driver.cpp"));
	// printf("%s\n", f.to_string().c_str());
	FileDescList list;
	puts("Test for FileDesc: ");
	printf("%s %ld %s\n", f.getMimeType().c_str(), f.getSize(), f.getUser().c_str());
	list.insertNode(FileDesc("./driver.cpp"));
	list.insertNode(FileDesc("./a.out"));
	list.insertNode(FileDesc("./driver.cpp"));
	list.insertNode(FileDesc("./driver.cpp"));
	list.insertNode(FileDesc("./a.out"));
	puts("Unsorted");
	list.printList();
	list.sort();
	puts("Sorted");
	list.printList();
}
