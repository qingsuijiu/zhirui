#ifndef MONITOR_H
#define MONITOR_H
#include<iostream>
#include<cstring>

#include "student.h"

class monitor : public student
{
	private:
		std::vector<bool> isfinished;
		std::vector<std::string> tasks;
		int m_default_num = 1;
	public:
		monitor();
		monitor(std::string name);
		monitor(std::string name, std::string sex);
		monitor(std::string name, std::string sex , std::string college);
		monitor(std::string name, std::string sex , std::string college, double stu_num);
		~monitor();
		void ArrangeTask(std::string taskname);
		void ArrangeTask();
		void FinishTask(std::string taskname);
		void ShowTaskSituation();
		void ClearTaskList();
		
	protected:
};

#endif
