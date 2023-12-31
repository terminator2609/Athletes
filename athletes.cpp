#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const unsigned short MAX_SIZE = 245;
const unsigned short MAX_SIZE_ATHLETES_BY_DIST = 7;
const unsigned short MAX_SIZE_ATHLETES_BY_COUNTRY = 35;
const unsigned short MAX_SIZE_COUNTRY = 7;
const unsigned short MAX_SIZE_DISCIPLINE = 5;

const string disciplinesList[] = { "200m Sprint", "4x400 Relay", "Pushing Shotgun", "Shepherd's Jump", "Triple Jump" };
const string countryBalkan[] = { "Albania", "Bosnia and Herzegovina", "Bulgaria", "Greece", "Kosovo", "North Macedonia", "Montenegro" };

struct Athlete {
	char numberAthlete[4];
	char name[30];
	unsigned short age;
	char discipline[20];
	unsigned int personalBest;
	unsigned int personalBestYear;
	unsigned short countParticipationWorld;
	char country[25];
};


void manageDiscipline(const Athlete atheletes[], string currentParam[], const unsigned short& countAthletes, unsigned short& optionCount, char country[23]) {

	unsigned short countOfAthletesByDiscipline(0), counterCurrentParam(0);


	for (int i = 0; i < MAX_SIZE_DISCIPLINE; i++) {

		for (int g = 0; g < countAthletes; g++) {

			if (strcmp(country, atheletes[g].country) == 0 && strcmp(disciplinesList[i].c_str(), atheletes[g].discipline) == 0) {
				countOfAthletesByDiscipline++;
			}
		}

		if (countOfAthletesByDiscipline < MAX_SIZE_ATHLETES_BY_DIST) {

			currentParam[counterCurrentParam] = disciplinesList[i];

			counterCurrentParam++;
			countOfAthletesByDiscipline = 0;

			optionCount++;
		}

	}

}

void manageCountry(const Athlete atheletes[], string currentParam[], const unsigned short& countAthletes, unsigned short& optionCount, unsigned short funcOption) {

	unsigned short countOfAthletesByCountry(0), counterCurrentParam(0);


	for (int i = 0; i < MAX_SIZE_COUNTRY; i++) {

		for (int g = 0; g < countAthletes; g++) {

			if (strcmp(countryBalkan[i].c_str(), atheletes[g].country) == 0) {
				countOfAthletesByCountry++;
			}
		}

		if (countOfAthletesByCountry < MAX_SIZE_ATHLETES_BY_COUNTRY && funcOption == 1) {

			currentParam[counterCurrentParam] = countryBalkan[i];

			counterCurrentParam++;
			countOfAthletesByCountry = 0;

			optionCount++;
		}


		if (countOfAthletesByCountry > 0 && funcOption == 2) {

			currentParam[counterCurrentParam] = countryBalkan[i];

			counterCurrentParam++;
			countOfAthletesByCountry = 0;

			optionCount++;
		}

	}



}

void printAthleteTemp(const Athlete athletes[], unsigned short index) {


	string unit;

	double convertPersonalBestToUnit;
	double convertPersonalBestYearToUnit;


	if (strcmp(athletes[index].discipline, disciplinesList[0].c_str()) == 0 || strcmp(athletes[index].discipline, disciplinesList[1].c_str()) == 0) {

		unit = "minutes";

		convertPersonalBestToUnit = athletes[index].personalBest / 60;
		convertPersonalBestYearToUnit = athletes[index].personalBestYear / 60;
	}
	else {
		unit = "meters";

		convertPersonalBestToUnit = athletes[index].personalBest / 100;
		convertPersonalBestYearToUnit = athletes[index].personalBestYear / 100;


	}

	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| " << setiosflags(ios::left) << setw(5) << "A.N" << " | " << setw(30) << "Name" << " | " << setw(3) << "Age" << " | "
		<< setw(25) << "Country" << " | " << setw(22) << "Discipline" << " | " << setw(30) << "Count of Participation World"
		<< " | " << setw(30) << "Record for carier( " + unit + ")" << " | " << setw(30) << "Record for year( " + unit + ")" << " |" << endl;

	cout << "| " << setiosflags(ios::left) << setw(5) << athletes[index].numberAthlete << " | " << setw(30) << athletes[index].name << " | " << setw(3) << athletes[index].age << " | "
		<< setw(25) << athletes[index].country << " | " << setw(22) << athletes[index].discipline << " | " << setw(30) << athletes[index].countParticipationWorld
		<< " | " << setw(30) << setiosflags(ios::fixed) << setprecision(2) << convertPersonalBestToUnit << " | " << setw(30) << setiosflags(ios::fixed) << setprecision(2) << convertPersonalBestYearToUnit << " |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

}

string printOption(string currentParam[], unsigned short& chooseOption, unsigned short& optionCount, const unsigned short& funcOption)
{
	string selectedParam;

	switch (funcOption)
	{
	case 1:

		cout << "Choose country:\n";
		break;

	case 2:
		cout << "Choose discipline:\n";
		break;
	default:
		break;
	}


	if (optionCount > 0) {

		for (int i = 0; i < optionCount; i++) {

			cout << "[" << i + 1 << "]" << currentParam[i] << "\n";
		}
	}
	else {

		switch (funcOption)
		{
		case 1:

			for (int i = 0; i < MAX_SIZE_COUNTRY; i++) {

				cout << "[" << i + 1 << "]" << countryBalkan[i] << "\n";
			}

			break;

		case 2:

			for (int i = 0; i < MAX_SIZE_DISCIPLINE; i++) {

				cout << "[" << i + 1 << "]" << disciplinesList[i] << "\n";
			}

			break;
		default:
			break;
		}
	}

	cin >> chooseOption;

	switch (funcOption)
	{
	case 1:

		switch (chooseOption)
		{
		case 1:

			if (optionCount >= 1) {

				selectedParam = currentParam[0];
			}

			if (optionCount == 0) {
				selectedParam = countryBalkan[0];
			}

			break;

		case 2:

			if (optionCount >= 2) {

				selectedParam = currentParam[1];
			}

			if (optionCount == 0) {
				selectedParam = countryBalkan[1];
			}

			break;

		case 3:

			if (optionCount >= 3) {

				selectedParam = currentParam[2];
			}

			if (optionCount == 0) {
				selectedParam = countryBalkan[2];
			}

			break;

		case 4:

			if (optionCount >= 4) {

				selectedParam = currentParam[3];
			}

			if (optionCount == 0) {
				selectedParam = countryBalkan[3];
			}

			break;

		case 5:

			if (optionCount >= 5) {

				selectedParam = currentParam[4];
			}

			if (optionCount == 0) {
				selectedParam = countryBalkan[4];
			}

			break;

		case 6:

			if (optionCount >= 6) {

				selectedParam = currentParam[5];
			}

			if (optionCount == 0) {
				selectedParam = countryBalkan[5];
			}

			break;
		case 7:

			if (optionCount >= 7) {

				selectedParam = currentParam[6];
			}

			if (optionCount == 0) {
				selectedParam = countryBalkan[6];
			}

			break;

		default:
			break;
		}
		break;

	case 2:

		switch (chooseOption)
		{
		case 1:

			if (optionCount >= 1) {

				selectedParam = currentParam[0];
			}

			if (optionCount == 0) {
				selectedParam = disciplinesList[0];
			}

			break;

		case 2:

			if (optionCount >= 2) {

				selectedParam = currentParam[1];
			}

			if (optionCount == 0) {
				selectedParam = disciplinesList[1];
			}

			break;

		case 3:

			if (optionCount >= 3) {

				selectedParam = currentParam[2];
			}

			if (optionCount == 0) {
				selectedParam = disciplinesList[2];
			}

			break;

		case 4:

			if (optionCount >= 4) {

				selectedParam = currentParam[3];
			}

			if (optionCount == 0) {
				selectedParam = disciplinesList[3];
			}

			break;

		case 5:

			if (optionCount >= 5) {

				selectedParam = currentParam[4];
			}

			if (optionCount == 0) {
				selectedParam = disciplinesList[4];
			}

			break;

		default:
			break;
		}

		break;
	default:
		break;
	}

	return selectedParam;
}

void inputData(Athlete atheletes[], const unsigned short index)
{


	cout << "User data:" << endl;
	cout << "" << endl;

	char firstName[14] = "", lastName[14] = "";

	cin.ignore();


	do
	{
		cout << "Enter value of first name: ";
		cin.getline(firstName, 14);
	} while (firstName != NULL && firstName[0] == '\0');

	do
	{
		cout << "Enter value of last name: ";
		cin.getline(lastName, 14);

	} while (lastName != NULL && lastName[0] == '\0');

	do
	{
		cout << "Enter value of age: ";
		cin >> atheletes[index].age;

	} while (atheletes[index].age < 0 || atheletes[index].age > 100);

	if (strcmp(atheletes[index].discipline, disciplinesList[0].c_str()) == 0 || strcmp(atheletes[index].discipline, disciplinesList[1].c_str()) == 0) {

		do
		{
			cout << "Enter value of personal best in the carier[in seconds]: ";
			cin >> atheletes[index].personalBest;

		} while (atheletes[index].personalBest < 0);

		do
		{
			cout << "Enter value of personal best for this year [in seconds]: ";
			cin >> atheletes[index].personalBestYear;

		} while (atheletes[index].personalBestYear < 0);

	}

	if (strcmp(atheletes[index].discipline, disciplinesList[2].c_str()) == 0 || strcmp(atheletes[index].discipline, disciplinesList[3].c_str()) == 0 || strcmp(atheletes[index].discipline, disciplinesList[4].c_str()) == 0) {
		do
		{
			cout << "Enter value of personal best in the carier[in cm]: ";
			cin >> atheletes[index].personalBest;

		} while (atheletes[index].personalBest < 0);

		do
		{
			cout << "Enter value of personal best for this year [in cm]: ";
			cin >> atheletes[index].personalBestYear;

		} while (atheletes[index].personalBestYear < 0);
	}


	do
	{
		cout << "Enter value of count of Participation in World : ";
		cin >> atheletes[index].countParticipationWorld;

	} while (atheletes[index].countParticipationWorld < 1);

	strcpy_s(atheletes[index].name, firstName);
	strcat_s(atheletes[index].name, " ");
	strcat_s(atheletes[index].name, lastName);

	if (index + 1 < 10) {


		strcpy_s(atheletes[index].numberAthlete, "00");
		strcat_s(atheletes[index].numberAthlete, to_string(index + 1).c_str());
	}
	else if (index + 1 >= 10 && index + 1 < 100) {
		strcpy_s(atheletes[index].numberAthlete, "0");
		strcat_s(atheletes[index].numberAthlete, to_string(index + 1).c_str());
	}
	else {
		strcpy_s(atheletes[index].numberAthlete, to_string(index + 1).c_str());
	}

	cout << "" << endl;

	fflush(stdin);
}

void sortByPersonalBestYearAndPrint(Athlete copyAthletes[], const unsigned short& copyCountAthletes)
{
	int count = -1;
	Athlete current;

	for (int i = 0; i < copyCountAthletes; i++)
	{

		for (int j = 0; j < copyCountAthletes; j++)
		{
			if (j > i && i != 0 || i != j && i == 0)
			{
				if (strcmp(copyAthletes[i].discipline, disciplinesList[0].c_str()) == 0 || strcmp(copyAthletes[i].discipline, disciplinesList[1].c_str()))
				{

					if (copyAthletes[i].personalBestYear > copyAthletes[j].personalBestYear)
					{
						count = j;
					}
				}



			}
		}

		if (count > -1) {

			current = copyAthletes[count];

			copyAthletes[count] = copyAthletes[i];

			copyAthletes[i] = current;

			count = -1;

			i--;
		}
	}

	cout << "Successfull sorting by discipline" << endl;
	cout << "" << endl;
}


void addAthlete(Athlete athletes[], unsigned short& countAthletes) {

	unsigned short choiceNAthletes;

	unsigned short optionCount(0), chooseOption(0);

	string selectedParam;

	string currentParam[7] = { "\0" };


	do
	{

		cout << "Enter value of athletes for adding[1-" << MAX_SIZE << "]: ";
		cin >> choiceNAthletes;

		if (choiceNAthletes + countAthletes > MAX_SIZE) {
			cout << "Exceeds the maximum number of athletes" << "Free space: " << MAX_SIZE - countAthletes << endl;
			cout << "" << endl;
		}

	} while (choiceNAthletes < 1 || choiceNAthletes + countAthletes > MAX_SIZE);



	for (int i = countAthletes; i < countAthletes + choiceNAthletes; i++) {

		if (i > 0) {
			manageCountry(athletes, currentParam, countAthletes, optionCount, 1);
		}

		do
		{

			selectedParam = printOption(currentParam, chooseOption, optionCount, 1);

			strcpy_s(athletes[i].country, selectedParam.c_str());


		} while (chooseOption < 1 || optionCount != 0 && chooseOption > optionCount || chooseOption > MAX_SIZE_COUNTRY);


		optionCount = 0;

		if (i > 0) {
			manageDiscipline(athletes, currentParam, countAthletes, optionCount, athletes[i].discipline);
		}

		do
		{

			selectedParam = printOption(currentParam, chooseOption, optionCount, 2);


			strcpy_s(athletes[i].discipline, selectedParam.c_str());


		} while (chooseOption < 1 || optionCount != 0 && chooseOption > optionCount || chooseOption > MAX_SIZE_DISCIPLINE);


		optionCount = 0;


		inputData(athletes, i);


		system("CLS");

		cout << "Successfull adding athlete with number " << athletes[i].numberAthlete << endl;
		cout << "" << endl;
	}

	countAthletes += choiceNAthletes;

	cout << "Free space: " << MAX_SIZE - countAthletes << endl;
	cout << "" << endl;
}

void printAllAthletes(const Athlete athletes[], const unsigned short& countAthletes)
{
	cout << "Print all athlets: " << endl;

	for (int i = 0; i < countAthletes; i++) {
		printAthleteTemp(athletes, i);
	}
}

void searchAndPrint(const Athlete athletes[], const unsigned short& countAthletes)
{
	short choose = -1;

	unsigned short selectedIndex = -1;

	unsigned short mostCountParticipationWorld = 0;

	unsigned short optionCount(0), chooseOption(0);
	string selectedParam;
	string currentParam[7] = { "\0" };


	do
	{
		cout << "Seacrhing and printing. Choose function:\n[1] The athlete with the most appearances at a world championship\n[2] All athletes from an entered selected country\n[0] Exit\n";
		cin >> choose;

		switch (choose)
		{
		case 1:

			system("CLS");

			for (int i = 0; i < countAthletes; i++) {

				if (athletes[i].countParticipationWorld > mostCountParticipationWorld) {

					mostCountParticipationWorld = athletes[i].countParticipationWorld;

					selectedIndex = i;
				}
			}

			cout << "Print athlete: " << endl;

			printAthleteTemp(athletes, selectedIndex);

			choose = -1;

			break;

		case 2:

			system("CLS");

			manageCountry(athletes, currentParam, countAthletes, optionCount, 2);

			do
			{

				selectedParam = printOption(currentParam, chooseOption, optionCount, 1);


			} while (chooseOption < 1 || optionCount != 0 && chooseOption > optionCount || chooseOption > MAX_SIZE_COUNTRY);

			cout << "Print athlete: " << endl;

			for (int i = 0; i < countAthletes; i++) {

				if (strcmp(athletes[i].country, selectedParam.c_str()) == 0) {

					printAthleteTemp(athletes, i);
				}
			}

			choose = -1;

			break;
		default:
			break;
		}


	} while (choose < 0 || choose > 2);

}

void sortByDiscipline(Athlete athletes[], const unsigned short& countAthletes)
{
	int count = -1;
	Athlete current;

	for (int i = 0; i < countAthletes; i++)
	{

		for (int j = 0; j < countAthletes; j++)
		{
			if (j > i && i != 0 || i != j && i == 0)
			{
				if (strcmp(athletes[i].discipline, athletes[j].discipline) > 0)
				{
					count = j;
				}

			}
		}

		if (count > -1) {

			current = athletes[count];

			athletes[count] = athletes[i];

			athletes[i] = current;

			count = -1;

			i--;
		}
	}

	cout << "Successfull sorting by discipline" << endl;
	cout << "" << endl;
}

int saveDataToBinaryFile(Athlete athletes[], unsigned short& countAthletes)
{
	ofstream athletesData("athletes.dat", ios::out | ios::binary);

	if (!athletesData) {
		cout << "Cannot open file!" << endl;
		return 1;
	}


	for (int i = 0; i < countAthletes; i++) {

		athletesData.write((char*)&athletes[i], sizeof(Athlete));

	}

	athletesData.close();

	if (!athletesData.good()) {
		cout << "Error occurred at writing time!" << endl;
		return 1;
	}
	else {
		cout << "Successfull save data to file" << endl;

		cout << "" << endl;
	}


}

int loadDataFromBinaryFile(Athlete athletes[], unsigned short& countAthlete)
{
	ifstream athletesDataInput("athletes.dat", ios::in | ios::binary);

	if (!athletesDataInput) {
		cout << "Cannot open file!" << endl;
		return 1;
	}

	while (!athletesDataInput.eof())
	{
		athletesDataInput.read((char*)&athletes[countAthlete], sizeof(Athlete));

		countAthlete++;
	}


	athletesDataInput.close();

	if (!athletesDataInput.good()) {
		cout << "Error occurred at reading time!" << endl;
		return 1;
	}
	else {
		cout << "Successfull load data to file" << endl;

		cout << "" << endl;
	}
}

void sortAndPrintByDiscipline(const Athlete athletes[], const unsigned short& countAthletes) {

	Athlete copyAthletes[MAX_SIZE] = { 0 };

	string copyDisciplinesList[MAX_SIZE_DISCIPLINE];

	string current;

	short count = -1;

	for (int i = 0; i < MAX_SIZE_DISCIPLINE; i++) {

		copyDisciplinesList[i] = disciplinesList[i];
	}


	for (int i = 0; i < MAX_SIZE_DISCIPLINE; i++)
	{

		for (int j = 0; j < MAX_SIZE_DISCIPLINE; j++)
		{
			if (j > i && i != 0 || i != j && i == 0)
			{
				if (strcmp(copyDisciplinesList[i].c_str(), copyDisciplinesList[j].c_str()) > 0)
				{
					count = j;
				}

			}
		}

		if (count > -1) {

			current = copyDisciplinesList[count];

			copyDisciplinesList[count] = copyDisciplinesList[i];

			copyDisciplinesList[i] = current;

			count = -1;

			i--;
		}
	}

	count = 0;

	for (int i = 0; i < MAX_SIZE_DISCIPLINE; i++) {

		for (int g = 0; g < countAthletes; g++) {

			if (strcmp(copyDisciplinesList[i].c_str(), athletes[g].discipline) == 0) {
				copyAthletes[count] = athletes[g];
				count++;
			}
		}

		if (count > 0) {


		}

	}


}

int main()
{

	Athlete athletes[MAX_SIZE] = { 0 };
	unsigned short countAthletes(0);

	short choice = -1;
	short underChoose = -1;

	do
	{
		cout << "Choice function:\n[1] Add Athlete\n[2] Print all athletes\n[3] Search and Print\n[4] Sort by discipline\n[5] Save data to file\n[6] Load data to file\n[7] Other";
		cin >> choice;


		switch (choice)
		{
		case 1:

			system("CLS");

			if (countAthletes < MAX_SIZE) {
				addAthlete(athletes, countAthletes);
			}
			else {
				cout << "No free space" << endl;
				cout << "" << endl;
			}

			choice = -1;

			break;

		case 2:

			system("CLS");

			if (countAthletes > 0) {
				printAllAthletes(athletes, countAthletes);
			}
			else {
				cout << "No found athletes" << endl;
				cout << "" << endl;
			}

			choice = -1;

			break;

		case 3:

			system("CLS");

			if (countAthletes > 0) {
				searchAndPrint(athletes, countAthletes);
			}
			else {
				cout << "No found athletes" << endl;
				cout << "" << endl;
			}

			choice = -1;

			break;


		case 4:

			system("CLS");

			if (countAthletes > 1) {
				sortByDiscipline(athletes, countAthletes);
			}
			else {
				cout << "No found athletes or found 1 athlete" << endl;
				cout << "" << endl;
			}

			choice = -1;

			break;

		case 5:
			system("CLS");

			if (countAthletes > 0) {

				saveDataToBinaryFile(athletes, countAthletes);
			}
			else {

				cout << "No found customers" << endl;
				cout << "" << endl;
			}

			choice = -1;

			break;

		case 6:
			system("CLS");

			loadDataFromBinaryFile(athletes, countAthletes);

			choice = -1;

			break;

		case 7:

			system("CLS");

			do
			{
				cout << "Other: Choose func\n[1] Print all athletes sorted by discipline\n[2] Search and print all athlete by age\n";
				cin >> underChoose;

				switch (underChoose)
				{
				case 1:


				default:
					break;
				}


			} while (underChoose < 0 || underChoose > 2);


		default:
			break;
		}

	} while (choice < 0 || choice > 7);

}