
#pragma once
#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem {
public:
    
    // constructors are functions like setup(), but they run automatically
    // when the object is created in our app
   
    ParticleSystem();                   // default
    ParticleSystem(glm::vec2 _pos);     // "overload" / alternative
    
    void applyForce(glm::vec2 force);   // applies force to particles
    
    void update(int numNewParticles = 10, int maxParticles = 500);
    /*
        numNewParticles:
            how many new particles to create each frame
                (defaults to 10)
        maxParticles:
            maximum number of particles the system will hold
                (defaults to 1000)
     */
    
    
    void draw();
    
    glm::vec2 pos;                  // origin of the particle system
    
    vector<Particle> particles;
};
