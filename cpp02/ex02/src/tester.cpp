#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include "Fixed.hpp"

#define TEST_SECTION(name) std::cout << "\n=== " << name << " ===\n"
#define TEST(desc) std::cout << "\n[TEST] " << desc << "\n"

void printFixed(const Fixed& f, const std::string& name = "")
{
	std::cout << std::fixed << std::setprecision(6);
	if (!name.empty())
		std::cout << name << ": ";
	std::cout << "float=" << f.toFloat()
			  << " int=" << f.toInt()
			  << " raw=" << f.getRawBits() << "\n";
}

void testMultiplication()
{
	TEST_SECTION("MULTIPLICATION TESTS");

	// Basic multiplication
	TEST("Basic: 2 * 3");
	{
		Fixed a(2);
		Fixed b(3);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 6.0\n";
	}

	TEST("Basic: 5 * 4");
	{
		Fixed a(5);
		Fixed b(4);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 20.0\n";
	}

	// Floating point multiplication
	TEST("Float: 2.5 * 3.0");
	{
		Fixed a(2.5f);
		Fixed b(3.0f);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 7.5\n";
	}

	TEST("Float: 1.5 * 2.5");
	{
		Fixed a(1.5f);
		Fixed b(2.5f);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 3.75\n";
	}

	TEST("Float: 0.5 * 0.5");
	{
		Fixed a(0.5f);
		Fixed b(0.5f);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.25\n";
	}

	TEST("Float: 0.25 * 0.25");
	{
		Fixed a(0.25f);
		Fixed b(0.25f);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.0625\n";
	}

	// Zero multiplication
	TEST("Zero: 0 * 5");
	{
		Fixed a(0);
		Fixed b(5);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.0\n";
	}

	TEST("Zero: 5 * 0");
	{
		Fixed a(5);
		Fixed b(0);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.0\n";
	}

	TEST("Zero: 0 * 0");
	{
		Fixed a(0);
		Fixed b(0);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.0\n";
	}

	TEST("Zero: 0.0 * 123.456");
	{
		Fixed a(0.0f);
		Fixed b(123.456f);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.0\n";
	}

	// One multiplication (identity)
	TEST("Identity: 1 * 1");
	{
		Fixed a(1);
		Fixed b(1);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 1.0\n";
	}

	TEST("Identity: 42 * 1");
	{
		Fixed a(42);
		Fixed b(1);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 42.0\n";
	}

	TEST("Identity: 1 * 42");
	{
		Fixed a(1);
		Fixed b(42);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 42.0\n";
	}

	TEST("Identity: 3.14159 * 1");
	{
		Fixed a(3.14159f);
		Fixed b(1);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~3.14159\n";
	}

	// Negative multiplication
	TEST("Negative: -2 * 3");
	{
		Fixed a(-2);
		Fixed b(3);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: -6.0\n";
	}

	TEST("Negative: 2 * -3");
	{
		Fixed a(2);
		Fixed b(-3);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: -6.0\n";
	}

	TEST("Negative: -2 * -3");
	{
		Fixed a(-2);
		Fixed b(-3);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 6.0\n";
	}

	TEST("Negative: -1.5 * 2.0");
	{
		Fixed a(-1.5f);
		Fixed b(2.0f);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: -3.0\n";
	}

	TEST("Negative: -0.5 * -0.5");
	{
		Fixed a(-0.5f);
		Fixed b(-0.5f);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.25\n";
	}

	TEST("Negative: -7 * -7");
	{
		Fixed a(-7);
		Fixed b(-7);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 49.0\n";
	}

	// Small numbers
	TEST("Small: 0.1 * 0.1");
	{
		Fixed a(0.1f);
		Fixed b(0.1f);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~0.01\n";
	}

	TEST("Small: 0.01 * 0.01");
	{
		Fixed a(0.01f);
		Fixed b(0.01f);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~0.0001\n";
	}

	TEST("Small: 0.001 * 0.001");
	{
		Fixed a(0.001f);
		Fixed b(0.001f);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~0.000001 (likely rounds to 0)\n";
	}

	TEST("Small: 0.00390625 * 2 (1 LSB * 2)");
	{
		Fixed a;
		a.setRawBits(1); // Smallest representable positive number
		Fixed b(2);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.0078125 (2 LSB)\n";
	}

	// Large numbers
	TEST("Large: 100 * 100");
	{
		Fixed a(100);
		Fixed b(100);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 10000.0\n";
	}

	TEST("Large: 1000 * 10");
	{
		Fixed a(1000);
		Fixed b(10);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 10000.0\n";
	}

	TEST("Large: 256 * 256");
	{
		Fixed a(256);
		Fixed b(256);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 65536.0\n";
	}

	TEST("Large: 500 * 500");
	{
		Fixed a(500);
		Fixed b(500);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 250000.0\n";
	}

	// Overflow tests (MERCILESS)
	TEST("Overflow: 10000 * 10000 (WILL OVERFLOW)");
	{
		Fixed a(10000);
		Fixed b(10000);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 100000000.0 (but will overflow with int32)\n";
	}

	TEST("Overflow: 50000 * 50000 (EXTREME OVERFLOW)");
	{
		Fixed a(50000);
		Fixed b(50000);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 2500000000.0 (MASSIVE OVERFLOW)\n";
	}

	TEST("Overflow: Large negative * Large negative");
	{
		Fixed a(-10000);
		Fixed b(-10000);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: Should be positive 100000000 (but overflows)\n";
	}

	// Edge case: Maximum representable value
	TEST("Max Value: Max int multiplication");
	{
		// Max value for Q24.8: 8388607.99609375 (0x7FFFFF00)
		Fixed a;
		a.setRawBits(0x7FFFFF00); // Near max positive
		Fixed b(2);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: Overflow\n";
	}

	TEST("Max Value: Max * 0.5 (should not overflow)");
	{
		Fixed a;
		a.setRawBits(0x7FFFFF00);
		Fixed b(0.5f);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: Half of max value\n";
	}

	TEST("Min Value: Min int multiplication");
	{
		Fixed a;
		a.setRawBits(0x80000000); // Most negative
		Fixed b(2);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: Overflow (wraps around)\n";
	}

	// Precision loss tests
	TEST("Precision: 1.234567 * 1.234567");
	{
		Fixed a(1.234567f);
		Fixed b(1.234567f);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~1.524155 (with precision loss)\n";
	}

	TEST("Precision: Very precise * Very precise");
	{
		Fixed a(3.14159265f);
		Fixed b(2.71828182f);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~8.539734 (with precision loss)\n";
	}

	// Chain multiplication
	TEST("Chain: 2 * 3 * 4");
	{
		Fixed a(2);
		Fixed b(3);
		Fixed c(4);
		Fixed result = (a * b) * c;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(c, "c");
		printFixed(result, "result");
		std::cout << "Expected: 24.0\n";
	}

	TEST("Chain: 1.5 * 2.0 * 3.0");
	{
		Fixed a(1.5f);
		Fixed b(2.0f);
		Fixed c(3.0f);
		Fixed result = (a * b) * c;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(c, "c");
		printFixed(result, "result");
		std::cout << "Expected: 9.0\n";
	}
}

void testDivision()
{
	TEST_SECTION("DIVISION TESTS");

	// Basic division
	TEST("Basic: 6 / 2");
	{
		Fixed a(6);
		Fixed b(2);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 3.0\n";
	}

	TEST("Basic: 10 / 5");
	{
		Fixed a(10);
		Fixed b(5);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 2.0\n";
	}

	TEST("Basic: 20 / 4");
	{
		Fixed a(20);
		Fixed b(4);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 5.0\n";
	}

	// Float division
	TEST("Float: 7.5 / 2.5");
	{
		Fixed a(7.5f);
		Fixed b(2.5f);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 3.0\n";
	}

	TEST("Float: 10.0 / 4.0");
	{
		Fixed a(10.0f);
		Fixed b(4.0f);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 2.5\n";
	}

	TEST("Float: 1.0 / 2.0");
	{
		Fixed a(1.0f);
		Fixed b(2.0f);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.5\n";
	}

	TEST("Float: 1.0 / 4.0");
	{
		Fixed a(1.0f);
		Fixed b(4.0f);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.25\n";
	}

	TEST("Float: 3.0 / 8.0");
	{
		Fixed a(3.0f);
		Fixed b(8.0f);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.375\n";
	}

	// Division by 1 (identity)
	TEST("Identity: 42 / 1");
	{
		Fixed a(42);
		Fixed b(1);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 42.0\n";
	}

	TEST("Identity: 3.14159 / 1");
	{
		Fixed a(3.14159f);
		Fixed b(1);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~3.14159\n";
	}

	TEST("Identity: -5 / 1");
	{
		Fixed a(-5);
		Fixed b(1);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: -5.0\n";
	}

	// Self-division
	TEST("Self: 5 / 5");
	{
		Fixed a(5);
		Fixed b(5);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 1.0\n";
	}

	TEST("Self: 123.456 / 123.456");
	{
		Fixed a(123.456f);
		Fixed b(123.456f);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~1.0 (may have small error)\n";
	}

	// Division by zero (THE KILLER)
	TEST("DIVISION BY ZERO: 5 / 0 (SHOULD CRASH OR HANDLE)");
	{
		Fixed a(5);
		Fixed b(0);
		try {
			Fixed result = a / b;
			printFixed(a, "a");
			printFixed(b, "b");
			printFixed(result, "result");
			std::cout << "Expected: Exception or undefined\n";
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << "\n";
		} catch (...) {
			std::cout << "Unknown exception caught\n";
		}
	}

	TEST("DIVISION BY ZERO: 0 / 0 (UNDEFINED)");
	{
		Fixed a(0);
		Fixed b(0);
		try {
			Fixed result = a / b;
			printFixed(a, "a");
			printFixed(b, "b");
			printFixed(result, "result");
			std::cout << "Expected: Exception or NaN-equivalent\n";
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << "\n";
		} catch (...) {
			std::cout << "Unknown exception caught\n";
		}
	}

	TEST("DIVISION BY ZERO: -10 / 0 (SHOULD CRASH OR HANDLE)");
	{
		Fixed a(-10);
		Fixed b(0);
		try {
			Fixed result = a / b;
			printFixed(a, "a");
			printFixed(b, "b");
			printFixed(result, "result");
			std::cout << "Expected: Exception or undefined\n";
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << "\n";
		} catch (...) {
			std::cout << "Unknown exception caught\n";
		}
	}

	// Division into zero
	TEST("Zero dividend: 0 / 5");
	{
		Fixed a(0);
		Fixed b(5);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.0\n";
	}

	TEST("Zero dividend: 0 / 123.456");
	{
		Fixed a(0);
		Fixed b(123.456f);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.0\n";
	}

	// Negative division
	TEST("Negative: -6 / 2");
	{
		Fixed a(-6);
		Fixed b(2);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: -3.0\n";
	}

	TEST("Negative: 6 / -2");
	{
		Fixed a(6);
		Fixed b(-2);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: -3.0\n";
	}

	TEST("Negative: -6 / -2");
	{
		Fixed a(-6);
		Fixed b(-2);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 3.0\n";
	}

	TEST("Negative: -10.5 / 3.0");
	{
		Fixed a(-10.5f);
		Fixed b(3.0f);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: -3.5\n";
	}

	TEST("Negative: -1.0 / -4.0");
	{
		Fixed a(-1.0f);
		Fixed b(-4.0f);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.25\n";
	}

	// Division that increases value
	TEST("Increase: 5 / 0.5");
	{
		Fixed a(5);
		Fixed b(0.5f);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 10.0\n";
	}

	TEST("Increase: 1 / 0.25");
	{
		Fixed a(1);
		Fixed b(0.25f);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 4.0\n";
	}

	TEST("Increase: 2 / 0.1");
	{
		Fixed a(2);
		Fixed b(0.1f);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~20.0\n";
	}

	// Small divisor (potential overflow in intermediate)
	TEST("Small divisor: 100 / 0.01 (TESTS OVERFLOW IN SHIFT)");
	{
		Fixed a(100);
		Fixed b(0.01f);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~10000.0 (may overflow in intermediate)\n";
	}

	TEST("Small divisor: 1000 / 0.001 (EXTREME TEST)");
	{
		Fixed a(1000);
		Fixed b(0.001f);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~1000000.0 (WILL LIKELY OVERFLOW)\n";
	}

	TEST("Small divisor: 50000 / 0.5 (OVERFLOW TEST)");
	{
		Fixed a(50000);
		Fixed b(0.5f);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 100000.0 (may overflow in shift)\n";
	}

	// Non-exact division (precision test)
	TEST("Precision: 1 / 3");
	{
		Fixed a(1);
		Fixed b(3);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~0.333333 (limited by Q24.8 precision)\n";
	}

	TEST("Precision: 2 / 3");
	{
		Fixed a(2);
		Fixed b(3);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~0.666666\n";
	}

	TEST("Precision: 10 / 3");
	{
		Fixed a(10);
		Fixed b(3);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~3.333333\n";
	}

	TEST("Precision: 22 / 7 (pi approximation)");
	{
		Fixed a(22);
		Fixed b(7);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~3.142857\n";
	}

	TEST("Precision: 355 / 113 (better pi approximation)");
	{
		Fixed a(355);
		Fixed b(113);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~3.141592\n";
	}

	// Large numbers
	TEST("Large: 10000 / 100");
	{
		Fixed a(10000);
		Fixed b(100);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 100.0\n";
	}

	TEST("Large: 1000000 / 1000 (MAY OVERFLOW IN SHIFT)");
	{
		Fixed a(1000000);
		Fixed b(1000);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 1000.0 (but may overflow in left shift)\n";
	}

	// Very small results
	TEST("Small result: 1 / 100");
	{
		Fixed a(1);
		Fixed b(100);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.01\n";
	}

	TEST("Small result: 1 / 1000");
	{
		Fixed a(1);
		Fixed b(1000);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.001\n";
	}

	TEST("Small result: 1 / 10000");
	{
		Fixed a(1);
		Fixed b(10000);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 0.0001 (may underflow to 0)\n";
	}

	TEST("Small result: LSB / 2");
	{
		Fixed a;
		a.setRawBits(1); // Smallest positive
		Fixed b(2);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: Underflow to 0\n";
	}

	// Extreme values
	TEST("Extreme: Max / 2");
	{
		Fixed a;
		a.setRawBits(0x7FFFFF00); // Near max positive
		Fixed b(2);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: Half of max\n";
	}

	TEST("Extreme: Max / Max (should be ~1)");
	{
		Fixed a, b;
		a.setRawBits(0x7FFFFF00);
		b.setRawBits(0x7FFFFF00);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: ~1.0\n";
	}

	TEST("Extreme: Min / -1 (OVERFLOW TEST)");
	{
		Fixed a;
		a.setRawBits(0x80000000); // Most negative
		Fixed b(-1);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: Overflow (can't represent +2147483648)\n";
	}

	TEST("Extreme: Min / 2");
	{
		Fixed a;
		a.setRawBits(0x80000000);
		Fixed b(2);
		Fixed result = a / b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: Quarter of most negative\n";
	}

	// Chain division
	TEST("Chain: 100 / 5 / 2");
	{
		Fixed a(100);
		Fixed b(5);
		Fixed c(2);
		Fixed result = (a / b) / c;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(c, "c");
		printFixed(result, "result");
		std::cout << "Expected: 10.0\n";
	}

	TEST("Chain: 1000 / 10 / 10");
	{
		Fixed a(1000);
		Fixed b(10);
		Fixed c(10);
		Fixed result = (a / b) / c;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(c, "c");
		printFixed(result, "result");
		std::cout << "Expected: 10.0\n";
	}
}

void testMixedOperations()
{
	TEST_SECTION("MIXED MULTIPLICATION AND DIVISION");

	TEST("Mixed: (2 * 3) / 4");
	{
		Fixed a(2);
		Fixed b(3);
		Fixed c(4);
		Fixed result = (a * b) / c;
		printFixed(result, "result");
		std::cout << "Expected: 1.5\n";
	}

	TEST("Mixed: (10 / 2) * 3");
	{
		Fixed a(10);
		Fixed b(2);
		Fixed c(3);
		Fixed result = (a / b) * c;
		printFixed(result, "result");
		std::cout << "Expected: 15.0\n";
	}

	TEST("Mixed: 5 * 5 / 5");
	{
		Fixed a(5);
		Fixed b(5);
		Fixed c(5);
		Fixed result = (a * b) / c;
		printFixed(result, "result");
		std::cout << "Expected: 5.0\n";
	}

	TEST("Mixed: 100 / 10 * 10 / 10");
	{
		Fixed a(100);
		Fixed b(10);
		Fixed result = ((a / b) * b) / b;
		printFixed(result, "result");
		std::cout << "Expected: 10.0\n";
	}

	TEST("Mixed: (1 / 3) * 3 (precision test)");
	{
		Fixed a(1);
		Fixed b(3);
		Fixed result = (a / b) * b;
		printFixed(result, "result");
		std::cout << "Expected: ~1.0 (may have precision error)\n";
	}

	TEST("Mixed: 0.5 * 0.5 / 0.5");
	{
		Fixed a(0.5f);
		Fixed b(0.5f);
		Fixed c(0.5f);
		Fixed result = (a * b) / c;
		printFixed(result, "result");
		std::cout << "Expected: 0.5\n";
	}

	TEST("Commutative: a*b vs b*a");
	{
		Fixed a(7.5f);
		Fixed b(2.3f);
		Fixed r1 = a * b;
		Fixed r2 = b * a;
		printFixed(r1, "a*b");
		printFixed(r2, "b*a");
		std::cout << "Expected: Both should be equal\n";
	}

	TEST("Associative: (a*b)*c vs a*(b*c)");
	{
		Fixed a(2.0f);
		Fixed b(3.0f);
		Fixed c(4.0f);
		Fixed r1 = (a * b) * c;
		Fixed r2 = a * (b * c);
		printFixed(r1, "(a*b)*c");
		printFixed(r2, "a*(b*c)");
		std::cout << "Expected: Should be equal (may differ due to rounding)\n";
	}

	TEST("Inverse: (a*b)/b should equal a");
	{
		Fixed a(42.5f);
		Fixed b(7.3f);
		Fixed result = (a * b) / b;
		printFixed(a, "original a");
		printFixed(result, "(a*b)/b");
		std::cout << "Expected: Should equal a (may have precision error)\n";
	}

	TEST("Inverse: (a/b)*b should equal a");
	{
		Fixed a(123.0f);
		Fixed b(17.0f);
		Fixed result = (a / b) * b;
		printFixed(a, "original a");
		printFixed(result, "(a/b)*b");
		std::cout << "Expected: Should equal a (may have precision error)\n";
	}
}

void testEdgeCases()
{
	TEST_SECTION("ADDITIONAL EDGE CASES");

	TEST("Raw bits: Direct manipulation");
	{
		Fixed a;
		a.setRawBits(512); // 512 / 256 = 2.0
		Fixed b;
		b.setRawBits(768); // 768 / 256 = 3.0
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: 6.0\n";
	}

	TEST("Raw bits: Power of 2 multiplication");
	{
		Fixed a;
		a.setRawBits(256); // 1.0
		Fixed b;
		b.setRawBits(256); // 1.0
		Fixed result = a * b;
		printFixed(result, "result");
		std::cout << "Expected: 1.0 (raw=256)\n";
	}

	TEST("Raw bits: Negative raw bits");
	{
		Fixed a;
		a.setRawBits(-512); // -2.0
		Fixed b;
		b.setRawBits(256); // 1.0
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: -2.0\n";
	}

	TEST("Compound: a = a * b");
	{
		Fixed a(5);
		Fixed b(3);
		std::cout << "Before: ";
		printFixed(a, "a");
		a = a * b;
		std::cout << "After a=a*b: ";
		printFixed(a, "a");
		std::cout << "Expected: 15.0\n";
	}

	TEST("Compound: a = a / b");
	{
		Fixed a(15);
		Fixed b(3);
		std::cout << "Before: ";
		printFixed(a, "a");
		a = a / b;
		std::cout << "After a=a/b: ";
		printFixed(a, "a");
		std::cout << "Expected: 5.0\n";
	}

	TEST("Self-multiplication: a * a");
	{
		Fixed a(7);
		Fixed result = a * a;
		printFixed(a, "a");
		printFixed(result, "a*a");
		std::cout << "Expected: 49.0\n";
	}

	TEST("Self-multiplication: 0.5 * 0.5");
	{
		Fixed a(0.5f);
		Fixed result = a * a;
		printFixed(a, "a");
		printFixed(result, "a*a");
		std::cout << "Expected: 0.25\n";
	}

	TEST("Copy semantics: result = a * b with copies");
	{
		Fixed a(4);
		Fixed b(5);
		Fixed c = a; // Copy
		Fixed d = b; // Copy
		Fixed result = c * d;
		printFixed(result, "result");
		std::cout << "Expected: 20.0\n";
	}

	TEST("Comparison after operation");
	{
		Fixed a(10);
		Fixed b(5);
		Fixed c(2);
		Fixed result1 = a / b; // 2
		Fixed result2 = c;      // 2
		std::cout << "result1 == result2: " << (result1 == result2) << "\n";
		std::cout << "Expected: 1 (true)\n";
	}

	TEST("Boundary: Just below overflow");
	{
		// Max safe multiplication: sqrt(INT_MAX * 256) ≈ 46340
		Fixed a(46340);
		Fixed b(1.0f);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(result, "result");
		std::cout << "Expected: 46340.0 (no overflow)\n";
	}

	TEST("Boundary: Just above overflow trigger");
	{
		Fixed a(46341);
		Fixed b(46341);
		Fixed result = a * b;
		printFixed(a, "a");
		printFixed(b, "b");
		printFixed(result, "result");
		std::cout << "Expected: Overflow\n";
	}
}

void tester()
{
	testMultiplication();
	testDivision();
	testMixedOperations();
	testEdgeCases();
}