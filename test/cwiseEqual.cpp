#include "test.h"

int main(int /*argc*/, char** /*argv*/) {
	Vector3L input1 = {1 * meter, 1 * meter, 1 * meter};
	Vector3L input2 = {2 * meter, 1 * meter, 1 * meter};
	Vector3b result = {false,     true,      true};

	assert(input1.cwiseEqual(input2) == result);
}

