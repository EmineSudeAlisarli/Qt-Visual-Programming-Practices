# Qt-Visual-Programming-Practices
Weekly practices, assignments, and UI projects for the Visual Programming lesson using C++ and Qt Framework.

# Week 9: Custom Analog Clock (Analog Saat Uygulaması)

Bu haftaki uygulamada, Qt Framework içerisinde yer alan `QPainter` sınıfı kullanılarak sıfırdan özel bir widget (analog saat) çizimi gerçekleştirilmiştir. Saat, sistem saatini anlık olarak okuyarak akrep, yelkovan ve saniye kollarını matematiksel hesaplamalarla doğru açılarda ekrana yansıtır.

## Öğrenilen Kazanımlar ve Kullanılan Teknolojiler

* **Custom Widget Design:** Mevcut widget'ları kullanmak yerine `paintEvent` fonksiyonunu *override* ederek sıfırdan arayüz çizimi.
* **QPainter:** Şekil çizimleri (`drawConvexPolygon`, `drawLine`), fırça ve kalem ayarları (`setPen`, `setBrush`), kenar yumuşatma (`Antialiasing`).
* **Coordinate Transformations (Koordinat Dönüşümleri):** * `translate()` ile orijini pencere merkezine taşıma.
    * `scale()` ile pencere boyutu değiştiğinde saatin de dinamik olarak yeniden boyutlanması.
    * `rotate()` ile kolların saniye ve dakikaya göre doğru açılarda döndürülmesi.
* **QTimer & QTime:** `QTimer` kullanılarak saniyede bir `update()` metodunun tetiklenmesi ve `QTime::currentTime()` ile sistem saatinin çekilmesi.
