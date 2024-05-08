#include "./headfile/player.h"

Player::Player() /*: velocity(0), gravity(0.2)*/ {
  setPixmap(QPixmap("./dataset/images/doodleL.png").scaled(80, 80));
  setPos(230, 700);
  setFlag(ItemIsFocusable);
  

        
  // collisionRect = QRect(0, 0, 80, 80);
  jump();
}

void Player::jump() {
  jumpDistance = 0;
  velocity = -5;
  collisionFlag = false;
  // 播放音频文件
    QSound::play("./dataset/sounds/jump.wav");
}
void Player::turnLeft() {
  leftDistance = 0;
  Lvelocity = -5;
  setPixmap(QPixmap("./dataset/images/doodleL.png"));
}
void Player::turnRight() {
  rightDistance = 0;
  Rvelocity = 5;
  setPixmap(QPixmap("./dataset/images/doodleR.png"));
}
void Player::update() {
  if(leftDistance < maxLRDistance){
    leftDistance += (-Lvelocity);
    setPos(x() + Lvelocity, y() );
  }
  if(rightDistance < maxLRDistance){
    rightDistance += (Rvelocity);
    setPos(x() + Rvelocity, y() );
  }
  if (jumpDistance < maxJumpDistance) {  // 上升
    jumpDistance += (-velocity);
    setPos(x(), y() + velocity);
    if (turnflag)
      setPixmap(QPixmap("./dataset/images/doodleR.png"));
    else
      setPixmap(QPixmap("./dataset/images/doodleL.png"));
  } else {  // 下降
    setPos(x(), y() - velocity);
    checkCollision();
    if (collisionFlag) {
      jump();
      if (turnflag)
        setPixmap(QPixmap("./dataset/images/doodleUR.png"));
      else
        setPixmap(QPixmap("./dataset/images/doodleUL.png"));
    }
  }
  // if (y() < 0)
  // emit outOfBounds();

  //  qDebug() << score ;
}

void Player::checkCollision() {
  QList<QGraphicsItem *> collidingItemsList = collidingItems();
  foreach (QGraphicsItem *item, collidingItemsList) {
    // 处理碰撞逻辑
    if (dynamic_cast<Platform *>(item)) {
      // 与另一个QGraphicsPixmapItem发生碰撞
      // 在这里添加你的处理逻辑
      collisionFlag = 1;
      qDebug() << "Collision detected!";
    }
  }
}
// bool Player::checkDroping() { return collisionFlag; }
// QRect Player::returncollisionRect() { return collisionRect; }
long long Player::returnScore() { return score; }

