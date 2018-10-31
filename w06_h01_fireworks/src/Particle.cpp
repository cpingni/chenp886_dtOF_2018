
#include "Particle.hpp"

Particle::Particle()
{
    
    // default constructor:
    // Particle particle = Particle();
    
    pos = glm::vec2(ofGetMouseX(),ofGetMouseY());
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass)
{
    
    // "overload" constructor, alternative:
    // Particle particle = Particle(pos,vel,acc);
    
    pos = _pos;
    vel = _vel;
    mass = _mass;
}

void Particle::applyForce(glm::vec2 force)
{
    acc += force / mass;
}

void Particle::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
}

void Particle::draw()
{
    ofPushStyle();
    float hue = ofMap(mass, 0, 5, 0, 255);
    ofSetColor(ofColor::fromHsb(0,hue,100));
    ofDrawCircle(pos, mass * 1.0);
    ofPopStyle();
}

    


