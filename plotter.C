// Tatiana Vassiliev
// 8/3/2023
{
  // identify the source files for the two graphs
  // change the channel and file numbers to align with the event you want to visualize
  g = new TGraph("C3--Trace--01228.txt");
  z = new TGraph("C4--Trace--01228.txt");

  // create a canvas
  c1 = new TCanvas("c1", "C3 01228 vs C4 01228", 1600, 500);
  c1 -> Divide(2,1);

  // graph the first file
  c1 -> cd(1);
  // change this line to adjust the title of the second graph
  g -> SetTitle("C3 01228; Time (seconds); Amplitude (Volts)");
  g->GetHistogram()->SetMaximum(0.2);
  g->GetHistogram()->SetMinimum(-1.3);
  g-> Draw();

  // graph the second file
  c1 -> cd(2);
  // change this line to adjust the title of the second graph
  z -> SetTitle("C4 01228; Time (seconds); Amplitude (Volts)");
  z->GetHistogram()->SetMaximum(0.2);
  z->GetHistogram()->SetMinimum(-1.3);
  z->Draw();
}
