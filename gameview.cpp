#include "./headfile/gameview.h"
GameView::GameView(QStackedWidget *stackedWidget, QGraphicsScene *scene,
                   QWidget *parent)
    : QGraphicsView(scene, parent), scene(scene) {
  // 創建計分板
  scoreBoard = new ScoreBoard(this);
  // // 創建一個返回選單按鈕
  // pauseButton = new QPushButton(this);
  // // pauseButton->move(460, 5);
  // pauseButton->setFixedSize(50, 50);
  // // 設置 pauseButton 的樣式表
  // pauseButton->setStyleSheet(
  //     "QPushButton {"
  //     "    border-image: url(./dataset/images/pausebutton.png);"
  //     "    width: 50px;"
  //     "    height: 50px;"
  //     "}");
  // // 連接按鈕的點擊信號到槽
  // connect(pauseButton, &QPushButton::clicked,parent,&GameWidget::togglePause);
  QHBoxLayout *infoLayout = new QHBoxLayout;
  infoLayout->addWidget(scoreBoard);
  // infoLayout->addWidget(pauseButton);
  infoLayout->setAlignment(Qt::AlignTop);  // 将布局置于窗口的顶部
  setLayout(infoLayout);
  // 創建計時器
  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, [=]() {
    scoreBoard->culScore(score);
});

  timer->start(20);
}
void GameView::setScore(long long score) { this->score = score; }
bool GameView::scrollToPlayer() {
  // 获取玩家的图形项
  bool flag = 0;
  QList<QGraphicsItem *> players = scene->items();
  QGraphicsItem *playerItem = nullptr;
  for (QGraphicsItem *item : players) {
    if (dynamic_cast<Player *>(item)) {
      playerItem = item;
      // qDebug() << "sscess" << playerItem;
      break;
    }
  }

  if (!playerItem) {
    qDebug() << "cantfind";
  }
  // 获取玩家的位置
 
  playerPos = playerItem->pos();
  // 将玩家的位置转换为视图坐标
  QPointF playerPosInView = mapFromScene(playerPos);
  // qDebug() << "playerPosInView: " << playerPosInView.y() <<" height/2: "<<
  // viewport()->height()/2;
  verticalScrollBar()->setMinimum(INT_MIN);
  // 如果玩家超过视图的中线，则移动视图
  if (playerPosInView.y() < viewport()->height() / 2) {
    flag = 1;
    // 计算视图需要向上滚动的距离
    int scrollDistance = viewport()->height() / 2 - playerPosInView.y();

    // 获取当前的垂直滚动条位置
    int currentScrollBarValue = verticalScrollBar()->value();

    // 将垂直滚动条向上滚动相应的距离
    verticalScrollBar()->setValue(currentScrollBarValue - scrollDistance);
    // qDebug()<< "cur: " << currentScrollBarValue << " dis: " <<
    // scrollDistance<< "  " << currentScrollBarValue - scrollDistance ;
    // 获取视口的范围
    QRectF viewportRect = mapToScene(viewport()->rect()).boundingRect();

    // 获取场景中的所有平台
    QList<QGraphicsItem *> platforms = scene->items();
    // qDebug() << platforms;
    // 遍历所有平台
    for (QGraphicsItem *item : platforms) {
      if (dynamic_cast<Platform *>(
              item)) {  // 假设 Platform 是平台类的名称和类型标识符
        // 获取平台的边界矩形
        ;
        // qDebug()<< "   " << score <<" "<< item;
        // 判断平台是否在视口下方以外
        if ((700 - item->y()) < score - 1000) {
          // 删除平台
          scene->removeItem(item);
          delete item;
        }
      }
    }
  }
  return flag;
}
void GameView::checkPlayerPosition() {
  // 获取玩家在视图中的位置
  QPointF playerPosInView = mapFromScene(playerPos);

  // 获取视图的矩形范围
  QRectF viewportRect = viewport()->rect();

  // 如果玩家超出了视图底部边界
  if (playerPosInView.y() > viewportRect.bottom()) {
    // 触发游戏结束逻辑
    emit gameOver();
  }
  
}
