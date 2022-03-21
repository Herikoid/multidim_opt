#ifndef OPTIMISER_HEATMAP_H
#define OPTIMISER_HEATMAP_H

#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <qpainter.h>


class HeatMap : public QLabel {
public:
    HeatMap();
    HeatMap(std::vector<std::vector<double>> data, std::vector<std::pair<int, int>> x, std::vector<double> res);
    void setData(std::vector<std::vector<double>> data, std::vector<std::pair<int, int>> x, std::vector<double> res);

    ~HeatMap();

private:
    double maximum(std::vector<std::vector<double>> data);
    double minimum(std::vector<std::vector<double>> data);
    QImage* image = nullptr;
    QPixmap mainFrame;
    int width;
    int height;
};


#endif //OPTIMISER_HEATMAP_H
