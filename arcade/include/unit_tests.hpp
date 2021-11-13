// https://github.com/hugorplobo/

#pragma once

#include <functional>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include "../include/colors.hpp"

enum TestResultStatus {
	OK, FAILED
};

class TestResult {
public:
	TestResultStatus status;
	std::string message;

	TestResult() {}

	TestResult(TestResultStatus status, std::string message)
	: status {status}, message {message} {}
};

class UnitTests {
	static inline std::vector<std::pair<std::string, std::function<TestResult()>>> tests {};

public:
	UnitTests() {}

	void add_test(std::string name, std::function<TestResult()> test_function) {
		UnitTests::tests.push_back(std::make_pair(name, test_function));
	}

	void run_tests() {
		int passed = 0, failed = 0, total = 0;

		std::cout << colors::bold << "Running tests: \n" << colors::reset;

		for (auto test : UnitTests::tests) {
			total++;
			auto test_result = test.second();
			if (test_result.status == TestResultStatus::OK) {
				passed++;
			} else {
				std::cout << "\n" << colors::bright_red << test.first << "\n" << test_result.message << "\n" << colors::reset;
				failed++;
			}
		}

		std::cout << colors::bright_green << "\nPassed: " << passed << std::endl;
		std::cout << colors::bright_red << "Failed: " << failed << std::endl;
		std::cout << colors::reset << "Total: " << total << std::endl;
	}

	template <typename T>
	static TestResult assert_equals(const T& op1, const T& op2) {
		TestResult result;
		std::stringstream message;
		if (op1 == op2) {
			result.status = TestResultStatus::OK;
		} else {
			result.status = TestResultStatus::FAILED;
			message << "Expected: " << op1 << " equals to " << op2;
			result.message = message.str();
		}

		return result;
	}

	template <typename T>
	static TestResult assert_not_equals(const T& op1, const T& op2) {
		TestResult result;
		std::stringstream message;
		if (op1 != op2) {
			result.status = TestResultStatus::OK;
		} else {
			result.status = TestResultStatus::FAILED;
			message << "Expected: " << op1 << " != " << op2;
			result.message = message.str();
		}

		return result;
	}

	template <typename T>
	static TestResult assert_true(const T& op) {
		TestResult result;
		std::stringstream message;
		if (op) {
			result.status = TestResultStatus::OK;
		} else {
			result.status = TestResultStatus::FAILED;
			message << "Expected: " << op << " to be true";
			result.message = message.str();
		}

		return result;
	}

	template <typename T>
	static TestResult assert_false(const T& op) {
		TestResult result;
		std::stringstream message;
		if (!op) {
			result.status = TestResultStatus::OK;
		} else {
			result.status = TestResultStatus::FAILED;
			message << "Expected: " << op << " to be false";
			result.message = message.str();
		}

		return result;
	}
};