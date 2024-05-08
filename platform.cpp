#include "./headfile/platform.h"


 Platform::Platform(int x, int y ) 
    {
        setPixmap(QPixmap("./dataset/images/stair-basic.png").scaled(120, 30));
        setPos(x, y);
        collisionRect = QRect(x, y, 120, 30);
        //qDebug() << "platform" << collisionRect;
    }
    QRect Platform::returncollisionRect(){
  return collisionRect;
}
