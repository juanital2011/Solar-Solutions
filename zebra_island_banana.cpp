//Header Files
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<cmath>

using namespace std;

//Function declarations
string intToString(int); //Function to convert integer into string
int convertToBinary(int); //Function to convert number into binary


int main()
{
	//Declarations
	int num, bin;
	ifstream fin;
	ofstream fout;
	string line;
	
	//Opening the file to read data
	fin.open("data.txt");
	fout.open("output.txt");
	
	//Check if file is opened
	if(fin.is_open())
	{
		//Reading the data from the file
		while(getline(fin, line))
		{
			//Getting the data from string line
			stringstream convert(line);
			convert >> num;
			
			//Calculating binary equivalent
			bin = convertToBinary(num);
			
			//Writing the content to output file
			fout << intToString(bin) << endl;
		}
	}
	else 
	{
		//If file is not opened
		cout << "Unable to open file" << endl;
	}
	
	//Close the files
	fin.close();
	fout.close();
	
	return 0;
}

//Function definitions
int convertToBinary(int n)
{
	int remainder, binary=0, i=1;
	
	while(n>0)
	{
		remainder = n%2;
		binary = binary + (remainder*i);
		n = n/2;
		i = i*10;
	}
	
	return binary;
}

string intToString(int n)
{
	stringstream ss;
	ss << n;
	string str = ss.str();
	
	return str;
}