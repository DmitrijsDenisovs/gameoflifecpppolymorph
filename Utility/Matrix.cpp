#include "Matrix.h"

#include <array>
#include <ranges>
#include <vector>

using Utility::Matrix;

//gets neighbors in Chebyshev's distance
//template<typename T, std::size_t TRows, std::size_t TColumns>
//std::vector<unsigned int> Matrix<T, TRows, TColumns>::getNeighbors(const unsigned int index, const unsigned int range) const{
//	//row and column
//	const auto row = this->data.size() / TColumns;
//	const auto column = this->data.size() % TColumns;
//
//	std::vector<unsigned int> neighbors{};
//
//	//dr - delta row (vertical), dc - delta column (horizontal)
//	for (int dr = -range; dr <= range; ++dr) {
//		for (int dc = -range; dc <= range; ++dc) {
//			int r = static_cast<int>(row) + dr;
//			int c = static_cast<int>(column) + dc;
//
//			if (r < 0 || r >= static_cast<int>(TRows) || c < 0 || c >= static_cast<int>(TColumns))
//				continue;
//
//			neighbors.push_back(static_cast<unsigned int>(r) * TColumns + static_cast<unsigned int>(c));
//		}
//	}
//
//	return neighbors;
//}