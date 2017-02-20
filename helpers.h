#ifndef HELPER
#define HELPER
#include <iostream>
#include <math.h>

 // Reference Units For System
 // Gravitational constant 6.6742e-11 N m^2 / kg^2
 // Mass-
 //		Earth = 5.9721986e24 kg
 //     Sun   = 1.988435e30  kg
 //     Moon  = 7.3459e22    kg
 //
 // Distance-
 //     Sun from earth  = 1.485e11 m
 //     Earth From moon = 406653e3 m

	const double gravitational_constant = 6.674e-11;
	const double distance_sun_earth = 1.485e11;
	const double distance_earth_moon = 406653000;
	const double mass_earth = 5.9721986e24;
	const double mass_sun = 1.988435e30;
	const double mass_moon = 7.3459e22;
	const double one_day = 24*60*60;
	double one_year = 365*one_day;

	// using one day as time unit,
	// distance between earth and moon as distance unit,
	// mass of earth as mass unit
	double velocity = distance_earth_moon / one_day;
	const double G = gravitational_constant * mass_earth * pow(one_day, 2) / pow(distance_earth_moon, 3);
	double v_earth = sqrt(gravitational_constant * mass_sun / distance_sun_earth) / velocity;
	double v_moon = sqrt(gravitational_constant * mass_earth / distance_earth_moon) / velocity;


struct Body
{

		vec3 velocity,force,position,oldp;
		double mass,dt;

		Body(vec3 v,vec3 f,vec3 p,double mas,double dtt=0.01):velocity(v),force(f),position(p),dt(dtt),mass(mas)
		{
			oldp=position-(dt*velocity);

		}
		void info(int i)
		{
			std::cout<<"Info of Body "<<i<<"\nPosition:"<<position<<"\nVelocity:"<<velocity<<"\nForce:"<<force<<"\nMass:"<<mass<<"\n\n";
		}
		void resetforce()
		{
			this->force = vec3(0.0,0.0,0.0);
		}
};

double cube(vec3 r)
{
	double mag = sqrt( r.x * r.x + r.y * r.y + r.z * r.z);
	return pow( mag , 3 );
}
#endif