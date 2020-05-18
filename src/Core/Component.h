#ifndef COMPONENT_H
#define COMPONENT_H

#include "./Entity.h"
#include <string>

class Entity;

class Component {
public:
    std::string componentName;
    Entity* owner;
    virtual ~Component() {}
    virtual void Init() {}
    virtual void Update(float deltaTime) {}
    virtual void Render() {}
};

#endif