#include "chooseparams.h"
#include "ui_chooseparams.h"
#include <chrono>
#include <thread>
#include <QHBoxLayout>

std::mt19937 SingletonGenerator::mersennetwister;



ChooseParams::ChooseParams(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChooseParams)
{
    ui->setupUi(this);

    ui->left1DSB->setValue(left_1);
    ui->left2DSB->setValue(left_2);
    ui->right1DSB->setValue(right_1);
    ui->right2DSB->setValue(right_2);
    ui->xstartDSB->setValue(start_x);
    ui->ystartDSB->setValue(start_y);
    ui->left1DSB->setMaximum(INFINITY);
    ui->left1DSB->setMinimum(-INFINITY);
    ui->left2DSB->setMaximum(INFINITY);
    ui->left2DSB->setMinimum(-INFINITY);
    ui->right1DSB->setMaximum(INFINITY);
    ui->right1DSB->setMinimum(-INFINITY);
    ui->right2DSB->setMaximum(INFINITY);
    ui->right2DSB->setMinimum(-INFINITY);
    ui->xstartDSB->setMaximum(INFINITY);
    ui->xstartDSB->setMinimum(-INFINITY);
    ui->ystartDSB->setMaximum(INFINITY);
    ui->ystartDSB->setMinimum(-INFINITY);

}

ChooseParams::~ChooseParams()
{
    delete ui;
}


void ChooseParams::on_plotButton_clicked()
{
    parallel par;
    opt_function* f = nullptr;
    opt_method* om = nullptr;
    stop_crit* sc = nullptr;

    try {
        par.clear_limits();
        left_1 = ui->left1DSB->value();
        left_2 = ui->left2DSB->value();
        right_1 = ui->right1DSB->value();
        right_2 = ui->right2DSB->value();
        par.add_limits(left_1, right_1);
        par.add_limits(left_2, right_2);

        if (ui->sqsmRB->isChecked()) {
            f = new sq_sum;
        } else {
            f = new rosenbrok_f;
        }

        if (ui->rsmethodRB->isChecked()) {
             sc = new iter_ctrit;
             om = new random_search(*f, *sc, par);
        } else {
            if (ui->xcritRB->isChecked()) {
                sc = new x_crit;
            }
            if (ui->fcritRB->isChecked()) {
                sc = new f_crit;
            }
            if (ui->gradcritRB->isChecked()) {
                sc = new grad_crit;
            }
            om = new fletcher_reeves(*f, *sc, par);
        }

        start_x = ui->xstartDSB->value();
        start_y = ui->ystartDSB->value();

        om->calc(std::vector<double> {start_x, start_y});

        std::vector<std::vector<double>> x = om->get_x();

        int length = 500, height = 500;
        std::vector<std::vector<double>> f_heatmap {};
        std::vector<double> temp{};
        double step_l = (par.get_lim(0).second - par.get_lim(0).first) / length;
        double step_h = (par.get_lim(1).second - par.get_lim(1).first) / height;
        double cur_h = par.get_lim(1).second;
        double cur_l = par.get_lim(0).first;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < length; ++j) {
                temp.push_back(f->calc(std::vector<double>{cur_l, cur_h}));
                cur_l += step_l;
            }
            f_heatmap.push_back(temp);
            cur_l = par.get_lim(0).first;
            cur_h -= step_h;
        }

        std::vector<std::pair<int, int>> f_coord{};
        for (std::vector<double> v:x) {
            f_coord.push_back(std::pair<int, int>{
                                  (int) (length * (v[0] - par.get_lim(0).first) / (par.get_lim(0).second - par.get_lim(0).first)),
                                  height - (int) (height * (v[1] - par.get_lim(1).first) / (par.get_lim(1).second - par.get_lim(1).first))
                              });
        }

        hm.setData(f_heatmap, f_coord, x.back());





    }  catch (const std::exception& e) {
        QMessageBox::warning(this, "Exception", e.what());
    }
    delete f;
    delete om;
    delete sc;
}



