#include "allClasses.h"
#include<string>

using namespace std;

//*******************************************A N I M A L**************************************************

Animal::Animal()//set the default color to GRAY and other params to 0
{

	this->SetColor("GRAY");
	this->SetChildCount(0);
	this->SetLifetime(0);
}
Animal::Animal(const char* color, int childs, float avgLifetime)//init the Animal with a given attributes
{
	this->SetColor(color);
	this->SetChildCount(childs);
	this->SetLifetime(avgLifetime);
}
Animal::Animal(ifstream& in_file)//init the Animal from a binary file
{
	int size;
	in_file.read((char*)&size, sizeof(size));
	m_color = new char[size + 1];
	in_file.read(m_color, size + 1);
	in_file.read((char*)&(this->m_childCount), sizeof(this->m_childCount));
	in_file.read((char*)&(this->m_avgLifetime), sizeof(this->m_childCount));
	
}
Animal::~Animal()
{
	if (this->m_color != NULL)
		delete[]this->m_color;
}
const char* Animal::GetColor() const//return the color of the animal
{
	return this->m_color;
}
int Animal::GetChildCount() const//return the child count of the animal
{
	return this->m_childCount;
}
float Animal::GetLifetime() const//return the life time of the animal
{
	return this->m_avgLifetime;
}
void Animal::SetColor(const char* color)
{
	this->m_color = new char[strlen(color)];
	strcpy(this->m_color,color);
}
void Animal::SetChildCount(int childs)
{
	this->m_childCount = childs;
}
void Animal::SetLifetime(float lifetime)
{
	this->m_avgLifetime = lifetime;
}
void Animal::SetAnimal(const char* color, int childs, float avgLifetime) // set an animal
{
	this->SetColor(color);
	this->SetChildCount(childs);
	this->SetLifetime(avgLifetime);
}


//******************************* M A M M ELS********************************************************
Mammals::Mammals():Animal()//set the default color to GRAY and other params to 0
{
	this->SetMilk(0);
	this->SetPPregnanceTime(0);
}
Mammals::Mammals(const char* color, int childs, float avgLifetime, float preg, float milk) : Animal(color,  childs,avgLifetime)//init the Mammals with a given attributes
{
	this->SetAnimal(color, childs, avgLifetime);
	this->SetMilk(milk);
	this->SetPPregnanceTime(preg);
}
Mammals::Mammals(ifstream& in_file):Animal(in_file)//init the Mammals from a binary file
{
	in_file.read((char *)&(this->m_pregnancyTime), sizeof(this->m_pregnancyTime));
	in_file.read((char *)&(this->m_milkLiters), sizeof(this->m_milkLiters));
}
Mammals:: ~Mammals()
{

}
float Mammals::GetPregnanceTime() const//return the pregnance time of the animal
{
	return this->m_pregnancyTime;
}
float Mammals::GetMilk() const//return the milk liters of the animal
{
	return this->m_milkLiters;
}
void Mammals::SetPPregnanceTime(float pregnancytime)
{
	this->m_pregnancyTime = pregnancytime;
}
void Mammals::SetMilk(float milk)
{
	this->m_milkLiters = milk;
}
//************************************* B I R D S *******************************************************

Birds::Birds():Animal()//set the default color to GRAY and other params to 0
{
	this->SetIncubationTime(0);
}
Birds::Birds(const char* color, int childs, float avgLifetime, float incubation):Animal(color,childs,avgLifetime)//init the Birds with a given attributes
{
	this->SetAnimal(color, childs, avgLifetime);
	this->SetIncubationTime(incubation);
}
Birds::Birds(ifstream& in_file):Animal(in_file)//init the Birds from a binary file
{
	in_file.read((char*)&m_incubationTime, sizeof(m_incubationTime));
}
Birds:: ~Birds()
{

}
float Birds::GetIncubationTime() const//return the incubation time of the animal
{
	return this->m_incubationTime;
}
void Birds::SetIncubationTime(float incubationtime)
{
	this->m_incubationTime = incubationtime;
}
//********************************************** F I S H *************************************************

Fish::Fish():Animal()//set the default color to GRAY and other params to 0
{
	this->SetFinCount(0);
	this->SetGillsCount(0);
}
Fish::Fish(const char* color, int childs, float avgLifetime, int fin, int gills):Animal(color, childs,avgLifetime)//init the Fish with a given attributes
{
	this->SetAnimal(color, childs, avgLifetime);
	this->SetFinCount(fin);
	this->SetGillsCount(gills);
}
Fish::Fish(ifstream& in_file): Animal(in_file)//init the Fish from a binary file
{
	in_file.read((char*)&m_gillsCount, sizeof(m_gillsCount));
	in_file.read((char*)&m_finCount, sizeof(m_finCount));
}
Fish:: ~Fish()
{

}
int	Fish::GetFinCount() const//return the fin count of the animal
{
	return this->m_finCount;
}
int	Fish::GetGillsCount() const//return the gills count of the animal
{
	return this->m_gillsCount;
}
void Fish::SetFinCount(int fincount)
{
	this->m_finCount = fincount;
}
void Fish::SetGillsCount(int gillscount)
{
	this->m_gillsCount = gillscount;
}
//*************************************************** H O R S E ****************************************
Horse::Horse()//set the default color to GRAY and other params to 0
{
	this->m_type = 0;
}
Horse::Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type):Mammals( color, childs,avgLifetime,preg,milk)//init the Horse with a given attributes
{
	this->SetAnimal(color, childs, avgLifetime);
	Mammals::m_pregnancyTime = preg;
	Mammals::m_milkLiters = milk;
	this->SetType(type);
}
Horse::Horse(ifstream& in_file):Mammals(in_file)//init the Horse from a binary file
{
	int len;
	in_file.read((char *)&(len), sizeof(len));// the lenght of type
	this->m_type = new char[len + 1];
	in_file.read(this->m_type, len);
	this->m_type[len] = '\0';
}
Horse:: ~Horse()
{/*
	delete this->m_type;*/
}
const char*	Horse::GetType() const//return the type of the horse
{
	return this->m_type;
}
void Horse::SetType(const char * type)
{
	this->m_type = new char[strlen(type)];
	strcpy(this->m_type,type);
}
//********************************** F L A M I N G O ***************************************************
Flamingo::Flamingo(): Birds()//set the default color to GRAY and other params to 0
{
	this->SetHight(0);
}
Flamingo::Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight):Birds(color, childs, avgLifetime, incubation)//init the Flamingo with a given attributes
{
	this->SetAnimal(color, childs, avgLifetime);
	this->SetHight(avgHeight);
}
Flamingo::Flamingo(ifstream& in_file):Birds(in_file)//init the Flamingo from a binary file
{
	in_file.read((char*)&this->m_avgHeight, sizeof(this->m_avgHeight));
}
Flamingo:: ~Flamingo()
{

}
float Flamingo::GetHeight() const//return the avg height of the flamingo
{
	return this->m_avgHeight;
}
void Flamingo::SetHight(float height)
{
	this->m_avgHeight = height;
}
//********************************** M A M E L S F I S H *************************************************
MammalsFish::MammalsFish(): Mammals(), Fish()//set the default color to GRAY and other params to 0
{

}
MammalsFish::MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills):Mammals(color, childs, avgLifetime, preg, milk), Fish(color, childs, avgLifetime, fin, gills)//init the MammalsFish with a given attributes
{

}
MammalsFish::MammalsFish(ifstream& in_file): Mammals(in_file), Fish(in_file)//init the MammalsFish from a binary file
{

}
MammalsFish:: ~MammalsFish()
{

}





//****************************************** G O L D F I S H ********************************************
GoldFish::GoldFish() : MammalsFish() //set the default color to GRAY and other params to 0
{
	this->SetWeight(0);
	this->SetLength(0);
}
GoldFish::GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL):MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills)//init the GoldFish with a given attributes
{
	this->SetAnimal(color, childs, avgLifetime);
	Fish::m_finCount = fin;
	Fish::m_gillsCount = gills;
	Mammals::m_milkLiters = milk;
	Mammals::m_pregnancyTime = preg;
	this->SetWeight(avgW);
	this->SetLength(avgL);
}
GoldFish::GoldFish(ifstream& in_file):MammalsFish(in_file) //init the GoldFish from a binary file
{
	in_file.read((char*)&m_avgWeight, sizeof(m_avgWeight));
	in_file.read((char*)&m_avgLength, sizeof(m_avgLength));
}
GoldFish:: ~GoldFish()
{

}
float GoldFish::GetWeight() const//return the avg weight of the gold fish
{
	return this->m_avgWeight;

}
float GoldFish::GetLength() const//return the avg length of the gold fish
{
	return this->m_avgLength;
}
void GoldFish::SetWeight(float weight)
{
	this->m_avgWeight = weight;
}
void GoldFish::SetLength(float length)
{
	this->m_avgLength = length;
}
//************************************ M E R M A I D ***************************************************
Mermaid::Mermaid():MammalsFish()//set the default color to GRAY and other params to 0
{
	this->m_firstName = NULL;
	this->m_lastName = NULL;
}
Mermaid::Mermaid(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName) :MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills)//init the GoldFish with a given attributes
{
	this->SetAnimal(color, childs, avgLifetime);
	Mammals::m_milkLiters = milk;
	Mammals::m_pregnancyTime = preg;
	Fish::m_finCount = fin;
	Fish::m_gillsCount = gills;
	this->m_firstName = new char[strlen(firstName) + 1];
	strcpy(this->m_firstName, firstName);
	this->m_lastName = new char[strlen(lastName) + 1];
	strcpy(this->m_lastName, lastName);
}
Mermaid::Mermaid(ifstream& in_file):MammalsFish(in_file)//init the Mermaid from a binary file
{
	int lenfirst;
	in_file.read((char *)&(lenfirst), sizeof(lenfirst));// the lenght of the first name
	this->m_firstName = new char[lenfirst + 1];
	in_file.read(this->m_firstName, lenfirst);// read the first name
	this->m_firstName[lenfirst] = '\0';
	int lenlast;
	in_file.read((char *)&(lenlast), sizeof(lenlast));// the lenght of the last name
	this->m_lastName = new char[lenlast + 1];
	in_file.read(this->m_lastName, lenlast); // read the new last name
	this->m_lastName[lenlast] = '\0';
}
Mermaid:: ~Mermaid()
{
	if (this->m_firstName != NULL)
		delete[] this->m_firstName;
	if (this->m_lastName != NULL)
		delete[] this->m_lastName;
}
const char*	Mermaid::GetFirstName() const//return the first name of the mermaid
{
	return this->m_firstName;
}
const char*	Mermaid::GetLastName() const//return the last name of the mermaid
{
	return this->m_lastName;
}
void Mermaid::SetFirstName(const char* firstname)
{
	this->m_firstName = new char[strlen(firstname)];
	strcpy(this->m_firstName, firstname);
}
void Mermaid::SetLastName(const char* lastname)
{
	this->m_lastName = new char[strlen(lastname)];
	strcpy(this->m_lastName, lastname);
}

// **************************************************** Z O O *********************************************
Zoo::Zoo()//default c'tor  - all to 0 or null
{
	this->m_address = NULL;
	this->m_animals = NULL;
	this->m_closeHours = NULL;
	this->m_name = NULL;
	this->m_numOfAnimals = 0;
	this->m_openHours = NULL;
	this->m_ticketPrice = 0;
	
}
Zoo::Zoo(const char* name, const char* address, float ticket, const char* open, const char* close)//c'tor with data - init class
{
	this->m_address = new char[strlen(address)+1];
	strcpy(this->m_address, address);
	this->m_closeHours = new char[strlen(close) + 1];
	strcpy(this->m_closeHours, close);
	this->m_name = new char[strlen(name) + 1];
	strcpy(this->m_name, name);
	this->m_openHours = new char[strlen(open) + 1];
	strcpy(this->m_openHours, open);
	this->m_ticketPrice = ticket;
	this->m_numOfAnimals = 0;
}
Zoo::Zoo(ifstream& in_file)//c'tor that gets a binary file and loads the data of the zoo from the file
{
	int lename, lenadd, lenopen, lenclose, i;
	in_file.read((char *)&(lename), sizeof(lename));// the lenght of the first name
	this->m_name = new char[lename + 1];
	in_file.read(this->m_name, lename + 1);// read the first name
	this->m_name[lename] = '\0';

	in_file.read((char *)&(lenadd), sizeof(lenadd));
	this->m_address = new char[lenadd + 1];
	in_file.read(this->m_address, lenadd + 1); // read the new last name
	this->m_address[lenadd] = '\0';

	in_file.read((char*)&(this->m_ticketPrice), sizeof(this->m_ticketPrice));

	in_file.read((char *)&(lenopen), sizeof(lenopen));// the lenght of the first name
	this->m_openHours = new char[lenopen + 1];
	in_file.read(this->m_openHours, lenopen + 1);// read the first name
	this->m_openHours[lenopen] = '\0';

	in_file.read((char *)&(lenclose), sizeof(lenclose));// the lenght of the first name
	this->m_closeHours = new char[lenclose + 1];
	in_file.read(this->m_closeHours, lenclose + 1);// read the first name
	this->m_closeHours[lenclose] = '\0';

	in_file.read((char*)&(this->m_numOfAnimals), sizeof(this->m_numOfAnimals));

	this->m_animals = new Animal*[this->m_numOfAnimals];
	for (i = 0; i < this->m_numOfAnimals; i++)
	{
		char * name = NULL;
		int lenname;
		in_file.read((char*)&lenname, sizeof(lename));
		name = new char[lenname + 1];
		in_file.read(name, lenname + 1);
		name[lenname] = '\0';

		if (strcmp(name, "Horse") == 0)// if this animal is HORSE
		{
			char * color = NULL;
			int lencolor;
			in_file.read((char*)&lencolor, sizeof(lencolor));
			if (color != NULL)
				delete[] color;
			color = new char[lencolor + 1];
			in_file.read(color, lencolor + 1);
			color[lencolor] = '\0';

			int childs;
			in_file.read((char*)&childs, sizeof(childs));

			float avglifet;
			in_file.read((char*)&avglifet, sizeof(avglifet));

			float preg;
			in_file.read((char*)&preg, sizeof(preg));

			float milk;
			in_file.read((char*)&milk, sizeof(milk));

			char * type = NULL;
			int lentype;
			in_file.read((char*)&lentype, sizeof(lentype));
			if (type != NULL)
				delete[] type;
			type = new char[lentype + 1];
			in_file.read(type, lentype + 1);
			type[lentype] = '\0';
			this->m_animals[i] = new Horse(color, childs, avglifet, preg, milk, type);
		}

		else if (strcmp(name, "Flamingo") == 0)// if this animal is FLAMINGO
		{
			char * color = NULL;
			int sizecolor;
			in_file.read((char*)&(sizecolor), sizeof(sizecolor));
			if (name != NULL)
				delete[] name;
			color = new char[sizecolor + 1];
			
				in_file.read(color, sizecolor + 1);
			color[sizecolor] = '\0';

			int childs;
			in_file.read((char*)&childs, sizeof(childs));

			float avglifet;
			in_file.read((char*)&(avglifet), sizeof(avglifet));

			float incub;
			in_file.read((char*)&incub, sizeof(incub));

			float avgHeight;
			in_file.read((char*)&avgHeight, sizeof(avgHeight));

			this->m_animals[i] = new Flamingo(color, childs, avglifet, incub, avgHeight);
		}

		else if (strcmp(name, "GoldFish") == 0)// if this animal is GoldFish
		{
			char * color = NULL;
			int lencolor;
			in_file.read((char*)&lencolor, sizeof(lencolor));
			if (name != NULL)
				delete[] name;
			color = new char[lencolor + 1];
			in_file.read(color, lencolor + 1);
			color[lencolor] = '\0';

			int childs;
			in_file.read((char*)&childs, sizeof(childs));

			float avglifet;
			in_file.read((char*)&avglifet, sizeof(avglifet));

			float preg;
			in_file.read((char*)&preg, sizeof(preg));

			float milk;
			in_file.read((char*)&milk, sizeof(milk));

			int fincount;
			in_file.read((char*)&fincount, sizeof(fincount));

			int gillscount;
			in_file.read((char*)&gillscount, sizeof(gillscount));

			float avgweight;
			in_file.read((char*)&avgweight, sizeof(avgweight));

			float avglen;
			in_file.read((char*)&avglen, sizeof(avglen));

			this->m_animals[i] = new GoldFish(color, childs, avglifet, preg, milk, fincount, gillscount, avgweight, avglen);
		}

		else if (strcmp(name, "Mermaid") == 0)// if this animal is Mermaid
		{
			int childs, preg, milk, fin, count;
			float lifetime;

			char * color = NULL;
			int lencolor;
			in_file.read((char*)&lencolor, sizeof(lencolor));
			if (name != NULL)
				delete[] name;
			color = new char[lencolor + 1];
			in_file.read(color, lencolor + 1);
			color[lencolor] = '\0';

			in_file >> childs;
			in_file >> lifetime;
			in_file >> preg;
			in_file >> milk;
			in_file >> fin;
			in_file >> count;
			//int childs;
			//in_file.read((char*)&childs, sizeof(childs));// הוספתי כאן +1
			//
			//float avglifet;
			//in_file.read((char*)&avglifet, sizeof(avglifet));// גם כאן
			//
			//float preg;
			//in_file.read((char*)&preg, sizeof(preg));
			//
			//float milk;
			//in_file.read((char*)&milk, sizeof(milk));
			//
			//int fincount;
			//in_file.read((char*)&fincount, sizeof(fincount));
			//
			//int gillscount;
			//in_file.read((char*)&gillscount, sizeof(gillscount));

			char * firstname = NULL;
			int lenfirst;
			in_file.read((char*)&lenfirst, sizeof(lenfirst));
			if (firstname != NULL)
				delete[] firstname;
			firstname = new char[lenfirst + 1];
			in_file.read(firstname, lenfirst + 1);
			firstname[lenfirst] = '\0';

			char * lastname = NULL;
			int lenlast;
			in_file.read((char*)&lenlast, sizeof(lenlast));
			if (lastname != NULL)
				delete[] lastname;
			lastname = new char[lenlast + 1];
			in_file.read(lastname, lenlast + 1);
			lastname[lenlast] = '\0';

			this->m_animals[i] = new Mermaid(color, childs, lifetime, preg, milk, fin, count, firstname, lastname);
		}
	}
}
Zoo:: ~Zoo()//d'tor
{
	/*delete this->m_address;
	delete this->m_closeHours;
	delete this->m_openHours;
	delete this->m_name;
	delete[] this->m_animals; */// לחזורררררררררררררררררררררררררררררררררר
	
}
const char*	Zoo::GetName() const//return the name of the zoo
{
	return this->m_name;
}
const char*	Zoo::GetAddress() const//return the address of the zoo
{
	return this->m_address;
}
float Zoo::GetTicketPrice() const//return the ticket price of the zoo
{
	return this->m_ticketPrice;
}
const char*	Zoo::GetOpenHour() const//return the open hour of the zoo
{
	return this->m_openHours;
}
const char*	Zoo::GetCloseHour() const//return the close hour of the zoo
{
	return this->m_closeHours;
}
int	Zoo::GetNumOfAnimals() const//return the num of animals in the zoo
{
	return this->m_numOfAnimals;
}
Animal** Zoo::GetAnimals() const//return the animals array of the zoo
{
	return this->m_animals;
}

void Zoo::SetName1(const char * name)
{
	this->m_name = new char[strlen(name) + 1];
	strcpy(this->m_name, name);
}

void Zoo::SetAdress1(const char * add)
{
	this->m_address = new char[strlen(add) + 1];
	strcpy(this->m_address, add);
}

void Zoo::Setticket1(float ticket)
{
	this->m_ticketPrice = ticket;
}

void Zoo::Setopen1(const char * open)
{
	this->m_openHours = new char[strlen(open) + 1];
	strcpy(this->m_openHours, open);
}

void Zoo::Setclose1(const char * close)
{
	this->m_closeHours = new char[strlen(close) + 1];
	strcpy(this->m_closeHours, close);
}

void Zoo::Setnumofanimals1(int num)
{
	this->m_numOfAnimals = num;
}
void Zoo::AddAnimal(Animal* an)//creates a copy of "an" (deep copy) and adds an animal to the array
{
	
	Animal ** temp;
	temp= new Animal*[this->m_numOfAnimals + 1];
	for (int i = 0; i < this->m_numOfAnimals; i++)
		temp[i] = this->m_animals[i]; 
	if(m_numOfAnimals!=0)
	delete[] this->m_animals;
	this->m_animals = temp;

	
	Horse* h = dynamic_cast<Horse*>(an);
	if (h)
		this->m_animals[m_numOfAnimals] = new Horse(h->GetColor(),h->GetChildCount(), h->GetLifetime(),h->GetPregnanceTime(), h->GetMilk(), h->GetType());

	Flamingo* f = dynamic_cast<Flamingo*>(an);
	if (f)
		this->m_animals[m_numOfAnimals] = new Flamingo(f->GetColor(), f->GetChildCount(), f->GetLifetime(), f->GetIncubationTime(), f->GetHeight());

	GoldFish* g = dynamic_cast<GoldFish*>(an);
	if (g)
		this->m_animals[m_numOfAnimals] = new GoldFish(g->GetColor(), g->GetChildCount(), g->GetLifetime(), g->GetPregnanceTime(), g->GetMilk(), g->GetFinCount(), g->GetGillsCount(), g->GetWeight(), g->GetLength());

	Mermaid* m = dynamic_cast<Mermaid*>(an);
	if (m)
		this->m_animals[m_numOfAnimals] = new Mermaid(m->GetColor(), m->GetChildCount(), m->GetLifetime(), m->GetPregnanceTime(), m->GetMilk(), m->GetFinCount(), m->GetGillsCount(), m->GetFirstName(), m->GetLastName());
	this->m_numOfAnimals++;
}
Zoo& Zoo::operator+(Animal* an)//adds an animal (only pointer, no copy needed) to the class and returns this with the change
{
	AddAnimal(an);
	return *(this);
}
Zoo Zoo::operator+(const Zoo& other) const //returns a new Zoo with the properties of this and animals of this and other (need to deep copy the data of other)
{
	Zoo z;
	int size = this->GetNumOfAnimals() + other.GetNumOfAnimals();
	z.SetName1(this->GetName());
	z.SetAdress1(this->GetAddress());
	z.Setticket1(this->GetTicketPrice());
	z.Setnumofanimals1(size);
	z.Setopen1(this->GetOpenHour());
	z.Setclose1(this->GetCloseHour());
	z.m_animals = new Animal*[size];
	for (int i = 0; i < this->GetNumOfAnimals(); i++)
	{
		Horse* h = dynamic_cast<Horse*>(this->m_animals[i]); // if this an is type of HORSE*
		if (h)
			z.m_animals[i] = new Horse(h->GetColor(), h->GetChildCount(), h->GetLifetime(), h->GetPregnanceTime(), h->GetMilk(), h->GetType());

		Flamingo* f = dynamic_cast<Flamingo*>(this->m_animals[i]); // if this an is type of Flamingo*
		if (f)
			z.m_animals[i] = new Flamingo(f->GetColor(), f->GetChildCount(), f->GetLifetime(), f->GetIncubationTime(), f->GetHeight());

		GoldFish* g = dynamic_cast<GoldFish*>(this->m_animals[i]); // if this an is type of GOLDFISH*
		if (g)
			z.m_animals[i] = new GoldFish(g->GetColor(), g->GetChildCount(), g->GetLifetime(), g->GetPregnanceTime(), g->GetMilk(), g->GetFinCount(), g->GetGillsCount(), g->GetWeight(), g->GetLength());

		Mermaid* m = dynamic_cast<Mermaid*>(this->m_animals[i]);// if this an is type of Mermaid*
		if (m)
			z.m_animals[i] = new Mermaid(m->GetColor(), m->GetChildCount(), m->GetLifetime(), m->GetPregnanceTime(), m->GetMilk(), m->GetFinCount(), m->GetGillsCount(), m->GetFirstName(), m->GetLastName());
	}
	int k = 0;
	for (int j = this->GetNumOfAnimals(); j < size; k++, j++)
	{
		Horse* h = dynamic_cast<Horse*>(other.m_animals[k]); // if this an is type of HORSE*
		if (h)
			z.m_animals[j] = new Horse(h->GetColor(), h->GetChildCount(), h->GetLifetime(), h->GetPregnanceTime(), h->GetMilk(), h->GetType());

		Flamingo* f = dynamic_cast<Flamingo*>(other.m_animals[k]); // if this an is type of Flamingo*
		if (f)
			z.m_animals[j] = new Flamingo(f->GetColor(), f->GetChildCount(), f->GetLifetime(), f->GetIncubationTime(), f->GetHeight());

		GoldFish* g = dynamic_cast<GoldFish*>(other.m_animals[k]); // if this an is type of GOLDFISH*
		if (g)
			z.m_animals[j] = new GoldFish(g->GetColor(), g->GetChildCount(), g->GetLifetime(), g->GetPregnanceTime(), g->GetMilk(), g->GetFinCount(), g->GetGillsCount(), g->GetWeight(), g->GetLength());

		Mermaid* m = dynamic_cast<Mermaid*>(other.m_animals[k]);// if this an is type of Mermaid*
		if (m)
			z.m_animals[j] = new Mermaid(m->GetColor(), m->GetChildCount(), m->GetLifetime(), m->GetPregnanceTime(), m->GetMilk(), m->GetFinCount(), m->GetGillsCount(), m->GetFirstName(), m->GetLastName());
	}
	return z;

}
// ofstream& operator<<(ofstream& out, const Zoo& z)//operator to write the zoo to a text file
// { 
//	 
//	 out << strlen(z.GetName());
//	 out << (z.GetName());
//	 out << strlen(z.GetAddress());
//	 out << z.GetAddress();
//	 out << z.GetTicketPrice();
//	 out << strlen(z.GetOpenHour());
//	 out << z.GetOpenHour();
//	 out << strlen(z.GetCloseHour());
//	 out << z.GetCloseHour();
//	 out << z.m_numOfAnimals;
//	 
//
// }
//ifstream& operator>>(ifstream& in, Zoo& z)//operator to read the zoo from a text file
//{
//	
//	int size;
//	in >> size ;
//	z.m_name = new char[size + 1];
//	in >> z.m_name;
//	in >> size;
//	z.m_address = new char[size + 1];
//	in >> z.m_address;
//	in >> z.m_ticketPrice;
//    in >> size;
//	z.m_openHours = new char[size + 1];
//	in >> z.m_openHours;
//	in >> size;
//	z.m_closeHours = new char[size + 1];
//	in >> z.m_closeHours;
//	in >> z.m_numOfAnimals;
//	
//}
void Zoo::Save(ofstream& ofs) const//method to save the info to a text file
{
	
	ofs << strlen(this->m_name) << endl;
	ofs << this->m_name << endl;

	ofs << strlen(this->m_address) << endl;
	ofs << this->m_address << endl;

	ofs << this->m_ticketPrice << endl;

	ofs << strlen(this->m_openHours) << endl;
	ofs << this->m_openHours << endl;

	ofs << strlen(this->m_closeHours) << endl;
	ofs << this->m_closeHours << endl;

	ofs << this->m_numOfAnimals << endl;
	for (int i = 0; i < this->GetNumOfAnimals(); i++)
	{
		Horse* h = dynamic_cast<Horse*>(this->m_animals[i]);
		if (h)
		{
			ofs << strlen("Horse") << endl;
			ofs << "Horse" << endl;
			ofs << strlen(h->GetColor()) << endl;
			ofs << h->GetColor() << endl;
			ofs << h->GetChildCount() << endl;
			ofs << h->GetLifetime() << endl;
			ofs << h->GetPregnanceTime() << endl;
			ofs << h->GetMilk() << endl;
			ofs << strlen(h->GetType()) << endl;
			ofs << h->GetType() << endl;
		}
		Flamingo* f = dynamic_cast<Flamingo*>(this->m_animals[i]);
		if (f)
		{
			ofs << strlen("Flamingo") << endl;
			ofs << "Flamingo" << endl;
			ofs << strlen(f->GetColor()) << endl;
			ofs << f->GetColor() << endl;
			ofs << f->GetChildCount() << endl;
			ofs << f->GetLifetime() << endl;
			ofs << f->GetIncubationTime() << endl;
			ofs << f->GetHeight() << endl;
		}

		GoldFish* g = dynamic_cast<GoldFish*>(this->m_animals[i]);
		if (g)
		{
			ofs << strlen("GoldFish") << endl;
			ofs << "GoldFish" << endl;
			ofs << strlen(g->GetColor()) << endl;
			ofs << g->GetColor() << endl;
			ofs << g->GetChildCount() << endl;
			ofs << g->GetLifetime() << endl;
			ofs << g->GetPregnanceTime() << endl;
			ofs << g->GetMilk() << endl;
			ofs << g->GetFinCount() << endl;
			ofs << g->GetGillsCount() << endl;
			ofs << g->GetWeight() << endl;
			ofs << g->GetLength() << endl;
		}

		Mermaid* m = dynamic_cast<Mermaid*>(this->m_animals[i]);
		if (m)
		{
			ofs << strlen("Mermaid") << endl;
			ofs << "Mermaid" << endl;
			ofs << strlen(m->GetColor()) << endl;
			ofs << m->GetColor() << endl;
			ofs << m->GetChildCount() << endl;
			ofs << m->GetLifetime() << endl;
			ofs << m->GetPregnanceTime() << endl;
			ofs << m->GetMilk() << endl;
			ofs << m->GetFinCount() << endl;
			ofs << m->GetGillsCount() << endl;
			ofs << strlen(m->GetFirstName()) << endl;
			ofs << m->GetFirstName() << endl;
			ofs << strlen(m->GetLastName()) << endl;
			ofs << m->GetLastName() << endl;
		}
	}
	
}
void Zoo::Load(ifstream& ifs)//method to load the info from a text file
{
	int lenname;
	ifs >> lenname;
	this->m_name = new char[lenname + 1];
	ifs.read(this->m_name, lenname + 1);// הוספתי כאן +1
	this->m_name[lenname] = '\0';
	if (this->m_name[0] == '\n')
		this->m_name = CleanName(this->m_name);

	int lenadd;
	ifs >> lenadd;
	this->m_address = new char[lenadd + 1];
	ifs.read(this->m_address, lenadd + 1);//
	this->m_address[lenadd] = '\0';
	if (this->m_address[0] == '\n')
		this->m_address = CleanName(this->m_address);

	ifs >> this->m_ticketPrice;

	int lenopen;
	ifs >> lenopen;
	this->m_openHours = new char[lenopen + 1];
	ifs.read(this->m_openHours, lenopen + 1);//
	this->m_openHours[lenopen] = '\0';


	int lenclose;
	ifs >> lenclose;
	this->m_closeHours = new char[lenclose + 1];
	ifs.read(this->m_closeHours, lenclose + 1);//
	this->m_closeHours[lenclose] = '\0';

	ifs >> this->m_numOfAnimals;

	this->m_animals = new Animal*[this->m_numOfAnimals];

	for (int i = 0; i < this->GetNumOfAnimals(); i++)
	{
		char* newname = NULL;
		int lenname1;
		ifs >> lenname1;
		newname = new char[lenname1 + 1];
		ifs >> newname;

		if (strcmp(newname, "Horse") == 0)
		{
			char* color = NULL;
			int lencolor;
			ifs >> lencolor;
			color = new char[lencolor + 1];
			ifs >> color;

			int childs;
			ifs >> childs;

			float avglife;
			ifs >> avglife;

			float preg;
			ifs >> preg;

			float milk;
			ifs >> milk;

			char* type = NULL;
			int lentype;
			ifs >> lentype;
			type = new char[lentype + 1];
			ifs.read(type, lentype + 1);
			type[lentype] = '\0';

			this->m_animals[i] = new Horse(color, childs, avglife, preg, milk, type);
		}

		if (strcmp(newname, "Flamingo") == 0)
		{
			char* color = NULL;
			int lencolor;
			ifs >> lencolor;
			color = new char[lencolor + 1];
			ifs >> color;
			color[lencolor] = '\0';

			int childs;
			ifs >> childs;

			float avglife;
			ifs >> avglife;

			float incub;
			ifs >> incub;

			float height;
			ifs >> height;

			this->m_animals[i] = new Flamingo(color, childs, avglife, incub, height);
		}

		if (strcmp(newname, "GoldFish") == 0)
		{
			char* color = NULL;
			int lencolor;
			ifs >> lencolor;
			color = new char[lencolor + 1];
			ifs >> color;
			color[lencolor] = '\0';

			int childs;
			ifs >> childs;

			float avglife;
			ifs >> avglife;

			float preg;
			ifs >> preg;

			float milk;
			ifs >> milk;

			int fin;
			ifs >> fin;

			int gill;
			ifs >> gill;

			float avgw;
			ifs >> avgw;

			float avgh;
			ifs >> avgh;

			this->m_animals[i] = new GoldFish(color, childs, avglife, preg, milk, fin, gill, avgw, avgh);
		}


		if (strcmp(newname, "Mermaid") == 0)
		{
			char* color = NULL;
			int lencolor;
			ifs >> lencolor;
			color = new char[lencolor + 1];
			ifs >> color;
			color[lencolor] = '\0';

			int childs;
			ifs >> childs;

			float avglife;
			ifs >> avglife;

			float preg;
			ifs >> preg;

			float milk;
			ifs >> milk;

			int fin;
			ifs >> fin;

			int gill;
			ifs >> gill;

			char* firstname = NULL;
			int firstsize;
			ifs >> firstsize;
			firstname = new char[firstsize];
			ifs >> firstname;

			char* lastname = NULL;
			int lastsize;
			ifs >> lastsize;
			lastname = new char[lastsize];
			ifs >> lastname;

			this->m_animals[i] = new Mermaid(color, childs, avglife, preg, milk, fin, gill, firstname, lastname);
		}
	}
	
}
void Zoo::SaveBin(ofstream& ofs) const//method to save the info to a binary file
{
	int sizename = strlen(this->m_name);
	ofs.write((char*)&sizename, sizeof(sizename));
	ofs.write(this->m_name, sizename) << endl;

	int lenadd = strlen(this->m_address);
	ofs.write((char*)&lenadd, sizeof(lenadd));
	ofs.write(this->m_address, lenadd) << endl;

	ofs.write((char*)&this->m_ticketPrice, sizeof(this->m_ticketPrice));

	int open = strlen(this->m_openHours);
	ofs.write((char*)&open, sizeof(open));
	ofs.write(this->m_openHours, open) << endl;

	int closezise = strlen(this->m_closeHours);
	ofs.write((char*)&closezise, sizeof(closezise));
	ofs.write(this->m_closeHours, closezise) << endl;

	ofs.write((char*)&this->m_numOfAnimals, sizeof(this->m_numOfAnimals));

	for (int i = 0; i < this->m_numOfAnimals; i++)
	{
		Horse* h = dynamic_cast<Horse*> (this->m_animals[i]);
		if (h)
		{
			int lenname = strlen("Horse");
			ofs.write((char*)&lenname, sizeof(lenname));
			ofs.write("Horse", lenname) << endl;

			int lencolor = strlen(h->GetColor());
			ofs.write((char*)&lencolor, sizeof(lencolor));
			ofs.write(h->GetColor(), lencolor) << endl;

			int childs = h->GetChildCount();
			ofs.write((char*)&childs, sizeof(childs));//

			float avglife = h->GetLifetime();
			ofs.write((char*)&avglife, sizeof(avglife));//

			float preg = h->GetPregnanceTime();
			ofs.write((char*)&preg, sizeof(preg));//

			float milk = h->GetMilk();
			ofs.write((char*)&milk, sizeof(milk));

			int sizetype = strlen(h->GetType());
			ofs.write((char*)&sizetype, sizeof(sizetype + 1));
			ofs.write(h->GetType(), sizetype + 1);
		}

		Flamingo* f = dynamic_cast<Flamingo*>(this->m_animals[i]);
		if (f)
		{
			int lenname = strlen("Flamingo");
			ofs.write((char*)&lenname, sizeof(lenname));
			ofs.write("Flamingo", lenname) << endl;

			int lencolor = strlen(f->GetColor());
			ofs.write((char*)&(lencolor), sizeof(lencolor));
			ofs.write(f->GetColor(), lencolor) << endl;

			int childs = f->GetChildCount();
			ofs.write((char*)&childs, sizeof(childs));// מחקתי ירידת שורה

			float avglife = f->GetLifetime();
			ofs.write((char*)&avglife, sizeof(avglife));//

			float incub = f->GetIncubationTime();
			ofs.write((char*)&incub, sizeof(incub));//

			float height = f->GetHeight();
			ofs.write((char*)&height, sizeof(height));//
		}

		GoldFish* g = dynamic_cast<GoldFish*>(this->m_animals[i]);
		if (g)
		{
			int lenname = strlen("GoldFish");
			ofs.write((char*)&lenname, sizeof(lenname));
			ofs.write("GoldFish", lenname) << endl;

			int lencolor = strlen(g->GetColor());
			ofs.write((char*)&lencolor, sizeof(lencolor));
			ofs.write(g->GetColor(), lencolor) << endl;

			int childs = g->GetChildCount();
			ofs.write((char*)&childs, sizeof(childs));//

			float avglife = g->GetLifetime();
			ofs.write((char*)&avglife, sizeof(avglife));

			float preg = g->GetPregnanceTime();
			ofs.write((char*)&preg, sizeof(preg));//

			float milk = g->GetMilk();
			ofs.write((char*)&milk, sizeof(milk));//

			int fins = g->GetFinCount();
			ofs.write((char*)&fins, sizeof(fins));//

			int gills = g->GetGillsCount();
			ofs.write((char*)&gills, sizeof(gills));//

			float weight = g->GetWeight();
			ofs.write((char*)&weight, sizeof(weight));//

			float length = g->GetLength();
			ofs.write((char*)&length, sizeof(length));//
		}

		Mermaid* m = dynamic_cast<Mermaid*>(this->m_animals[i]);
		if (m)
		{
			int lenname = strlen("Mermaid");
			ofs.write((char*)&lenname, sizeof(lenname));
			ofs.write("Mermaid", lenname) << endl;/////////// הוספתי לכולם +1

			int lencolor = strlen(m->GetColor());
			ofs.write((char*)&lencolor, sizeof(lencolor));
			ofs.write(m->GetColor(), lencolor) << endl;

			ofs << m->GetChildCount() << endl;
			ofs << m->GetLifetime() << endl;
			ofs << m->GetPregnanceTime() << endl;
			ofs << m->GetMilk() << endl;
			ofs << m->GetFinCount() << endl;
			ofs << m->GetGillsCount();

			int firstname = strlen(m->GetFirstName());
			ofs.write((char*)&firstname, sizeof(firstname));
			ofs.write(m->GetFirstName(), firstname) << endl;

			int lastname = strlen(m->GetLastName());
			ofs.write((char*)&lastname, sizeof(lastname));
			ofs.write(m->GetLastName(), lastname) << endl;
		}
	}
	
}
Zoo& Zoo::operator+=(Animal* newanimal)
{
	Animal** temp = new Animal*[this->GetNumOfAnimals() + 1];
	for (int i = 0; i < this->GetNumOfAnimals(); i++)
		temp[i] = this->m_animals[i];
	delete[] this->m_animals;
	this->m_animals = temp;
	this->m_animals[this->m_numOfAnimals] = newanimal;
	this->m_numOfAnimals++;
	return *(this);
}
ofstream& operator<<(ofstream& out, const Zoo& z)
{
	out << strlen(z.GetName()) << endl;
	out << z.GetName() << endl;

	out << strlen(z.GetAddress()) << endl;
	out << z.GetAddress() << endl;

	out << z.GetTicketPrice() << endl;

	out << strlen(z.GetOpenHour()) << endl;
	out << z.GetOpenHour() << endl;

	out << strlen(z.GetCloseHour()) << endl;
	out << z.GetCloseHour() << endl;

	out << z.m_numOfAnimals << endl;

	for (int i = 0; i < z.m_numOfAnimals; i++)
	{
		Horse* h = dynamic_cast<Horse*>(z.m_animals[i]);
		if (h)
		{
			out << strlen("Horse") << endl;
			out << "Horse" << endl;
			out << strlen(h->GetColor()) << endl;
			out << h->GetColor() << endl;
			out << h->GetChildCount() << endl;
			out << h->GetLifetime() << endl;
			out << h->GetPregnanceTime() << endl;
			out << h->GetMilk() << endl;
			out << strlen(h->GetType()) << endl;
			out << h->GetType() << endl;
		}
		Flamingo* f = dynamic_cast<Flamingo*>(z.m_animals[i]);
		if (f)
		{
			out << strlen("Flamingo") << endl;
			out << "Flamingo" << endl;
			out << strlen(f->GetColor()) << endl;
			out << f->GetColor() << endl;
			out << f->GetChildCount() << endl;
			out << f->GetLifetime() << endl;
			out << f->GetIncubationTime() << endl;
			out << f->GetHeight() << endl;
		}

		GoldFish* g = dynamic_cast<GoldFish*>(z.m_animals[i]);
		if (g)
		{
			out << strlen("GoldFish") << endl;
			out << "GoldFish" << endl;
			out << strlen(h->GetColor()) << endl;
			out << g->GetColor() << endl;
			out << g->GetChildCount() << endl;
			out << g->GetLifetime() << endl;
			out << g->GetPregnanceTime() << endl;
			out << g->GetMilk() << endl;
			out << g->GetFinCount() << endl;
			out << g->GetGillsCount() << endl;
			out << g->GetWeight() << endl;
			out << g->GetLength() << endl;
		}

		Mermaid* m = dynamic_cast<Mermaid*>(z.m_animals[i]);
		if (m)
		{
			out << strlen("Mermaid") << endl;
			out << "Mermaid" << endl;
			out << strlen(m->GetColor()) << endl;
			out << m->GetColor() << endl;
			out << m->GetChildCount() << endl;
			out << m->GetLifetime() << endl;
			out << m->GetPregnanceTime() << endl;
			out << m->GetMilk() << endl;
			out << m->GetFinCount() << endl;
			out << m->GetGillsCount() << endl;
			out << strlen(m->GetFirstName()) << endl;
			out << m->GetFirstName() << endl;
			out << strlen(m->GetLastName()) << endl;
			out << m->GetLastName() << endl;
		}
	}
	return out;
}
ifstream& operator>>(ifstream& in, Zoo& z)
{
	int lenname;
	in >> lenname;
	z.m_name = new char[lenname + 1];
	in.read(z.m_name, lenname + 1);
	z.m_name[lenname + 1] = '\0';
	if (z.m_name[0] == '\n')
	z.m_name = z.CleanName(z.m_name);

	int lenadd;
	in >> lenadd;
	z.m_address = new char[lenadd + 2];
	in.read(z.m_address, lenadd + 2);
	z.m_address[lenadd + 1] = '\0';// שינית הכל, הורדתי 1 במיקום
	if (z.m_address[0] == '\n')
		z.m_address = z.CleanName(z.m_address);

	in >> z.m_ticketPrice;

	int lenopen;
	in >> lenopen;
	z.m_openHours = new char[lenopen + 1];
	in.read(z.m_openHours, lenopen + 1);
	z.m_openHours[lenopen + 1] = '\0';
	z.m_openHours = z.CleanName(z.m_openHours);

	int lenclose;
	in >> lenclose;
	z.m_closeHours = new char[lenclose + 1];
	in.read(z.m_closeHours, lenclose + 1);
	z.m_closeHours[lenclose + 1] = '\0';
	z.m_closeHours = z.CleanName(z.m_closeHours);

	in >> z.m_numOfAnimals;

	z.m_animals = new Animal*[z.m_numOfAnimals];
	for (int i = 0; i < z.GetNumOfAnimals(); i++)
	{
		char* newname = NULL;
		int lenname1;
		in >> lenname1;
		newname = new char[lenname1 + 1];
		in >> newname;
		if (strcmp(newname, "Horse") == 0)
		{
			char* color = NULL;
			int lencolor;
			in >> lencolor;
			color = new char[lencolor + 1];
			in >> color;

			int childs;
			in >> childs;

			float avglife;
			in >> avglife;

			float preg;
			in >> preg;

			float milk;
			in >> milk;

			char* type = NULL;
			int lentype;
			in >> lentype;
			type = new char[lentype + 1];
			in.read(type, lentype + 1);
			type[lentype + 1] = '\0';
			type = z.CleanName(type);

			z.m_animals[i] = new Horse(color, childs, avglife, preg, milk, type);
		}

		if (strcmp(newname, "Flamingo") == 0)
		{
			char* color = NULL;
			int lencolor;
			in >> lencolor;
			color = new char[lencolor + 1];
			in >> color;

			int childs;
			in >> childs;

			float avglife;
			in >> avglife;

			float incub;
			in >> incub;

			float height;
			in >> height;

			z.m_animals[i] = new Flamingo(color, childs, avglife, incub, height);
		}

		if (strcmp(newname, "GoldFish") == 0)
		{
			char* color = NULL;
			int lencolor;
			in >> lencolor;
			color = new char[lencolor + 1];
			in >> color;

			int childs;
			in >> childs;

			float avglife;
			in >> avglife;

			float preg;
			in >> preg;

			float milk;
			in >> milk;

			int fin;
			in >> fin;

			int gill;
			in >> gill;

			float avgw;
			in >> avgw;

			float avgh;
			in >> avgh;

			z.m_animals[i] = new GoldFish(color, childs, avglife, preg, milk, fin, gill, avgw, avgh);
		}


		if (strcmp(newname, "Mermaid") == 0)
		{
			char* color = NULL;
			int lencolor;
			in >> lencolor;
			color = new char[lencolor + 1];
			in >> color;

			int childs;
			in >> childs;

			float avglife;
			in >> avglife;

			float preg;
			in >> preg;

			float milk;
			in >> milk;

			int fin;
			in >> fin;

			int gill;
			in >> gill;

			char* firstname = NULL;
			int firstsize;
			in >> firstsize;
			firstname = new char[firstsize + 1];
			in >> firstname;

			char* lastname = NULL;
			int lastsize;
			in >> lastsize;
			lastname = new char[lastsize + 1];
			in >> lastname;

			z.m_animals[i] = new Mermaid(color, childs, avglife, preg, milk, fin, gill, firstname, lastname);
		}
	}
	return in;
}
void Zoo::LoadAnmialBin(ifstream& is)
{
	is.read((char*)&this->m_numOfAnimals, sizeof(m_numOfAnimals));

	// allocate memory for products.
	this->m_animals = new Animal*[this->m_numOfAnimals];

	for (unsigned int i = 0; i < m_numOfAnimals && !is.eof(); ++i)
	{
		Animal* p = CreateAnimalBin(is);  // Creates a new product, identify its type in running time.

		this->m_animals[i] = p;
	}

}
Animal* Zoo::CreateAnimalBin(ifstream& in_file)
{
	char type[3] = { 0 };

	// read type to construct
	in_file.read((char*)type, 2);

	// construct the appropriate object
	if (strncmp(type, "Horse", 2) == 0)
	{
		return new Horse(in_file);
	}
	else if (strncmp(type, "Birds", 2) == 0)
	{
		return new Birds(in_file);
	}
	else if (strncmp(type, "Flamingo", 2) == 0)
	{
		return new Flamingo(in_file);
	}
	else if (strncmp(type, "GoldFish", 2) == 0)
	{
		return new GoldFish(in_file);
	}
	else if (strncmp(type, "Mermaid", 2) == 0)
	{
		return new Mermaid(in_file);
	}

	else return NULL;
}

char * Zoo:: CleanName(char * name)
{
	char* temp = NULL;
	temp = new char[strlen(name)];
	for (int i = 0; i < strlen(name); i++)
	{
		temp[i] = name[i + 1];
	}

	return temp;
}
