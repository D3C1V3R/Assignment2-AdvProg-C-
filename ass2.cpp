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

struct PhoneRecord {
	char PhoneNo[cMaxPChars + 1];
	char FamilyName[cMaxNChars + 1];
	char GivenName[cMaxNChars + 1];
	int StreetNo;
	char StreetName[cMaxLChars + 1];
	char Suburb[cMaxLChars + 1];
	int PostCode;
};


// ============= Global Data =========================================

PhoneRecord *gRecs[cMaxRecs];
int gNumRecs = 0;


// ============= Private Function Prototypes =========================

void DisplayRecord(int i); // Displays record i on screen


// ============= Public Function Definitions =========================

void ReadFile()
{//Load Phone records from text datafile into array
	ifstream fin;
	fin.open("phone.txt");
	if (!fin.good())
	{
		cerr << "Could not open data file!\n";
		exit(1);
	}
	gNumRecs = 0;
	int i;

	for (i = 0; i < cMaxRecs; i++)
	{
		gRecs[i] = new PhoneRecord;
		fin >> gRecs[i]->PhoneNo;
		if (fin.fail()) break; // then eof
		fin >> gRecs[i]->FamilyName;
		fin >> gRecs[i]->GivenName;
		fin >> gRecs[i]->StreetNo;
		fin.ignore();
		fin.getline(gRecs[i]->StreetName, cMaxLChars + 1);
		fin.getline(gRecs[i]->Suburb, cMaxLChars + 1);
		fin >> gRecs[i]->PostCode;
	}
	gNumRecs = i;
	fin.close();
	cout << "\nThere are " << gNumRecs << " records in the Phone database\n";
}

void SaveFile(int index) {
	ofstream  File;
	File.open("phone.txt", ios::app);

	File << gRecs[index]->PhoneNo << endl;

	File.write((char*)gRecs[index]->FamilyName, strlen(gRecs[index]->FamilyName));
	File << endl;

	File.write((char*)gRecs[index]->GivenName, strlen(gRecs[index]->GivenName));
	File << endl;

	File << gRecs[index]->StreetNo << endl;

	File.write((char*)gRecs[index]->StreetName, strlen(gRecs[index]->StreetName));
	File << endl;

	File.write((char*)gRecs[index]->Suburb, strlen(gRecs[index]->Suburb));
	File << endl;

	File << gRecs[index]->PostCode << endl;

	cout << endl << "record saved to file" << endl;
}

void DisplayRecords()
{// Displays records one at a time
	for (int i = 0; i < gNumRecs / 5; i++) {
		for (int j = 0; j <= 4; j++) {
			DisplayRecord((i * 5) + j);
		}
		cout << "Display more records (y/n)> ";
		char Ans;
		cin >> Ans;
		cout << endl;
		if (Ans == 'n') return;
	}
}


void AddRecord()
{// Adds a new record to the database array

	cout << "Adding a new Record to Database... " << endl;
	gRecs[gNumRecs] = new (nothrow) PhoneRecord{};
		
	if (gNumRecs < cMaxRecs) {
		char _temp[cMaxLChars + 1];

		while (1) {
			cout << "Please enter a Phone Number: ";
			cin >> _temp;																	//Input of PhoneNum
			if (strlen(_temp)== cMaxPChars){												//Compare input to cMaxPChars
				memcpy(gRecs[gNumRecs]->PhoneNo, &_temp, cMaxPChars + 1);					//Copy check temp to pointer
				break;
			}else {
				cout << "Please input a correct contact Number" << endl;
			}
		}
		while (1) {
			cout << "Please enter a Family Name: ";
			cin >> _temp;																	//Input of FamilyName
			if (strlen(_temp) <= cMaxNChars) {												//Compare input to cMaxNChars
				_temp[0] = toupper(_temp[0]);												//Uppercase first Character
				memcpy(gRecs[gNumRecs]->FamilyName, &_temp, cMaxNChars + 1);				//Copy check temp to pointer
				break;
			}
			else {
				cout << "Please input a correct Family name" << endl;
			}
		}
		while (1) {
			cout << "Please enter a Given Name: ";
			cin >> _temp;																	//Input of Given name
			if (strlen(_temp) <= cMaxNChars) {												//Compare input to cMaxNChars
				_temp[0] = toupper(_temp[0]);												//Uppercase first Character
				memcpy(gRecs[gNumRecs]->GivenName, &_temp, cMaxNChars + 1);					//Copy check temp to pointer
				break;
			}
			else {
				cout << "Please input a correct Given name" << endl;
			}
		}
		while (1) {
			cout << "Please enter a Street Num: ";
			cin >> _temp;																	//Input of Street Num
			if (atoi(_temp)>=1) {															//why not just unsigned
				gRecs[gNumRecs]->StreetNo = atoi(_temp);
				break;
			}
			else {
				cout << "Please input a correct Street number" << endl;
			}
		}
		while (1) {
			cout << "Please enter a Street Name: ";	
			cin.ignore();
			cin.getline(_temp, cMaxLChars);													//Input of Street Name
			if (strlen(_temp) <= cMaxNChars) {												//Compare input to cMaxLChars
				memcpy(gRecs[gNumRecs]->StreetName, &_temp, cMaxLChars + 1);				//Copy check temp to pointer
				break;
			}
			else {
				cout << "Please input a correct Street number" << endl;
			}
		}
		while (1) {
			cout << "Please enter a Suburb: ";
			cin.getline(_temp, cMaxLChars);													//Input of Suburb
			if (strlen(_temp) <= cMaxLChars) {												//Compare input to cMaxLChars
				memcpy(gRecs[gNumRecs]->Suburb, &_temp, cMaxLChars + 1);					//Copy check temp to pointer
				break;
			}
			else {
				cout << "Please input a correct Suburb" << endl;
			}
		}
		while (1) {
			cout << "Please enter a Postcode: ";
			cin >> _temp;																	//Input of Postcode
			if (strlen(_temp) == 4) {														//Compare input to cMaxLChars
				gRecs[gNumRecs]->PostCode = atoi(_temp);
				break;
			}
			else {
				cout << "Please input a correct Postcode" << endl;
			}
		}
		gNumRecs++;
		cout << "A new record has been added to the database " << endl;
		cout << "...there are "<<gNumRecs<<" records in the database " << endl;

		SaveFile(gNumRecs - 1);


	}else {
		cout << "Error: DB Full!";
	}
}


void SearchRecords()
{// Searches database array for phone number 


	cout<<"Enter phone number:";
	int index;
	cin >> index;
	
	for (int i = 0; i <= gNumRecs; i++) {
		if (atoi(gRecs[i]->PhoneNo) == index) {
			DisplayRecord(i);
			return;
		}
	}
	cout << "Record not found!" << endl;
}


void CleanUp()
{// Deletes all dynamic data in gRecs array

	delete *gRecs;

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
