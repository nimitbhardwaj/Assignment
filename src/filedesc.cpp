#include <filedesc.hpp>
#include <cstring>
#include <stdexcept>
#include <cstdio>
#include <pwd.h>

FileDesc::FileDesc() {
    path = "";
    mimetype = "";
    userName = "";
    memset(&fileAttrib, 1, sizeof(struct stat));
}

FileDesc::FileDesc(const std::string &S) {
    path = S;
    if (stat(path.c_str(), &fileAttrib) < 0)
        throw std::runtime_error("Some Error occured");
    char A[1000];
    sprintf(A, "/usr/bin/file -i %s", S.c_str());
    FILE *fp;
    fp = popen(A, "r");
    if (fp == NULL)
        throw std::runtime_error("Some Error occured for command");
    fgets(A, sizeof(A)-2, fp);
    mimetype = "";
    pclose(fp);
    int l = strlen(A);
    bool foundColon = false;
    for (int i = 0; i < l; i++) {
        if (A[i] == ':') foundColon = true;
        else if (A[i] == ';') break;
        else if (A[i] == ' ') continue;
        else if (foundColon) mimetype += A[i];
    }
    userName = getpwuid(fileAttrib.st_uid)->pw_name;
    size = fileAttrib.st_size;
    lastEdit = fileAttrib.st_atim;
}

std::string FileDesc::getUser() const { return userName; }
std::string FileDesc::getMimeType() const { return mimetype; }
off_t FileDesc::getSize() const { return size; }

bool FileDesc::operator<(const FileDesc &f) const{
    if (size < f.size) {
        return true;
    } else if (size == f.size){
        if (userName < f.userName) {
            return true;
        } else if (userName == f.userName) {
            if (lastEdit.tv_sec < f.lastEdit.tv_sec) {
                return true;
            } else if (lastEdit.tv_sec == f.lastEdit.tv_sec) {
                if (lastEdit.tv_nsec < f.lastEdit.tv_nsec) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
    return false;
}

bool FileDesc::operator==(const FileDesc &f) const {
    return size == f.size && userName == f.userName &&\
    lastEdit.tv_sec == f.lastEdit.tv_sec && lastEdit.tv_nsec == f.lastEdit.tv_nsec;
}

bool FileDesc::operator<=(const FileDesc &f) const {
    return this->operator==(f) || this->operator<(f);
}

FileDesc &FileDesc::operator=(const FileDesc &f) {
    path = f.path;
    mimetype = f.mimetype;
    userName = f.userName;
    fileAttrib = f.fileAttrib;
    size = f.size;
    lastEdit = f.lastEdit;
    return *this;
}


std::string FileDesc::to_string() const {
    char A[10000];
    sprintf(A, "{%d %s {%d %d}}", (int)size, userName.c_str(),\
        (int)lastEdit.tv_sec, (int)lastEdit.tv_nsec);
    return std::string(A);
}