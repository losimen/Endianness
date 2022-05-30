#include <iostream>
#include "InfInt.h"

const int BASE_16 = 16;


InfInt Pow(const InfInt &base, const InfInt &exponent) {
    if (exponent == 0)
        return 1;
    else if (exponent < 0)
        return InfInt(1) / Pow(base, -exponent);
    else if (exponent % 2 == 0)
    {
        InfInt half_pow = Pow(base, (exponent / 2));
        return half_pow * half_pow;
    }
    else
        return base * Pow(base, exponent - 1);
}


InfInt HexToDec(char hexdec) {
    std::string temp;

    switch (hexdec) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'A':
        case 'a':
            return 10;
        case 'B':
        case 'b':
            return 11;
        case 'C':
        case 'c':
            return 12;
        case 'D':
        case 'd':
            return 13;
        case 'E':
        case 'e':
            return 14;
        case 'F':
        case 'f':
            return 15;
        default:
            throw std::invalid_argument("Invalid HEX string");
    }

}


InfInt Hex2BigEndian(const std::string &hexNumber) {
    InfInt result = 0;

    unsigned long powTo1;
    unsigned long powTo2;

    for (auto it = hexNumber.begin(); it < hexNumber.end()-1; it += 2) {
        powTo1 = hexNumber.length() - std::distance(hexNumber.begin(), it) - 1;
        powTo2 = hexNumber.length() - std::distance(hexNumber.begin(), (it+1)) - 1;

        result += (HexToDec(*(it+1)) * Pow(BASE_16, int(powTo2)));
        result += (HexToDec(*(it)) * Pow(BASE_16, int(powTo1)));
    }

    return result;
}


InfInt Hex2LittleEndian(const std::string &hexNumber) {
    InfInt result = 0;

    unsigned long powTo1;
    unsigned long powTo2;

    for (auto it = hexNumber.end()-1; it >= hexNumber.begin()+1; it -= 2) {
        powTo1 = std::distance(hexNumber.begin(), it);
        powTo2 = std::distance(hexNumber.begin(), (it-1));

        result += (HexToDec(*(it)) * Pow(BASE_16, int(powTo2)));
        result += (HexToDec(*(it-1)) * Pow(BASE_16, int(powTo1)));
    }

    return result;
}


std::string BigEndian2Hex(InfInt myNum) {
    std::string hexStr;
    std::string resultHex;

    while (myNum != 0)
    {
        std::stringstream stream;

        stream << std::hex << myNum%16;
        myNum /= 16;

        hexStr += stream.str();
    }

    std::transform(hexStr.begin(), hexStr.end(), hexStr.begin(), ::toupper);
    std::reverse(hexStr.begin(), hexStr.end());

    return hexStr;
}


std::string LittleEndian2Hex(InfInt myNum, int numberOfBytes) {
    std::string hexStr;

    while (myNum != 0)
    {
        std::stringstream stream;

        stream << std::hex << myNum%16;
        myNum /= 16;

        hexStr += stream.str();
    }

    std::transform(hexStr.begin(), hexStr.end(), hexStr.begin(), ::toupper);
    std::reverse(hexStr.begin(), hexStr.end());

    hexStr += std::string((numberOfBytes*2 - hexStr.length()), '0');

    return hexStr;
}


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
