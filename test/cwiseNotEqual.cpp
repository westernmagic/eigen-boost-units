#include "test.h"

int main(int /*argc*/, char** /*argv*/) {
	Vector3L input1 = {1 * meter, 1 * meter, 1 * meter};
	Vector3L input2 = {2 * meter, 1 * meter, 1 * meter};
	Vector3b result = {true,      false,     false};

	assert(input1.cwiseNotEqual(input2) == result);
}

