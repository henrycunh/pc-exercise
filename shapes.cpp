#define DEG2RAD(deg) (2 * 3.14159 * deg / 360)  

class Shape {
	protected:
		int x, y;
	public:
		Shape() : x(0), y(0) {}
		Shape(int x, int y) : x(x), y(y) {}
		void draw(int);
};

class Polygon : Shape {
	private:
		int sides;
	public:
		Polygon() : Shape(){}
		Polygon(int x, int y, int sides) : Shape(x,y), sides(sides){}
		void draw(int scale){
			glBegin(GL_LINE_LOOP);
			for(int i = 0; i < this->sides; i++){
				float deg = DEG2RAD( (i - (1.5 - this->sides * .25)) * 360 / this->sides);
				glVertex2d(this->x + cos(deg) * scale, this->y + sin(deg) * scale);	
			}
			glEnd();			
		}

};

class Circle : Polygon {
	public:
		Circle() : Polygon() {}
		Circle(int x, int y) : Polygon(x, y, 1080) {}
};	

class Pentagon : Polygon {
	public:
		Pentagon() : Polygon() {}
		Pentagon(int x, int y) : Polygon(x, y, 5) {}
};


class Triangle : Polygon {
	public:
		Triangle() : Polygon() {}
		Triangle(int x, int y) : Polygon(x, y, 3) {}
};



