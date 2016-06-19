#include "bird_c.h"
#include <QKeyEvent>
#include "mainwindow.h"
#include <QTimer>

Bird_C::Bird_C(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird( x, y, radius, timer, pixmap, world, scene)
{

}
void Bird_C::ability()
{
    setLinearVelocity(b2Vec2(0,0));
    g_body->SetGravityScale(0);
    status=3;
}
