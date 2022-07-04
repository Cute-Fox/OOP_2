#include <iostream>
#include <string>
#include <tuple>
using namespace std;

size_t student_count;

size_t get_count() { return student_count; }

class Person {
protected:
	string m_name;
	size_t m_age;
	string m_sex;
	float m_weight;
public:
	Person(string name, size_t age, string sex, float weight) : m_name(name), m_age(age), 
		m_sex(sex), m_weight(weight) {}

	tuple<string, size_t, string, float> get() {
		return {m_name, m_age, m_sex, m_weight};
	}
	void print_info() {
		cout << "name: " << m_name << endl
			<< "sex: " << m_sex << endl << "weight: " << m_weight << endl
			<< "age: " << m_age << endl;
	}
	~Person() {}
};

class Student : public Person {
private:
	size_t m_lrnYear;
public:
	Student(string name, size_t age, string sex, float weight, size_t lrnYear)
		: Person(name, age, sex, weight), m_lrnYear(lrnYear) { student_count++; }
	
	tuple<string, size_t, string, float, size_t> get() {
		return { m_name, m_age, m_sex, m_weight, m_lrnYear };
	}

	void set_lrnYear(size_t lrnYear) { m_lrnYear = lrnYear; }
	void add_lrnYear(size_t n) { m_lrnYear += n; }
	void print_info() {
		cout << "name: " << m_name << endl
			<< "sex: " << m_sex << endl << "weight: " << m_weight << endl
			<< "age: " << m_age << endl << "Lear year: " << m_lrnYear << endl;
	}

	~Student() { student_count--; }
};

class Fruit {
protected:
	string m_name;
	string m_color;
public:
	Fruit(string name, string color) : m_name(name), m_color(color) {}
	string get_color() { return m_color; }
	string get_name() { return m_name; }
	~Fruit() {}
};

class Apple : public Fruit {
protected:
public:
	Apple(string color, string name = "apple") : Fruit(name, color) {}
};

class Banana : public Fruit {
public:
	Banana() : Fruit("banana", "yellow") {}
};

class GrannySmith : public Apple {
public:
	GrannySmith() : Apple("green", "Granny Smith apple") { }
};



int main()
{
	// --***=== Task 1 ===***--
	cout << "----*-*-**** Task 1 ****-*-*----" << endl;
	// Creating stuedents 
	Student s1("Max", 20, "Male", 65.2, 2);
	Student s2("Elly", 22, "Female", 56.4, 4);
	Student s3("Nick", 19, "Male", 50.25, 1);

	// Stuendents info + changing info about their
	s1.print_info();
	cout << endl << "+2 to Learn year" << endl;
	s1.add_lrnYear(2);
	s1.print_info();
	cout << endl << endl;

	// --***=== Task 2 ===***--
	cout << "----*-*-**** Task 2 ****-*-*----" << endl;
	Apple a("red");
	Banana b;
	GrannySmith c;

	cout << "My " << a.get_name() << " is " << a.get_color() << ".\n";
	cout << "My " << b.get_name() << " is " << b.get_color() << ".\n";
	cout << "My " << c.get_name() << " is " << c.get_color() << ".\n";
	return 0;

}