This is a colorful tiny logger tool which is easy to use for terminal and log-file output.

Install:

```
#!shell

cmake CMakeLists.txt
make install
```

Example:

```
#!c++

#include "prolog/pLogger.h"

int main() {
	pLogger::log<GRN>("Simple terminal log with green color.\n"); // with pLogger::logf<YEL>(...) it writes log to file as well.
	pLogger::warning_msg("This a yellow warning message!\n");
	pLogger::error_msg("This a red error message with termination.\n");
	return 0;
}
// g++ -std=c++11 -I /usr/include main.cpp -o main /usr/lib/prolog/libprolog.a
```

Output:

![terminal_log.png](https://bitbucket.org/repo/bEXdEz/images/4196771629-terminal_log.png)