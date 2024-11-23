#include <ranges>
#include <vector>

template<typename T>
class MergeSorter {
private: 
	std::vector<T> mergeSort(std::vector<T>& toMerge) {
		if(toMerge.size() <= 1) {
			return toMerge;
		}
		auto& [left, right] =  std::pair {
			toMerge | std::views::take(toMerge.size() / 2),
			toMerge | std::views::drop(toMerge.size() / 2)
		};

		auto sortedLeft = mergeSort(left);
		auto sortedRight = mergeSort(right);
	}
	void merge(std::vector<T>& left, std::vector<T>& right) {
		}
	}
public:
	void operator() (std::vector<T>& toSort) {
		
	}
};
