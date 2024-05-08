#ifndef PLATFORM_H
#define PLATFORM_H
#include<QObject>
#include<QWidget>
#include <QDebug>
#include<QGraphicsPixmapItem>
class Platform : public QObject , public QGraphicsPixmapItem
{
      Q_OBJECT
public:
    Platform(int ,int); 
    QRect returncollisionRect();
private:
    QRect collisionRect;
    
};
#endif