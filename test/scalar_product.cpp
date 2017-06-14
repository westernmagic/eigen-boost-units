#include "test.h"

int main(int /*argc*/, char** /*argv*/) {
	double input1 = 2.0;
	Length input2 = 2 * meter;
	Vector3L input3 = {1 * meter, 1 * meter, 1 * meter};
	Vector3L result1 = {2 * meter, 2 * meter, 2 * meter};
	Vector3A result2 = {2 * meter * meter, 2 * meter * meter, 2 * meter * meter};

	assert(input1 * input3 == result1);
	assert(input3 * input1 == result1);
	assert(input1 * input3 == result2);
	assert(input3 * input1 == result2);
}

