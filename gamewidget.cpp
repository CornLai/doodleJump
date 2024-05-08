#include "./headfile/gamewidget.h"
GameWidget::GameWidget(QStackedWidget *stackedWidget, QWidget *parent)
    : QWidget(parent), stackedWidget(stackedWidget) {
  this->setFixedSize(540, 960);
  // 创建场景
  scene = new GameScene(this);
  scene->setSceneRect(0, 0, 540, 2000);
  QPixmap backgroundImage("./dataset/images/background.png");  // 載入背景圖片
  qDebug() << backgroundImage;
  // 將背景圖片設置為 QGraphicsScene 的背景
  scene->setBackgroundBrush(backgroundImage);
  // 创建视图
  view = new GameView(stackedWidget, scene, this);
  view->setRenderHint(QPainter::Antialiasing);
  view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
  view->setFixedSize(540, 960);  // 设置视图的固定大小为 540x960 像素
  // 設置layout
  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addWidget(view);
  setLayout(mainLayout);

  // 創建玩家
  player = new Player();
  this->addGameItem(player);
  player->setFocus();
  // 創建初始平台
  Platform *startplatform = new Platform(250, 900);
  this->addGameItem(startplatform);

  timer = new QTimer(this);
  QObject::connect(timer, QTimer::timeout, this, GameWidget::updateGame);
  timer->start(20);
  spawnPlatform();
  connect(view, &GameView::gameOver, this, &GameWidget::handleGameOver);
  // qDebug() << "遊戲創建成功";
  // this->setFocus();
  // connect(player, &Player::outOfBounds, this, SLOT(adjustView()));
  // test
  // Platform *testplatform = new Platform(400,20,this);
  // Platform *test2platform = new Platform(0,60,this);
  // testplatform->setPixmap(QPixmap("./dataset/images/stair-blue.png").scaled(120,
  // 30));
  // test2platform->setPixmap(QPixmap("./dataset/images/stair-blue.png").scaled(120,
  // 30)); qDebug() << testplatform->returncollisionRect(); qDebug() <<
  // test2platform->returncollisionRect();
  //
}
void GameWidget::addGameItem(QGraphicsItem *item) { scene->addItem(item); }

void GameWidget::updateGame() {
  player->update();
  score = (score > 700 - player->y()) ? score : (700 - player->y());
  // qDebug() << score;
  view->setScore(this->returnScore());
  view->scrollToPlayer();
  view->checkPlayerPosition();
  if((score%1000) == 995)
    spawnPlatform();
}
void GameWidget::spawnPlatform() {
  int platformCount = 20;  // 設置每次觸發時要創建的平台數量

  for (int i = 0; i < platformCount; ++i) {
    int randomY = lastY - ((rand() % 211) + 60);
    Platform *platform = new Platform((rand() % 540)-60, randomY);
    // qDebug() << i << " " << platform->returncollisionRect();
    qDebug()<< lastY - randomY;
    lastY = randomY;  // 更新上一個平台的 Y 座標
    this->addGameItem(platform);
  }
}
long long GameWidget::returnScore() { return score; }
// void GameWidget::checkCollisions() {
//   foreach (Platform *platform, platforms) {
//     if (player->returncollisionRect().intersects(
//             platform->returncollisionRect())) {
//       player->jump();
//       if (turnflag)
//         player->setPixmap(QPixmap("./dataset/images/doodleUR.png"));
//       else
//         player->setPixmap(QPixmap("./dataset/images/doodleUL.png"));
//     }
//   }
// }
void GameWidget::handleGameOver(){
   GameOverWidget *gameOverWidget = new GameOverWidget(stackedWidget, this);
            stackedWidget->addWidget(gameOverWidget);  // index 2
            stackedWidget->setCurrentIndex(2); 
}
