#include "student.h"

student::student()
{
	m_name = "未知";
	m_sex = "未知";
	m_college = "未知学院"; 
	m_student_num = 0;
}

student::student(std::string name)
{
	m_name = name;
	m_sex = "未知";
	m_college = "未知学院"; 
	m_student_num = 0;
}

student::student(std::string name, std::string sex)
{
	m_name = name;
	m_sex = sex;
	m_college = "未知学院"; 
	m_student_num = 0;
}

student::student(std::string name, std::string sex , std::string college)
{
	m_name = name;
	m_sex = sex;
	m_college = college; 
	m_student_num = 0;
}

student::student(std::string name, std::string sex , std::string college, double stu_num)
{
	m_name = name;
	m_sex = sex;
	m_college = college; 
	m_student_num = stu_num;
}

void student::ShowInf()
{
	std::cout<<"名字："<<m_name<<std::endl;
	std::cout<<"性别："<<m_sex <<std::endl;
	std::cout<<"学院："<<m_college <<std::endl;
	std::cout<<"学号："<<m_student_num <<std::endl; 
}

std::ostream & operator<<(std::ostream & out,const student & onestu)
{
    out<<"名字："<<onestu.m_name<<std::endl;
	out<<"性别："<<onestu.m_sex<<std::endl;
    out<<"学院："<<onestu.m_college <<std::endl;
	out<<"学号："<<onestu.m_student_num<<std::endl; 
	return out;
}

void student::SetGrade(std::string gradename1,double grade1)
{
	grades.push_back(grade1);
	gradesname.push_back(gradename1 );
}

void student::SetGrade(std::string gradename1,double grade1,std::string gradename2,double grade2)
{
	grades.push_back(grade1);
	gradesname.push_back(gradename1 );
	grades.push_back(grade2);
	gradesname.push_back(gradename2);
}

void student::SetGrades(int gradesnum,std::string* in_gradesname, double* in_grades)
{
	for(int i=0;i<gradesnum;i++)
	{
		gradesname.push_back(in_gradesname[i]);
		grades.push_back(in_grades[i] );
	}
}

double student::GetGrade(std::string subject)
{
	for(int i=0;i<grades.size();)
	{
		if(gradesname[i] == subject)
		return grades[i];
		
		else
		i++;
	}
	//std::cout<<GetName()<<"同学没有"<<subject<<"科目的成绩!"<<std::endl;
	return 0; 
}

void student::ShowGrades()
{
	for(int i=0;i<grades.size();i++)
	{
		std::cout<<gradesname[i]<<":"<<grades[i]<<std::endl;
	}
}

double student::GetAverageGrade()
{
	double sum = 0;
	for(auto iter = grades.begin();iter != grades.end() ;iter++ )
	{
		sum = sum + *iter;
	}
	double average = sum/grades.size() ;
	return average;
}

double student::GetSumGrade()
{
	double sum = 0;
	for(auto iter = grades.begin();iter != grades.end() ;iter++ )
	{
		sum = sum + *iter;
	}
	return sum;
}

std::string student::ShowFailedSubject()
{
	for(int i=0;i<grades.size();i++)
	{
		if(grades[i]<60)
		std::cout<<GetName()<<": "<<gradesname[i]<<" "<<grades[i]<<std::endl;
	}
	std::cout<<std::endl;
}

student::~student()
{
}
