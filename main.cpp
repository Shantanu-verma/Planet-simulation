
#include <iostream>
#include "vectors.h"                                              // Vector Class With Operator Overloads
#include "helpers.h"                                              // Refrence Units And Helper Functions
#include "OrbitalPhysics.h"                                       // Method For Forces And Verlet

int main()
{
	// Body Initialization Velocity , Force , Position ,Mass ,Timestep

	Body body[3]={ Body(vec3(0.0,0.0,0.0), vec3(0.0,0.0,0.0), vec3(0.0,0.0,0.0), 332948.57274170354),

			      Body(vec3(0.0,v_earth,0.0), vec3(0.0,0.0,0.0), vec3(distance_sun_earth/distance_earth_moon,0.0,0.0), 1.0),

			      Body(vec3(v_moon, v_earth,0.0), vec3(0.0,0.0,0.0), vec3(distance_sun_earth/distance_earth_moon,1.0,0.0), 0.012300160279331637)
	};

	std::cout<<"For What Time Simulate:";
	double simulation_time;
	std::cin>>simulation_time;

	simulate(body,simulation_time,0.01);

}



