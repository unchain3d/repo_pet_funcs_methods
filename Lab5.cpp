#include <iostream>
#include <vector>

using namespace std;

enum Kind {
	cat,
	dog,
	bird,
	hamster
};


class Pet {
public:
	Pet() {

	}

	Pet(string name, string breed, int age, string greeting, int mass, Kind petType) {
		this->name = name;
		this->breed = breed;
		this->age = age;
		this->greeting = greeting;
		this->mass = mass;
		this->petType = petType;
	}

	~Pet() {

	}

	string getName() {
		return name;
	}

	string getBreed() {
		return breed;
	}

	int getAge() {
		return age;
	}

	string getGreeting() {
		return greeting;
	}

	int getMass() {
		return mass;
	}

	Kind getPetType() {
		return petType;
	}

	bool isPolite() {
		return greeting.find("Hello") != string::npos;
		// ::npos is a constant static number with the highest possible value
	}

private:
	string name;
	string breed;
	int age;
	string greeting;
	int mass;
	Kind petType;
	
};


class Home {
public:
	Home() {

	}

	Home(string Name, vector<Pet> animals) {
		this->Name = Name;
		this->animals = animals;
	}

	~Home() {

	}

	string getName() {
		return Name;
	}

	vector<Pet> getAnimals() {
		return animals;
	}

private:
	string Name; 
	vector<Pet> animals;

};

void selectionSort(vector<Pet> animals) {
	// sorting from lowest to highest (by age)
	int j, minIndex;
	for (int i = 0; i < animals.size(); i++) {
		minIndex = i;
		for (j = i + 1; j < animals.size(); j++) {
			if (animals[j].getAge() < animals[minIndex].getAge()) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			Pet temp = animals[i];
			animals[i] = animals[minIndex];
			animals[minIndex] = temp;
		}
	}
}

void printAnimals(vector<Pet> animals) {
	for (int i = 0; i < animals.size(); i++) {
		cout << animals[i].getAge() << " ";
	}
	cout << endl;
}

void areFriends(vector<Pet> animals) {
	for (int i = 0; i < animals.size(); i++) {
		for (int j = 0; j < animals.size(); j++) {
			int difference = animals[i].getAge() - animals[j].getAge();
			if (i != j && difference <= 2 && difference >= 0) {
				cout << animals[i].getName() << " and " << animals[j].getName() << endl;
			}
		}
	}
}

int main() {

	Pet animal1 = Pet("Chunk", "x", 3, "Hello", 8, dog);
	Pet animal2 = Pet("Cloud", "y", 5, "Meow", 3, cat);
	Pet animal3 = Pet("David", "z", 1, "Hello, X", 3, hamster);
	
	cout << animal1.getName() << animal1.isPolite() << endl;
	cout << animal2.getName() << animal2.isPolite() << endl;
	cout << animal3.getName() << animal3.isPolite() << endl;

	vector<Pet> anim = { animal1, animal2, animal3 };
	
	// anim is the name of a dynamic array (vector) 
	
	printAnimals(anim);
	selectionSort(anim); 
	printAnimals(anim);

	areFriends(anim);

	Home home = Home("My Home", anim);
}


