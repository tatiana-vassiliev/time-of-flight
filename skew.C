// Tatiana Vassiliev
// 8/3/2023

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "TStopwatch.h"
#include <cstdlib>

{
  // begin run time, initialize and declare variables
  TStopwatch run_time;
  run_time.Start();
  double timediff = 0;
  int k = 0;
  TGraph* m = new TGraph();
  string formattedNumber;

  // to write values to a .txt file for debugging purposes, uncomment lines 22, 23, 161, and 166
  /*
  ofstream file("values.txt", ios::out | ios::app);
  file <<"#\tC3 Scaling\tC4 Scaling\tC3 Time\tC4 Time"<<endl;
  */

  // change the upper bound of the for loop to match the number of the last event taken
  for (int i = 0; i<= 5241; ++i)
  {
    // formats numbers to match the oscilliscope
    formattedNumber = "00000" + to_string(i);
    formattedNumber = formattedNumber.substr(formattedNumber.length()-5);

    // change the "C3" value to match the channel number used
    string c3 = "C3--Trace--" + formattedNumber +".txt";

    // go into .txt file
    ifstream infile(c3);
    if (!infile)
    {
      cout << "Error opening file: " << c3 << endl;
    }

    //loop through to find the minimum value
    double x1,y1;
    double tempmin1 = 10000.0;
    double tempx1 = 0.0;
    while(infile>>x1>>y1)
    {
      if (y1<tempmin1)
      {
        tempmin1 = y1;
        tempx1 = x1;
      }
    }
    infile.close();

    // normalize the peak for further comparison as needed
    double normal_c3 = -1.0/tempmin1;

    //get the 40% point, if you want a different percentage value, change variable param
    infile.open(c3);
    double param = -0.4;
    double paramx1 = 0.0;
    double x1_10,y1_10;
    while(infile>>x1_10>>y1_10)
    {
      if (y1_10>param/normal_c3)
      {
        paramx1=x1_10;
      }
      else
      {
        if (y1_10 == param/normal_c3)
        {
          paramx1=x1_10;
          break;
        }
        else
        {
          paramx1 = x1_10 -0.000000000025;
          break;
        }
      }
    }
    infile.close();

    // change the "C4" value to match the channel number used
    string c4 = "C4--Trace--" + formattedNumber +".txt";

    // go into .txt file
    infile.open(c4);
    if (!infile)
    {
      cout << "Error opening file: " << c4 << endl;
    }

    //loop through to find the minimum value
    double x2,y2;
    double tempmin2 = 10000.0;
    double tempx2 = 0.0;
    while(infile>>x2>>y2)
    {
      if (y2<tempmin2)
      {
        tempmin2 = y2;
        tempx2 = x2;
      }
    }
    infile.close();

    // normalize the peak for further comparison as needed
    double normal_c4 = -1.0/tempmin2;

    //get the 40% point, if you want a different percentage value, change the variable param on line 64
    infile.open(c4);
    double paramx2 = 0.0;
    double x2_10,y2_10;
    while(infile>>x2_10>>y2_10)
    {
      if (y2_10>param/normal_c4)
      {
        paramx2=x2_10;
      }
      else
      {
        if (y2_10 == param/normal_c4)
        {
          paramx2=x2_10;
          break;
        }
        else
        {
          paramx2 = x2_10 -0.000000000025;
          break;
        }
      }
    }
    infile.close();

    // calculate the time difference
    timediff = paramx1-paramx2;

    // if plateaus are present in the data, uncomment the following code
    /*
    if ((tempmin1 == -0.477944) | (tempmin2 == -0.477944))
    {
    }
    else
    {
      m-> SetPoint(k, abs(tempmin1-tempmin2), timediff);
      k= k+1;
    }
    */

    //this will add all of the points to the TGraph
    // add if statements to cut the data at certain limits
    m-> SetPoint(k, abs(tempmin1-tempmin2), timediff);
    k= k+1;

    // to write values to a .txt file for debugging purposes, uncomment lines 22, 23, 161, and 166
    //file <<fixed << setprecision(7)<<formattedNumber<< "\t"<<normal_c3<< "\t"<<normal_c4<<"\t"<<setprecision(14)<<paramx1<<"\t"<<paramx2<< endl;

  }

  // to write values to a .txt file for debugging purposes, uncomment lines 22, 23, 161, and 166
  //file.close();

  // create a TGraph with the skew
  m-> SetMarkerStyle(22);
  m -> SetTitle("Time Difference vs Difference Peak Height; Difference Peak Height (Volts); Time Difference (Seconds)");
  m-> Draw("AP");

  run_time.Stop();
  run_time.Print();
}
