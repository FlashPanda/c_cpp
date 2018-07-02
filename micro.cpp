#define BX_MACRO_BLOCK_BEGIN for(;;) {
#define BX_MACRO_BLOCK_END break; }
#define BX_NOOP(...) BX_MACRO_BLOCK_BEGIN BX_MACRO_BLOCK_END
#define BX_CHECK(_condition, ...) BX_NOOP()

#include <iostream>
#include <stdint.h>

int main () {
	int32_t result = 0;
	BX_CHECK (result == 0, "Faild to chdir to dir...", "test");

	return 0;
}
