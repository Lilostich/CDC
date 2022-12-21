#include <openssl/sha.h>
#include <iostream>
#include <algorithm>

bool invalidChar(char c) {
    return !(c>=21 && c <128);
}

void stripUnicode(std::string & str) {
    str.erase(remove_if(str.begin(),str.end(), invalidChar), str.end());
}

int main(int argc, char* argv[])
{
    if (argc < 2)
        exit(1);

    std::string str = argv[1];
    unsigned char hash[100];

    SHA512(reinterpret_cast<const unsigned char*>(str.c_str()), sizeof(str.c_str()) - 1, hash);

    std::string HASH(reinterpret_cast<const char*>(hash));
    stripUnicode(HASH);

    // do some stuff with the hash
    std::cout << "HASH: " << HASH << std::endl;

    return 0;
}
