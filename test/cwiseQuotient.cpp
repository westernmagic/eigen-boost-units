#include "test.h"

int main(int /*argc*/, char** /*argv*/) {
	Vector3A input1 = {1 * meter * meter, 1 * meter * meter, 1 * meter * meter};
	Vector3L input2 = {1 * meter, 1 * meter, 1 * meter};
	Vector3L result = {1 * meter, 1 * meter, 1 * meter};

	assert(input1.cwiseQuotient(input2) == result);
}

