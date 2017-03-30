/***********************************************************************************
 * CSCI251/851 - Assignment 2
 * ass2.cpp - Contains function definitions for phone database program
 * Put you name, login and the date last modified here.
 *
 ***********************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

// ============== Constants ==========================================

const char cDataFileName[] = "phone.txt";
const int cMaxRecs = 250;  // Max records in database
const int cMaxNChars = 20; // Max chars in name
const int cMaxLChars = 30; // Max chars in location
const int cMaxPChars = 8;  // Max chars in phone no


// ============= User Defined types ==================================

struct PhoneRecord{
	char PhoneNo[cMaxPChars+1];
	char FamilyName[cMaxNChars+1];
	char GivenName[cMaxNChars+1];
	int StreetNo;
	char StreetName[cMaxLChars+1];
	char Suburb[cMaxLChars+1];
	int PostCode;
};


// ============= Global Data =========================================

PhoneRecord *gRecs[cMaxRecs];
int gNumRecs=0;


// ============= Private Function Prototypes =========================

void DisplayRecord(int i); // Displays record i on screen


// ============= Public Function Definitions =========================

void ReadFile()
{//Load Phone records from text datafile into array
	ifstream fin;
	fin.open(cDataFileName);
	if (!fin.good())
	{
		cerr << "Could not open data file!\n";
		exit(1);
	}
	gNumRecs=0;
	int i;
	for(i=0;i<cMaxRecs;i++)
	{
		gRecs[i] = new PhoneRecord;
		fin >> gRecs[i]->PhoneNo;
		if(fin.fail()) break; // then eof
		fin >> gRecs[i]->FamilyName;
		fin >> gRecs[i]->GivenName;
		fin >> gRecs[i]->StreetNo;
		fin.ignore();
		fin.getline(gRecs[i]->StreetName,cMaxLChars+1);
		fin.getline(gRecs[i]->Suburb,cMaxLChars+1);
		fin >> gRecs[i]->PostCode;
	}
	gNumRecs=i;
	fin.close();
	cout<< "\nThere are "<< gNumRecs <<" records in the Phone database\n";
}

void DisplayRecords()
{// Displays records one at a time
	for (int i = 0; i < gNumRecs/5; i++) {
		for (int j = 0; j <= 4; j++) {
			DisplayRecord(i+j);
		}
		cout<<"Display more records (y/n)> ";
		char Ans;
		cin>>Ans;
		cout<<endl;
		if(Ans=='n') return;
	}
}


void AddRecord()
{// Adds a new record to the database array

	cout << "Adding a new Record to Database... ";

	if (gNumRecs < cMaxRecs) {
		gRecs[gNumRecs + 1] = new PhoneRecord;
		while (1) {
			cin >> gRecs[gNumRecs + 1]->PhoneNo;

		}

	}
	else {
		cout << "Error: DB Full!";
	}





	//	char PhoneNo[cMaxPChars + 1];
	//	char FamilyName[cMaxNChars + 1];
	//	char GivenName[cMaxNChars + 1];
	//	int StreetNo;
	//	char StreetName[cMaxLChars + 1];
	//	char Suburb[cMaxLChars + 1];
	//	int PostCode;
	//const int cMaxNChars = 20; // Max chars in name
	//const int cMaxLChars = 30; // Max chars in location
	//const int cMaxPChars = 8;  // Max chars in phone no

	//      get data from user and assign to new record's fields
	//      add new record to array
	//      increment gNumRecs
	//      append new record to the DB file
	//      print "record added to DB" message
}

void SearchRecords()
{// Searches database array for phone number 

	cout<<"SearchRecord()- Not yet implemented\n";

	// get phone no. from user
	// search array for record
	// if found 
	//     display record
	// else
	//     print "record not found!" message
}


void CleanUp()
{// Deletes all dynamic data in gRecs array

	cout<<"CleanUp()- Not yet implemented\n";

	cout<<"\n\t*** Thanks for using the Phone DB ***\n";
}
// ============= Private Functions Definitions =========================



void DisplayRecord(int i)
{// Displays record i on screen
	cout << gRecs[i]->PhoneNo << "\t";
	cout << gRecs[i]->GivenName << " ";
	cout << gRecs[i]->FamilyName << ", ";
	cout << gRecs[i]->StreetNo << " ";
	cout << gRecs[i]->StreetName << ", ";
	cout << gRecs[i]->Suburb << ", ";
	cout << gRecs[i]->PostCode;
	cout << endl;
}

