#ifndef GAMESCENE_H
#define GAMESCENE_H
#include <QGraphicsScene>
#include <QPainter>
#include "player.h"

class GameScene : public QGraphicsScene {
public:
    GameScene(QObject *parent = nullptr);

private:
    Player *player;
};
#endif