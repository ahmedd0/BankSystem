#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
class Person
{
protected:
	int id; //auto incremental
	string firstName, lastName, password, nationalId;

public:
	//---------- DEFAULT CONSTRUCTOR FUNCTION
	Person()
	{
		setId(1);
		setFirstName("");
		setLastName("");
		setNationalId("");
		setPassword("0000");
	}
	//---------- PARAMETERIZED CONSTRUCTOR FUNCTION
	Person(string firstName, string lastName, string nationalId, string password)
	{
		//setId(1);
		setFirstName(firstName);
		setLastName(lastName);
		setNationalId(nationalId);
		setPassword(password);
	}
	//--------------------	SET CLIENT ID FUNCTION
	void setId(int id)
	{
		//get the last id in db then ++
		this->id = id;
	}

	//--------------------	SET PASSWORD  FUNCTION
	void setPassword(string password)
	{
		//encrypt the password then
		this->password = password;
	}
	// ------------------- 	SET FIRST NAME FUNCTION
	void setFirstName(string firstName)
	{
		this->firstName = firstName;
	}
	// ----------------- 	SET LAST NAME FUNCTION

	void setLastName(string lastName)
	{
		this->lastName = lastName;
	}
	//--------------------  SET NATIONAL ID FUNCTION
	void setNationalId(string nationalId)
	{
		this->nationalId = nationalId;
	}
	// ---------------- 	GET ID FUNCTION
	int getId()
	{
		return id;
	}
	// -------------------- GET FIRST NAME FUNTION

	string getFirstName()
	{
		return firstName;
	}

	// -------------- GET LAST NAME FUNCTION

	string getLastName()
	{
		return lastName;
	}
	string getFullName()
	{
		return firstName + " " + lastName;
	}

	// -------------- GET NATIONAL ID
	string getNationalId()
	{
		return nationalId;
	}

	//--------------- GET PASSWORD
	string getPassword()
	{
		return password;
	}
	//PRINT INFO
	void printInfo()
	{
		cout << "ID: " << this->getId() << endl;
		cout << "FULL NAME :" << this->getFullName() << endl;
		cout << "NATIONAL ID : " << this->getNationalId() << endl;
	}
};

#endif
