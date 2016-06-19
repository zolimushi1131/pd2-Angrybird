#ifndef BIRD_B_H
#define BIRD_B_H
#include <gameitem.h>
#include <bird.h>
#include "mainwindow.h"

class Bird_B: public Bird
{
public:
    Bird_B(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void ability();
};

#endif // BIRD_B_H
