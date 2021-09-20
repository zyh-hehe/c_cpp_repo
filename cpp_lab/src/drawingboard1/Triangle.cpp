#include"Triangle.h"

int Triangle::CountOfTriangle = 0;

Triangle::Triangle() :Triangle(Point(0,0), Point(0, 0), Point(0, 0),BLACK, WHITE, true) {};

Triangle::Triangle(Point p1_, Point p2_, Point p3_, color_t BorderColor_, color_t FilledColor_, bool isFilled_)
	:Shape(BorderColor_, FilledColor_, isFilled_) 
{
	this->p1 = new Point(p1_);
	this->p2 = new Point(p2_);
	this->p3 = new Point(p3_);
	CountOfTriangle++;
}

Triangle::Triangle(Triangle* triangle_)
	:Shape(*triangle_)
{
	this->p1 = new Point(*triangle_->p1);
	this->p2 = new Point(*triangle_->p2);
	this->p3 = new Point(*triangle_->p3);
	CountOfTriangle++;
}

vector<Point*> Triangle::getTriPoint() const{
	vector<Point*> vp;
	vp.push_back(this->p1);
	vp.push_back(this->p2);
	vp.push_back(this->p3);
	return vp;
}

int Triangle::getCountOfTriangle() {
	return CountOfTriangle;
}

Triangle::~Triangle() {
	delete p1, p2, p3;
	p1 = nullptr;
	p2 = nullptr;
	p3 = nullptr;
	CountOfTriangle--;
}

void Triangle::draw() {
	setcolor(this->getBorderColor());
	setfillcolor(this->getFilledColor());
	line(p1->getX(), p1->getY(), p2->getX(), p2->getY());
	line(p2->getX(), p2->getY(), p3->getX(), p3->getY());
	line(p3->getX(), p3->getY(), p1->getX(), p1->getY());
	if (this->getIsFilled()) {
		int vertexpoint[6]{ p1->getX(), p1->getY(), p2->getX(), p2->getY() , p3->getX(), p3->getY() };
		fillpoly(3, vertexpoint);
	}
	setcolor(BLACK);
	setfillcolor(WHITE);
}

void Triangle::WriteToFile(ofstream& output) {
	output << 3 << endl;
	output << this->getTriPoint()[0]->getX() << ' ' << this->getTriPoint()[0]->getY() << ' '
		<< this->getTriPoint()[1]->getX() << ' ' << this->getTriPoint()[1]->getY() << ' '
		<< this->getTriPoint()[2]->getX() << ' ' << this->getTriPoint()[2]->getY() << endl;
	output << this->getBorderColor() << ' ' << this->getIsFilled() << endl;
}

double Triangle::getArea()const {
	double a = sqrt(pow(p2->getX() - p1->getX(), 2) + pow(p2->getY() - p1->getY(), 2));
	double b = sqrt(pow(p3->getX() - p2->getX(), 2) + pow(p3->getY() - p2->getY(), 2));
	double c = sqrt(pow(p3->getX() - p1->getX(), 2) + pow(p3->getY() - p1->getY(), 2));
	double cosA = (b * b + c * c - a * a) / (2.0 * b * c);
	double sinA = sqrt(1.0 - cosA * cosA);
	double area = (b * c * sinA) / (2.0);
	return area;
}

Triangle& Triangle::operator=(const Triangle& t) {
	this->setBorderColor(t.getBorderColor());
	this->setFilledColor(t.getFilledColor());//上面这两个函数内部已经实现了深拷贝，所以直接调用即可
	this->setIsFilled(t.getIsFilled());
	this->p1 = new Point(*t.p1);
	this->p2 = new Point(*t.p2);
	this->p3 = new Point(*t.p3);
	return *this;
}

bool Triangle::operator<(Shape*& secgeo)const {
	if (this->getArea() < secgeo->getArea())
		return true;
	else
		return false;
}

bool Triangle::operator<=(Shape*& secgeo)const {
	if (this->getArea() <= secgeo->getArea())
		return true;
	else
		return false;
}

bool Triangle::operator>(Shape*& secgeo)const {
	if (this->getArea() > secgeo->getArea())
		return true;
	else
		return false;
}

bool Triangle::operator>=(Shape*& secgeo)const {
	if (this->getArea() >= secgeo->getArea())
		return true;
	else
		return false;
}

bool Triangle::operator==(Shape*& secgeo)const {
	if (fabs(this->getArea() - secgeo->getArea()) < 1e-10)
		return true;
	else
		return false;
}

bool Triangle::operator!=(Shape*& secgeo)const {
	if (fabs(this->getArea() - secgeo->getArea()) >= 1e-10)
		return true;
	else
		return false;
}

Point& Triangle::operator[](int index) {
	if (0 == index)
		return *(this->p1);
	else if (1 == index)
		return *(this->p2);
	else if (2 == index)
		return *(this->p3);
	else
		throw std::out_of_range("index is out of range!");
}