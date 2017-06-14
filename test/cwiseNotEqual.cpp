#include "test.h"

int main(int /*argc*/, char** /*argv*/) {
	Vector3L input1 = {1 * meter, 1 * meter, 1 * meter};
	Vector3L input2 = {2 * meter, 1 * meter, 1 * meter};
	Vector3L result = {1 * meter, 0 * meter, 0 * meter};

	assert(input1.cwiseNotEqual(input2) == result);
}

