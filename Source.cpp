
#include "Header.hpp"

// definition from `extern const` forward declare in header 
#if _MSC_VER
    // must have constexpr correctness on msvc
    const int non_constexpr = 1;
#else
    // on gcc can be constexpr (with no warnings)
    constexpr int non_constexpr = 1;
#endif

constexpr int constexpr_ = 2; // See header

// bar source code is in this header file but is not yet defined so cannot be executed at compile time
// CHECK // fails to compile

constexpr int bar() {
	return 2;
}

// bar source code is now avalible so can be executed at compile time
CHECK

int main() {
	// bar is constexpr in this file
	static_assert(bar() == 2);
	// check works as expected
	static_assert(check());
	
	return foo(); // Must be 3
}
