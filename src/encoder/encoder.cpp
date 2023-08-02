#include <cstddef>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

#ifndef __DEBUG__
int main(int argc, char** argv) {
	for(unsigned int i = 1; i < argc; i++) {
		std::ifstream in(argv[i], std::ios::binary);
		if(!in) { std::cerr << "Shader file: " << argv[i] << " either doesn't exist or has some problem being opened!" << std::endl; exit(1); }
		in.seekg(0, std::ios::end);
		unsigned int length = in.tellg();
		std::byte* result = new std::byte[length];
		in.seekg(0, std::ios::beg);
		in.read((char*)result, length);
		in.close();
		std::cout << result << std::endl;
	}
	return 0;
}
#endif
