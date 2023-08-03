// Tatiana Vassiliev
// 8/3/2023
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdio>

{
  string formattedNumber;

  // change the upper bound of the for loop to match the number of the last event taken
  for (int i = 0; i<= 5152; ++i)
  {
    // formats numbers to match the oscilliscope
    formattedNumber = "00000" + to_string(i);
    formattedNumber = formattedNumber.substr(formattedNumber.length()-5);

    // change the "C4" value to match the channel number used
    string channel = "C4--Trace--" + formattedNumber;

    // file paths for input .csv and output .txt files
    string inputFilePath = channel+".csv";
    string outputFilePath = channel+".txt";
    ifstream inputFile(inputFilePath);
    ofstream outputFile(outputFilePath);

    // ignore the first five lines of the .csv file
    int count = 1;
    string line;
    for (int count = 1; (count <= 5) && getline(inputFile,line); ++count)
    {
    }

    // process the contents of each line and write them to the .txt file
    while (getline(inputFile, line))
    {
        istringstream iss(line);
        string value1, value2;
        if ((getline(iss, value1, ',')) && (getline(iss, value2)))
        {
          double num1, num2;
          istringstream(value1)>>num1;
          istringstream(value2) >> num2;
          ostringstream oss;
          oss << fixed << setprecision(14) << num1;
          outputFile << oss.str() << '\t'<<num2 <<'\n';
        }
    }

    // close the input and output files
    inputFile.close();
    outputFile.close();
    remove(inputFilePath.c_str());
  }

  cout << ".csv files have been converted to .txt files" << endl;

}
