#include "test.h"

int main(int /*argc*/, char** /*argv*/) {
	Length input1 = 2 * meter;
	Vector3L input2 = {1 * meter, 1 * meter, 1 * meter};
	Vector3A result = {2 * meter * meter, 2 * meter * meter, 2 * meter * meter};

	assert(input1 * input2 == result);
	assert(input2 * input1 == result);
}

