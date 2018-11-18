class Shape{
	private:
		int x, y;
	public:
		Shape() : x(0), y(0) {}
		Shape(int x, int y) : x(x), y(y) {}
		void draw(int);
}

class Circle : Shape {
	public:
		void draw(int radius){

			glBegin(GL_LINE_LOOP);
			int r = 100;
			for(int i = 0; i < 360; i++){
				float deg = 2 * 3.14159 * i / 360;
				glVertex2d(x + cos(deg) * radius, y + sin(deg) * radius);
			}
			glEnd();	

		}
}	




