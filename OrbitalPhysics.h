#ifndef A
#define A
#include <math.h>
#define N 3                                          // Number Of Bodies
bool CONSOLE_INFO = true;                            // Flag For Printing On Console

 

void forces(Body *l)
{
	for(int i=0; i<N ;i++)
	{
		for(int j=i+1; j<N; j++)
		{

		vec3 dx = l[j].position-l[i].position;
		double f = G* (l[i].mass* l[j].mass)/cube(dx);

		l[i].force = l[i].force + f*dx;
		l[j].force = l[j].force - f*dx;


		}

	}
}

void simulate(Body *body, double time, double dt = 0.01) {
	double sim_step = 0.0;
	int i = 0;
	while ((sim_step += dt) <= time) {
		i = 0;                          // Index Reset
		// Resetting Forces
		while (i++ < N) {
			body[i].resetforce();
		}

		// Initializing Forces For Three Bodies
		forces(body);

		// Verlet Integration Method

		i = 0;                         // Index Reset
		while (i++ < N) {

			vec3 temp = body[i].position;

			// x[t+dt] = 2* x[t]- x[t-dt]+ f/m* dt* dt  | Central Difference

			body[i].position = ((2.0 * body[i].position) - body[i].oldp)+ (dt * dt * (body[i].force / body[i].mass));

			// v[t+dt] = ( x[t+dt]- x[t-dt] )/ 2* dt | Central Difference

			body[i].velocity = (body[i].position - body[i].oldp) / (2.0 * dt);
			body[i].oldp = temp;

		}

		// Printing Body Info On Console

		if (CONSOLE_INFO) {
			i = 0;
			while (i < N) {
				body[i].info(i);
				i++;
			}
		}

	}

}
#endif