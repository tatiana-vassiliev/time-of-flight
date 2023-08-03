# Time of Flight Analysis Project for SiPM Array using Root Cern, Tel Aviv University

## convert.C
This file allows for manipulation of the .csv files produced by the Teledyne Lecroy Waverunner 8404M Oscilliscope. The code converts the .csv to a .txt file, deletes all unnecessary lines, and properly formats the values in both columns for use by Root Cern.  

Usage:
* Change the upper bound of the for loop to match the number of the last event taken.
* Within the for loop, change the "C4" value of the string variable "channel" to match the channel number used, ie. C3.

Notes:
* The code deletes the .csv files as it converts them to .txt, so ensure files are backed up before running the code.
* The code only converts one channel at a time. Since there are two channels used for the project, you must run the code once, change the string channel variable, and then run it again.
* If you run the code twice on the same channel, it will produce empty .txt files. Ensure that you only run the code once on each set of files.

## plotter.C
This file allows you to visualize an event by graphing a peak from each channel side by side.  

Usage:
* Change the g and z variable source files to align with the channel and file numbers you want to visualize.
* To update the graph titles, change the g -> SetTitle and z -> SetTitle lines

## time_diff.C
This file allows you to plot a histogram of time diffferences for specified events. The code calculates the time difference by subtracting the time it takes one graph of an event to reach a percentage of the peak from the time it takes for the other graph to reach the same percentage of its peak.

## skew.C
This file allows you to plot a graph that compares two characteristics of specified events. The code calculates the time difference in the same way as the time_diff.C file, and then allows you to specify what characteristic of the events to plot on each axis.

Usage:
* Change the upper bound of the for loop to match the number of the last event taken.
* Within the for loop, change the "C3"  and "C4" values of the string variables c3 and c4 to match the channel numbers used, ie. C1 and C2.
* To debug the code and see values for each event in a .txt file, uncomment lines 22, 23, and 161
