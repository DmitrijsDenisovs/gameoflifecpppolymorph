#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include <array>
#include <vector>

namespace Utility
{
    //class for tabular storage of T type
    template <typename T, std::size_t TRows, std::size_t TColumns>
    class Matrix {
    private:
        //flattened 2D array
        std::array<T, TRows * TColumns> data;

    public:
        Matrix() : data{ std::array<T, TRows * TColumns>() } {}

        inline T& operator()(std::size_t row, std::size_t column) { return data[row * TColumns + column]; }
        inline const T& operator()(std::size_t row, std::size_t column) const { return data[row * TColumns + column]; }
		
		inline T& operator[](std::size_t index) { return data[index]; }
		inline const T& operator[](std::size_t index) const { return data[index]; }

        inline std::size_t getRows() const { return TRows; }
        inline std::size_t getColumns() const { return TColumns; }
		inline std::size_t size() const { return TRows * TColumns; }

        std::vector<unsigned int> getNeighbors(const unsigned int index, const int range) const;
    };
}

template<typename T, std::size_t TRows, std::size_t TColumns>
std::vector<unsigned int> Utility::Matrix<T, TRows, TColumns>::getNeighbors(const unsigned int index, const int range) const {
	//row and column
	const auto row = index / TColumns;
	const auto column = index % TColumns;

	std::vector<unsigned int> neighbors{};

	//dr - delta row (vertical), dc - delta column (horizontal)
	for (int dr = -range; dr <= range; ++dr) {
		for (int dc = -range; dc <= range; ++dc) {
			if (dr == 0 && dc == 0)
				continue;

			int r = static_cast<int>(row) + dr;
			int c = static_cast<int>(column) + dc;

			if (r < 0 || r >= static_cast<int>(TRows) || c < 0 || c >= static_cast<int>(TColumns))
				continue;

			neighbors.push_back(static_cast<unsigned int>(r) * TColumns + static_cast<unsigned int>(c));
		}
	}

	return neighbors;
}

#endif
