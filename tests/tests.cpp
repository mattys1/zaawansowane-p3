#include <gtest/gtest.h>
#include "MergeSorter.hpp"

TEST(ImportantTests, MergeSorter) {
	MergeSorter<int> sorter;	
	std::vector test { 5,2,4,3,1 };
	sorter(test);

	EXPECT_EQ(test, (std::vector { 1,2,3,4,5 }));
}
