#include <ranges>
#include <vector>

///@brief The class inside this template is responsible for sorting vectors using the merge sort algorithm
///
/// The sorting functionality can be accessed with `operator()()`
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
	/// @brief Will sort any vector inserted into the function using the merge sort algorithm. This operation happens recursively and IS NOT in place
	///
	/// @param toSort The vector that is to be sorted
	void operator()(std::vector<T>& toSort) {
		if(toSort.size() <= 1) {
			return;
		}

		toSort = mergeSort(toSort);	
	}
};
