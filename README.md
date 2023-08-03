# Time of Flight Analysis Project for SiPM Array using Root Cern, Tel Aviv University

## convert.C
This file allows for manipulation of the .csv files produced by the Teledyne Lecroy Waverunner 8404M Oscilliscope. The code converts the .csv to a .txt file, deletes all unnecessary lines, and properly formats the values in both columns for use by Root Cern.  

Two changes must be made in the file for each new set of data.
* Change the upper bound of the for loop to match the number of the last event taken.
* Within the for loop, change the "C4" value of the string variable "channel" to match the channel number used, ie. C3. 

Notes:
* The code deletes the .csv files as it converts them to .txt, so ensure files are backed up before running the code
* The code only converts one channel at a time. Since there are two channels used for the project, you must run the code once, change the string channel variable, and then run it again.
* If you run the code twice on the same channel, it will produce empty .txt files. Ensure that you only run the code once on each set of files.
