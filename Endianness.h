//
// Created by Павло Коваль on 30.05.2022.
//

#ifndef ENDIANNESS_ENDIANNESS_H
#define ENDIANNESS_ENDIANNESS_H

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


#endif //ENDIANNESS_ENDIANNESS_H
