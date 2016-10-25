This is a colorful tiny logger tool which is easy to use for terminal and log-file output.

# Install: #

```
#!shell

cmake CMakeLists.txt
make install
```

# Available colors: #

```
#!text

NRM : normal
RED : red
GRN : green
YEL : yellow
BLU : blue
MAG : magenta
CYN : cyan
LGY : light gray
DGY : dark gray
LRD : light red
LGN : light green
LYW : light yellow
LBL : light blue
LMA : light magenta
LCY : light cyan
WHT : white
```


# Example: #

```
#!c++

#include "prolog/pLogger.h"

int main() {
	pLogger::logfile = "sim.log";
	pLogger::log<GRN>("Simple terminal log with green color.\n");
	pLogger::logf<CYN>("Another one in cyan and file output.\n");
	pLogger::warning_msg("This a yellow warning message placed in terminal only!\n");
	pLogger::warning_msgf("This is another warning message but now it is placed in the log-file too!\n");
	pLogger::error_msgf("This a red error message with termination.\n");
	return 0;
}
// g++ -std=c++11 -I /usr/include main.cpp -o main /usr/lib/prolog/libprolog.a
```

# Output: #

![terminal_log.png](https://bitbucket.org/repo/bEXdEz/images/1477975845-terminal_log.png)

# sim.log: #

```
#!text

Another one in cyan and file output.
  WARNING: This is another warning message but now it is placed in the log-file too!
  ERROR: This a red error message with termination.
```