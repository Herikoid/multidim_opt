#include "Heatmap.h"

HeatMap::HeatMap() {

};

HeatMap::HeatMap(std::vector<std::vector<double>> data, std::vector<std::pair<int, int>> x, std::vector<double> res)
{
    setData(data, x, res);
};



void HeatMap::setData(std::vector<std::vector<double>> data, std::vector<std::pair<int, int>> x, std::vector<double> res){
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

    QPainter p(&mainFrame);
    p.setPen(Qt::red);

    for (int i = 1; i < x.size(); ++i) {
        p.drawLine(x[i - 1].first, x[i - 1].second, x[i].first, x[i].second);
    }
    p.setPen(Qt::blue);
    p.setBrush(Qt::blue);
    p.drawEllipse(QPointF(x.back().first, x.back().second), 3, 3);

    QFont font = p.font();
    font.setPointSize(font.pointSize() * 2);
    p.setFont(font);

    p.drawText(0, 20, ("x = (" + std::to_string(res[0]) + ", " + std::to_string(res[1]) + ")").c_str());

    p.end();


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

HeatMap::~HeatMap()
{
    delete image;
}
