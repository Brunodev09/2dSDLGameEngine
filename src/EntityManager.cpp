#include "./EntityManager.h"
#include <iostream>

void EntityManager::Clear() {
    for (auto& entity : entities) {
        entity->Destroy();
    }
}

bool EntityManager::hasNoEntities() { return entities.size() == 0; }

void EntityManager::Update(float deltaTime) {
    for (auto& entity : entities) {
        entity->Update(deltaTime);
    }
}

void EntityManager::Render() {
    for (auto& entity : entities) {
        entity->Render();
    }
}

Entity& EntityManager::AddEntity(std::string entityName) {
    Entity* entity = new Entity(*this, entityName);
    entities.emplace_back(entity);
    return *entity;
}

std::vector<Entity*> EntityManager::GetEntities() const { return entities; }

unsigned int EntityManager::GetEntityCount() { return entities.size(); }

void EntityManager::ListAllEntities() {
    for (auto& e : entities) {
        std::cout << "Entity: ";
        std::cout << e->name << std::endl;
        std::cout << "\tComponents: " << std::endl;
        for (auto& c : e->components) {
            std::cout << "\t\t" + c->componentName;
        }

        std::cout << std::endl;
    }
}
