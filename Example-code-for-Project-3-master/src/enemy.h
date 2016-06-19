#ifndef ENEMY_H
#define ENEMY_H
#include "bird.h"
class Enemy : Bird
{
public:
    Enemy(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // ENEMY_H
