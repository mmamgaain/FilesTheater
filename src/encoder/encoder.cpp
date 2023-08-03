#include "encoder.hpp"
#include <cstdint>
#include <fstream>
#include <iostream>

void loadFile(const char* filename) {
	std::ifstream in(filename, std::ios::binary);
	if(!in) { std::cerr << "File: " << filename << " either doesn't exist or has some problem being opened!" << std::endl; exit(1); }
	in.seekg(0, std::ios::end);
	unsigned int length = in.tellg(), *result = new unsigned int[length];
	in.seekg(0, std::ios::beg);
	in.read((char*)result, length);
	in.close();
	for(unsigned int i = 0; i < length; ++i) std::cout << result[i] << std::endl;
}

#ifndef __DEBUG__
int main(int argc, char** argv) {
	for(unsigned int i = 1; i < argc; i++) {
		loadFile(argv[i]);
	}
	return 0;
}
#endif
