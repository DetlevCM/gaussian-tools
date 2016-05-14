# Gaussian Tools
A simple utility to extract some data from Gaussian 09 log files. (Command Line Application)

The code traverses a Gaussian Log File and can return the following values:
- SCF Energy Calculation value of the molecule (default, always output)
- Distance between 2 atoms
- Valence Angle between 3 atoms
- Dihedral Angle between 4 atoms

For a scan calculation, output is provided at every scan step. For an optimisation every step is ouput.
IRC calculations are currently not officially supported but seem to work as well (just don't provide a pretty plot).

Linux Users: Please compile the code using the Eclipse generated Makefiles in "Release Makefile", you need a C++ compiler.

Windows Users: A binary for use with a 64Bit OS is supplied (in "Release Makefile").
Alternatively you can compile your own using either MinGW or your favourite compiler using the supplied makefiles.