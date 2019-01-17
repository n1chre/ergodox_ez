#pragma once

// disable debugging
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // NO_DEBUG

// disable printing/debugging using hid_listen
#ifndef NO_PRINT
#define NO_PRINT
#endif // NO_PRINT

// this was deprecated
#ifndef NO_ACTION_FUNCTION
#define NO_ACTION_FUNCTION
#endif // NO_ACTION_FUNCTION

// how long before oneshot times out
#ifdef ONESHOT_TIMEOUT
#undef ONESHOT_TIMEOUT
#endif // ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 200
