#ifndef ALL_CLASSES
#define ALL_CLASSES

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <fstream>

using namespace std;

class Animal
{
protected:
	Animal();//set the default color to GRAY and other params to 0
	Animal( const char* color, int childs, float avgLifetime );//init the Animal with a given attributes
	Animal( ifstream& in_file );//init the Animal from a binary file

public:
	virtual ~Animal();

public:
	const char* GetColor() const;//return the color of the animal
	int			GetChildCount() const;//return the child count of the animal
	float		GetLifetime() const;//return the life time of the animal
	void SetColor(const char* color);
	void SetChildCount(int childs);
	void SetLifetime(float lifetime);
	void SetAnimal(const char* color, int childs, float avgLifetime);

protected:
	char*	m_color;
	int		m_childCount;
	float	m_avgLifetime;
};

class Mammals : virtual public Animal
{
public:
	Mammals();//set the default color to GRAY and other params to 0
	Mammals( const char* color, int childs, float avgLifetime, float preg, float milk );//init the Mammals with a given attributes
	Mammals( ifstream& in_file );//init the Mammals from a binary file
	virtual ~Mammals();
	
public:
	float		GetPregnanceTime() const;//return the pregnance time of the animal
	float		GetMilk() const;//return the milk liters of the animal
	void SetPPregnanceTime(float pregnancytime);
	void SetMilk(float milk);

protected:
	float m_pregnancyTime;
	float m_milkLiters;
};

class Birds : public Animal
{
public:
	Birds();//set the default color to GRAY and other params to 0
	Birds( const char* color, int childs, float avgLifetime, float incubation );//init the Birds with a given attributes
	Birds( ifstream& in_file );//init the Birds from a binary file
	virtual ~Birds();
	
public:
	float		GetIncubationTime() const;//return the incubation time of the animal
	void SetIncubationTime(float incubationtime);
protected:
	float m_incubationTime;
};

class Fish : virtual public Animal
{
public:
	Fish();//set the default color to GRAY and other params to 0
	Fish( const char* color, int childs, float avgLifetime, int fin, int gills );//init the Fish with a given attributes
	Fish( ifstream& in_file );//init the Fish from a binary file
	virtual ~Fish();
	
public:
	int		GetFinCount() const;//return the fin count of the animal
	int		GetGillsCount() const;//return the gills count of the animal
	void SetFinCount(int fincount);
	void SetGillsCount(int gillscount);


protected:
	int m_finCount;
	int m_gillsCount;
};

class Horse : public Mammals
{
public:
	Horse();//set the default color to GRAY and other params to 0
	Horse( const char* color, int childs, float avgLifetime, float preg, float milk, const char* type );//init the Horse with a given attributes
	Horse( ifstream& in_file );//init the Horse from a binary file
	virtual ~Horse();
	
public:
	const char*		GetType() const;//return the type of the horse
	void SetType(const char * type);

protected:
	char*	m_type;
};

class Flamingo : public Birds
{
public:
	Flamingo();//set the default color to GRAY and other params to 0
	Flamingo( const char* color, int childs, float avgLifetime, float incubation, float avgHeight );//init the Flamingo with a given attributes
	Flamingo( ifstream& in_file );//init the Flamingo from a binary file
	virtual ~Flamingo();

public:
	float		GetHeight() const;//return the avg height of the flamingo
	void SetHight(float height);

protected:
	float m_avgHeight;
};

class MammalsFish : virtual public Mammals, virtual public Fish
{
public:
	MammalsFish();//set the default color to GRAY and other params to 0
	MammalsFish( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills );//init the MammalsFish with a given attributes
	MammalsFish( ifstream& in_file );//init the MammalsFish from a binary file
	virtual ~MammalsFish();
};

class GoldFish : public MammalsFish
{
public:
	GoldFish();//set the default color to GRAY and other params to 0
	GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL);//init the GoldFish with a given attributes
	GoldFish( ifstream& in_file );//init the GoldFish from a binary file
	virtual ~GoldFish();
	
public:
	float		GetWeight() const;//return the avg weight of the gold fish
	float		GetLength() const;//return the avg length of the gold fish
	void SetWeight(float weight);
	void SetLength(float length);


protected:
	float m_avgWeight;
	float m_avgLength;
};

class Mermaid :  public MammalsFish
{
public:
	Mermaid();//set the default color to GRAY and other params to 0
	Mermaid( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName );//init the Mermaid with a given attributes
	Mermaid( ifstream& in_file );//init the Mermaid from a binary file
	virtual ~Mermaid();
	
public:
	const char*		GetFirstName() const;//return the first name of the mermaid
	const char*		GetLastName() const;//return the last name of the mermaid
	void SetFirstName(const char * firstname);
	void SetLastName(const char * lastname);

protected:
	char* m_firstName;
	char* m_lastName;
};

class Zoo
{
public:
	Zoo();//default c'tor  - all to 0 or null
	Zoo( const char* name, const char* address, float ticket, const char* open, const char* close );//c'tor with data - init class
	Zoo( ifstream& in_file );//c'tor that gets a binary file and loads the data of the zoo from the file
	virtual ~Zoo();//d'tor
	
public:
	const char*		GetName() const;//return the name of the zoo
	const char*		GetAddress() const;//return the address of the zoo
	float			GetTicketPrice() const;//return the ticket price of the zoo
	const char*		GetOpenHour() const;//return the open hour of the zoo
	const char*		GetCloseHour() const;//return the close hour of the zoo
	int				GetNumOfAnimals() const;//return the num of animals in the zoo
	Animal**		GetAnimals() const;//return the animals array of the zoo

public:
	void AddAnimal( Animal* an );//creates a copy of "an" (deep copy) and adds an animal to the array
	void LoadAnmialBin(ifstream& in_file);
	Animal* CreateAnimalBin(ifstream& in_file);

public:
	Zoo& operator+( Animal* an );//adds an animal (only pointer, no copy needed) to the class and returns this with the change
	Zoo operator+( const Zoo& other ) const; //returns a new Zoo with the properties of this and animals of this and other (need to deep copy the data of other)
	Zoo& operator+=(Animal* newanimal);
public:
	friend ofstream& operator<<( ofstream& out, const Zoo& z );//operator to write the zoo to a text file
	friend ifstream& operator>>( ifstream& in, Zoo& z );//operator to read the zoo from a text file

public:
	void Save( ofstream& ofs ) const;//method to save the info to a text file
	void Load( ifstream& ifs );//method to load the info from a text file
	void SaveBin( ofstream& ofs ) const;//method to save the info to a binary file
	void SetName1(const char* name);
	void SetAdress1(const char* add);
	void Setticket1(float ticket);
	void Setopen1(const char* open);
	void Setclose1(const char* close);
	void Setnumofanimals1(int num);
	char * CleanName(char * name);

private:
	char*		m_name;
	char*		m_address;
	float		m_ticketPrice;
	char*		m_openHours;
	char*		m_closeHours;
	int			m_numOfAnimals;
	Animal**	m_animals;
};

ofstream& operator<<( ofstream& out, const Zoo& z );
ifstream& operator>>( ifstream& in, Zoo& z );

#endif // ifndef