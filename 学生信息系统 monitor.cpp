#include "monitor.h"

monitor::monitor():student("未知","未知","未知学院",0)
{
}

monitor::monitor(std::string name):student(name,"未知","未知学院",0)
{
}

monitor::monitor(std::string name, std::string sex):student(name,sex,"未知学院",0)
{
}

monitor::monitor(std::string name, std::string sex , std::string college):student(name,sex,college,0)
{
}

monitor::monitor(std::string name, std::string sex , std::string college, double stu_num):student(name,sex,college,stu_num)
{
}

void monitor::ArrangeTask(std::string taskname)
{
	tasks.push_back(taskname);
	isfinished.push_back(false);  
}

void monitor::ArrangeTask()
{
	std::string Num = std::to_string(m_default_num);
	std::string tem_name = "任务" + Num;
	m_default_num ++;
	 
	tasks.push_back(tem_name);
	isfinished.push_back(false); 
}

void monitor::FinishTask(std::string taskname)
{
	int len = tasks.size();
	for (int i=0;i<len;i++)
	{
		if(tasks[i] == taskname)
		{
			isfinished[i] = true;
			break;
		}
		if(i==len-1)
		std::cout<<"未找到"<<taskname<<"任务，请检查输入！"<<std::endl; 
	}
}

void monitor::ShowTaskSituation()
{
	std::cout<<this->GetName()<<"所在的班级："<<std::endl;  
	int len = tasks.size();
	if(tasks.empty())
	{
		std::cout<<"暂无任务"<<std::endl; 
		return;
	}    
	for(int i=0;i<len;i++)
	{
		std::cout<<tasks[i]<<":";
		if(isfinished[i]==true)
		std::cout<<"已完成"<<std::endl; 
		else
		std::cout<<"未完成"<<std::endl; 
	}
}

void monitor::ClearTaskList()
{
	tasks.clear() ;
	isfinished.clear() ;
}


monitor::~monitor()
{
}
