

#pragma once

// A variable that is marked as extern const can be intialised at compile time
extern const int non_constexpr;
// But a variable marked as constexpr cannot
// extern constexpr int constexpr_; // fails to compile

// A extern constexpr function can be forward declared
#if true
	extern constexpr int bar();
#else
	// But MUST have contexpr correctness
	extern int bar();
#endif
// But cannot be executed at compile time based solely on the forward declare

int foo() {
	// bar can be used, just not at compile time
	return bar() + non_constexpr;
}

// static assert fails to compile because bar cannot be executed at compile time, despite being constexpr
#define CHECK constexpr bool check() { static_assert(bar() == 2); return true; }

// CHECK check(); // fails to compile

// check CAN be called if bar's source is in the same translation unit
