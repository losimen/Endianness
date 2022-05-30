#include <iostream>
#include "Endianness.h"

int main() {
    std::string vector_1 = "ff00000000000000000000000000000000000000000000000000000000000000";
    std::string vector_2 = "aaaa000000000000000000000000000000000000000000000000000000000000";
    std::string vector_3 = "FFFFFFFF";
    std::string vector_4 = "F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    // **********************************************
    // ************** hex 2 endianness **************
    // **********************************************
    std::cout  << std::endl << "HEX 2 ENDIANNESS" << std::endl;

    InfInt vec_little_1 = Hex2LittleEndian(vector_1);
    InfInt vec_big_1 = Hex2BigEndian(vector_1);

    InfInt vec_little_2 = Hex2LittleEndian(vector_2);
    InfInt vec_big_2 = Hex2BigEndian(vector_2);

    InfInt vec_little_3 = Hex2LittleEndian(vector_3);
    InfInt vec_big_3 = Hex2BigEndian(vector_3);

    InfInt vec_little_4 = Hex2LittleEndian(vector_4);
    InfInt vec_big_4 = Hex2BigEndian(vector_4);

    std::cout << "1- Little-endian: " << vec_little_1 << std::endl;
    std::cout << "1- Big-endian: " << vec_big_1 << std::endl;
    std::cout << std::endl;

    std::cout << "2- Little-endian: " << vec_little_2 << std::endl;
    std::cout << "2- Big-endian: " << vec_big_2 << std::endl;
    std::cout << std::endl;

    std::cout << "3- Little-endian: " << vec_little_3 << std::endl;
    std::cout << "3- Big-endian: " << vec_big_3 << std::endl;
    std::cout << std::endl;

    std::cout << "4- Little-endian: " << vec_little_4 << std::endl;
    std::cout << "4- Big-endian: " << vec_big_4 << std::endl;
    std::cout << std::endl;

    // **********************************************
    // ************** endianness 2 hex   **************
    // **********************************************
    std::cout  << std::endl << "ENDIANNESS 2 HEX" << std::endl;

    std::cout << "Little-endian: " << LittleEndian2Hex(vec_little_1, 32) << std::endl;
    std::cout << "Big-endian: " << BigEndian2Hex(vec_big_1) << std::endl;
    std::cout << std::endl;

    std::cout << "Little-endian: " << LittleEndian2Hex(vec_little_2, 32) << std::endl;
    std::cout << "Big-endian: " << BigEndian2Hex(vec_big_2) << std::endl;
    std::cout << std::endl;

    std::cout << "Little-endian: " << LittleEndian2Hex(vec_little_3, 4) << std::endl;
    std::cout << "Big-endian: " << BigEndian2Hex(vec_big_3) << std::endl;
    std::cout << std::endl;

    std::cout << "Little-endian: " << LittleEndian2Hex(vec_little_4, 512) << std::endl;
    std::cout << "Big-endian: " << BigEndian2Hex(vec_big_4) << std::endl;

    return 0;
}
