#ifndef FILEDESC_HPP_
#define FILEDESC_HPP_

#include <string>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

class FileDesc {
  private:
    std::string path, mimetype, userName;
    struct stat fileAttrib;
    off_t size;
    timespec lastEdit;
  public:
    FileDesc();
    FileDesc(const std::string &S);
    std::string getMimeType() const;
    std::string getUser() const;
    std::string to_string() const;
    off_t getSize() const;

    bool operator<(const FileDesc &f) const;
    bool operator==(const FileDesc &f) const;
    bool operator<=(const FileDesc &f) const;
    FileDesc &operator=(const FileDesc &f);
};
#endif