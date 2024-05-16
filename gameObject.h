#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
protected:
    int gridSize;

public:
    GameObject(int gridSize);
    virtual ~GameObject();
    virtual void respawn(int gridSize) = 0; // Pure virtual function to respawn the object
};

#endif // GAMEOBJECT_H
