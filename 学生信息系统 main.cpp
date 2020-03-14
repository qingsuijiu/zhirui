#include <iostream>
#include"student.h"
#include"monitor.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int operation1; 
    std::vector<student> student_list;
    int judge =1,stu_num = 1; 
    while(judge == 1){
    std::cout<<"1.输入学生数据"<<std::endl
             <<"2.读取学生数据"<<std::endl
             <<"3.输入学生成绩"<<std::endl 
			 <<"4.计算平均成绩"<<std::endl
			 <<"5.打印挂科信息"<<std::endl
			 <<"6.结束" <<std::endl
			 <<"请输入您要进行的操作的序号：" ;
	std::cin>>operation1; 
	switch(operation1)
	{
		case 1:
			{
				string name;
				std::cout<<"请输入学生姓名：";
				std::cin>>name;
				student st1(name);
				st1.SetStudentNum(stu_num) ;
				stu_num ++;
				student_list.push_back(st1);
				std::cout<<"1.输入性别：\n" 
				    <<"2.输入学院：\n"
				    <<"3.输入性别与学院：\n"
	                <<"4.返回主菜单\n"
	                <<"请输入您的选项："<<std::endl;
	            int operation2;
	            string sex,college; 
	            std::cin>>operation2;
	            switch(operation2)
	            {
	            	case 1:
	            		{
	            			std::cout<<"请输入性别:";
	            			std::cin>>sex;
	            			st1.SetSex(sex);  
	            			break;
						}
					case 2:
	            		{
	            			std::cout<<"请输入学院:";
	            			std::cin>>college;
	            			st1.SetCollege(college) ; 
	            			break;
						}
					case 3:
	            		{
	            			std::cout<<"请输入性别:";
	            			std::cin>>sex;
	            			st1.SetSex(sex);  
	            			std::cout<<"请输入学院:";
	            			std::cin>>college;
	            			st1.SetCollege(college) ; 
	            			break;
						} 
					case 4:
					        break; 
					
				}
				break;
			}
		
		case 2:
		    {
		    int i;
			std::cout<<"请输入您要读取学生的姓名：";
			string name;
			cin>>name;
			for(i=0;i<=student_list.size()-1;)
	           {
		          if(student_list[i].GetName() == name)
		          {
		          	std::cout<<student_list[i]<<std::endl;
		          	break;
				  }
		          else
		          {
		          	i++;
				  }
	           } 
	           if(i == student_list.size())
	           {
	           	std::cout<<"没有该同学的信息!"<<std::endl; 
			   }
	        break;
		    }  
		    
		case 3:
			{
				string subject,s_name;
				double grade;
				int i;
				std::cout<<"请输入学科名称：";
				std::cin>>subject; 
				std::cout<<"请输入学生姓名：";
				std::cin>>s_name; 
				std::cout<<"请输入学生成绩：";
				std::cin>>grade; 
				for(i=0;i<=student_list.size()-1;)
	           {
		          if(student_list[i].GetName() == s_name)
		          {
		          	student_list[i].SetGrade(subject,grade); 
		          	std::cout<<"信息录入完成。\n"<<std::endl;
		          	break;
				  }
		          else
		          {
		          	i++;
				  }
	           } 
	           if(i==student_list.size())
	           {
	           	std::cout<<"未找到该同学，请检查输入！\a"<<std::endl;
			   }
				break;
			}
		
		case 4:
			{
				string subject;
				double sum=0;
				int total=0;
				std::cout<<"请输入您要计算均分的学科名称：";
				std::cin >>subject;
				for(int i=0;i<student_list.size();i++)
				{
					if(student_list[i].GetGrade(subject) != 0) 
					{
						total++;
					}
				   sum = sum + student_list[i].GetGrade(subject);
				}
				std::cout<<subject<<"科目的均分为"<<sum/total<<std::endl<<std::endl;
				break;
			}
			
		case 5:
			{
				std::cout<<"挂科同学信息如下："<<std::endl;
				for(int i=0;i<student_list.size();i++)
				{
				   student_list[i].ShowFailedSubject();
				}
				std::cout<<std::endl;
				break;
			}
		
		case 6:
			{
				judge = 0;
				std::cout<<"程序结束,欢迎使用!"<<std::endl; 
			}
		 	
	}}//第二个后括号是while总条件的 
	return 0;
}
