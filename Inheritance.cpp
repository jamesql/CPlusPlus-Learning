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
  string toString;

  Person(string nm, int page) :
  name(nm), age(page)  {}
};

struct Family {
  public:
  std::list<Person> members;
  string lastname;

  void addMember(Person m) {
    members.push_back(m);
  }

  string toString() {
    string buildon = lastname + " Family : ";
    for (Person m : members) {
      buildon += m.toString + " <-> ";
    }
    return buildon;
  }

  Family(std::list<Person> mmbrs, string ln) :
    members(mmbrs), lastname(ln) { }
};

struct Child : Person {
  public:
  std::list<Person> parents;
  Family family;

  void addParent(Person one) {
    parents.push_back(one);
  }

  Child(string nm, int page, std::list<Person> prts, Family fam) :
  parents(prts), family(fam), Person(nm,page) { toString = "Child : " + name + " - " + to_string(age); }
  Child(string nm, int page, Family fam) :
  family(fam), Person(nm,page) { toString = "Child : " + name + " - " + to_string(age); }

};

struct Parent : Person {
  public:
  std::list<Child> children;
  Person partner;

  void addChildren(Child ch) {
    children.push_back(ch);
  }

  Parent(string nm, int page, std::list<Child> chirren, Person part) :
    Person(nm,page), children(chirren), partner(part) { toString = "Parent : " + name + " - " + to_string(age); }
  Parent(string nm, int page, Person part) :
    Person(nm,page), partner(part)   { toString = "Parent : " + name + " - " + to_string(age); }

};


int main() {
  Person karen("Karen", 33);
  Parent jeff("Jeff", 34, karen);
  karen = Parent("Karen", 33, jeff);
  std::list<Person> ashParents;
  ashParents.push_back(karen);
  ashParents.push_back(jeff);
  Family ashFam(ashParents, "Ash");
  Child shark("Sharqeshia", 12, ashFam);
  ashFam.addMember(shark);
  cout << ashFam.toString() << endl;
  return 0;
}
