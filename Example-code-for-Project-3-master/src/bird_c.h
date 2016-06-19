#ifndef BIRD_C_H
#define BIRD_C_H
#include <gameitem.h>
#include <bird.h>
#include "mainwindow.h"

class Bird_C: public Bird
{
public:
    Bird_C(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void ability();
};
#endif // BIRD_C_H
