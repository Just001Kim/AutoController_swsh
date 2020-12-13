#include "../../Joystick.h"
#include <avr/pgmspace.h>

// Define ECHOES here:
// 0 will run significantly faster but min button push time is 5 (sticks are 4)
// 1 is not tested
// 2 is the regular mode with min push time 1
#define ECHOES 2
#if ECHOES <= 1
	#define SPAM_DURATION 5
#else
	#define SPAM_DURATION 1
#endif

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Close game [3,8]----------
	{HOME, 1},
	{NOTHING, 40},
	{X, 1},			// Close game
	{NOTHING, 8},
	{A, 1},			// Comfirm close game
	{NOTHING, 120},
	
	//----------To System Settings [9,33]----------
	{RIGHT, 1},
	{RRIGHT, 1},
	{DOWN, 1},
	{RIGHT, 1},
	{A, 40},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{RDOWN, 1},
	{A, 10},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{RDOWN, 1},
	{A, 10},
	
	//----------Sync and unsync time [34,39]----------
	{NOTHING, 1},
	{A, 4},
	{NOTHING, 1},
	{A, 10},
	{HOME, 1},
	{NOTHING, 30},
	
	//----------Start game [40,45]----------
	{A, 1},			// Choose game
	{NOTHING, 50},
	{A, 1},			// Pick User
	{NOTHING, 820},
	{A, 1},			// Enter game
	{NOTHING, 460},
	
	//----------To actually Date and Time [46,48]----------
	{DOWN, 1},
	{RDOWN, 1},
	{A, 8},
	
	//----------Plus 1 year [49,55]----------
	{RIGHT, 1},		// EU/US start
	{RRIGHT, 1},
	{UP_A, 1},		// JP start
	{RIGHT, 1},
	{RRIGHT, 1},	// EU end
	{RIGHT, 1},		// US end
	{RRIGHT, 1},	// JP end
	
	//----------Back to game after plus 1 year [56,61]----------
	{A, 1},
	{NOTHING, 4},
	{HOME, 1},
	{NOTHING, 30},
	{HOME, 1},
	{NOTHING, 30},
	
	//----------Quit the raid [62,65]----------
	{B, 32},
	{NOTHING, 1},
	{A, 200},		// WAITING on local communication
	{NOTHING, 1},
	
	//----------Collect Watts [66,77]----------
	{A, 12},		// Talk
	{NOTHING, 1},
	{A, 6},			// There's energy pouring out from the den!
	{NOTHING, 1},
	{A, 30},		// You gained 2,000W! (Start here if no watts)
	{NOTHING, 1},
	{A, 30},		// (Optional) You can't catch this Pokemon, Is that OK?
	{NOTHING, 1},
	{A, 120},		// WAITING on local communication
	{NOTHING, 1},
	
	{HOME, 1},		// Goto home for day skip
	{NOTHING, 30},
	
	//----------Collect watts then scroll to make sound [78,84]----------
	{A, 12},		// Talk
	{NOTHING, 1},
	{A, 6},			// There's energy pouring out from the den!
	{NOTHING, 1},
	{A, 30},		// You gained 2,000W! (Delay longer for player to check)
	
	{DPAD_DOWN, 1},
	{NOTHING, 1},
};
