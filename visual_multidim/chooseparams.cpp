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

    ui->left1DSB->setMaximum(INFINITY);
    ui->left1DSB->setMinimum(-INFINITY);
    ui->left2DSB->setMaximum(INFINITY);
    ui->left2DSB->setMinimum(-INFINITY);
    ui->right1DSB->setMaximum(INFINITY);
    ui->right1DSB->setMinimum(-INFINITY);
    ui->right2DSB->setMaximum(INFINITY);
    ui->right2DSB->setMinimum(-INFINITY);

    ui->left1DSB->setValue(left_1);
    ui->left2DSB->setValue(left_2);
    ui->right1DSB->setValue(right_1);
    ui->right2DSB->setValue(right_2);

}

ChooseParams::~ChooseParams()
{
    delete ui;
    delete sc;
    delete f;
    delete om;
}


void ChooseParams::on_plotButton_clicked()
{
    delete sc;
    delete f;
    delete om;

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
        }
        if (ui->rosenbrokRB->isChecked()){
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
            temp.clear();
        }

        hm.setData(f_heatmap, om, par);


    }  catch (const std::exception& e) {
        QMessageBox::warning(this, "Exception", e.what());
    }

}



