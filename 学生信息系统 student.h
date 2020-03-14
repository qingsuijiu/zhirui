#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<cstring>
#include<vector>
#include<stdio.h>

using namespace std;

/******可能存在的问题
1.ShowGrades中数组的引用，const使用问题****/ 


class student
{
	private:
		std::string m_name;
		std::string m_sex;
		std::string m_college;
		std::string m_class;
		
		int m_old;
		int m_birth_year;
		int m_birth_month;
		int m_birth_day;
		double m_student_num;
		
		std::vector<double> grades;
		std::vector<std::string> gradesname;
		
	public:
		student();
		student(std::string);
		student(std::string , std::string);
		student(std::string , std::string,std::string);
		student(std::string , std::string,std::string,double);
		~student();
		
		void SetName(std::string name) {m_name = name;}
		std::string GetName() {return m_name;}
		
		void SetSex(std::string sex) 
		{
		   if(sex!="男" and sex!="女")
		   std::cout<<"输入有误，请检查！"<<std::endl;
		   else 
		   m_sex = sex;
		}
		std::string GetSex() {return m_sex;}
		
		void SetCollege(std::string college) {m_college = college;}
		std::string GetCollege() {return m_college;}
		
		void SetStudentNum(double stu_num) {m_student_num  = stu_num;}
		double GetStudentNum() {return m_student_num;}
		
		void SetClass(std::string clas) {m_class = clas;}
		std::string GetClass() {return m_class;}
		
		void SetOld(int old) 
		{
		   if(old<=0 or old>=150)
		   std::cout<<"输入有误，请检查！"<<std::endl;
		   else
		   m_old = old;
		}
		int GetOld() {return m_old;}
		
		void SetBirth(int year,int month,int day)
		{
			if (year<=0 or month<=0 or month>12 or day<=0 or day>31)
			std::cout<<"输入有误，请检查！"<<std::endl;
			else{
			m_birth_year  = year;
		    m_birth_month = month;
		    m_birth_day = day;
			}
		}
		
		void ShowInf();
		friend std::ostream & operator<<(std::ostream & out,const student & onestu);
		void SetGrade(std::string,double); 
		void SetGrade(std::string,double,std::string,double); 
		void SetGrades(int gradesnum,std::string *in_gradesname,double *in_grades);
		double GetGrade(std::string);
		void ShowGrades();
		double GetAverageGrade();
		double GetSumGrade();
		std::string ShowFailedSubject();
		
		//student(const student& s);
		
		operator double()
		{
			return m_student_num ;
		}
		
	protected:
};

#endif
