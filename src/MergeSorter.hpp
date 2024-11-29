#include <ranges>
#include <vector>

template<typename T>
class MergeSorter {
private: 
	std::vector<T> mergeSort(const std::vector<T>& toMerge) {
		if(toMerge.size() <= 1) {
			return toMerge;
		}

		auto left = toMerge | std::views::take(toMerge.size() / 2) | std::ranges::to<std::vector>();
		auto right = toMerge | std::views::drop(toMerge.size() / 2) | std::ranges::to<std::vector>();

		auto sortedLeft = mergeSort(left);
		auto sortedRight = mergeSort(right);

		return merge(sortedLeft, sortedRight);
	}

	std::vector<T> merge(const std::vector<T>& left, const std::vector<T>& right) {
		std::vector<T> merged;
		auto leftIt { left.begin() }, rightIt { right.begin() };

		for (; leftIt != left.end() && rightIt != right.end();) {
			if(*leftIt <= *rightIt) {
				merged.push_back(*leftIt);
				leftIt++;
			} else {
				merged.push_back(*rightIt);
				rightIt++;
			}
		}

		merged.insert(merged.end(), leftIt, left.end());
		merged.insert(merged.end(), rightIt, right.end());
		
		return merged;
	}

public:
	void operator()(std::vector<T>& toSort) {
		if(toSort.size() <= 1) {
			return;
		}

		toSort = mergeSort(toSort);	
	}
};
