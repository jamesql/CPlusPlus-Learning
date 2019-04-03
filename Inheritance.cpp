#include <iostream>
#include "list"

using namespace std;

// Declaring Structs
struct Parent;
struct Child;
struct Family;

// Animal and Pet Structs
struct Dog;
struct Cat;

// Person Object - almost all of our objects will be build off of this
struct Person {
  public:
  string name;
  int age;
  // used to pass onto children
  string toString;

  // Constructor
  Person(string nm, int page) :
  name(nm), age(page)  {}
};

  struct Animal {
    public:
      string name;
      int age;
      string toString;

      Animal(string nm,int page) :
      name(nm), age(page), toString("[Animal : " + nm + " - " + to_string(age) + "]")        {}
  };

  struct Pet : Animal {
    public:
      string breed;

      Pet(string nm, int page, string breedd):
      Animal(nm,page), breed(breedd)   { toString = "[Pet : " + name + " - " + to_string(age) + " ( " + breed + " )]";}

  };

  struct Dog : Pet {
  public:
    string favoritetoy;

    Dog(string nm, int page, string breed, string favtoy) :
    Pet(nm,page,breed), favoritetoy(favtoy) {toString = "[Dog : " + name + " - " + to_string(age) + " ( " + breed + " ), ( "+ favoritetoy +" )]";}
  };

  struct Cat : Pet {
  public:
    string favoritetoy;

    Cat(string nm, int page, string breed, string favtoy) :
    Pet(nm,page,breed), favoritetoy(favtoy) {toString = "[Cat : " + name + " - " + to_string(age) + " ( " + breed + " ), ( "+ favoritetoy +" )]";}
  };

// Family Object
struct Family {
  public:
  std::list<Person> members;
  string lastname;
  std::list<Pet> pets;

  // welcome to the family
  void addMember(Person m) {
    members.push_back(m);
  }

  // Add a pet
  void addPet(Pet p) {
    pets.push_back(p);
  }

  // Compiles all of the members toStrings
  string toString() {
    string buildon = lastname + " Family : ";
    for (Person m : members) {
      buildon += m.toString + " <-> ";
    }
    buildon += " Pets : ";
    for (Pet p : pets) {
      buildon += p.toString + " <-> ";
    }
    return buildon;
  }

  // Constructors
  Family(std::list<Person> mmbrs, string ln) :
    members(mmbrs), lastname(ln) { }
  Family(std::list<Person> mmbrs, string ln, std::list<Pet> ps) :
      members(mmbrs), lastname(ln), pets(ps) { }
};

// Child Object -- is a person
struct Child : Person {
  public:
  // List of parents
  std::list<Person> parents;
  // Their family
  Family family;

  // used to add a parent if a parent list does not exist
  void addParent(Person one) {
    parents.push_back(one);
  }

  // Constructors
  Child(string nm, int page, std::list<Person> prts, Family fam) :
  parents(prts), family(fam), Person(nm,page) { toString = "Child : " + name + " - " + to_string(age); }
  Child(string nm, int page, Family fam) :
  family(fam), Person(nm,page) { toString = "Child : " + name + " - " + to_string(age); }

};

// Parent Object -- is a person
struct Parent : Person {
  public:
  // List of their children
  std::list<Child> children;
  Person partner;

  // Add a child
  void addChildren(Child ch) {
    children.push_back(ch);
  }

  // constructors
  Parent(string nm, int page, std::list<Child> chirren, Person part) :
    Person(nm,page), children(chirren), partner(part) { toString = "Parent : " + name + " - " + to_string(age); }
  Parent(string nm, int page, Person part) :
    Person(nm,page), partner(part)   { toString = "Parent : " + name + " - " + to_string(age); }

};

// Main Program
int main() {
  // Make a new person names karen
  Person karen("Karen", 33);
  // Make a new Parent jeff and set partner to karen
  Parent jeff("Jeff", 34, karen);
  // now that jeff is karens partner set karen as a parent
  karen = Parent(karen.name, karen.age, jeff);
  // add them to a list -- edit make the list
  std::list<Person> ashParents;
  // actually add them to the list
  ashParents.push_back(karen);
  ashParents.push_back(jeff);
  // Make a new family "Ash Family"
  Family ashFam(ashParents, "Ash");
  // Make a new child
  Child shark("Sharqeshia", 12, ashParents, ashFam);
  // Add them to the family
  ashFam.addMember(shark);
  // Print out results
  cout << ashFam.toString() << endl;
  cout << "Adding Pets to the Family (Doug, Kitty & Goldy)" << endl;
  // Now we want to make some Pets
  Dog doug("Doug", 3, "Golden Retreiver","Tennis Ball");
  Cat kitty("Kitty", 1, "Scottish Fold", "Yarn");
  Pet goldy("Goldy", 2, "Gold Fish");
  // Add pets to faimly
  ashFam.addPet(doug);
  ashFam.addPet(kitty);
  ashFam.addPet(goldy);
  // Print out results
  cout << ashFam.toString() << endl;
  // Make it easier to read
  cout << endl;
  cout << endl;
  cout << endl;
  return 0;
  // END
}
