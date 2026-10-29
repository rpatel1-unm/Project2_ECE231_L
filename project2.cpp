#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

class Student
{
protected:
  std::string first_name;
  std::string last_name;
  double gpa;
  int grad_year;
  std::string grad_semester;
  int enroll_year;
  std::string enroll_semester;
  std::string level; // Undergrad or Grad

public:
  Student()
  {
    first_name = "None";
    last_name = "None";
    gpa = 0.0;
    grad_year = 0;
    grad_semester = "None";
    enroll_year = 0;
    enroll_semester = "None";
    level = "Undergrad";
  }

  virtual ~Student() {}

  void setName(std::string f, std::string l) { first_name = f; last_name = l; }
  void setGPA(double g) { gpa = g; }
  void setGradYear(int y) { grad_year = y; }
  void setGradSemester(std::string s) { grad_semester = s; }
  void setEnrollYear(int y) { enroll_year = y; }
  void setEnrollSemester(std::string s) { enroll_semester = s; }
  void setLevel(std::string l) { level = l; }

  std::string getFirstName() { return first_name; }
  std::string getLastName() { return last_name; }
  double getGPA() { return gpa; }
  int getGradYear() { return grad_year; }
  std::string getGradSemester() { return grad_semester; }
  int getEnrollYear() { return enroll_year; }
  std::string getEnrollSemester() { return enroll_semester; }
  std::string getLevel() { return level; }

  virtual void write(std::ofstream &out)
  {
    out << first_name << " " << last_name << ", GPA: " << gpa
        << ", Enrolled: " << enroll_semester << " " << enroll_year
        << ", Graduating: " << grad_semester << " " << grad_year
        << ", Level: " << level;
  }
};

class Art_Student : public Student
{
private:
  std::string art_emphasis;

public:
  Art_Student() { art_emphasis = "None"; }
  ~Art_Student() {}

  void setArtEmphasis(std::string e)
  {
    if (e == "Art Studio" || e == "Art History" || e == "Art Education")
      art_emphasis = e;
    else
      std::cout << "Invalid art emphasis: " << e << std::endl;
  }
  std::string getArtEmphasis() { return art_emphasis; }

  void write(std::ofstream &out)
  {
    Student::write(out);
    out << ", Art Emphasis: " << art_emphasis << std::endl;
  }
};

class Physics_Student : public Student
{
private:
  std::string concentration;

public:
  Physics_Student() { concentration = "None"; }
  ~Physics_Student() {}

  void setConcentration(std::string c)
  {
    if (c == "Biophysics" || c == "Earth and Planetary Sciences")
      concentration = c;
    else
      std::cout << "Invalid concentration: " << c << std::endl;
  }
  std::string getConcentration() { return concentration; }

  void write(std::ofstream &out)
  {
    Student::write(out);
    out << ", Concentration: " << concentration << std::endl;
  }
};

int main()
{
  std::vector<Art_Student *> art_students;

  std::vector<Physics_Student *> physics_students;

  std::string art_first[5] = {"Maya", "Leo", "Sofia", "Ethan", "Nina"};
  std::string art_last[5] = {"Torres", "Chen", "Ramirez", "Brooks", "Patel"};
  std::string art_emph[5] = {"Art Studio", "Art History", "Art Education", "Art Studio", "Art History"};
  double art_gpa[5] = {3.9, 3.4, 3.7, 2.9, 3.6};

  std::string phys_first[5] = {"Omar", "Grace", "Lucas", "Priya", "Jack"};
  std::string phys_last[5] = {"Hassan", "Kim", "Nguyen", "Shah", "Miller"};
  std::string phys_conc[5] = {"Biophysics", "Earth and Planetary Sciences", "Biophysics", "Biophysics", "Earth and Planetary Sciences"};
  double phys_gpa[5] = {3.8, 3.5, 3.1, 4.0, 3.3};

  for (int i = 0; i < 5; i++)
  {
    art_students.push_back(new Art_Student);
    art_students[i]->setName(art_first[i], art_last[i]);
    art_students[i]->setGPA(art_gpa[i]);
    art_students[i]->setEnrollYear(2023);
    art_students[i]->setEnrollSemester("Fall");
    art_students[i]->setGradYear(2027);
    art_students[i]->setGradSemester("Spring");
    art_students[i]->setLevel("Undergrad");
    art_students[i]->setArtEmphasis(art_emph[i]);

    physics_students.push_back(new Physics_Student);
    physics_students[i]->setName(phys_first[i], phys_last[i]);
    physics_students[i]->setGPA(phys_gpa[i]);
    physics_students[i]->setEnrollYear(2024);
    physics_students[i]->setEnrollSemester("Spring");
    physics_students[i]->setGradYear(2028);
    physics_students[i]->setGradSemester("Fall");
    physics_students[i]->setLevel(i == 4 ? "Grad" : "Undergrad");
    physics_students[i]->setConcentration(phys_conc[i]);
  }

  std::ofstream outfile("student_info.dat");
  outfile << std::fixed << std::setprecision(1);
  outfile << "Art Students" << std::endl;
  for (int i = 0; i < art_students.size(); i++)
    art_students[i]->write(outfile);

  outfile << std::endl << "Physics Students" << std::endl;
  for (int i = 0; i < physics_students.size(); i++)
    physics_students[i]->write(outfile);
  outfile.close();

  for (int i = 0; i < art_students.size(); i++)
    delete art_students[i];
  for (int i = 0; i < physics_students.size(); i++)
    delete physics_students[i];

  return 0;
}
