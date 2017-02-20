#ifndef ORBIT
#define ORBIT
#include <math.h>
struct vec3
{
		double x,y,z;
		vec3(double x=0.0, double y=0.0, double z=0.0):x(x), y(y), z(z) {}

};

        std::ostream & operator<<(std::ostream &output,vec3 rhs)
		{
               output<<"X:"<<rhs.x<<" Y:"<<rhs.y<<" Z:"<<rhs.z<<"\n";
               return output;
		}
		vec3 operator+(vec3 l,vec3 r)
		{
			return vec3(l.x+r.x, l.y+r.y, l.z+r.z);
		}
		vec3 operator-(vec3 l,vec3 r)
		{
			return vec3(l.x-r.x, l.y-r.y, l.z-r.z);
		}
		vec3 operator*(double l,vec3 r)
		{
			return vec3(l* r.x,l* r.y,l* r.z);
		}
		vec3 operator/(vec3 l,double r)
		{
			return vec3(l.x/r,l.y/r,l.z/r);
		}
#endif