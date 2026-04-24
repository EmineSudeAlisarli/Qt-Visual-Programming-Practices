#include "analogclock.h"
#include <QTime>
#include <QTimer>
#include <QPainter>

analogclock::analogclock(QWidget *parent)
    : QWidget(parent)
{
    QTimer *timer = new QTimer(this);

    connect(timer,&QTimer::timeout,this,QOverload<>::of(&analogclock::update));
    timer->start(1000);
    setWindowTitle(tr("Anlog Saat"));
    resize(200,200);
}

void analogclock::paintEvent(QPaintEvent *event)
{
    static const QPoint hourHand[3] = {QPoint(7,8),QPoint(-7,8),QPoint(0,-40),};
    static const QPoint hourMinute[3] = {QPoint(7,8),QPoint(-7,8),QPoint(0,-70),};
    static const QPoint secondHand[3] = {QPoint(1,1), QPoint(-1,1), QPoint(0,-70)};

    //(kırmızı,yeşil,mavi,saydamlık) RGB-Alpha
    // Saydamlık 0-255 arası 0-> tam saydam |♣ 255-> tam opak
    QColor hourColor(127,0,127);
    QColor MinuteColor(0,127,127,50);
    QColor secondColor(255,0,255);

    QTime time=QTime::currentTime();
    QPainter painter(this);

    // pikselleşmeyi azaltır
    painter.setRenderHint(QPainter::Antialiasing);

    // ölçeklendirme için yazıyoruz
    // qMin(): İki değer alır ve küçük olanı döndürür.
    // width(): Açılan pencerenin genişlik değeri
    // height(): Açılan pencerenin yükseklik değeri
    int side=qMin(width(),height());

    // orijini (0,0) noktasından widget'in merkezine taşıyan bir dönüşüm yapar.
    painter.translate(width()/2,height()/2);

    // Ölçeklendirme için, pencere büyüdükçe saate büyür
    painter.scale(side/200,side/200);

    //Akrep kolunun çizimi
    painter.setPen(Qt::SolidLine);//Çizginin stilini belirler
    painter.setBrush(hourColor);//Şekli boyar
    painter.save();//O anki koordinatları kaydettim
    painter.rotate(30*(time.hour()+time.minute()/60));//Çizimi saate göre döndürdüm
    painter.drawConvexPolygon(hourHand,3);//Şeklin çizimi
    painter.restore(); //Çizimi tekrar eski haline getiriyor

    // yelkovan icin cizim
    painter.setPen(Qt::DotLine);
    painter.setBrush(MinuteColor);
    painter.save();
    painter.rotate(6*(time.minute()+time.second()/60));
    painter.drawConvexPolygon(hourMinute,3);
    painter.restore();

    // Saniye icin cizim
    painter.setPen(Qt::SolidLine);
    painter.setBrush(secondColor);
    painter.save();
    painter.rotate(6*(time.second()+time.msec()/1000));
    painter.drawConvexPolygon(secondHand,3);
    painter.restore();


    // Saat çizgilerini çizer
    painter.setPen(Qt::SolidLine);
    for (int i=0;i<12;i++)
    {
        // (88, 0) koordinatından (x1, y1) başlar ve (96, 0) koordinatına (x2, y2) kadar devam eder
        painter.drawLine(88,0,96,0);
        painter.rotate(30); // 360/12 =30 derecede bir saat çizgisi var.
    }

    // Dakika çizgilerini çizer
    painter.setPen(Qt::DotLine);
    for (int j=0;j<60;j++)
    {
        if ((j%5)!=0)
        {
            painter.drawLine(92,0,96,0);
            // 360/60 =6 derecede bir saat çizgisi var.

        };
        painter.rotate(6);
    };
}
