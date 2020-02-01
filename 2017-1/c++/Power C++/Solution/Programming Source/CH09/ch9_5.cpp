#include <iostream>
#include <string>

using namespace std;

class CellPhone
{
private:
	string model;
	string manufact;
	string color;
	bool power;
	bool camera;
public:
	void setModel(string m)
	{
		this->model = m;
	}
	string getModel()
	{
		return model;
	}
	void setManufact(string m)
	{
		this->manufact = m;
	}
	string getManufact()
	{
		return manufact;
	}
	void setColor(string c)
	{
		this->color = c;
	}
	string getColor()
	{
		return color;
	}
	void PowerOn(string model, string manufact, string color, bool camera)
	{
		setModel(model);
		setManufact(manufact);
		setColor(color);
		setCamera(camera);
		power = true;
	}
	void PowerOff()
	{
		power = false;
	}
	bool getCamera()
	{
		return camera;
	}
	void setCamera(bool c)
	{
		camera = c;
	}
};

int main()
{
	CellPhone c1;
	string tmp;
	
	c1.PowerOn("NEXUS ONE", "HTC", "Black", true);
	cout<<"�𵨸� : "<<c1.getModel()<<endl;
	cout<<"������ : "<<c1.getManufact()<<endl;
	cout<<"���� : "<<c1.getColor()<<endl;
	if(c1.getCamera()){
		tmp = "����";
	}
	else{
		tmp = "������";
	}
	cout<<"ī�޶� �������� : "<<tmp<<"�Դϴ�."<<endl;
	return 0;
}
