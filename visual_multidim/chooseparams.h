#ifndef CHOOSEPARAMS_H
#define CHOOSEPARAMS_H

#include <QWidget>
#include <QMessageBox>

#include "Heatmap.h"

#include "fletcher_reeves.h"
#include "x_crit.h"
#include "f_crit.h"
#include "grad_crit.h"
#include "iter_ctrit.h"
#include "sq_sum.h"
#include "f_3dim.h"
#include "f_4dim.h"
#include "parallel.h"
#include "random_search.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChooseParams; }
QT_END_NAMESPACE



class ChooseParams : public QWidget
{
    Q_OBJECT

public:
    ChooseParams(QWidget *parent = nullptr);
    ~ChooseParams();

private slots:
    void on_plotButton_clicked();


private:
    Ui::ChooseParams *ui;
    double left_1 = -1, left_2 = -1, right_1 = 1, right_2 = 1, start_x = 0.5, start_y = 0.5;
    HeatMap hm;
};
#endif // CHOOSEPARAMS_H
