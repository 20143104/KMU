class Car {

public:
	// ��� ���� ����
	int speed; // �ӵ�
	int gear; // ���
	string color; // ����

	// ��� �Լ� ����
	void speedUp() { // �ӵ� ���� ��� �Լ�
		speed += 10;
	}

	void speedDown() { // �ӵ� ���� ��� �Լ�
		speed -= 10;
	}
};
