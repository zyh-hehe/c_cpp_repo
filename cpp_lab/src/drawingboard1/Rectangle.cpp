#include"Rectangle.h"
int cRectangle::CountOfRectangle = 0;

cRectangle::cRectangle() :cRectangle(0,0,100,100,BLACK,WHITE,true) { }

cRectangle::cRectangle(int px1_, int py1_, int px2_, int py2_, color_t BorderColor_, color_t FilledColor_, bool isFilled_)
	:Shape(BorderColor_, FilledColor_, isFilled_)
{
	CountOfRectangle++;
	this->p1 = new Point(px1_, py1_);
	this->p2 = new Point(px2_, py1_);
	this->p3 = new Point(px2_, py2_);
	this->p4 = new Point(px1_, py2_);
}

cRectangle::cRectangle(cRectangle* rectangle_)
	:Shape(*rectangle_)
{
	CountOfRectangle++;
	this->p1 = new Point(*rectangle_->p1);
	this->p2 = new Point(*rectangle_->p2);
	this->p3 = new Point(*rectangle_->p3);
	this->p4 = new Point(*rectangle_->p4);
}

vector<Point*> cRectangle::getRecPoint() {
	vector<Point*> vp;
	vp.push_back(this->p1);
	vp.push_back(this->p2);
	vp.push_back(this->p3);
	vp.push_back(this->p4);
	return vp;
}

int cRectangle::getCountOfRectangle() {
	return CountOfRectangle;
}

void cRectangle::draw() {
	setcolor(this->getBorderColor());
	setfillcolor(this->getFilledColor());
	line(p1->getX(), p1->getY(), p2->getX(), p2->getY());
	line(p2->getX(), p2->getY(), p3->getX(), p3->getY());
	line(p3->getX(), p3->getY(), p4->getX(), p4->getY());
	line(p4->getX(), p4->getY(), p1->getX(), p1->getY());
	
	if (true == this->getIsFilled())
		bar(p1->getX(), p1->getY(), p3->getX(), p3->getY());
	setcolor(BLACK);
	setfillcolor(WHITE);
}

cRectangle::~cRectangle() {
	delete p1, p2, p3, p4;
	p1 = nullptr;
	p2 = nullptr;
	p3 = nullptr;
	p4 = nullptr;
	CountOfRectangle--;
}

void cRectangle::WriteToFile(ofstream& output) {
	output << 2 << endl;
	output << this->getRecPoint()[0]->getX() << ' ' << this->getRecPoint()[0]->getY() << ' '
		<< this->getRecPoint()[2]->getX() << ' ' << this->getRecPoint()[2]->getY() << endl;
	output << this->getBorderColor() << ' ' << this->getIsFilled() << endl;
}

double cRectangle::getArea()const {
	int a = abs(p1->getX() - p3->getX());
	int b = abs(p1->getY() - p3->getY());
	return static_cast<double>(a) * static_cast<double>(b);
}

cRectangle& cRectangle::operator=(const cRectangle& r) {
	this->setBorderColor(r.getBorderColor());
	this->setFilledColor(r.getFilledColor());//上面这两个函数内部已经实现了深拷贝，所以直接调用即可
	this->setIsFilled(r.getIsFilled());
	this->p1 = new Point(*r.p1);
	this->p2 = new Point(*r.p2);
	this->p3 = new Point(*r.p3);
	this->p4 = new Point(*r.p4);
	return *this;
}

bool cRectangle::operator<(Shape*& secgeo)const {
	if (this->getArea() < secgeo->getArea())
		return true;
	else
		return false;
}

bool cRectangle::operator<=(Shape*& secgeo)const {
	if (this->getArea() <= secgeo->getArea())
		return true;
	else
		return false;
}

bool cRectangle::operator>(Shape*& secgeo)const {
	if (this->getArea() > secgeo->getArea())
		return true;
	else
		return false;
}

bool cRectangle::operator>=(Shape*& secgeo)const {
	if (this->getArea() >= secgeo->getArea())
		return true;
	else
		return false;
}

bool cRectangle::operator==(Shape*& secgeo)const {
	if (fabs(this->getArea() - secgeo->getArea()) < 1e-10)
		return true;
	else
		return false;
}

bool cRectangle::operator!=(Shape*& secgeo)const {
	if (fabs(this->getArea() - secgeo->getArea()) >= 1e-10)
		return true;
	else
		return false;
}

Point& cRectangle::operator[](int index) {
	if (0 == index)
		return *(this->p1);
	else if (1 == index)
		return *(this->p2);
	else if (2 == index)
		return *(this->p3);
	else if (3 == index)
		return *(this->p4);
	else
		throw std::out_of_range("index is out of range!");
}