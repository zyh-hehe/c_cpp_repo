#pragma once
class father {
private:
public:
	int a{ 0 };
	father() = default;
	virtual void vfprint(int i) {
		a = i;
	}
	void ifprint(int i) {
		a = i;
	}
};

class son :public father {
private:
public:
	int b{ 0 };
	son() = default;
	void vfprint(int i)override {
		b = i;
	}
};
