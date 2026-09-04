// 50 students in a Class. Each Student have 5 subjects and have Specific Grade. Write an Algorithm that calculates how many students have A, B, C, D, E, and F Grade.

#include <iostream>
using namespace std;

class student
{
public:
     student()
     {
          for (int i = 0; i < 3; i++)
          {
               if (i == 1)
               {
                    subject_1_marks[i] = 1;
                    subject_2_marks[i] = 1;
                    subject_3_marks[i] = 1;
                    subject_4_marks[i] = 1;
                    subject_5_marks[i] = 1;   
               }
               else
               {
                    subject_1_marks[i] = 0;
                    subject_2_marks[i] = 0;
                    subject_3_marks[i] = 0;
                    subject_4_marks[i] = 0;
                    subject_5_marks[i] = 0;
               }
          }
          studentGrade = '0';
     }

     char studentGrade;
     int subject_1_marks[3];
     int subject_2_marks[3];
     int subject_3_marks[3];
     int subject_4_marks[3];
     int subject_5_marks[3];

     void calculate_subject_percentage(int subject_marks[])
     {
          int obtainedMarks = subject_marks[0];
          int TotalMarks = subject_marks[1];
          int percentage = (obtainedMarks / TotalMarks) * 100;
          subject_marks[2] = percentage;
     }

     void calculate_student_grade()
     {
          calculate_subject_percentage(subject_1_marks);
          calculate_subject_percentage(subject_2_marks);
          calculate_subject_percentage(subject_3_marks);
          calculate_subject_percentage(subject_4_marks);
          calculate_subject_percentage(subject_5_marks);

          int percentage = (subject_1_marks[2] + subject_2_marks[2] + subject_3_marks[2] + subject_4_marks[2] + subject_5_marks[2]) / 5;

          if (percentage > 85)
          {
               studentGrade = 'A';
          }
          else if (percentage < 85 && percentage >= 75)
          {
               studentGrade = 'B';
          }
          else if (percentage < 75 && percentage >= 50)
          {
               studentGrade = 'C';
          }
          else if (percentage < 50 && percentage >= 30)
          {
               studentGrade = 'D';
          }
          else if (percentage < 30 && percentage >= 20)
          {
               studentGrade = 'E';
          }
          else
          {
               studentGrade = 'F';
          }
     }
};

class NumberofGrades
{
public:
     NumberofGrades()
     {
          Numberof_A_Grades = 0;
          Numberof_B_Grades = 0;
          Numberof_C_Grades = 0;
          Numberof_D_Grades = 0;
          Numberof_E_Grades = 0;
          Numberof_F_Grades = 0;
     }

     int Numberof_A_Grades;
     int Numberof_B_Grades;
     int Numberof_C_Grades;
     int Numberof_D_Grades;
     int Numberof_E_Grades;
     int Numberof_F_Grades;
};

int countOccurrences(char arr[], int size, int x)
{
     int result = 0;
     for (int i = 0; i < size; i++)
          if (x == arr[i])
               result++;
     return result;
}

NumberofGrades *checkNumberOfGrades(student stdArr[], int size)
{
     char AllStudentGrades[size];
     for (int i = 0; i < size; i++)
     {
          AllStudentGrades[i] = stdArr[i].studentGrade;
     }

     NumberofGrades *grades = new NumberofGrades;
     grades->Numberof_A_Grades = countOccurrences(AllStudentGrades, size, 'A');
     grades->Numberof_B_Grades = countOccurrences(AllStudentGrades, size, 'B');
     grades->Numberof_C_Grades = countOccurrences(AllStudentGrades, size, 'C');
     grades->Numberof_D_Grades = countOccurrences(AllStudentGrades, size, 'D');
     grades->Numberof_E_Grades = countOccurrences(AllStudentGrades, size, 'E');
     grades->Numberof_F_Grades = countOccurrences(AllStudentGrades, size, 'F');
     return grades;
}

int main()
{
     int size = 50;
     student std[size];

     for (int i = 0; i < size; i++)
     {
          std[i].calculate_student_grade();
     }

     NumberofGrades *grades = checkNumberOfGrades(std, size);

     cout << "Number of A Grades: " << grades->Numberof_A_Grades << endl;
     cout << "Number of B Grades: " << grades->Numberof_B_Grades << endl;
     cout << "Number of C Grades: " << grades->Numberof_C_Grades << endl;
     cout << "Number of D Grades: " << grades->Numberof_D_Grades << endl;
     cout << "Number of E Grades: " << grades->Numberof_E_Grades << endl;
     cout << "Number of F Grades: " << grades->Numberof_F_Grades << endl;

     return 0;
}