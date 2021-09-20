 #include"Circle.h"

int Circle::CountOfCircle = 0;

Circle::Circle() :Shape() {
	CountOfCircle++;
	radius = 1.0;
	CircleCenter = new Point(0, 0);
}

Circle::Circle(int CircleCenterx_, int CircleCentery_, double radius_, color_t BorderColor_, color_t FilledColor_, bool isFilled_)
	:Shape(BorderColor_,FilledColor_,isFilled_)
{
	CountOfCircle++;
	radius = radius_;
	CircleCenter = new Point(CircleCenterx_, CircleCentery_);
}

Circle::Circle(int mpx1_, int mpy1_, int mpx2_, int mpy2_, color_t BorderColor_, color_t FilledColor_, bool isFilled_)
	:Shape(BorderColor_, FilledColor_, isFilled_)
{
	CountOfCircle++;
	radius = pow(pow(mpx1_ - mpx2_, 2) + pow(mpy1_ - mpy2_, 2), 0.5) / 2;
	CircleCenter = new Point((mpx1_ + mpx2_) / 2, (mpy1_ + mpy2_) / 2);
}

Circle::Circle(Circle* circle_)
	:Shape(*circle_)
{
	CountOfCircle++;
	this->CircleCenter = new Point(*circle_->CircleCenter);
	this->radius = circle_->radius;
}

Circle& Circle::operator=(const Circle& c) {
	this->setBorderColor(c.getBorderColor());
	this->setFilledColor(c.getFilledColor());//上面这两个函数内部已经实现了深拷贝，所以直接调用即可
	this->setIsFilled(c.getIsFilled());
	this->CircleCenter = new Point(c.getCircleCenter()->getX(), c.getCircleCenter()->getY());
	this->radius = c.radius;
	return *this;
}

double Circle::getRadius()const {
	return this->radius;
}

void Circle::setRadius(double radius_) {
	this->radius = radius_;
}

double Circle::getArea()const {
	return PI * radius * radius;
}

int Circle::getCountOfCircle() {
	return CountOfCircle;
}

Point* Circle::getCircleCenter()const {
	return this->CircleCenter;
}

void Circle::draw() {
	setcolor(this->getBorderColor());
	setfillcolor(this->getFilledColor());
	setlinewidth(1.0);
	circle(CircleCenter->getX(), CircleCenter->getY(), static_cast<int>(radius));
	if (true == getIsFilled())
		fillellipse(CircleCenter->getX(), CircleCenter->getY(), static_cast<int>(radius), static_cast<int>(radius));
	setcolor(BLACK);
	setfillcolor(WHITE);
}

void Circle::WriteToFile(ofstream& output) {
	output << 1 << endl;
	output << this->getCircleCenter()->getX() << ' ' << this->getCircleCenter()->getY() << ' '
		<< this->getRadius() << endl;
	output << this->getBorderColor() << ' ' << this->getIsFilled() << endl;
}

bool Circle::operator==(Shape*& secgeo)const {
	if (this->getArea() == secgeo->getArea())
		return true;
	else
		return false;
}

bool Circle::operator<(Shape*& secgeo)const {
	if (this->getArea() < secgeo->getArea())
		return true;
	else
		return false;
}

bool Circle::operator!=(Shape*& secgeo)const {
	if (this->getArea() != secgeo->getArea())
		return true;
	else
		return false;
}

bool Circle::operator<=(Shape*& secgeo)const {
	if (this->getArea() <= secgeo->getArea())
		return true;
	else
		return false;
}

bool Circle::operator>=(Shape*& secgeo)const {
	if (this->getArea() >= secgeo->getArea())
		return true;
	else
		return false;
}

bool Circle::operator>(Shape*& secgeo)const {
	if (this->getArea() > secgeo->getArea())
		return true;
	else
		return false;
}

Point& Circle::operator[](int index) {
	if (0 == index)
		return *(this->CircleCenter);
	else
		throw std::out_of_range("index is out of range!");
}

Circle::~Circle() {
	delete CircleCenter;
	CircleCenter = nullptr;
	CountOfCircle--;
}