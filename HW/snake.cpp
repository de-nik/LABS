#include "iostream"
#include "glut.h"
#include <ctime>

#define __HEIGHT__ 500
#define __WIDTH__ 800

class snake
{
protected:
	int num;
	size_t speed;
	std::pair<int, int> *s;
	float r, g, b;
	int napr;
public:

	snake() = default;

	snake(int x, int y)
	{
		num = 4;
		s = new std::pair<int, int>[30];
		s[0].first = x;
		s[0].second = y;
		speed = 0;
		napr = 0;
	}

	~snake() = default;


	size_t get_num()
	{
		return num;
	}

	int get_x(size_t i) {
		return s[i].first;
	}

	int get_y(size_t i) {
		return s[i].second;
	}

	void dec_num() {
		--num;
		r+=0.1;
	}

	void in_num() {
		++num;
		g+=0.1;
	}

	void set_num(size_t i)
	{
		num = i;
	}

	size_t get_speed()
	{
		return 40 - 10*speed;
	}

	void set_speed()
	{
		++speed;
		b+=0.1;
	}

	friend void mech(snake* s);
	friend void print_snake(snake s);
	friend void control(int key, int a, int b);
};
int napr;
class mod 
{
    protected:
        int x, y; 
    public:
        mod () 
        {
            x=rand() % 37 + 1;
            y=rand() % 23 + 1;
        }
 
        ~mod () = default;
        friend void mech(snake* s);
        friend void print();
};
 
class good: public mod
{
    public:
        good () : mod () {};
 
        void draw_good ()
        {
            glColor3f (0.0, 1.0, 0.0);
            glRectf(x*20, y*20, (x+1)*20, (y+1)*20);
        }
} g;
 
class bad: public mod
{
    public:
        bad () : mod () {};
    
        void draw_bad ()
        {
            glColor3f (1.0, 0.0, 0.0);
            glRectf(x*20, y*20, (x+1)*20, (y+1)*20);
        }
} b;
 
class boost : public mod
{
public:
	boost() : mod() {};

	void draw_boost()
	{
		glColor3f(0.0, 0.0, 1.0);
		glRectf(x * 20, y * 20, (x + 1) * 20, (y + 1) * 20);
	}
} bt;

void border () 
{
	glColor3f(0.0, 0.0, 0.0);
	glRectf(__WIDTH__ - 10, 0, __WIDTH__, __HEIGHT__ - 400);
	glRectf(__WIDTH__ - 10, __HEIGHT__ - 100, __WIDTH__, __HEIGHT__ );
	glRectf(0, 0, 10, __HEIGHT__ - 400);
	glRectf(0, __HEIGHT__ - 100, 10, __HEIGHT__);
	glRectf(0, __HEIGHT__ - 10, __WIDTH__, __HEIGHT__);
	glRectf(0, 0, __WIDTH__, __HEIGHT__ - 490);
}
 
void mech (snake* s) 
{

    for (int i = (*s).get_num(); i > 0; --i)
    {
        (*s).s[i].first=(*s).s[i-1].first;
        (*s).s[i].second=(*s).s[i-1].second;
    }

    if (napr==0) (*s).s[0].second+=1;
    if (napr==1) (*s).s[0].first-=1;
    if (napr==2) (*s).s[0].first+=1;
    if (napr==3) (*s).s[0].second-=1;

        if (((*s).s[0].first==g.x) && ((*s).s[0].second==g.y))
        {
            (*s).in_num();
            g.good::good();
        }
        if (((*s).s[0].first==b.x) && ((*s).s[0].second==b.y))
        {
            (*s).dec_num();
            b.bad::bad();
        }
		if (((*s).s[0].first == bt.x) && ((*s).s[0].second == bt.y))
		{
			(*s).set_speed();
			bt.boost::boost();
		}
	if ((*s).s[0].second < 20 && (*s).s[0].second > 5 && (*s).s[0].first > 40) (*s).s[0].first = 0;
	else if ((*s).s[0].second < 20 && (*s).s[0].second > 5 && (*s).s[0].first < 0) (*s).s[0].first = 40;
	else if ((*s).s[0].first>40) exit(1); 
	else if ((*s).s[0].first<0) exit(1);
    else if ((*s).s[0].second>24) exit(1);
    else if ((*s).s[0].second<1) exit(1);

    for (int i = 1; i < (*s).get_num(); i++) 
    {
        if ((*s).s[0].first == (*s).s[i].first && (*s).s[0].second == (*s).s[i].second)
        {
			exit(1);
        }
    }  	
}
 
void print_snake(snake s) {
	glColor3f(s.r, s.g, s.b);
	for (int i = 0; i < s.get_num(); i++)
	{
		glRectf(s.s[i].first * 20, s.s[i].second * 20, (s.s[i].first + 0.9) * 20, (s.s[i].second + 0.9) * 20); 
	}
}

void control (int key, int a, int b)
{
    switch (key)
    {
        case 101: napr = 0; break;
		case 100: napr = 1; break;
        case 102: napr = 2; break;
        case 103: napr = 3; break;
    }
}
static snake z;
void print() 
{
    glClear (GL_COLOR_BUFFER_BIT);
    border();
	print_snake(z);
    g.draw_good();
    b.draw_bad();
	bt.draw_boost();
    glFlush();
    glutSwapBuffers();
}

void timer (int = 0)
{
	static snake s(10, 10);
	z = s;
    print(); 
	mech(&s);
    glutTimerFunc (z.get_speed(), timer, 0); 
}
 
int main(int argc, char **argv)
{
	srand(time(0));
    glutInit(&argc, argv);  
    glutInitWindowSize (__WIDTH__, __HEIGHT__);
    glutCreateWindow ("snake");
    glClearColor(1.0,1.0,1.0,1.0); 
    gluOrtho2D (0, __WIDTH__, 0, __HEIGHT__);
    glutDisplayFunc (print);
	glutTimerFunc(z.get_speed(), timer, 0);
    glutSpecialFunc (control);
    glutMainLoop();   
    return 0;
}
