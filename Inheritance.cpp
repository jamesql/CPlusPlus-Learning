#include <iostream>
#include "list"

using namespace std;

struct Parent;
struct Child;
struct Family;

struct Person {
  public:
  string name;
  int age;
  Person(string nm, int page) :
  name(nm), age(page)  {}
};

struct Family {
  public:
  std::list<Person> members;
  string lastname;

  Family(std::list<Person> mmbrs, string ln) :
    members(mmbrs), lastname(ln) { }
};

struct Child : Person {
  public:
  std::list<Parent> parents;
  Family family;
  string toString;

  Child(string nm, int page, std::list<Parent> prts, Family fam) :
  parents(prts), family(fam), Person(nm,page), toString("Child : " + name + " (" + (age + ")"))  { }

};

struct Parent:Person {
  public:
  std::list<Child> children;
  Person partner;

  Parent(string nm, int page, std::list<Child> chirren, Person part) :
    Person(nm,page), children(chirren), partner(part)   {  }

};


int main() {
  return 0;
}
