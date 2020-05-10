#pragma once
#include  <cmath>

//1009. Complement of Base 10 Integer
//0 <= N < 10^9
int bitwiseComplement(int N) { // ex: N=5, ie 000000000101
	if (0 < N && N < INT_MAX) { // hedge the overflow of the integer
		size_t bits = std::ceil(std::log2(N));  //integer number bits, ex: bits=3, ie log2(5)=2,32 -> ceil(2,32)=3
		size_t inv = ~N;  //inverse all the bits, ex: 111111111010
		size_t removeBits = pow(2, bits) - 1;   //remove the exceeding bits, ex: 2^3-1=7, ie 000000000111
		return inv & removeBits; //And bitwise operator to keep the bits needed, 
                             //ie 111111111010 AND
                             //   000000000111
                             //   ____________
                             //   000000000010
	}
	return 1;
}
