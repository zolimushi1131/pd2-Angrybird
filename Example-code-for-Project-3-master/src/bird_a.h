#ifndef BIRD_A_H
#define BIRD_A_H
#include <gameitem.h>
#include <bird.h>
#include "mainwindow.h"

class Bird_A: public Bird
{
public:
    Bird_A(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void ability();
};

#endif // BIRD_A_H
