#include<bits/stdc++.h>
using namespace std;

class CPU{
public:
	virtual void calculate() = 0;
};

class Videocard{
public:
	virtual void display() = 0;
};

class Computer{
public: 
	Computer(CPU *cpu,Videocard *videocard){
		m_cpu = cpu;
		m_videocard = videocard;
	}
	
	~Computer(){
		if(m_cpu != NULL){
			delete m_cpu;
			m_cpu = NULL;
		}
			if(m_videocard != NULL){
			delete m_videocard;
			m_videocard = NULL;
		}
	}
	
	void dowork(){
		m_cpu->calculate();
		m_videocard->display();
	}
	
	CPU *m_cpu;
	Videocard *m_videocard;
};

class InterCPU:public CPU{
public:
	virtual void calculate(){
		cout<<"Inter的CPU正在运行"<<endl; 
	}
};

class InterVideocard:public Videocard{
public:
	virtual void display(){
		cout<<"Inter的显卡正在运行"<<endl;
	}
};

void test(){
	Computer *m_computer = new Computer(new InterCPU,new InterVideocard);
	m_computer->dowork();
	delete m_computer;
}

int main() {
	test();
	return 0;
}
