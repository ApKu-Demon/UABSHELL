DESCRIPTION ################################################################################

REPOSITORY STRUCTURE #######################################################################

CimaTerm/                   
├── bin/                    # Final binaries (ignored by Git)
├── docs/                   # User manual and screenshots
|
├── include/                # Header files (.h)
│   ├── shell.h             # Main shell definitions
│   └── colors.h            # ANSI color codes for draw_bmp (OPTIONAL...)
|
├── scripts/                # Default Scripts
│   ├── cleanuser.sh        # System user cleaning automation
│   └── sysinfo.sh          # System information automation
|
├── src/                    # Core Shell source code
│   ├── main.c              # The REPL loop
│   ├── parser.c            # Command parsing (strtok)
│   └── executor.c          # Fork, Exec, Wait logic
|
├── commands/               # The 3 C commands
│   ├── draw_bmp.c          # Image renderer (format bmp)
│   ├── sysinfo.c           # System monitor
│   └── cryptofile.c        # Basic encryption
|
├── assets/                 # Test BMP images
├── Makefile                # Compilation script
├── .gitignore              # Files to ignore
└── README.md               # Project documentation

BUILD INSTRUCTIONS #########################################################################


USAGE ######################################################################################


FEATURES ###################################################################################

    Commands . . .
        1. cryptofile: 

        2. drawbmp:

        3. sysinfo:

    Scripts:
        1. cleanuser.sh

        2. sysinfo.sh: