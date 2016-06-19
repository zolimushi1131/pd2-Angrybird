#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);

    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));

    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());

    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));

    //Create Enemy
    Enemy *enemy = new Enemy(25.0f,10.0f,2.0f,&timer,QPixmap(":/enemy").scaled(height()/3.0,height()/3.0),world,scene);

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        static int R=0;
        if(birdNum==0&&R==0)
        {
            Bird_A *birdie = new Bird_A(0.0f,10.0f,0.27f,&timer,QPixmap(":/birdA").scaled(height()/9.0,height()/9.0),world,scene);
            birdie->setLinearVelocity(b2Vec2(5,5));
            birdList.push_back(birdie);
            birdNum++;
        }
        else if(birdNum==1&&R==5)
        {
            Bird_B *birdie = new Bird_B(0.0f,10.0f,0.27f,&timer,QPixmap(":/birdB").scaled(height()/9.0,height()/9.0),world,scene);
            birdie->setLinearVelocity(b2Vec2(5,5));
            birdList.push_back(birdie);
            birdNum++;
        }
        else if(birdNum==2&&R==10)
        {
            Bird_C *birdie = new Bird_C(0.0f,10.0f,0.27f,&timer,QPixmap(":/birdC").scaled(height()/9.0,height()/9.0),world,scene);
            birdie->setLinearVelocity(b2Vec2(5,5));
            birdList.push_back(birdie);
            birdNum++;
        }
        R++;
    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        /* TODO : add your code here */
        //std::cout << "Release !" << std::endl ;
    }
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent* key = static_cast<QKeyEvent *>(event);
        if(key->key()==Qt::Key_Space&&birdNum!=0&&birdList[birdNum-1]->status!=1)
        {
            birdList[birdNum-1]->ability();
        }
        if(key->key()==Qt::Key_Space&&birdList[birdNum-1]->status==3)
        {
            copytimer = new QTimer();
            connect(copytimer,SIGNAL(timeout()),this,SLOT(copybird()));
            copytimer->start(400);


            QTimer::singleShot(5000,this,SLOT(stopcpbird()));


        }
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
void MainWindow::copybird()
{
    Bird_C *copybird = new Bird_C(0.0f,10.0f,0.27f,&timer,QPixmap(":/copybird2").scaled(height()/9.0,height()/9.0),world,scene);
    copybird->setLinearVelocity(b2Vec2(10,10));
}

void MainWindow::stopcpbird()
{
    std::cout<<"stop copy"<<"\n";
    copytimer->stop();
}
