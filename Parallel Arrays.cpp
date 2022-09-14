//Name: Sijan Panday
//Date: 4/17/2022
//Project Description: Using parralell arrays to arrange 

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

void fileCheck(ifstream& iFile);

void getStudentData(ifstream& iFile, string fName[], string lName[], string major[], string favClass[], string lFavClass[], string& highFname, string& highLname, string& highMajor, string& highFavClass, string& highLfavClass, double GPA[], double& highGPA, int creditHours[], int& highCreditHours, int& counter);

void outputData(ofstream& oFile, string fName[], string lName[], string major[], string favClass[], string lFavClass[], double GPA[], int creditHours[], int& counter);

void outputHighest(ofstream& oFile, string& highFname, string& highLname, string& highMajor, string& highFavClass, string& highLfavClass, double& highGPA, int& highCreditHours);

void closingFiles(ifstream& iFile, ofstream& oFile);

int main()
{
	cout << fixed << showpoint << setprecision(2);

	ifstream iFile;
	ofstream oFile;
	int const x = 50;
	string fName[x], lName[x], major[x], favClass[x], lFavClass[x], highFname,
		highLname, highMajor, highFavClass, highLfavClass;
	double GPA[x], highGPA=0.00;
	int creditHours[x], highCreditHours, counter = 0;

	iFile.open("Text.txt");
	oFile.open("Output.txt");

	fileCheck(iFile);

	getStudentData(iFile, fName, lName, major, favClass, lFavClass, highFname, highLname, highMajor, highFavClass, highLfavClass, GPA, highGPA, creditHours, highCreditHours, counter);

	outputData(oFile, fName, lName, major, favClass, lFavClass, GPA, creditHours, counter);

	outputHighest(oFile, highFname, highLname, highMajor, highFavClass, highLfavClass, highGPA, highCreditHours);

	closingFiles(iFile, oFile);
	




	return 0;
}



void fileCheck(ifstream& iFile)
{
	if (!iFile.is_open())
	{
		cout << "File did not open";
		exit(1);
	}
}

void getStudentData(ifstream& iFile, string fName[], string lName[], string major[], string favClass[], string lFavClass[], string& highFname, string& highLname, string& highMajor, string& highFavClass, string& highLfavClass, double GPA[], double& highGPA, int creditHours[], int& highCreditHours, int& counter)
{
	while (!iFile.eof())
	{
		iFile >> fName[counter];

		iFile >> lName[counter];

		iFile.ignore();

		getline(iFile, major[counter]);

		iFile >> creditHours[counter];

		iFile >> GPA[counter];

		iFile.ignore();

		getline(iFile, favClass[counter]);

		getline(iFile, lFavClass[counter]);

		if (GPA[counter] > highGPA)
		{
			highGPA = GPA[counter];
			highFname = fName[counter];
			highLname = lName[counter];
			highMajor = major[counter];
			highCreditHours = creditHours[counter];
			highFavClass = favClass[counter];
			highLfavClass = lFavClass[counter];
		}
		counter++;
	}
}

void outputData(ofstream& oFile, string fName[], string lName[], string major[], string favClass[], string lFavClass[], double GPA[], int creditHours[], int& counter)
{
	for (int a = 0; a < counter; a++)
	{
		cout << "Name: " << fName[a] << " " << lName[a] << endl;
		cout << "Major: " << major[a] << endl;
		cout << "Credit Hours: " << creditHours[a] << endl;
		cout << "GPA: " << GPA[a] << endl;
		cout << "Favorite class: " << favClass[a] << endl;
		cout << "Least favorite class: " << lFavClass[a] << endl;
		cout << "\n" << endl;
		oFile << "Name: " << fName[a] << " " << lName[a] << endl;
		oFile << "Major: " << major[a] << endl;
		oFile << "Credit Hours: " << creditHours[a] << endl;
		oFile << "GPA: " << GPA[a] << endl;
		oFile << "Favorite class: " << favClass[a] << endl;
		oFile << "Least favorite class: " << lFavClass[a] << endl;
		oFile << "\n" << endl;
	}
}

void outputHighest(ofstream& oFile, string& highFname, string& highLname, string& highMajor, string& highFavClass, string& highLfavClass, double& highGPA, int& highCreditHours)
{
	cout << "*******Highest GPA Student*********" << endl;
	cout << "Name: " << highFname << " " << highLname << endl;
	cout << "Major: " << highMajor << endl;
	cout << "Credit Hours: " << highCreditHours << endl;
	cout << "GPA: " << highGPA << endl;
	cout << "Favorite class: " << highFavClass << endl;
	cout << "Least favorite class: " << highLfavClass << endl;
	cout << "\n" << endl;
	oFile << "*******Highest GPA Student*********" << endl;
	oFile << "Name: " << highFname << " " << highLname << endl;
	oFile << "Major: " << highMajor << endl;
	oFile << "Credit Hours: " << highCreditHours << endl;
	oFile << "GPA: " << highGPA << endl;
	oFile << "Favorite class: " << highFavClass << endl;
	oFile << "Least favorite class: " << highLfavClass << endl;
	oFile << "\n" << endl;
}

void closingFiles(ifstream& iFile, ofstream& oFile)
{
	iFile.close();
	oFile.close();
}