#ifndef OPTIMISER_HEATMAP_H
#define OPTIMISER_HEATMAP_H

#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include "fletcher_reeves.h"
#include "random_search.h"
#include "parallel.h"

class HeatMap : public QLabel {
public:
    HeatMap();
    HeatMap(std::vector<std::vector<double>> data, opt_method* m, parallel p);
    void setData(std::vector<std::vector<double>> data, opt_method* m, parallel p);

    ~HeatMap();

private:
    double maximum(std::vector<std::vector<double>> data);
    double minimum(std::vector<std::vector<double>> data);
    QImage* image = nullptr;
    QPixmap mainFrame;
    QPixmap mainFrame1;
    int width;
    int height;

    opt_method* om;
    parallel par;

    void mousePressEvent(QMouseEvent* event);
};


#endif //OPTIMISER_HEATMAP_H
