#include "./headfile/gameoverwidget.h"
GameOverWidget::GameOverWidget(QStackedWidget *stackedWidget, QWidget *parent)
    : QWidget(parent), stackedWidget(stackedWidget) {
  this->parent = parent;
  this->setFixedSize(540, 960);
  QLabel *background = new QLabel(this);
  background->setPixmap(
      QPixmap("./dataset/images/background.png").scaled(540, 960));
  background->setGeometry(0, 0, 540, 960);
  background->lower();
  playAgainButton = new QPushButton("playagain", this);
  menuButton = new QPushButton("menu", this);
  scoreBoard = new QLabel(this);
  hLayout = new QHBoxLayout(this);
  scoreLayout = new QHBoxLayout(this);
  vLayout = new QVBoxLayout(this);
  scoreBoard->setGeometry(250, 300, 100, 50);
  hLayout->addWidget(playAgainButton);
  hLayout->addWidget(menuButton);
  vLayout->addLayout(hLayout);
  setLayout(vLayout);
  connect(menuButton, &QPushButton::clicked, this, &GameOverWidget::goToMenu);
  connect(playAgainButton, &QPushButton::clicked, this,
          &GameOverWidget::goToGame);
}
void GameOverWidget::setScore(long long score) {
  this->score = score;
  scoreBoard->setText(QString::number(score));
}
void GameOverWidget::goToGame() {
  stackedWidget->removeWidget(this);
  GameWidget *gameWidget = new GameWidget(stackedWidget, this);
  stackedWidget->addWidget(gameWidget);
  stackedWidget->setCurrentIndex(1);
  delete this;
}
void GameOverWidget::goToMenu() {
  stackedWidget->setCurrentIndex(0);
  stackedWidget->removeWidget(this);
   delete this;
}