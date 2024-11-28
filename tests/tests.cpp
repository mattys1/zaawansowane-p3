#include <gtest/gtest.h>
#include "MergeSorter.hpp"

TEST(ImportantTests, SortNormal) {
	MergeSorter<int> sorter;	
	std::vector test { 5,2,4,3,1 };
	sorter(test);

	EXPECT_EQ(test, (std::vector { 1,2,3,4,5 }));
}

TEST(ImportantTests, SortStability) {
	struct StabilityTest {
		int id;
		std::string name; 

		StabilityTest(int _id, std::string_view _name):
			id { _id },
			name { _name } {}

		std::strong_ordering operator<=>(const StabilityTest& other) const {
			return this->id <=> other.id;
		} 

		bool operator==(const StabilityTest& other) const {
			return operator<=>(other) == std::strong_ordering::equivalent;
		}
	};

	std::vector stabTest { 
		StabilityTest(1, "Polska,"),
		StabilityTest(2, "kraj"),
		StabilityTest(2, "piekny,"),
		StabilityTest(3, "ale"),
		StabilityTest(4, "ludzie"),
		StabilityTest(5, "to"),
	};

	MergeSorter<StabilityTest> sorter;

	auto sortedStabTest = stabTest;
	sorter(sortedStabTest);

	EXPECT_EQ(stabTest, sortedStabTest);
}

TEST(ImportantTests, SortReverse) {
	MergeSorter<int> sorter;	
	std::vector test { 5,4,3,2,1 };
	sorter(test);

	EXPECT_EQ(test, (std::vector { 1,2,3,4,5 }));
}
