#include "bird_b.h"
#include <QKeyEvent>
#include "mainwindow.h"
#include <QTimer>

Bird_B::Bird_B(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird( x, y, radius, timer, pixmap, world, scene)
{

}
void Bird_B::ability()
{
    setLinearVelocity(b2Vec2(5,10));
}
