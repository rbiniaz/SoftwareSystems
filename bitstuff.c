#include <stdio.h>
#include <inttypes.h>


int8_t low_bits(int8_t i, int n){
	return i & (-1 >> (8-n));

}


int main(){
	printf("%i\n", (b11111111 >> (4)));	
	printf("%i\n", low_bits(127, 1));
	printf("%i\n", low_bits(127, 2));
	printf("%i\n", low_bits(127, 3));
	printf("%i\n", low_bits(127, 4));
	printf("%i\n", low_bits(127, 5));
	printf("%i\n", low_bits(127, 6));
	printf("%i\n", low_bits(127, 7));
	printf("%i\n", low_bits(127, 8));
	return 0;
}