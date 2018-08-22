/*
 * Swarm.h
 *
 *  Created on: Jul 24, 2018
 *      Author: singh
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace screen {

class Swarm {
private:
	Particle * m_particles;
	int m_lastTime;
public:
	const static int Number_Of_Particles = 5000;
	Swarm();
	virtual ~Swarm();
	const Particle * const getParticles() { return m_particles; }
	void update(int elapsed);
};

} /* namespace screen */

#endif /* SWARM_H_ */
