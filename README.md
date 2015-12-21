# Gaussian Tools
A simple utility to extract some data from Gaussian 09 log files. (Command Line Application)

The code traverses a Gaussian Log File and can return the following values:
- SCF Energy Calculation value of the molecule (default, always output)
- Distance between 2 atoms
- Valence Angle between 3 atoms
- Dihedral Angle between 4 atoms

For a scan calculation, output is provided at every scan step. For an optimisation every step is ouput.
IRC calculatons are currently not officially supported but seem to work as well (just don't provide a pretty plot).