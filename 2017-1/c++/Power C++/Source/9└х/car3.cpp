class Car {
private:       
    // ��� ���� ����
    int speed;		//�ӵ�
    int gear;	//���
    string color;	//����
    ...   
public:
    // ������ ����
    int getSpeed() {
        return speed;
    }
    // ������ ����
    void setSpeed(int s) {	
        speed = s;
    }
    // ������ ����
    public int getGear() {
        return gear;
    }
    // ������ ����
    public void setGear(int g) {	
        gear = g;
    }
    // ������ ����
    public string getColor() {
        return color;
    }
    // ������ ����
    public void setColor(string c) {	
        color = c;
    }
}
