/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
class Employee{
    protected:
        int id;
        string name;
    public:
        Employee(const int& i, const string& n){
            id=i>0?i:-i;
            name=n;
        }
        virtual double computeSalary()=0;
};
class PartTimer : public Employee{
    private:
        int nbHrs;
        double rate;
    public:
        PartTimer(const int& id, const string& name, const int&nb, const double& r) :Employee(id,name){
            nbHrs = nb > 0? nb:0;
            rate = r>0?r:0;
        }
        //override
        double computeSalary(){
            return nbHrs * rate;
        }
};

class FullTimer: public Employee{
    private:
        double salary;
    public:
        FullTimer(const int& id, const string& name,  const double& s) :Employee(id,name){
          salary = s> 0 ? s: 0;
        }
        //override
        double computeSalary(){
            return salary;
        }
};
double max(Employee& e1, Employee& e2){ //polymorphism
	double s1=e1.computeSalary(), s2= e2.computeSalary();
	return s1>s2?s1:s2;
}
int main()
{
    PartTimer pt (1,"John",3,40);
    FullTimer ft (2,"Alice",1200);
    cout<< pt.computeSalary() << "\n" << ft.computeSalary()<<endl;
	cout<<"Highest salary:"<<max(pt,ft);
    return 0;
}
