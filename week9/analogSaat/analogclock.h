#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>

class analogclock : public QWidget
{
    Q_OBJECT

public:
    //explicit: Derleyicinin otomatik(örtük) tür dönüşümünü engeller.
    explicit analogclock(QWidget *parent = nullptr);

protected:
    //görüntünün güncellenmesini sağlar
    // QWidget içinde hazır olarak paintEvent bulunduğu için override ettik
    void paintEvent(QPaintEvent *event) override;

signals:

};
#endif // ANALOGCLOCK_H
