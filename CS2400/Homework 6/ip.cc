//****************************************************************
//
//  Program:          Unique Visitors
//
//  Name:             Derek Baker
//  Email:            db820017@ohio.edu
//
//  Section:          100 (Nasseef Abukamail)
//
//  Description:      Takes a list of ips that visit a number of sites, and
//                    filters them down to only the unique ips for each site,
//                    giving the number of visitors and unique visitors.
//
//  Date:             10-30-18
//
//****************************************************************

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

void files(string& inputName, string& outputName);
void readIP(string ips[], int& uniqueVisitors, int& visitors, ifstream& inputFile, ofstream& outputFile);
bool search(string ips[], string ip);
void output(string ips[], ofstream& outputFile, string& siteName, int& visitors, int& uniqueVisitors);

int main() {
  string inputName, outputName;
  int uniqueVisitors = 0, visitors = 0;
  string ips[100];
  files(inputName, outputName);
  ifstream inputFile;
  ofstream outputFile;
  inputFile.open(inputName.c_str());
  if (inputFile.fail()) {
    cout << "File failed to open." << endl;
    return 1;
  }
  outputFile.open(outputName.c_str());
  readIP(ips, uniqueVisitors, visitors, inputFile, outputFile);
  // output(ips, outputFile);
  inputFile.close();
  outputFile.close();
  return 0;
}

//****************************************************************
//
//  Function:         files
//
//  Purpose:          To receive the names of the input file and desired output
//                    file.
//
//  Parameters:       A string to store input file name and output file name.
//
//  Pre Conditions:   None.
//
//  Post Conditions:  Names of both input and output files.
//
//****************************************************************
void files(string& inputName, string& outputName) {
  cout << "Enter the name of the input file: ";
  cin >> inputName;
  cout << "Enter the name of the input file: ";
  cin >> outputName;
}

//****************************************************************
//
//  Function:         readIP
//
//  Purpose:          To read a list of websites and the IPs that have visited
//                    each site, and filter the list down to only unique IPs,
//                    while keeping track of both the total visitors and the
//                    unique visitors.
//
//  Parameters:       ips[], the array of IPs.
//                    uniqueVisitors, the number of unique IPs.
//                    visitors, the total number of IPs.
//                    inputFile, the file we're pulling IPs from.
//                    outputFile, the file everything is output to.
//
//  Pre Conditions:   a valid input file.
//
//  Post Conditions:  An array full of the IPs of each website.
//
//****************************************************************
void readIP(string ips[], int& uniqueVisitors, int& visitors, ifstream& inputFile, ofstream& outputFile) {
  string ip;
  string siteName;

  inputFile >> siteName;  // Stores the site name, at the beginning of each section.
  while (!inputFile.eof()) {
    int i = 0;
    visitors = 0;
    uniqueVisitors = 0;

    inputFile >> ip;
    while (ip != "-----") {
      visitors ++;          // Increments visitors for each IP.

      if (!search(ips, ip)) {  // Function returns false if there are no identical IPs in the array.
        uniqueVisitors ++;  // Increments uniqueVisitors if the IP is unique.
        ips[i] = ip;        // Assigns the extracted ip to compartment i
        i ++;               // Increments i to go to the next compartment of the array.
      }

      inputFile >> ip;
    }

    output(ips, outputFile, siteName, visitors, uniqueVisitors);

    inputFile >> siteName;
  }
}

//****************************************************************
//
//  Function:         search
//
//  Purpose:          To search an array to identify if a given IP is already
//                    included in the array.
//
//  Parameters:       ips[], the array of ips
//                    ip, a given ip
//
//  Pre Conditions:   The function is given a valid string with an IP, and
//                    a valid array.
//
//  Post Conditions:  The function returns true if there is a matching IP in the
//                    array, and false if there is not.
//
//****************************************************************
bool search(string ips[], string ip) {
  for (size_t i = 0; i < 100; i++) {
    if (ips[i] == ip) {
      return true;
    }
  }
  return false;
}

//****************************************************************
//
//  Function:         output
//
//  Purpose:          To fill the output file with the needed information.
//
//  Parameters:       ips[]. the array of IPs.
//                    outputFile, the output file.
//                    siteName, the name of each website.
//                    visitors, the total number of IPs for each site.
//                    uniqueVisitors, the number of unique IPs for each site.
//
//  Pre Conditions:   A valid array, valid output file, and valid information
//                    for visitors and site names.
//
//  Post Conditions:  A valid output, stored in a separate file.
//
//****************************************************************
void output(string ips[], ofstream& outputFile, string& siteName, int& visitors, int& uniqueVisitors) {
    outputFile << siteName << " | Number of visitors: " << visitors << " | Unique Visitors: " << uniqueVisitors << endl;
    for (int i = 0; i < uniqueVisitors; i++) {  // i is used to determine the number of each compartment.
    outputFile << "  " << ips[i] << endl;
    // ips[i] = " ";
  }
    outputFile << endl;
}
