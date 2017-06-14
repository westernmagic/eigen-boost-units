#include "test.h"

int main(int /*argc*/, char** /*argv*/) {
	Vector3L input1 = {1 * meter, 1 * meter, 1 * meter};
	Vector3L input2 = {1 * meter, 1 * meter, 1 * meter};
	Vector3A result = {1 * meter * meter, 1 * meter * meter, 1 * meter * meter};

	assert(input1.cwiseProduct(input2) == result);
}

