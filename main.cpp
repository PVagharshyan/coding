#include "decoder.h"

#include <iostream>

int main() {
    //I promise to study well
    std::string str = "I promise to study well";//23
    //u1:r3:l1
    std::string code = "u1:r3:l1";
    decoder c(str, code);
    std::string coding_result = c.coding();
    std::cout << coding_result << std::endl;
    //d1:l3:r1
    std::string decode = "u1:r3:l1";
    decoder d(coding_result, decode);
    std::string decoding_result = d.decoding();
    std::cout << decoding_result << std::endl;
    return 0;
}
