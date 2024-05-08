#include "./headfile/scoreboard.h"
ScoreBoard::ScoreBoard(QWidget *parent) : QWidget(parent) {
  // 創建資訊欄的 QLabel

  HP = 3;
  scoreLabel = new QLabel(this);
  healthLabel = new QLabel(this);

  // 設置分數 QLabel 的字體和大小
  QFont scoreFont("Arial", 24);  // 字體：Arial，大小：24
  scoreLabel->setFont(scoreFont);
  // 初始化血量圖片
  fullHeart = QPixmap("./dataset/images/heart_fill.png").scaled(50, 50);
  // 更新血量顯示
  culHP();
  scoreLabel->setText(QString("%1").arg(0));
  // 創建水平佈局並添加 QLabel
  QHBoxLayout *infoLayout = new QHBoxLayout;
  infoLayout->addWidget(scoreLabel);
  infoLayout->addSpacing(230);
  infoLayout->addWidget(healthLabel);

  // 創建垂直佈局並添加資訊欄的水平佈局
  // QVBoxLayout *mainLayout = new QVBoxLayout(this);
  // mainLayout->addLayout(infoLayout);  // 添加資訊欄
  // mainLayout->addStretch();           // 添加伸縮空間（可選）

  // 設置主佈局
  setLayout(infoLayout);
  // 使用 QTimer 模擬分數的變化
  // QTimer *timer = new QTimer(this);
  // connect(timer, &QTimer::timeout, this, &culScore);
  // timer->start(1000);  // 每隔1秒更新分數
  // 使用 QTimer 模擬碰撞事件
  // QTimer *timer1 = new QTimer(this);
  // connect(timer1, &QTimer::timeout, this, &onCollision);
  // timer1->start(3000);  // 每隔3秒觸發一次碰撞事件
}
void ScoreBoard::culScore(long long score) {
  // 更新分數並更新 QLabel 的內容

  scoreLabel->setText(QString(" %1").arg(score));
}
void ScoreBoard::onCollision() {
  // 減少血量並更新血量顯示
  if (HP > 0) {
    HP--;
    culHP();
  }
}
void ScoreBoard::culHP() {
  // 創建一個新的 QPixmap，用於顯示血量
  QPixmap healthPixmap(HP * fullHeart.width(), fullHeart.height());
  healthPixmap.fill(Qt::transparent);  // 填充透明背景
  QPainter painter(&healthPixmap);

  for (int i = 0; i < HP; ++i) {
    painter.drawPixmap(i * fullHeart.width(), 0, fullHeart);
  }

  // 更新 QLabel 的圖片
  healthLabel->setPixmap(healthPixmap);
}
