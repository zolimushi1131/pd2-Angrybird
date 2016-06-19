#include "bird_a.h"
#include <QKeyEvent>
#include "mainwindow.h"
#include <QTimer>

Bird_A::Bird_A(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird( x, y, radius, timer, pixmap, world, scene)
{

}
void Bird_A::ability()
{
    setLinearVelocity(b2Vec2(40,0));
    g_body->SetGravityScale(0);
    status=1;
}
