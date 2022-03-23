#include "Heatmap.h"
#include <iostream>

HeatMap::HeatMap() {

};

HeatMap::HeatMap(std::vector<std::vector<double>> data, opt_method* m, parallel p)
{
    setData(data, m, p);
};



void HeatMap::setData(std::vector<std::vector<double>> data, opt_method* m, parallel p_){
    om = m;
    par = p_;

    height = data.size();
    width = data[0].size();

    delete image;
    image = new QImage(width, height, QImage::Format_RGB32);

    double min = minimum(data);
    double max = maximum(data);

    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            int Rv = 0;
            if (max>min) {
                Rv = (int) (255 * (data[i][j] - min) / (max - min));
            }

            QRgb value = qRgb(0, Rv, 0);
            image->setPixel(j, i, value);
        }
    };
    resize(width, height);

    mainFrame = QPixmap::fromImage(*image);

    this->setPixmap(mainFrame);

    this->show();
}


double HeatMap::maximum(std::vector<std::vector<double>> data){
    double max = data[0][0];
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j) {
            if(data[i][j] > max) max = data[i][j];
        }
    };
    return max;
}

double HeatMap::minimum(std::vector<std::vector<double>> data){
    double min = data[0][0];
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j) {
            if(data[i][j] < min) min = data[i][j];
        }
    };
    return min;
}

void HeatMap::mousePressEvent(QMouseEvent *event)
{

    double start_x = event->position().x() * (par.get_lim(0).second - par.get_lim(0).first) / width + par.get_lim(0).first;
    double start_y = (height - event->position().y()) * (par.get_lim(1).second - par.get_lim(1).first) / height + par.get_lim(1).first;

    om->calc(std::vector<double> {start_x, start_y});
    std::vector<std::vector<double>> x = om->get_x();

    std::vector<std::pair<int, int>> x_coord{};
    for (std::vector<double> v:x) {
        x_coord.push_back(std::pair<int, int>{
                              (int) (width * (v[0] - par.get_lim(0).first) / (par.get_lim(0).second - par.get_lim(0).first)),
                              height - (int) (height * (v[1] - par.get_lim(1).first) / (par.get_lim(1).second - par.get_lim(1).first))
                          });
    }

    mainFrame = QPixmap::fromImage(*image);
    QPainter p(&mainFrame);
    p.setPen(Qt::red);

    for (int i = 1; i < x.size(); ++i) {
        p.drawLine(x_coord[i - 1].first, x_coord[i - 1].second, x_coord[i].first, x_coord[i].second);
    }
    p.setPen(Qt::blue);
    p.setBrush(Qt::blue);
    p.drawEllipse(QPointF(x_coord.back().first, x_coord.back().second), 3, 3);

    QFont font = p.font();
    font.setPointSize(font.pointSize() * 2);
    p.setFont(font);

    p.drawText(0, 20, ("x = (" + std::to_string(x.back()[0]) + ", " + std::to_string(x.back()[1]) + ")").c_str());

    p.end();

    this->setPixmap(mainFrame);

    this->show();
}

HeatMap::~HeatMap()
{
    delete image;
}
