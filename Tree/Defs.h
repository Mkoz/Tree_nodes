//Defs.h: List of definitions for Node class

#pragma once

// Streams should be used for printout info. Stream may be redirected in Microsoft CppUnit
#define PRINT cout << __FILE__ << ":" << __LINE__ << "->[" << __FUNCTION__ << "]  "
#define PRINT_ERROR cout << "ERROR###"<< __FILE__ << ":" << __LINE__ << "->[" << __FUNCTION__ << "]  "
