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
#include "rosenbrok_f.h"
#include "sincos_f.h"

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
    double left_1 = -5, left_2 = -5, right_1 = 5, right_2 = 5, start_x = 0, start_y = 0;
    HeatMap hm;
};
#endif // CHOOSEPARAMS_H
