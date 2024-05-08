#ifndef PLAYER_H
#define PLAYER_H
// 創建player類別
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QLabel>
#include <QObject>
#include <QScrollArea>
#include <QScrollBar>
#include <QSound>

#include "platform.h"
class Player : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
  // signals:
  //   void outOfBounds();
 public:
  Player();
  void jump();
  void update();
  // bool checkDroping();
  // QRect returncollisionRect();
   long long returnScore();
   bool returnTurnFlag();
  void keyPressEvent(QKeyEvent *event) {
    int step = 40;  // 移动步长
    if (event->key() == Qt::Key_Left) {
      // 按下左箭头键，向左移动
      // this->setPixmap(QPixmap("./dataset/images/doodleL.png"));
      turnflag = 0;
      setPos(x() - step, y());
    } else if (event->key() == Qt::Key_Right) {
      // 按下右箭头键，向右移动
      // this->setPixmap(QPixmap("./dataset/images/doodleR.png"));
      turnflag = 1;
      setPos(x() + step, y());
    }
  }
 public slots:
  void checkCollision();

 private:
  qreal velocity;
  qreal gravity;
  qreal jumpDistance;
  const qreal maxJumpDistance = 320;
  QRect collisionRect;
  bool collisionFlag = false;
  long long score = 0;
  bool turnflag = 0;
};
#endif