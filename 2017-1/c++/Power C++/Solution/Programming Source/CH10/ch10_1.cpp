#include <iostream>
#include <string>

using namespace std;

class Plane{
private:
	int id; //½Äº°¹øÈ£
	string model; //¸ðµ¨
	int passenger; //½Â°´¼ö
public:
	Plane(){
		id = 0;
		passenger = 0;
	}
	Plane(int id){
		this->id = id;
	}
	Plane(int id, string model){
		this->id = id;
		this->model = model;
	}
	Plane(int id, string model, int passenger){
		this->id = id;
		this->model = model;
		this->passenger = passenger;
	}
	int getId(){
		return id;
	}
	void setId(int id){
		this->id = id;
	}
	string getModel(){
		return model;
	}
	void setModel(string model){
		this->model = model;
	}
	int getPassenger(){
		return passenger;
	}
	void setPassenger(int passenger){
		this->passenger = passenger;
	}
	void print(){
		cout<<"½Äº°  ¹øÈ£ : "<<getId()<<endl;
		cout<<"¸ð      µ¨ : "<<getModel()<<endl;
		cout<<"½Â  °´  ¼ö : "<<getPassenger()<<endl;
	}
};

   

int main()
{
	Plane p1,p2(1),p3(2,"B-747"),p4(3,"A-330",80);
	p1.setModel("A-380");
	p1.setPassenger(60);
	p2.setModel("B-787");
	p2.setPassenger(120);
	p3.setPassenger(140);
	p1.print();
	p2.print();
	p3.print();
	p4.print();
	return 0;
}

