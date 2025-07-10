#pragma once

namespace Config {
	static constexpr unsigned int BOARD_WIDTH = 64;
	static constexpr unsigned int BOARD_HEIGHT = 64;

	static constexpr unsigned int NEIGHBORHOOD_RANGE = 1;

	static constexpr unsigned int UNDERPOPULATION_THRESHOLD = 2;	
	static constexpr unsigned int OVERPOPULATION_THRESHOLD = 3;
	static constexpr unsigned int REPRPODUCTION_THRESHOLD = 3;

	static constexpr unsigned int TERMINAL_HEIGHT = 600;
	static constexpr unsigned int TERMINAL_WIDTH = 320;

	static constexpr char POPULATED_SYMBOL = '*';
	static constexpr char UNPOPULATED_SYMBOL = '-';

	static constexpr unsigned int FRAME_UPDATE_MS = 200;
}
