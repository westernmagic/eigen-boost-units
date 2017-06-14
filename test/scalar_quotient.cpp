#include "test.h"

int main(int /*argc*/, char** /*argv*/) {
	Vector3A input1 = {2 * meter * meter, 2 * meter * meter, 2 * meter * meter};
	Length input2 = 2 * meter;
	Vector3L result = {1 * meter, 1 * meter, 1 * meter};

	assert(input1 / input2 == result);
}

